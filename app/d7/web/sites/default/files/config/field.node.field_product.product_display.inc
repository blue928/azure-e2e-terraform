<?php
/**
 * @file
 * field.node.field_product.product_display.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(),
    'field_permissions' => array(
      'type' => '0',
    ),
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'settings' => array(
      'options_list_limit' => '',
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
            'field_data_field_product' => array(
              'product_id' => 'field_product_product_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_product' => array(
              'product_id' => 'field_product_product_id',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'product_id' => array(
        'table' => 'commerce_product',
        'columns' => array(
          'product_id' => 'product_id',
        ),
      ),
    ),
    'field_name' => 'field_product',
    'type' => 'commerce_product_reference',
    'module' => 'commerce_product_reference',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'product_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'default_value' => NULL,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'label' => 'Product',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'pop_item' => 'pop_item',
        'product' => 'product',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'weight' => 32,
      'type' => 'options_select',
      'module' => 'options',
      'active' => 1,
      'settings' => array(),
    ),
    'field_name' => 'field_product',
    'entity_type' => 'node',
    'bundle' => 'product_display',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.product_display' => 'content_type.product_display',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'commerce_product_reference',
  2 => 'options',
);
