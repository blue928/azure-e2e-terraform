<?php

/**
 * @file
 * Contains taxonomy migrations for Stihl.
 */

/**
 * Class StihlMigrateTermsBase.
 */
class StihlMigrateTermsBase extends Migration {

  protected $csvcolumns;

  /**
   * StihlMigrateTermsBase constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Product category taxonomy import.');

    // Only take a subset of columns from the csv file.
    $this->csvcolumns = array(
      9 => array('top_level_category', t('Top level category')),
      10 => array('product_category', t('Product category')),
    );

    $this->source = new MigrateSourceCSV(
      STIHL_MIGRATE_PRODUCT_IMPORT_PATH . '/stihl_products.csv',
      $this->csvcolumns,
      array('header_rows' => 1, 'track_changes' => 1)
    );

    // Source and destination relation for rollbacks.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'product_category' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Product category',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // Destination vocabulary: product_category.
    $this->destination = new MigrateDestinationTerm('product_category');

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array(
      'tid',
      'description',
      'parent',
      'format',
      'weight',
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

    // Categories cannot be empty.
    if ($row->top_level_category == '' || $row->product_category == '') {
      $this->queueMessage('CSV row: ' . $row->csvrownum . ' not imported because of missing category - ' . format_date(REQUEST_TIME, 'short'));
      watchdog('taxonomy_migrate', 'CSV row: @row not imported because of missing category.',
        array('@row' => $row->csvrownum), WATCHDOG_ERROR);
      return FALSE;
    }

  }
}

/**
 * Class StihlMigrateParentTerms.
 */
class StihlMigrateParentTerms extends StihlMigrateTermsBase {

  /**
   * StihlMigrateParentTerms constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Set the parent level terms into product_category vocabulary.
    $this->addFieldMapping('name', 'top_level_category');

  }

}

/**
 * Class StihlMigrateChildTerms.
 */
class StihlMigrateChildTerms extends StihlMigrateTermsBase {

  /**
   * StihlMigrateChildTerms constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Set the child terms based on the parent term.
    $this->addFieldMapping('name', 'product_category');
    $this->addFieldMapping('parent_name', 'top_level_category')
      ->defaultValue(0);
  }

}
