<?php

/**
 * @file
 * Contains base methods for testing Stihl Orders logic.
 */

/**
 * Class StihlOrdersTestBase.
 */
class StihlOrdersTestBase extends PHPUnit_Framework_TestCase {

  /**
   * Creates a test order.
   *
   * @return object
   *   Returns a test orders as an EntityMetadataWrapper object.
   */
  protected static function createTestOrder() {
    $order = new stdClass();
    $order->type = 'commerce_order';
    $order->status = 'test';
    $order->mail = 'test-delete@example.com';
    $order->order_number = '';
    $wrapper = entity_metadata_wrapper('commerce_order', $order);
    $wrapper->field_order_title = 'New Test Order';
    $wrapper->save();
    return $wrapper;
  }

  /**
   * Creates new line items.
   *
   * @param int $order_id
   *   The order ID to which the line items should be associated.
   * @param array $product_ids
   *   The product ID off which the line items should be based.
   *
   * @return array
   *   An array of containing the IDs of the created line items.
   */
  protected static function createNewLineItems($order_id, array $product_ids = array()) {
    return array_map(function ($product_id) use ($order_id) {
      $product = commerce_product_load($product_id);
      return stihl_orders_add_line_item($product, $order_id);
    }, $product_ids);
  }

  /**
   * Returns the titles for the line items saved to an order.
   *
   * @param object $order
   *   An order entity_metadata_wrapper object.
   *
   * @return array
   *   An array containing the title of teh line items saved to an order.
   */
  protected function getLineItemTitles($order) {
    return array_map(function ($line_item) {
      return $line_item->line_item_label;
    }, $order->commerce_line_items->value());
  }

}
