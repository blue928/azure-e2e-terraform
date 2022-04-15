<?php

/**
 * @file
 * Contains the logic for cloning orders.
 */

/**
 * The hook_menu() callback for Clone Order.
 */
function stihl_orders_clone_order_callback($old_order_id) {
  $cloned_order_wrapper = stihl_orders_clone_order($old_order_id);
  drupal_goto('orders/new/' . $cloned_order_wrapper->getIdentifier());
}

/**
 * Clones an existing approved order.
 *
 * @param int $old_order_id
 *   The entity ID for an existing order.
 *
 * @return \EntityMetadataWrapper
 *   The wrapper object for the cloned order.
 */
function stihl_orders_clone_order($old_order_id) {
  $old_order_wrapper = entity_metadata_wrapper('commerce_order', $old_order_id);
  $cloned_order = new stdClass();
  $cloned_order->type = 'commerce_order';
  $cloned_order->status = $old_order_wrapper->status->value();
  $cloned_order->uid = $GLOBALS['user']->uid;
  $cloned_order->mail = $old_order_wrapper->mail->value();
  $cloned_order->order_number = '';
  $cloned_order_wrapper = entity_metadata_wrapper('commerce_order', $cloned_order);
  $cloned_order_wrapper->save();
  stihl_orders_clone_order_fields($old_order_wrapper, $cloned_order_wrapper);
  stihl_orders_clone_order_line_items($old_order_wrapper, $cloned_order_wrapper);
  return $cloned_order_wrapper;
}

/**
 * Clones most of the fields from the old order to the new.
 *
 * Most of the fields from the source order will need to be copied to the new
 * clone order. Some notable exceptions are `field_order_status`, as the status
 * of the new order should default to 'incomplete' upon creation,
 * `commerce_order_total` which should only be calculated when the new order has
 * been walked through the ordering steps, and `commerce_line_items` which gets
 * handled later by another set of functions. Additionally, we only want to copy
 * actual data, as copying NULL values to the cloned order will just fill the DB
 * with useless NULL records associated with the cloned order.
 *
 * @param \EntityMetadataWrapper $old_order
 *   The wrapper object for the existing order.
 * @param \EntityMetadataWrapper $new_order
 *   The wrapper object for the new order.
 */
function stihl_orders_clone_order_fields(EntityMetadataWrapper $old_order, EntityMetadataWrapper $new_order) {
  $fields = array_filter(array_keys(field_info_instances('commerce_order', 'commerce_order')), function ($field) {
    return !in_array($field, array(
      'field_order_status',
      'commerce_order_status',
      'commerce_line_items',
    ));
  });
  foreach ($fields as $field) {
    if ($old_order->$field->value() === NULL) {
      continue;
    }
    $old_field = $old_order->$field->value();
    $new_order->$field = ($field == 'field_order_title') ? "$old_field (clone)" : $old_field;
  }
  $new_order->save();
}

/**
 * Clones the line items for active products from the old order to the new.
 *
 * We only want to clone line items whose related products are currently active
 * at the time of cloning—-inactive items should be skipped.
 *
 * @param \EntityMetadataWrapper $old_order
 *   The wrapper object for the existing order.
 * @param \EntityMetadataWrapper $new_order
 *   The wrapper object for the new order.
 */
function stihl_orders_clone_order_line_items(EntityMetadataWrapper $old_order, EntityMetadataWrapper $new_order) {
  foreach ($old_order->commerce_line_items->value() as $existing_order_line_item) {
    $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $existing_order_line_item);
    $product_id = db_query('SELECT product_id FROM {commerce_product} WHERE sku = :line_item_label', array(':line_item_label' => $line_item_wrapper->line_item_label->value()))->fetchField();
    $product = commerce_product_load($product_id);
    if ($product->status == 1) {
      $new_order->commerce_line_items[] = stihl_orders_clone_order_clone_line_item($line_item_wrapper, $product, $new_order->getIdentifier());
    }
  }
  $new_order->save();
}

/**
 * Clones a given line item.
 *
 * If the line item from an order to be cloned is for a product that is
 * currently active, we need to create a new line item entity for it to be saved
 * to the cloned order. All data set in the source line item's fields should be
 * copied to the target line item.
 *
 * @param \EntityMetadataWrapper $existing_line_item
 *   A line item wrapper obejct from an existing order.
 * @param \stdClass $product
 *   A $product entity object.
 * @param int $order_id
 *   The ID of the new/cloned order to which the line items will be saved.
 *
 * @return \EntityMetadataWrapper
 *   A wrapper object for the newly created/cloned line item.
 */
function stihl_orders_clone_order_clone_line_item(EntityMetadataWrapper $existing_line_item, stdClass $product, $order_id) {
  $fields = array_keys(field_info_instances('commerce_line_item', 'product'));
  $new_line_item = stihl_orders_add_line_item($product, $order_id);
  $new_wrapper = entity_metadata_wrapper('commerce_line_item', $new_line_item);
  foreach ($fields as $field) {
    if ($existing_line_item->$field->value() === NULL) {
      continue;
    }
    $new_wrapper->$field = $existing_line_item->$field->value();
  }
  $new_wrapper->save();
  return $new_wrapper;
}
