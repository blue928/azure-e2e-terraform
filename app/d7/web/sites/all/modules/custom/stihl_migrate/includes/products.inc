<?php

/**
 * @file
 * Contains product migrations for Stihl.
 */

/**
 * Class StihlMigrateProducts.
 */
class StihlMigrateProducts extends StihlMigrateBase {

  private $csvcolumns;

  /**
   * The current active products as an array [product_id, sku].
   *
   * @var array
   */
  protected $activeProducts = [];

  /**
   * The list of product SKUs in the CSV for the current migration.
   *
   * @var array
   */
  protected $migratedSkus = [];

  /**
   * Array of products not in the CSV that should be disabled [product_id, sku].
   *
   * @var array
   */
  protected $productsToDisable = [];

  /**
   * Determine if stihl_orders module is enabled.
   *
   * @var bool
   */
  protected $stihlOrdersEnabled;

  /**
   * Line-items to be removed from current incomplete orders.
   *
   * @var array
   */
  protected $ordersLineItems = [];

  /**
   * StihlMigrateProducts constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Product data import.');

    // Only take a subset of columns from the csv file.
    $this->csvcolumns = array(
      1 => array('rlc_sku_code', t('RLC SKU Code')),
      2 => array('product_category_priority', t('Field Product category priority')),
      3 => array('horizontal_hangtag', t('Horizontal hangtag')),
      4 => array('chainsaw', t('Chainsaw')),
      5 => array('special_pricing_language', t('Special pricing language')),
      6 => array('new', t('New')),
      7 => array('custom_tags', t('Custom tags')),
      8 => array('model', t('Model')),
      9 => array('top_level_category', t('Top level category')),
      10 => array('product_category', t('Product category')),
      11 => array('product_usage_scale', t('Product usage scale')),
      12 => array('pro_usage_disclaimer', t('Pro product usage disclaimer')),
      13 => array('model_subhead', t('Model subhead')),
      14 => array('subhead_partnumber', t('Subhead partnumber')),
      19 => array('main_length', t('Main length')),
      54 => array('part_number', t('Part number')),
      55 => array('upc_code', t('UPC code')),
      56 => array('upc_heading', t('UPC heading')),
    );

    $this->source = new MigrateSourceCSV(
      STIHL_MIGRATE_PRODUCT_IMPORT_PATH . '/stihl_products.csv',
      $this->csvcolumns,
      array('header_rows' => 1, 'track_changes' => 1)
    );

    // Destination class from Commerce Migrate contrib module.
    $this->destination = new MigrateDestinationCommerceProduct('commerce_product', 'product');

    // Source and destination relation for rollbacks.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'rlc_sku_code' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'RLC SKU code',
        ),
      ),
      MigrateDestinationCommerceProduct::getKeySchema('commerce_product')
    );

    // Field mappings: destination, source.
    $this->addFieldMapping('sku', 'rlc_sku_code');
    $this->addFieldMapping('field_product_category_priority', 'product_category_priority');
    $this->addFieldMapping('field_horizontal_hangtag', 'horizontal_hangtag');
    $this->addFieldMapping('field_chainsaw', 'chainsaw');
    $this->addFieldMapping('field_special_pricing_language', 'special_pricing_language');
    $this->addFieldMapping('field_new', 'new');
    $this->addFieldMapping('field_custom_tags', 'custom_tags');
    $this->addFieldMapping('field_model', 'model');
    $this->addFieldMapping('field_product_usage_scale', 'product_usage_scale');
    $this->addFieldMapping('field_pro_usage_disclaimer', 'pro_usage_disclaimer');
    $this->addFieldMapping('field_model_subhead', 'model_subhead');
    $this->addFieldMapping('field_subhead_partnumber', 'subhead_partnumber');
    $this->addFieldMapping('field_main_length', 'main_length');
    $this->addFieldMapping('field_part_number', 'part_number');
    $this->addFieldMapping('field_upc_code', 'upc_code');
    $this->addFieldMapping('field_upc_heading', 'upc_heading');

    // Taxonomy product category references.
    $this->addFieldMapping('field_top_level_category', 'top_level_category');
    $this->addFieldMapping('field_product_category', 'product_category')
      ->sourceMigration(array('ChildTermsImport', 'ParentTermsImport'));
    $this->addFieldMapping('field_product_category:source_type')
      ->defaultValue('tid');

    // Custom source created in prepareRow for title and commerce price.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('commerce_price', 'commerce_price');

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array(
      'language',
      'status',
      'created',
      'changed',
      'uid',
    ));
    $destination_fields = $this->destination->fields();
    if (isset($destination_fields['path'])) {
      $this->addFieldMapping('path')
        ->issueGroup(t('DNM'));
      if (isset($destination_fields['pathauto'])) {
        $this->addFieldMapping('pathauto')
          ->issueGroup(t('DNM'));
      }
    }

    $this->activeProducts = db_query('SELECT product_id,sku FROM {commerce_product} WHERE status = 1')->fetchAllKeyed();
    $this->stihlOrdersEnabled = module_exists('stihl_orders');
  }

  /**
   * Sets an array of products that should be disabled.
   */
  protected function setProductsToDisable() {
    return array_diff($this->activeProducts, $this->migratedSkus);
  }

  /**
   * Callback method to disable a single product.
   *
   * @param string $sku
   *   The product SKU.
   * @param int $id
   *   The product ID.
   */
  protected function disableProduct($sku, $id) {

    $product = commerce_product_load($id);
    $product->status = 0;
    commerce_product_save($product);

    $this->productsDisabled[] = $sku;
  }

  /**
   * Method to disable products not contained in the current migration.
   */
  protected function disableProducts() {

    if (empty($this->productsToDisable) || empty($this->migratedSkus)) {
      watchdog('stihl_migrate', 'No products were disabled for this migration');
      return;
    }

    array_walk($this->productsToDisable, [$this, 'disableProduct']);

    watchdog('stihl_migrate', 'SKU: @skus was unpublished via product migration', ['@skus' => implode(', ', $this->productsToDisable)]);
  }

  /**
   * Generate a title value.
   *
   * Combine source fields to create a product title.
   *
   * @param object $row
   *   The current row of the migration.
   *
   * @return string
   *   The custom product title.
   */
  protected function generateProductTitle($row) {
    return $row->main_length ? "{$row->model}-{$row->main_length}" : $row->model;
  }

  /**
   * Order status id (sid) for incomplete.
   *
   * @return int
   *   The id for incomplete order status Workflow state.
   */
  protected function incompleteOrderStatus() {
    return stihl_orders_get_states_by_workflow()['incomplete'];
  }

  /**
   * Query orders containing a given SKU that are in an incomplete status.
   *
   * @param string $sku
   *   The SKU of the product in the order.
   *
   * @return mixed
   *   A keyed array containing order_id and line_item_id.
   */
  protected function queryOrders($sku) {

    $sql = 'SELECT li.order_id,li.line_item_id FROM {commerce_line_item} li
      INNER JOIN {field_data_field_order_status} os ON li.order_id = os.entity_id
      WHERE li.line_item_label = :sku
      AND os.field_order_status_value = :incomplete';

    $query = db_query($sql, [':sku' => $sku, ':incomplete' => $this->incompleteOrderStatus()]);
    return $query->fetchAllKeyed();
  }

  /**
   * Iterate list of SKUs ($productsToDisable) and create an orders array.
   *
   * Inner loop combines line-items under single order_id array key.
   */
  protected function setOrdersLineItems() {

    $orders = [];

    foreach ($this->productsToDisable as $sku) {

      $orders_with_skus = $this->queryOrders($sku);

      // Combine line-items into a sub-array under order_id array key.
      foreach ($orders_with_skus as $order_id => $line_item_id) {
        $orders[$order_id][$line_item_id] = $sku;
      }
    }
    return $orders;
  }

  /**
   * Set the value for field_order_migrate_message on an order.
   *
   * @param array $skus
   *   An array of SKUs being removed from an existing order.
   *
   * @return string
   *   A string message containing the SKUs removed from an incomplete order.
   */
  protected function setOrderMessage(array $skus) {

    return format_plural(count($skus),
      'The following product SKU is no longer available and is removed from this order: ' . reset($skus) . '.',
      'The following product SKU(s) are no longer available and are removed from this order: ' . implode(', ', $skus) . '.'
    );
  }

  /**
   * Creates Watchdog migration summary message.
   *
   * Summary of migration data used for troubleshooting and debugging.
   */
  protected function setWatchdogSummaryMessage() {

    $summary_message = 'Product Migrate Summary:
      @sku_count migrated SKUs,
      @active_product_count active products,
      @products_disable_count products to disable,
      @order_count orders updated';

    $replacements = [
      '@sku_count' => count($this->migratedSkus),
      '@active_product_count' => count($this->activeProducts),
      '@products_disable_count' => count($this->productsToDisable),
      '@order_count' => count($this->ordersLineItems),
    ];

    watchdog('stihl_migrate', $summary_message, $replacements, WATCHDOG_INFO);
  }

  /**
   * Iterate order_id array and remove line-items.
   */
  protected function removeLineItems() {

    if (empty($this->productsToDisable) || empty($this->ordersLineItems)) {
      watchdog('stihl_migrate', 'No line-items were removed for this migration');
      return;
    }

    foreach ($this->ordersLineItems as $order_id => $line_item_array) {

      // This is used for creating user messages and Watchdog logs.
      $skus_removed = [];

      // Make sure sure the order actually exists.
      if (!($order = commerce_order_load($order_id))) {
        // Keep import summary accurate by removing the non-existent order.
        unset($this->ordersLineItems[$order_id]);
        watchdog('stihl_migrate', 'Unable to update order: @order_id', ['@order_id' => $order_id], WATCHDOG_WARNING);
        continue;
      }

      foreach ($line_item_array as $line_item_id => $sku) {

        commerce_entity_reference_delete($order, 'commerce_line_items', 'line_item_id', $line_item_id);
        commerce_line_item_delete($line_item_id);

        $skus_removed[] = $sku;
      }

      $order->field_order_migrate_message[LANGUAGE_NONE][0]['value'] = $this->setOrderMessage($skus_removed);
      watchdog('stihl_migrate', 'SKU: @skus was removed from order: @order_id',
        ['@skus' => implode(', ', $skus_removed), '@order_id' => $order_id]
      );

      commerce_order_save($order);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    // Set boolean fields based on Y or N in csv file.
    $row->new = $this->setBoolean($row->new);
    $row->chainsaw = $this->setBoolean($row->chainsaw);
    $row->horizontal_hangtag = $this->setBoolean($row->horizontal_hangtag);

    // Generate product title.
    $row->title = $this->generateProductTitle($row);

    // Commerce price is set to zero during import.
    $row->commerce_price = 0;

    // Products must be assigned a category.
    if ($row->product_category == '') {
      $this->queueMessage('Not imported: missing product category - ' . format_date(REQUEST_TIME, 'short'));
      watchdog('product_migrate', 'SKU: @sku (CSV row: @row) not imported because of missing product category.',
        array('@sku' => $row->rlc_sku_code, '@row' => $row->csvrownum), WATCHDOG_ERROR);
      return FALSE;
    }

    // Generate array of SKUs used to determine product status after migration.
    $this->migratedSkus[] = $row->rlc_sku_code;

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function postImport() {
    parent::postImport();

    // Products are disabled if not in the current migration's CSV file.
    if ($this->activeProducts) {
      $this->productsToDisable = $this->setProductsToDisable();
    }
    $this->disableProducts();

    if ($this->stihlOrdersEnabled) {
      // Line-items are removed from incomplete orders with the above products.
      if ($this->productsToDisable) {
        $this->ordersLineItems = $this->setOrdersLineItems();
      }
      $this->removeLineItems();

      $this->setWatchdogSummaryMessage();
    }
  }

}
