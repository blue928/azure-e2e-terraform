<?php
/**
 * @file
 * variable.ldap_profile_conf.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'ldap_profile_conf',
  'content' => array(
    'ldap_fields' => array(
      0 => 'samaccountname',
      1 => 'mail',
    ),
    'mapping' => array(
      'username' => 'samaccountname',
      'mail' => 'mail',
      'field_full_name' => 'displayname',
    ),
    'derivedMapping' => array(
      'field_full_name' => array(
        'derive' => FALSE,
        'derive_value' => '',
      ),
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array();
