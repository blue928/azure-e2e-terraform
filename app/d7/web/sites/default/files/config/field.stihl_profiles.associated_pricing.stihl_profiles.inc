<?php
/**
 * @file
 * field.stihl_profiles.associated_pricing.stihl_profiles.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'settings' => array(
      'target_type' => 'stihl_pricing_years',
      'handler' => 'base',
      'handler_settings' => array(),
    ),
    'entity_types' => array(),
    'translatable' => '0',
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_associated_pricing' => array(
              'target_id' => 'associated_pricing_target_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_associated_pricing' => array(
              'target_id' => 'associated_pricing_target_id',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'stihl_pricing_year' => array(
        'table' => 'stihl_pricing_year',
        'columns' => array(
          'target_id' => 'id',
        ),
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'field_name' => 'associated_pricing',
    'type' => 'entityreference',
    'module' => 'entityreference',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'target_id' => array(
        'description' => 'The id of the target entity.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Associated Pricing Years',
    'default_value' => NULL,
    'description' => 'The Pricing Years associated with this BD.',
    'widget' => array(
      'type' => 'options_buttons',
      'settings' => array(),
      'weight' => 0,
      'module' => 'options',
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'entityreference_label',
        'settings' => array(
          'link' => FALSE,
          'bypass_access' => FALSE,
        ),
        'module' => 'entityreference',
        'weight' => 0,
      ),
    ),
    'required' => FALSE,
    'field_name' => 'associated_pricing',
    'entity_type' => 'stihl_profiles',
    'bundle' => 'stihl_profiles',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'entityreference',
  2 => 'options',
);
