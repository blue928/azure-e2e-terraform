<?php
/**
 * @file
 * field.commerce_product.field_price_table.pop_item.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_price_table' => array(
              'amount' => 'field_price_table_amount',
              'currency_code' => 'field_price_table_currency_code',
              'min_qty' => 'field_price_table_min_qty',
              'max_qty' => 'field_price_table_max_qty',
              'data' => 'field_price_table_data',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_price_table' => array(
              'amount' => 'field_price_table_amount',
              'currency_code' => 'field_price_table_currency_code',
              'min_qty' => 'field_price_table_min_qty',
              'max_qty' => 'field_price_table_max_qty',
              'data' => 'field_price_table_data',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'currency_price_table' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'field_permissions' => array(
      'type' => '0',
    ),
    'field_name' => 'field_price_table',
    'type' => 'commerce_price_table',
    'module' => 'commerce_price_table',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'amount' => array(
        'description' => 'The price amount.',
        'type' => 'int',
        'not null' => TRUE,
        'default' => 0,
      ),
      'currency_code' => array(
        'description' => 'The currency code for the price.',
        'type' => 'varchar',
        'length' => 32,
        'not null' => TRUE,
      ),
      'min_qty' => array(
        'description' => 'The minimal quantity for this amount.',
        'type' => 'int',
        'not null' => TRUE,
        'default' => 0,
      ),
      'max_qty' => array(
        'description' => 'The maximum quantity for this amount.',
        'type' => 'int',
        'not null' => TRUE,
        'default' => 0,
      ),
      'data' => array(
        'description' => 'A serialized array of additional price data.',
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
        'serialize' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Price Table',
    'widget' => array(
      'weight' => '7',
      'type' => 'commerce_price_table_multiple',
      'module' => 'commerce_price_table',
      'active' => 0,
      'settings' => array(
        'currency_code' => 'default',
      ),
    ),
    'settings' => array(
      'commerce_price_table' => array(
        'hide_default_price' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'commerce_multiprice_default',
        'weight' => '1',
        'settings' => array(
          'calculation' => FALSE,
          'price_label' => 'Price',
          'quantity_label' => 'Quantity',
          'table_orientation' => 'Orientation',
        ),
        'module' => 'commerce_price_table',
      ),
      'inline_entity_form' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
      'line_item' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
      'node_teaser' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
    ),
    'required' => 0,
    'description' => '',
    'default_value' => NULL,
    'field_name' => 'field_price_table',
    'entity_type' => 'commerce_product',
    'bundle' => 'pop_item',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'commerce_price_table',
);
