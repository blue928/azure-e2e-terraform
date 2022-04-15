<?php
/**
 * @file
 * permission.force_password_change.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'force password change',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'password_policy',
);
