<?php
/**
 * @file
 * field.commerce_line_item.field_sign_style.product.inc
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
        'Horizontal' => 'Horizontal',
        'Vertical' => 'Vertical',
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
            'field_data_field_sign_style' => array(
              'value' => 'field_sign_style_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_sign_style' => array(
              'value' => 'field_sign_style_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'field_name' => 'field_sign_style',
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
    'commerce_cart_settings' => array(
      'field_access' => 0,
    ),
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
    ),
    'label' => 'Sign Style',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
    'field_name' => 'field_sign_style',
    'entity_type' => 'commerce_line_item',
    'bundle' => 'product',
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
