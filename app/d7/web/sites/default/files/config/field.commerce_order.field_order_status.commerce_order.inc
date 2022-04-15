<?php
/**
 * @file
 * field.commerce_order.field_order_status.commerce_order.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'allowed_values_function' => 'workflowfield_allowed_values',
      'wid' => '7',
      'allowed_values_string' => '29 | (creation)
33 | incomplete
30 | submitted
31 | deleted
32 | approved',
      'widget' => array(
        'fieldset' => '0',
        'options' => 'select',
        'hide' => 0,
        'name_as_title' => 1,
        'schedule' => 1,
        'schedule_timezone' => 1,
        'comment' => '1',
      ),
      'watchdog_log' => 1,
      'history' => array(
        'history_tab_show' => 1,
        'roles' => array(
          3 => '3',
          -1 => 0,
          1 => 0,
          2 => 0,
          4 => 0,
          5 => 0,
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
            'field_data_field_order_status' => array(
              'value' => 'field_order_status_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_order_status' => array(
              'value' => 'field_order_status_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'field_permissions' => array(
      'type' => '0',
    ),
    'field_name' => 'field_order_status',
    'type' => 'workflow',
    'module' => 'workflowfield',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'description' => 'The {workflow_states}.sid that this node is currently in.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
        'disp-width' => '10',
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Order Status',
    'widget' => array(
      'weight' => '11',
      'type' => 'workflow_default',
      'module' => 'workflowfield',
      'active' => 1,
      'settings' => array(
        'name_as_title' => 1,
        'fieldset' => 0,
        'comment' => 1,
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'list_default',
        'settings' => array(),
        'module' => 'list',
        'weight' => 4,
      ),
    ),
    'required' => 1,
    'description' => '',
    'field_name' => 'field_order_status',
    'entity_type' => 'commerce_order',
    'bundle' => 'commerce_order',
    'deleted' => '0',
    'default_value' => NULL,
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'workflowfield',
);
