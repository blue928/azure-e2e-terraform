<?php
/**
 * @file
 * field.commerce_line_item.commerce_product.product.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'translatable' => '0',
    'settings' => array(
      'options_list_limit' => NULL,
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_commerce_product' => array(
              'product_id' => 'commerce_product_product_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_commerce_product' => array(
              'product_id' => 'commerce_product_product_id',
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
    'indexes' => array(
      'product_id' => array(
        0 => 'product_id',
      ),
    ),
    'field_name' => 'commerce_product',
    'type' => 'commerce_product_reference',
    'module' => 'commerce_product_reference',
    'active' => '1',
    'locked' => '1',
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
    'label' => 'Product',
    'required' => TRUE,
    'settings' => array(
      'referenceable_types' => array(),
      'field_injection' => TRUE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'type' => 'commerce_product_reference_autocomplete',
      'weight' => 0,
      'settings' => array(
        'autocomplete_match' => 'contains',
        'size' => 60,
        'autocomplete_path' => 'commerce_product/autocomplete',
      ),
      'module' => 'commerce_product_reference',
    ),
    'display' => array(
      'display' => array(
        'label' => 'hidden',
        'weight' => 0,
        'type' => 'commerce_cart_add_to_cart_form',
        'settings' => array(
          'show_quantity' => FALSE,
          'default_quantity' => 1,
          'combine' => TRUE,
          'show_single_product_attributes' => FALSE,
          'line_item_type' => 'product',
        ),
        'module' => 'commerce_cart',
      ),
      'default' => array(
        'label' => 'above',
        'type' => 'commerce_cart_add_to_cart_form',
        'settings' => array(
          'show_quantity' => FALSE,
          'default_quantity' => 1,
          'combine' => TRUE,
          'show_single_product_attributes' => FALSE,
          'line_item_type' => 'product',
        ),
        'module' => 'commerce_cart',
        'weight' => 2,
      ),
    ),
    'description' => '',
    'field_name' => 'commerce_product',
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
  1 => 'commerce_product_reference',
);
