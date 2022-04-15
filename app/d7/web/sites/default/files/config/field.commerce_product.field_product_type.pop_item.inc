<?php
/**
 * @file
 * field.commerce_product.field_product_type.pop_item.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'pop_item_category',
          'parent' => '0',
        ),
      ),
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_product_type' => array(
              'tid' => 'field_product_type_tid',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_product_type' => array(
              'tid' => 'field_product_type_tid',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'tid' => array(
        'table' => 'taxonomy_term_data',
        'columns' => array(
          'tid' => 'tid',
        ),
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'field_permissions' => array(
      'type' => '0',
    ),
    'field_name' => 'field_product_type',
    'type' => 'taxonomy_term_reference',
    'module' => 'taxonomy',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'tid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Product Type',
    'widget' => array(
      'type' => 'options_select',
      'weight' => '12',
      'settings' => array(),
      'module' => 'options',
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'taxonomy_term_reference_link',
        'weight' => '9',
        'settings' => array(),
        'module' => 'taxonomy',
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
    'required' => FALSE,
    'description' => '',
    'field_name' => 'field_product_type',
    'entity_type' => 'commerce_product',
    'bundle' => 'pop_item',
    'deleted' => '0',
    'default_value' => NULL,
  ),
);

$dependencies = array(
  'vocabulary.pop_item_category' => 'vocabulary.pop_item_category',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'taxonomy',
  2 => 'options',
);
