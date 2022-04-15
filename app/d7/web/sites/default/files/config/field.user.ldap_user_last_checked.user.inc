<?php
/**
 * @file
 * field.user.ldap_user_last_checked.user.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'user',
    ),
    'translatable' => '0',
    'no_ui' => 1,
    'settings' => array(),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_ldap_user_last_checked' => array(
              'value' => 'ldap_user_last_checked_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_ldap_user_last_checked' => array(
              'value' => 'ldap_user_last_checked_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'ldap_user_last_checked',
    'type' => 'number_integer',
    'module' => 'number',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'int',
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Unix timestamp of when Drupal user was compard to ldap entry.  This could be for purposes of synching, deleteing drupal account, etc.',
    'description' => 'This field should not be edited.',
    'required' => 0,
    'default_value' => NULL,
    'settings' => array(
      'min' => '',
      'max' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'type' => 'ldap_user_hidden',
      'settings' => array(),
      'module' => 'ldap_user',
      'weight' => 15,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'settings' => array(),
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'settings' => array(),
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'settings' => array(),
        'weight' => 5,
      ),
    ),
    'field_name' => 'ldap_user_last_checked',
    'entity_type' => 'user',
    'bundle' => 'user',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'number',
  2 => 'ldap_user',
);
