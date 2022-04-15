<?php

/**
 * @file
 * Contains pricing migrations for Stihl.
 */

/**
 * Class StihlMigratePricing.
 */
class StihlMigratePricing extends StihlMigrateBase {

  private $csvcolumns;

  /**
   * StihlMigratePricing constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import for product pricing data.');

    // Subset of columns from the csv file.
    $this->csvcolumns = array(
      0 => array('product_name', t('Product name')),
      7 => array('msrp', t('Product MSRP')),
      8 => array('current_year_price', t('Current year price')),
      9 => array('display_price', t('Display price')),
      10 => array('display_product', t('Display product')),
      11 => array('hangtag_code', t('RLC SKU hangtag code')),
      12 => array('next_year_price', t('Next year price')),
      13 => array('bd_reference', t('BD reference ID')),
    );

    $this->source = new MigrateSourceCSV(
      STIHL_MIGRATE_PRICING_IMPORT_PATH . '/stihl_pricing.csv',
      $this->csvcolumns,
      array('header_rows' => 1, 'track_changes' => 1)
    );

    // Destination class for custom entity.
    $this->destination = new MigrateDestinationEntityAPI('stihl_pricing', 'stihl_pricing');

    // Source and destination relationship.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'hangtag_code' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => t('RLC SKU hangtag code'),
        ),
        'bd_reference' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => t('BD Drupal id'),
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('stihl_pricing')
    );

    // Field mappings.
    $this->addSimpleMappings(array(
      'product_name',
      'msrp',
      'current_year_price',
      'display_price',
      'display_product',
      'hangtag_code',
      'next_year_price',
      'bd_reference',
    ));

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array(
      'id',
      'created',
      'changed',
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

  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    // If hangtag rlc sku data is missing, skip row and notify in watchdog.
    if (empty($row->hangtag_code)) {
      $message = 'Migration row: !row was not imported because of missing hangtag code';
      $replace = array('!row' => $row->csvrownum);
      watchdog('stihl_migrate', $message, $replace, WATCHDOG_ERROR);
      return FALSE;
    }

    // If bd_reference data is missing, skip row and notify in watchdog.
    if (empty($row->bd_reference)) {
      $message = 'Migration row: !row was not imported because of missing bd reference';
      $replace = array('!row' => $row->csvrownum);
      watchdog('stihl_migrate', $message, $replace, WATCHDOG_ERROR);
      return FALSE;
    }

    // Set boolean fields based on Y or N in csv file.
    $row->display_price = $this->setBoolean($row->display_price);
    $row->display_product = $this->setBoolean($row->display_product);

  }

}
