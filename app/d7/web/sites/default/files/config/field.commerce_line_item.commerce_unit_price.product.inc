<?php
/**
 * @file
 * field.commerce_line_item.commerce_unit_price.product.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'translatable' => '0',
    'settings' => array(),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_commerce_unit_price' => array(
              'amount' => 'commerce_unit_price_amount',
              'currency_code' => 'commerce_unit_price_currency_code',
              'data' => 'commerce_unit_price_data',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_commerce_unit_price' => array(
              'amount' => 'commerce_unit_price_amount',
              'currency_code' => 'commerce_unit_price_currency_code',
              'data' => 'commerce_unit_price_data',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'field_name' => 'commerce_unit_price',
    'type' => 'commerce_price',
    'module' => 'commerce_price',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '1',
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
    'label' => 'Unit price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'type' => 'commerce_price_full',
      'weight' => 0,
      'settings' => array(
        'currency_code' => 'default',
      ),
      'module' => 'commerce_price',
    ),
    'display' => array(
      'display' => array(
        'label' => 'hidden',
        'type' => 'commerce_price_formatted_amount',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'weight' => 0,
        'module' => 'commerce_price',
      ),
      'diff_standard' => array(
        'label' => 'hidden',
        'type' => 'commerce_price_formatted_amount',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'weight' => 0,
        'module' => 'commerce_price',
      ),
      'token' => array(
        'label' => 'hidden',
        'type' => 'commerce_price_formatted_amount',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'weight' => 0,
        'module' => 'commerce_price',
      ),
      'default' => array(
        'label' => 'hidden',
        'type' => 'commerce_price_formatted_amount',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'weight' => 0,
        'module' => 'commerce_price',
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'type' => 'commerce_price_formatted_amount',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'weight' => 0,
        'module' => 'commerce_price',
      ),
    ),
    'description' => '',
    'field_name' => 'commerce_unit_price',
    'entity_type' => 'commerce_line_item',
    'bundle' => 'product',
    'deleted' => '0',
    'default_value' => NULL,
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'commerce_price',
);
