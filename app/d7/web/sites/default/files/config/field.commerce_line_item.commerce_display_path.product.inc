<?php
/**
 * @file
 * field.commerce_line_item.commerce_display_path.product.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'translatable' => '0',
    'settings' => array(
      'max_length' => 255,
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_commerce_display_path' => array(
              'value' => 'commerce_display_path_value',
              'format' => 'commerce_display_path_format',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_commerce_display_path' => array(
              'value' => 'commerce_display_path_value',
              'format' => 'commerce_display_path_format',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'format' => array(
        'table' => 'filter_format',
        'columns' => array(
          'format' => 'format',
        ),
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'field_name' => 'commerce_display_path',
    'type' => 'text',
    'module' => 'text',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'format' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Display path',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'type' => 'text_textfield',
      'weight' => 0,
      'settings' => array(
        'size' => 60,
      ),
      'module' => 'text',
    ),
    'display' => array(
      'display' => array(
        'label' => 'hidden',
        'weight' => 0,
        'type' => 'text_default',
        'settings' => array(),
        'module' => 'text',
      ),
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
        'module' => 'text',
        'weight' => 3,
      ),
    ),
    'description' => '',
    'field_name' => 'commerce_display_path',
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
  1 => 'text',
);
