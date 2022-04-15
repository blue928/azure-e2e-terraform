<?php
/**
 * @file
 * field.user.ldap_user_puid_property.user.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'user',
    ),
    'translatable' => '0',
    'no_ui' => 1,
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
            'field_data_ldap_user_puid_property' => array(
              'value' => 'ldap_user_puid_property_value',
              'format' => 'ldap_user_puid_property_format',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_ldap_user_puid_property' => array(
              'value' => 'ldap_user_puid_property_value',
              'format' => 'ldap_user_puid_property_format',
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
    'field_name' => 'ldap_user_puid_property',
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
    'label' => 'Property specified as user\'s puid.',
    'description' => 'This field should not be edited.',
    'required' => 0,
    'default_value' => array(),
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'type' => 'ldap_user_hidden',
      'settings' => array(),
      'module' => 'ldap_user',
      'weight' => 12,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'settings' => array(),
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'settings' => array(),
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'hidden',
        'settings' => array(),
        'weight' => 2,
      ),
    ),
    'field_name' => 'ldap_user_puid_property',
    'entity_type' => 'user',
    'bundle' => 'user',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'text',
  2 => 'ldap_user',
);
