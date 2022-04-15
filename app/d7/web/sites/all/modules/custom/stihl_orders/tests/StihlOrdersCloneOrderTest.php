<?php

/**
 * @file
 * Contains the StihlOrdersCloneOrderTest class.
 */

$base_path = drupal_get_path('module', 'stihl_orders');
include_once "$base_path/tests/StihlOrdersTestBase.php";
include_once "$base_path/inc/stihl_orders.clone_order.inc";


/**
 * StihlOrdersCloneOrderTest class.
 */
class StihlOrdersCloneOrderTest extends StihlOrdersTestBase {

  protected static $testOrder;

  protected static $cleanUpIds = array();

  protected static $testProduct;

  protected static $testProductStatus;

  /**
   * {@inheritdoc}
   */
  public static function setUpBeforeClass() {
    $test_order = self::createTestOrder();
    $products = array(3, 5, 7, 11);
    $test_order->commerce_line_items = self::createNewLineItems($test_order->getIdentifier(), $products);
    $test_order->save();
    self::$cleanUpIds[] = $test_order->getIdentifier();
    self::$testOrder = $test_order;

    $test_product = commerce_product_load(3);
    self::$testProductStatus = $test_product->status;
    $test_product->status = 1;
    commerce_product_save($test_product);
    self::$testProduct = $test_product;
  }

  /**
   * {@inheritdoc}
   */
  public static function tearDownAfterClass() {
    commerce_order_delete_multiple(self::$cleanUpIds);
    self::$testProduct->status = self::$testProductStatus;
    commerce_product_save(self::$testProduct);
  }

  /**
   * Tests stihl_orders_clone_order_fields().
   *
   * @group stihl_orders
   */
  public function testStihlOrdersCloneOrderFields() {
    $test_order = self::$testOrder;
    $cloned_order = $this->createTestOrder();
    self::$cleanUpIds[] = $cloned_order->getIdentifier();
    stihl_orders_clone_order_fields($test_order, $cloned_order);
    $this->assertEquals('New Test Order (clone)', $cloned_order->field_order_title->value());
  }

  /**
   * Tests stihl_orders_clone_orders_line_items().
   *
   * @group stihl_orders
   */
  public function testStihlOrdersCloneOrdersLineItems() {
    $test_order = self::$testOrder;
    $cloned_order = $this->createTestOrder();
    self::$cleanUpIds[] = $cloned_order->getIdentifier();
    stihl_orders_clone_order_line_items($test_order, $cloned_order);
    $this->assertEquals($this->getLineItemTitles($test_order), $this->getLineItemTitles($cloned_order));
  }

  /**
   * Tests stihl_orders_clone_orders_clone_line_item().
   *
   * @group stihl_orders
   */
  public function testStihlOrdersCloneOrdersCloneLineItem() {
    $test_order = self::$testOrder;
    $cloned_order = $this->createTestOrder();
    self::$cleanUpIds[] = $cloned_order->getIdentifier();
    $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $test_order->commerce_line_items[0]->value());
    $cloned_order->commerce_line_items[] = stihl_orders_clone_order_clone_line_item($line_item_wrapper, self::$testProduct, $cloned_order->getIdentifier());
    $expected = $test_order->commerce_line_items[0];
    $actual = $cloned_order->commerce_line_items[0];
    $this->assertEquals($expected->line_item_label->value(), $actual->line_item_label->value(), 'The title in the cloned line item does not match the original.');
    $this->assertNotEquals($expected->getIdentifier(), $actual->getIdentifier(), 'The cloned order is using the same line item as the original.');
  }

  /**
   * Tests stihl_orders_clone_order().
   *
   * @group stihl_orders
   */
  public function testStihlOrdersCloneOrder() {
    $test_order = self::$testOrder;
    $expected = $this->getLineItemTitles($test_order);
    $cloned_order = stihl_orders_clone_order($test_order);
    self::$cleanUpIds[] = $cloned_order->getIdentifier();
    $actual = $this->getLineItemTitles($cloned_order);
    $this->assertEquals($expected, $actual, 'The titles in the cloned test order to not match the original test order.');
    $this->assertNotEquals($test_order->commerce_line_items[0]->getIdentifier(), $cloned_order->commerce_line_items[0]->getIdentifier(), 'The line items in the cloned order are the same entities as the original test order.');
  }

  /**
   * Tests stihl_orders_clone_orders_line_items()'s skipping ability.
   *
   * When an order is cloned, if one of the related products on the source order
   * is marked inactive, it should be skipped when cloning line items to the
   * cloned order.
   *
   * @group stihl_orders
   */
  public function testStihlOrdersCloneOrdersSkipLineItems() {
    $test_order = self::$testOrder;
    $product_id = $this->getProductIdBySku($test_order->commerce_line_items[0]->line_item_label->value());
    $this->assertEquals(3, $product_id);
    $this->assertCount(4, $test_order->commerce_line_items, 'There was an incorrect number of line items on the source order.');
    // Set the status of our test product to inactive.
    self::$testProduct->status = 0;
    commerce_product_save(self::$testProduct);
    // Confirm that the test product gets skipped when the order is cloned.
    $cloned_order = stihl_orders_clone_order($test_order);
    $product_id = $this->getProductIdBySku($cloned_order->commerce_line_items[0]->line_item_label->value());
    $this->assertNotEquals(3, $product_id);
    $this->assertCount(3, $cloned_order->commerce_line_items, 'There were an incorrect number of line items on the cloned order.');
  }

  /**
   * Return a product id based on the product's sku.
   *
   * @param string $sku
   *   The sku for a given product.
   *
   * @return mixed
   *   The id for the product.
   */
  public function getProductIdBySku($sku) {
    return db_query('SELECT product_id FROM {commerce_product} WHERE sku = :sku', array(':sku' => $sku))->fetchField();
  }

}
