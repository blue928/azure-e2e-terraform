<?php
/**
 * @file
 * permission.administer_field_permissions.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer field permissions',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_permissions',
);
