<?php
/**
 * @file
 * field.commerce_order.field_order_contains_kits.commerce_order.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(),
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'settings' => array(
      'allowed_values' => array(
        'Yes' => 'Yes',
        'No' => 'No',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => '0',
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_order_contains_kits' => array(
              'value' => 'field_order_contains_kits_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_order_contains_kits' => array(
              'value' => 'field_order_contains_kits_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'field_name' => 'field_order_contains_kits',
    'type' => 'list_text',
    'module' => 'list',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => -3,
      ),
    ),
    'label' => 'Order Contains Kits',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
    'field_name' => 'field_order_contains_kits',
    'entity_type' => 'commerce_order',
    'bundle' => 'commerce_order',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'list',
  2 => 'options',
);
