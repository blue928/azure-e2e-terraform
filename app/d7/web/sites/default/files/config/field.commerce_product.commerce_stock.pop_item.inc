<?php
/**
 * @file
 * field.commerce_product.commerce_stock.pop_item.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'commerce_product',
    ),
    'translatable' => '0',
    'settings' => array(
      'precision' => 10,
      'scale' => 2,
      'decimal_separator' => '.',
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_commerce_stock' => array(
              'value' => 'commerce_stock_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_commerce_stock' => array(
              'value' => 'commerce_stock_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'commerce_stock',
    'type' => 'number_decimal',
    'module' => 'number',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'numeric',
        'precision' => 10,
        'scale' => 2,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Stock',
    'required' => TRUE,
    'settings' => array(
      'min' => '',
      'max' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'number_decimal',
        'settings' => array(
          'thousand_separator' => '',
          'decimal_separator' => '.',
          'scale' => 2,
          'prefix_suffix' => TRUE,
        ),
        'module' => 'number',
        'weight' => 11,
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
    'description' => NULL,
    'default_value' => array(
      0 => array(
        'value' => '0',
      ),
    ),
    'widget' => array(
      'type' => 'number',
      'settings' => array(),
      'weight' => 14,
      'module' => 'number',
    ),
    'field_name' => 'commerce_stock',
    'entity_type' => 'commerce_product',
    'bundle' => 'pop_item',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'number',
);
