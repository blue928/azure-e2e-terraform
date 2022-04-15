<?php

/**
 * @file
 * Contains the admin settings for the Pro-Mail module.
 */

/**
 * Callback function for the admin settings menu.
 */
function promail_admin_settings() {
  // Settings for the Pro-Mail web service.
  $form['web_services_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Web services settings'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['web_services_settings']['promail_web_services_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail Web Services URL'),
    '#description' => t('URL for Pro-Mail Web Services.'),
    '#required' => TRUE,
    '#default_value' => variable_get('promail_web_services_url', ''),
  );
  $form['web_services_settings']['promail_web_services_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail Web Services username'),
    '#description' => t('Pro-Mail Web Services user for this system.'),
    '#required' => TRUE,
    '#default_value' => variable_get('promail_web_services_user', ''),
  );
  $form['web_services_settings']['promail_web_services_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail Web Services user password'),
    '#description' => t('Password for the Pro-Mail Web Services user.'),
    '#required' => TRUE,
    '#default_value' => variable_get('promail_web_services_password', ''),
  );
  $form['web_services_settings']['promail_soap_version'] = array(
    '#type' => 'select',
    '#title' => t('SOAP version'),
    '#description' => t('Select which version of SOAP to use. (SOAP 1.2 is experimental.)'),
    '#default_value' => variable_get('promail_soap_version', 'SOAP_1_1'),
    '#options' => array(
      'SOAP_1_1' => t('SOAP 1.1'),
      'SOAP_1_2' => t('SOAP 1.2'),
    ),
  );
  $form['web_services_settings']['promail_development_test_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Development test mode'),
    '#description' => t('If checked, dumps response to screen. For debugging only.'),
    '#default_value' => variable_get('promail_development_test_mode', FALSE),
  );
  $form['web_services_settings']['promail_development_full_errors'] = array(
    '#type' => 'checkbox',
    '#title' => t('Output full SOAP errors'),
    '#description' => t('If checked, outputs full Pro-Mail SOAP errors to drupal_set_message().'),
    '#default_value' => variable_get('promail_development_full_errors', FALSE),
  );

  // Settings for the MSSQL connection.
  $form['mssql_database_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('MSSQL database settings'),
    '#weight' => 2,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['mssql_database_settings']['promail_mssql_server_host'] = array(
    '#type' => 'textfield',
    '#title' => t('MSSQL server host'),
    '#description' => t('MSSQL FQDN server host name for the Pro-Mail database.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_mssql_server_host', ''),
  );
  $form['mssql_database_settings']['promail_mssql_server_user'] = array(
    '#type' => 'textfield',
    '#title' => t('MSSQL read-only account username'),
    '#description' => t('MSSQL read-only account username for the Pro-Mail databases.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_mssql_server_user', ''),
  );
  $form['mssql_database_settings']['promail_mssql_server_password'] = array(
    '#type' => 'textfield',
    '#title' => t('MSSQL read-only account password'),
    '#description' => t('MSSQL read-only account password for the Pro-Mail database.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_mssql_server_password', ''),
  );
  $form['mssql_database_settings']['promail_mssql_db_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Primary Pro-Mail database'),
    '#description' => t('Primary Pro-Mail MSSQL database.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_mssql_db_name', ''),
  );
  $form['mssql_database_settings']['promail_default_system'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Pro-Mail system'),
    '#description' => t('Default Pro-Mail system to connect to for direct database reporting.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_default_system', ''),
  );

  // Settings outside of setting up the Pro-Mail service.
  $form['other_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other settings'),
    '#weight' => 3,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['other_settings']['promail_error_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail Error Email'),
    '#description' => t('Email addresses to send notifications of an error with Pro-Mail (Ex: "dev@knowclassic.com, vihnt@knowclassic.com").'),
    '#required' => TRUE,
    '#default_value' => variable_get('promail_error_email', 'dev@knowclassic.com'),
  );
  $form['other_settings']['promail_owners'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pro-Mail owners'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['other_settings']['promail_owners']['promail_owner'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail primary owner'),
    '#description' => t('Pro-Mail store primary data owner.'),
    '#required' => TRUE,
    '#default_value' => variable_get('promail_owner', ''),
  );
  $form['other_settings']['promail_owners']['promail_owner_desc'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail store owner description'),
    '#description' => t('Description of use and purpose for the Pro-Mail store primary data owner.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_owner_desc', ''),
  );
  $form['other_settings']['promail_owners']['promail_additional_owner1'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail additional owner 1'),
    '#description' => t('Pro-Mail store additional data owner 1.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_additional_owner1', ''),
  );
  $form['other_settings']['promail_owners']['promail_additional_owner1_desc'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail additional owner 1 description'),
    '#description' => t('Description of use and purpose for the Pro-Mail store additional data owner 1.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_additional_owner1_desc', ''),
  );
  $form['other_settings']['promail_owners']['promail_additional_owner2'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail additional owner 2'),
    '#description' => t('Pro-Mail store additional data owner 2.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_additional_owner2', ''),
  );
  $form['other_settings']['promail_owners']['promail_additional_owner2_desc'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail additional owner 2 description'),
    '#description' => t('Description of use and purpose for the Pro-Mail store additional data owner 2.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_additional_owner2_desc', ''),
  );
  $form['other_settings']['promail_owners']['promail_additional_owner3'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail additional owner 3'),
    '#description' => t('Pro-Mail store additional data owner 3.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_additional_owner3', ''),
  );
  $form['other_settings']['promail_owners']['promail_additional_owner3_desc'] = array(
    '#type' => 'textfield',
    '#title' => t('Pro-Mail additional owner 3 description'),
    '#description' => t('Description of use and purpose for the Pro-Mail store additional data owner 3.'),
    '#required' => FALSE,
    '#default_value' => variable_get('promail_additional_owner3_desc', ''),
  );

  return system_settings_form($form);
}
