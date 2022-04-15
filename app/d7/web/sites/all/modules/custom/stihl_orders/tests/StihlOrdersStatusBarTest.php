<?php

/**
 * @file
 * Contains the StihlOrdersStatusBarTest class.
 */

include_once drupal_get_path('module', 'stihl_orders') . '/inc/stihl_orders.status_bar.inc';

/**
 * Class StihlOrdersStatusBarTest.
 */
class StihlOrdersStatusBarTest extends StihlOrdersTestBase {

  /**
   * An array of order IDs that need to be cleaned at the end of testing.
   *
   * @var array
   */
  protected static $cleanUpIds = array();

  /**
   * The test order EntityMetadataWrapper we are using for our test.
   *
   * @var object
   */
  protected static $testOrder;

  /**
   * Build out a test order object for use in our tests.
   */
  public static function setUpBeforeClass() {
    $test_order = self::createTestOrder();
    $product_ids = array(3, 5, 7, 11);
    $test_order->commerce_line_items = self::createNewLineItems($test_order->getIdentifier(), $product_ids);
    $test_order->save();
    self::$cleanUpIds[] = $test_order->getIdentifier();
    self::$testOrder = $test_order;
  }

  /**
   * Clean up after ourselves by deleting test orders.
   */
  public static function tearDownAfterClass() {
    commerce_order_delete_multiple(self::$cleanUpIds);
  }

  /**
   * Ensure the status bar data is consistent.
   *
   * @group stihl_orders
   */
  public function testStatusData() {
    $status_bar_data = StihlOrdersStatusBar::$statusData;

    // Make sure the step keys are right.
    $expected = array('order', 'tags', 'qty', 'subt', 'conf');
    $actual = array_keys($status_bar_data);
    $this->assertEquals($expected, $actual);

    // Ensure the 'step' value matches the key name for each step.
    foreach ($status_bar_data as $step => $data) {
      $this->assertEquals($step, $data['step']);
    }
  }

  /**
   * Test various aspects of the built Status Bar array.
   *
   * On step 4, steps 1, 2, & 3 should be linked, but 4 & 5 should not.
   *
   * @group stihl_orders
   */
  public function testBuildLinks() {
    $order_id = self::$testOrder->getIdentifier();
    $_GET['q'] = 'orders/submit/' . $order_id;
    $status_bar = StihlOrdersStatusBar::build($order_id);
    foreach ($status_bar as $step => $data) {
      if (in_array($step, array('subt', 'conf'))) {
        $this->assertNull($data['#prefix']);
        $this->assertNull($data['#suffix']);
      }
    }
  }

  /**
   * Test whether any links show on submitted orders.
   *
   * @group stihl_orders
   */
  public function testBuildNoLinksOnSubmitted() {
    $test_order = &self::$testOrder;
    $order_id = $test_order->getIdentifier();

    // Set the URL to step 4 just so its a factor.
    $_GET['q'] = 'orders/submit/' . $order_id;

    // Set the workflow state of the order to 'Submitted'.
    $order_status_workflow_states = workflow_get_workflow_state_names('order_status');
    $new_sid = array_search('submitted', $order_status_workflow_states);
    $test_order->field_order_status = $new_sid;
    $test_order->save();

    // Build the status bar and verify that none of the steps are linked.
    $status_bar = StihlOrdersStatusBar::build($order_id);
    foreach ($status_bar as $step => $data) {
      if (in_array($step, array('order', 'tags', 'qty', 'subt', 'conf'))) {
        $this->assertNull($data['#prefix']);
        $this->assertNull($data['#suffix']);
      }
    }
  }

}
