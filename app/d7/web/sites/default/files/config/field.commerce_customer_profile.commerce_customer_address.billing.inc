<?php
/**
 * @file
 * field.commerce_customer_profile.commerce_customer_address.billing.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'commerce_customer_profile',
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
            'field_data_commerce_customer_address' => array(
              'country' => 'commerce_customer_address_country',
              'administrative_area' => 'commerce_customer_address_administrative_area',
              'sub_administrative_area' => 'commerce_customer_address_sub_administrative_area',
              'locality' => 'commerce_customer_address_locality',
              'dependent_locality' => 'commerce_customer_address_dependent_locality',
              'postal_code' => 'commerce_customer_address_postal_code',
              'thoroughfare' => 'commerce_customer_address_thoroughfare',
              'premise' => 'commerce_customer_address_premise',
              'sub_premise' => 'commerce_customer_address_sub_premise',
              'organisation_name' => 'commerce_customer_address_organisation_name',
              'name_line' => 'commerce_customer_address_name_line',
              'first_name' => 'commerce_customer_address_first_name',
              'last_name' => 'commerce_customer_address_last_name',
              'data' => 'commerce_customer_address_data',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_commerce_customer_address' => array(
              'country' => 'commerce_customer_address_country',
              'administrative_area' => 'commerce_customer_address_administrative_area',
              'sub_administrative_area' => 'commerce_customer_address_sub_administrative_area',
              'locality' => 'commerce_customer_address_locality',
              'dependent_locality' => 'commerce_customer_address_dependent_locality',
              'postal_code' => 'commerce_customer_address_postal_code',
              'thoroughfare' => 'commerce_customer_address_thoroughfare',
              'premise' => 'commerce_customer_address_premise',
              'sub_premise' => 'commerce_customer_address_sub_premise',
              'organisation_name' => 'commerce_customer_address_organisation_name',
              'name_line' => 'commerce_customer_address_name_line',
              'first_name' => 'commerce_customer_address_first_name',
              'last_name' => 'commerce_customer_address_last_name',
              'data' => 'commerce_customer_address_data',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'field_name' => 'commerce_customer_address',
    'type' => 'addressfield',
    'module' => 'addressfield',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'country' => array(
        'description' => 'Two letter ISO country code of this address.',
        'type' => 'varchar',
        'length' => 2,
        'not null' => FALSE,
        'default' => '',
      ),
      'administrative_area' => array(
        'description' => 'The administrative area of this address. (i.e. State/Province)',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'sub_administrative_area' => array(
        'description' => 'The sub administrative area of this address.',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'locality' => array(
        'description' => 'The locality of this address. (i.e. City)',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'dependent_locality' => array(
        'description' => 'The dependent locality of this address.',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'postal_code' => array(
        'description' => 'The postal code of this address.',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'thoroughfare' => array(
        'description' => 'The thoroughfare of this address. (i.e. Street address)',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'premise' => array(
        'description' => 'The premise of this address. (i.e. Apartment / Suite number)',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'sub_premise' => array(
        'description' => 'The sub_premise of this address.',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'organisation_name' => array(
        'description' => 'Contents of a primary OrganisationName element in the xNL XML.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'name_line' => array(
        'description' => 'Contents of a primary NameLine element in the xNL XML.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'first_name' => array(
        'description' => 'Contents of the FirstName element of a primary PersonName element in the xNL XML.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'last_name' => array(
        'description' => 'Contents of the LastName element of a primary PersonName element in the xNL XML.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'data' => array(
        'description' => 'Additional data for this address.',
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
        'serialize' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Address',
    'required' => TRUE,
    'widget' => array(
      'type' => 'addressfield_standard',
      'weight' => -10,
      'settings' => array(
        'format_handlers' => array(
          0 => 'address',
          1 => 'name-oneline',
        ),
        'available_countries' => array(),
        'default_country' => 'site_default',
      ),
      'module' => 'addressfield',
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'addressfield_default',
        'weight' => -10,
        'settings' => array(
          'use_widget_handlers' => 1,
          'format_handlers' => array(
            0 => 'address',
          ),
        ),
        'module' => 'addressfield',
      ),
      'customer' => array(
        'label' => 'hidden',
        'type' => 'addressfield_default',
        'weight' => -10,
        'settings' => array(
          'use_widget_handlers' => 1,
          'format_handlers' => array(
            0 => 'address',
          ),
        ),
        'module' => 'addressfield',
      ),
      'administrator' => array(
        'label' => 'hidden',
        'type' => 'addressfield_default',
        'weight' => -10,
        'settings' => array(
          'use_widget_handlers' => 1,
          'format_handlers' => array(
            0 => 'address',
          ),
        ),
        'module' => 'addressfield',
      ),
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'description' => '',
    'field_name' => 'commerce_customer_address',
    'entity_type' => 'commerce_customer_profile',
    'bundle' => 'billing',
    'deleted' => '0',
    'default_value' => NULL,
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'addressfield',
);
