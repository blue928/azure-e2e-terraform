<?php

/**
 * @file
 * Contains the StihlOrdersEmailSummary class.
 */

/**
 * Class StihlOrdersEmailSummary().
 */
class StihlOrdersEmailSummary {

  /**
   * The wrapper for the order that needs summarized.
   *
   * @var \EntityMetadataWrapper
   */
  protected $orderWrapper;

  /**
   * The total number of Kit #1 for this order.
   *
   * @var int
   */
  protected $kit1Qty;

  /**
   * The total number of Kit #2 for this order.
   *
   * @var int
   */
  protected $kit2Qty;

  /**
   * The total styles & quantities that make up Kit 1.
   *
   * @var array
   */
  protected $kitOne = array();

  /**
   * The total styles & quantities that make up Kit 2.
   *
   * @var array
   */
  protected $kitTwo = array();

  /**
   * The total Bulk styles & quantities.
   *
   * @var array
   */
  protected $bulk = array();

  /**
   * {@inheritdoc}
   */
  public function __construct(EntityMetadataWrapper $order_wrapper) {
    $this->orderWrapper = $order_wrapper;
    $this->kit1Qty = $order_wrapper->field_order_kit_1_qty->value() ?: 0;
    $this->kit2Qty = $order_wrapper->field_order_kit_2_qty->value() ?: 0;

    // Give the sign types a starting quantity.
    $sign_types = array(
      'vertical_one_sided' => 0,
      'vertical_two_sided' => 0,
      'horizontal' => 0,
    );
    $this->kitOne = $sign_types;
    $this->kitTwo = $sign_types;
    $this->bulk = $sign_types;

    // Run through the line items and add up the sign_types for each group.
    $this->parseLineItems();
  }

  /**
   * Runs through the Order's line items and adds quantities to kits & bulk.
   */
  protected function parseLineItems() {
    foreach ($this->orderWrapper->commerce_line_items as $liw) {
      $line_item_sign_style = strtolower($liw->field_sign_style->value());
      $this->kitOne[$line_item_sign_style] += $liw->field_kit_1_qty->value();
      $this->kitTwo[$line_item_sign_style] += $liw->field_kit_2_qty->value();
      $this->bulk[$line_item_sign_style] += $liw->field_order_bulk->value();
    }
  }

  /**
   * Returns the total number of signs for a group.
   *
   * @param string $group
   *   Group options: 'kitOne', 'kitTwo', 'bulk'.
   *
   * @return int
   *   The total number of signs from for a group.
   */
  protected function getGroupTotal($group) {
    $group_total = array_reduce($this->$group, function ($carry, $style) {
      $carry += $style;
      return $carry;
    });
    return $group_total ?: 0;
  }

  /**
   * Returns the total number of signs for all styles in all groups.
   *
   * @return int
   *   The total number of signs for all styles in all groups.
   */
  public function getGrandTotal() {
    $kit_one_total = $this->kit1Qty * $this->getGroupTotal('kitOne');
    $kit_two_total = $this->kit2Qty * $this->getGroupTotal('kitTwo');
    $bulk_total = $this->getGroupTotal('bulk');
    return $kit_one_total + $kit_two_total + $bulk_total;
  }

  /**
   * Creates the summary email's summary.
   */
  public function getSummaryText() {
    // Get Kit 1 total quantity and sub-group quantities.
    $output = 'Kit 1, number of kits ordered: ' . $this->kit1Qty . "\r\n";
    $output .= "made up of the following:\r\n";
    $output .= "Vertical, 1-sided tags: " . $this->kitOne['vertical_one_sided'] . "\r\n";
    $output .= "Vertical, 2-sided tags: " . $this->kitOne['vertical_two_sided'] . "\r\n";
    $output .= "Horizontal, 1-sided tags: " . $this->kitOne['horizontal'] . "\r\n\r\n";

    // Get Kit 2 total quantity and sub-group quantities.
    $output .= 'Kit 2, number of kits ordered: ' . $this->kit2Qty . "\r\n";
    $output .= "made up of the following:\r\n";
    $output .= 'Vertical, 1-sided tags: ' . $this->kitTwo['vertical_one_sided'] . "\r\n";
    $output .= 'Vertical, 2-sided tags: ' . $this->kitTwo['vertical_two_sided'] . "\r\n";
    $output .= 'Horizontal, 1-sided tags: ' . $this->kitTwo['horizontal'] . "\r\n\r\n";

    // Get Bulk sub-group quantities.
    $output .= 'Bulk total: ' . $this->getGroupTotal('bulk') . "\r\n";
    $output .= "made up of the following:\r\n";
    $output .= 'Vertical, 1-sided tags: ' . $this->bulk['vertical_one_sided'] . "\r\n";
    $output .= 'Vertical, 2-sided tags: ' . $this->bulk['vertical_two_sided'] . "\r\n";
    $output .= 'Horizontal, 1-sided tags: ' . $this->bulk['horizontal'] . "\r\n\r\n";

    // Get the grand total for all sign types in all groups.
    $output .= 'GRAND TOTAL OF HANG TAGS FOR THIS ORDER: ' . $this->getGrandTotal();

    return $output;
  }

}
