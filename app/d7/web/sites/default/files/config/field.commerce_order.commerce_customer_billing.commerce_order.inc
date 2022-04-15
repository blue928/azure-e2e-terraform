<?php
/**
 * @file
 * field.commerce_order.commerce_customer_billing.commerce_order.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'translatable' => '0',
    'settings' => array(
      'profile_type' => 'billing',
      'options_list_limit' => 50,
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_commerce_customer_billing' => array(
              'profile_id' => 'commerce_customer_billing_profile_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_commerce_customer_billing' => array(
              'profile_id' => 'commerce_customer_billing_profile_id',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'profile_id' => array(
        'table' => 'commerce_customer_profile',
        'columns' => array(
          'profile_id' => 'profile_id',
        ),
      ),
    ),
    'indexes' => array(
      'profile_id' => array(
        0 => 'profile_id',
      ),
    ),
    'field_name' => 'commerce_customer_billing',
    'type' => 'commerce_customer_profile_reference',
    'module' => 'commerce_customer',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'profile_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Billing information',
    'widget' => array(
      'type' => 'commerce_customer_profile_manager',
      'weight' => '-5',
      'settings' => array(),
      'module' => 'commerce_customer',
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'commerce_customer_profile_reference_display',
        'weight' => -5,
        'settings' => array(),
        'module' => 'commerce_customer',
      ),
      'customer' => array(
        'label' => 'above',
        'type' => 'commerce_customer_profile_reference_display',
        'weight' => -5,
        'settings' => array(),
        'module' => 'commerce_customer',
      ),
      'administrator' => array(
        'label' => 'above',
        'type' => 'commerce_customer_profile_reference_display',
        'weight' => -5,
        'settings' => array(),
        'module' => 'commerce_customer',
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'required' => FALSE,
    'description' => '',
    'field_name' => 'commerce_customer_billing',
    'entity_type' => 'commerce_order',
    'bundle' => 'commerce_order',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'commerce_customer',
);
