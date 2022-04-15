<?php

/**
 * @file
 * Include file for functionality around configuring pricing on an order.
 */

/**
 * Custom page handler to render tableselect for adding new hangtags.
 *
 * @param int $order_id
 *   Order ID.
 *
 * @return int
 *   Order ID.
 */
function _stihl_orders_add_hangtags_to_order_form($order_id) {
  return $order_id;
}

/**
 * Delivery callback that received data from custom page callback.
 *
 * Receives data from _stihl_orders_add_hangtags_to_order_form() and renders it.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_add_hangtags_to_order_form_delivery_callback($order_id) {
  $query = db_select('commerce_product', 'p');
  $query->join('field_data_commerce_price', 'c', 'p.product_id = c.entity_id');
  $query
    ->fields('p', array('product_id', 'sku', 'title'))
    ->fields('c', array('commerce_price_amount'))
    ->range(0, 15);

  $result = $query->execute();

  $header = array('SKU', 'Description', 'Price');
  $rows = array();

  while ($record = $result->fetchAssoc()) {
    $product_info = array(
      $record['sku'],
      $record['title'],
      $record['commerce_price_amount'],
    );
    $rows[$record['product_id']] = $product_info;
  }

  print theme('table', array('header' => $header, 'rows' => $rows));
}
