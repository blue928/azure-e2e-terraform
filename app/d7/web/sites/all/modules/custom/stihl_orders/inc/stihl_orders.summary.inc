<?php

/**
 * @file
 * Contains the StihlOrdersSummary class.
 */

/**
 * Class StihlOrdersSummary.
 *
 * Calculates the summary for an Order.
 */
class StihlOrdersSummary {

  /**
   * The prices for the various sign types at admin/config/stihl/orders.
   *
   * @var array
   */
  protected $prices = array();

  /**
   * The wrapper object for the order being summarized.
   *
   * @var \EntityMetadataWrapper
   */
  public $orderWrapper;

  /**
   * The number of #1 kits being ordered during Step 1.
   *
   * @var int
   */
  protected $orderKitQty1 = 0;

  /**
   * The number of #2 kits being ordered during Step 1.
   *
   * @var int
   */
  protected $orderKitQty2 = 0;

  /**
   * Total of all ordered kitted, one-sided hang tags.
   *
   * @var int
   *   All ordered kitted, one-sided hang tags.
   */
  protected $kittedOneSidedTotalQty = 0;

  /**
   * Total of all ordered bulk, one-sided hang tags.
   *
   * @var int
   *   All ordered bulk, one-sided hang tags.
   */
  protected $bulkOneSidedTotalQty = 0;

  /**
   * Total of all ordered kitted, two-sided hang tags.
   *
   * @var int
   *   All ordered kitted, two-sided hang tags.
   */
  protected $kittedTwoSidedTotalQty = 0;

  /**
   * Total of all ordered bulk, two-sided hang tags.
   *
   * @var int
   *   All ordered bulk, two-sided hang tags.
   */
  protected $bulkTwoSidedTotalQty = 0;

  /**
   * Total UPC Books downloaded.
   *
   * @var int
   */
  protected $upcBooksDownloaded = 0;

  /**
   * The user has the ability to download UPC Books.
   *
   * @var bool
   *   TRUE if the user can download UPC Books; FALSE otherwise.
   */
  protected $accessUpcBooks = FALSE;

  /**
   * StihlOrdersCalculate constructor.
   *
   * @param int $order_id
   *   The ID of the order we are summarizing.
   */
  public function __construct($order_id) {
    $this->orderWrapper = $this->setOrderWrapper($order_id);
    $this->pricingYear = $this->getPricingYear();
    $this->orderKitQty1 = (int) $this->orderWrapper->field_order_kit_1_qty->value();
    $this->orderKitQty2 = (int) $this->orderWrapper->field_order_kit_2_qty->value();
    $this->accessUpcBooks = stihl_orders_order_access('download upc books');
    $this->upcBooksDownloaded = (int) $this->orderWrapper->field_upc_downloads->value() ?: 0;
    $this->prices = $this->setPrices();
    $this->setSubTotals();
  }

  /**
   * Checks the validity of an order and returns an order wrapper if valid.
   *
   * @param int $order_id
   *   The ID of the order we are summarizing.
   *
   * @return \EntityMetadataWrapper
   *   The wrapped order entity.
   */
  protected function setOrderWrapper($order_id) {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order_id);
    try {
      $order_number = $order_wrapper->order_number->value();
      if ($order_number) {
        return $order_wrapper;
      }
    }
    catch (Exception $e) {
      drupal_set_message(t('The order number @order_number is not valid .', array('@order_number' => $order_id)));
      watchdog('commerce_order', $e->getMessage(), array(), WATCHDOG_ERROR);
    }
  }

  /**
   * Returns the Pricing Year entity for an order.
   *
   * @return \StihlPricingYearEntity
   *   The Pricing Year entity.
   */
  protected function getPricingYear() {
    return $this->orderWrapper->field_pricing_year_reference->value();
  }

  /**
   * Returns an array containing the prices stored in config.
   *
   * @return array
   *   An array containing the prices stored in config.
   */
  protected function setPrices() {
    return array(
      'bulk' => array(
        'one_sided' => (float) $this->pricingYear->bulk_one_sided,
        'two_sided' => (float) $this->pricingYear->bulk_two_sided,
      ),
      'kitted' => array(
        'one_sided' => (float) $this->pricingYear->kitted_one_sided,
        'two_sided' => (float) $this->pricingYear->kitted_two_sided,
      ),
    );
  }

  /**
   * Parses the line items and generates quantity sub totals.
   */
  protected function setSubTotals() {
    foreach ($this->orderWrapper->commerce_line_items as $liw) {
      $sign_style = $liw->field_sign_style->value();
      $kit_1_qty = $liw->field_kit_1_qty->value() * $this->orderKitQty1;
      $kit_2_qty = $liw->field_kit_2_qty->value() * $this->orderKitQty2;

      if ($sign_style == 'vertical_two_sided') {
        $this->kittedTwoSidedTotalQty += (integer) $kit_1_qty + $kit_2_qty;
        $this->bulkTwoSidedTotalQty += (integer) $liw->field_order_bulk->value();
      }
      else {
        $this->kittedOneSidedTotalQty += (integer) $kit_1_qty + $kit_2_qty;
        $this->bulkOneSidedTotalQty += (integer) $liw->field_order_bulk->value();
      }
    }
  }

  /**
   * Returns the total quantity for a given packaging & sided group of tags.
   *
   * @param string $sides
   *   How many sides a line item has. Can be either 'one' or 'two'.
   * @param string $packaging
   *   Packaging configuration s for a line item. Can be 'bulk' or 'kitted'.
   *
   * @return int
   *   The total number of signs for a given configuration.
   */
  public function getTotalQty($sides = 'one', $packaging = 'bulk') {
    $var = $packaging . ucwords($sides) . 'SidedTotalQty';
    return $this->$var;
  }

  /**
   * Returns the total price for a given line item configuration.
   *
   * @param string $sides
   *   How many sides a line item has. Can be either 'one' or 'two'.
   * @param string $packaging
   *   Packaging configuration s for a line item. Can be 'bulk' or 'kitted'.
   *
   * @return int
   *   The total price for the total quantity of a line item configuration.
   */
  public function getTotalPrice($sides = 'one', $packaging = 'bulk') {
    $var = $packaging . ucwords($sides) . 'SidedTotalQty';
    $total = $this->$var * $this->prices[$packaging][$sides . '_sided'];
    return $total;
  }

  /**
   * Returns the value of getTotalPrice(), formatted as currency.
   *
   * @param string $sides
   *   How many sides a line item has. Can be either 'one' or 'two'.
   * @param string $packaging
   *   Packaging configuration s for a line item. Can be 'bulk' or 'kitted'.
   *
   * @return string
   *   The total price for the line item, formatted as currency.
   */
  public function getTotalPriceFormatted($sides, $packaging) {
    $total = $this->getTotalPrice($sides, $packaging);
    return '$' . number_format($total, 2);
  }

  /**
   * Determines total cost of UPC Books.
   *
   * @return int
   *   Total price of the UPC Book downloads.
   */
  protected function getTotalUpcPrice() {
    $price = (float) $this->pricingYear->upc_book;
    return $price * $this->upcBooksDownloaded;
  }

  /**
   * Returns the total price for all ordered hang tags.
   *
   * @return int
   *   The total price for all ordered hang tags.
   */
  public function getGrandTotal() {
    $one_sided_total = $this->getTotalPrice('one', 'bulk') + $this->getTotalPrice('one', 'kitted');
    $two_sided_total = $this->getTotalPrice('two', 'bulk') + $this->getTotalPrice('two', 'kitted');
    $total = $one_sided_total + $two_sided_total;
    if ($this->accessUpcBooks) {
      $total += $this->getTotalUpcPrice();
    }
    return '$' . number_format($total, 2);
  }

  /**
   * Builds the line item for UPC Downloads.
   *
   * @return array
   *   An array containing the "Item Description," "Quantity," and "Cost" if the
   *   user has access to download UPC Books.
   *   Otherwise, returns NULL.
   */
  protected function getUpcLineItem() {
    if ($this->accessUpcBooks && stihl_orders_track_download() == FALSE) {
      return array(
        'UPC Book Downloads',
        $this->upcBooksDownloaded,
        '$' . number_format($this->getTotalUpcPrice(), 2),
      );
    }
    return NULL;
  }

  /**
   * Builds the link to the hangtag proofs for this order.
   *
   * @return mixed
   *   Full file url if the file exists, translated string if the order is in an
   *   "approved" state, and FALSE otherwise.
   */
  protected function getProofs() {
    if ($this->orderWrapper->field_upc_only->value() != 'Yes') {
      $order_state = $this->orderWrapper->field_order_status->value();
      $states = stihl_orders_get_states_by_workflow();
      if ($order_state == $states['approved']) {
        return t('<i>Proofs already approved.</i>');
      }
      return stihl_orders_proof_download_link($this->orderWrapper->getIdentifier());
    }
    return FALSE;
  }

  /**
   * Get the BD ID for this order.
   */
  protected function getBdId() {
    return db_query('SELECT field_bd_reference_target_id FROM {field_data_field_bd_reference} WHERE entity_id = :uid',
      array(':uid' => $this->orderWrapper->uid->value()))->fetchField();
  }

  /**
   * Get the minimum order amount message for a BD.
   */
  protected function getMinimumOrderMessage() {
    $message = variable_get('stihl_orders_minimum_order_message_default');

    // Pacific Island BD (ID 22) has a specific minimum order message.
    if ($this->getBdId() == '22') {
      $message = variable_get('stihl_orders_minimum_order_message_pacific_island');
    }
    return $message;
  }

  /**
   * Returns the rendered summary table as a render array.
   *
   * @return array
   *   The rendered summary table.
   */
  public function render() {
    $headers = array('Item Description', 'Quantity', 'Cost');
    $rows = array(
      array(
        'One-sided Bulk Tags',
        $this->getTotalQty('one', 'bulk'),
        $this->getTotalPriceFormatted('one', 'bulk'),
      ),
      array(
        'One-sided Kitted Tags',
        $this->getTotalQty('one', 'kitted'),
        $this->getTotalPriceFormatted('one', 'kitted'),
      ),
      array(
        'Two-sided Bulk Tags',
        $this->getTotalQty('two', 'bulk'),
        $this->getTotalPriceFormatted('two', 'bulk'),
      ),
      array(
        'Two-sided Kitted Tags',
        $this->getTotalQty('two', 'kitted'),
        $this->getTotalPriceFormatted('two', 'kitted'),
      ),
      $this->getUpcLineItem(),
      array(
        '<strong>Grand Total</strong>*',
        '',
        '<strong>' . $this->getGrandTotal() . '</strong>',
      ),
    );

    $render['#order_id'] = $this->orderWrapper->getIdentifier();

    $render['summary'] = array(
      '#markup' => theme('table', array('header' => $headers, 'rows' => $rows)),
    );

    $render['message_disclaimer'] = array(
      '#prefix' => '<div class="message-disclaimer clearfix">',
      '#suffix' => '</div>',
    );
    $render['message_disclaimer']['minimum_order_message'] = array(
      '#prefix' => '<div class="minimum-order-message pull-right">',
      '#markup' => $this->getMinimumOrderMessage(),
      '#suffix' => '</div>',
    );
    $render['message_disclaimer']['shipping_disclaimer'] = array(
      '#prefix' => '<div class="shipping-disclaimer">',
      '#markup' => t('* Cost does not include shipping and freight'),
      '#suffix' => '</div>',
    );

    if ($this->orderWrapper->field_order_notes->value()) {
      $render['order_note'] = array(
        '#type' => 'markup',
        '#prefix' => '<div class="well well-sm">Order Note: ',
        '#suffix' => '</div>',
        '#markup' => $this->orderWrapper->field_order_notes->value(),
      );
    }

    $render['download_link'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="well well-sm">Download Order CSV: ',
      '#suffix' => '</div>',
      '#markup' => stihl_orders_approval_csv_download_link($this->orderWrapper->getIdentifier()),
    );

    // Append the link to download proofs if it exists.
    if ($proof_link = $this->getProofs()) {
      $render['download_link']['#markup'] .= t('<br/>Download Online Proofs:&nbsp;') . $proof_link;
    }

    if ($this->accessUpcBooks) {
      $render['download_upc_books'] = array(
        '#type' => 'markup',
        '#prefix' => '<div class="well well-sm">Download UPC Books:<br/>',
        '#suffix' => '</div>',
        '#markup' => stihl_orders_upc_download_links($this->orderWrapper->getIdentifier()),
      );
    }

    return $render;
  }

}
