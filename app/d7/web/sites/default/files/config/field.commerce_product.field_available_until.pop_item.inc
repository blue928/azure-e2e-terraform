<?php
/**
 * @file
 * field.commerce_product.field_available_until.pop_item.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'granularity' => array(
        'month' => 'month',
        'day' => 'day',
        'hour' => 'hour',
        'year' => 'year',
        'minute' => 0,
        'second' => 0,
      ),
      'tz_handling' => 'site',
      'timezone_db' => 'UTC',
      'cache_enabled' => 0,
      'cache_count' => '4',
      'todate' => '',
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_available_until' => array(
              'value' => 'field_available_until_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_available_until' => array(
              'value' => 'field_available_until_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_permissions' => array(
      'type' => '0',
    ),
    'field_name' => 'field_available_until',
    'type' => 'datetime',
    'module' => 'date',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'datetime',
        'mysql_type' => 'datetime',
        'pgsql_type' => 'timestamp without time zone',
        'sqlite_type' => 'varchar',
        'sqlsrv_type' => 'smalldatetime',
        'not null' => FALSE,
        'sortable' => TRUE,
        'views' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Available until',
    'widget' => array(
      'weight' => '8',
      'type' => 'date_popup',
      'module' => 'date',
      'active' => 1,
      'settings' => array(
        'input_format' => 'm/d/Y - g:i:sa',
        'input_format_custom' => '',
        'year_range' => '-3:+3',
        'increment' => 1,
        'label_position' => 'above',
        'text_parts' => array(),
        'no_fieldset' => 0,
      ),
    ),
    'settings' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'date_default',
        'weight' => '5',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_number' => '',
          'multiple_from' => '',
          'multiple_to' => '',
          'show_remaining_days' => 1,
        ),
        'module' => 'date',
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
    'field_name' => 'field_available_until',
    'entity_type' => 'commerce_product',
    'bundle' => 'pop_item',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'date',
);
