<?php
/**
 * @file
 * field.commerce_order.commerce_line_items.commerce_order.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'commerce_order',
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
            'field_data_commerce_line_items' => array(
              'line_item_id' => 'commerce_line_items_line_item_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_commerce_line_items' => array(
              'line_item_id' => 'commerce_line_items_line_item_id',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'line_item_id' => array(
        'table' => 'commerce_line_item',
        'columns' => array(
          'line_item_id' => 'line_item_id',
        ),
      ),
    ),
    'indexes' => array(
      'line_item_id' => array(
        0 => 'line_item_id',
      ),
    ),
    'field_name' => 'commerce_line_items',
    'type' => 'commerce_line_item_reference',
    'module' => 'commerce_line_item',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'line_item_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Line items',
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'type' => 'commerce_line_item_manager',
      'weight' => '-10',
      'settings' => array(),
      'module' => 'commerce_line_item',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'commerce_line_item_reference_view',
        'weight' => -10,
        'settings' => array(
          'view' => 'commerce_line_item_table|default',
        ),
        'module' => 'commerce_line_item',
      ),
      'customer' => array(
        'label' => 'hidden',
        'type' => 'commerce_line_item_reference_view',
        'weight' => -10,
        'settings' => array(
          'view' => 'commerce_line_item_table|default',
        ),
        'module' => 'commerce_line_item',
      ),
      'administrator' => array(
        'label' => 'hidden',
        'type' => 'commerce_line_item_reference_view',
        'weight' => -10,
        'settings' => array(
          'view' => 'commerce_line_item_table|default',
        ),
        'module' => 'commerce_line_item',
      ),
    ),
    'required' => FALSE,
    'description' => '',
    'field_name' => 'commerce_line_items',
    'entity_type' => 'commerce_order',
    'bundle' => 'commerce_order',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'commerce_line_item',
);
