<?php
/**
 * @file
 * permission.view_field_bd_reference.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view field_bd_reference',
  'roles' => array(
    0 => 'authenticated user',
    1 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_permissions',
);
