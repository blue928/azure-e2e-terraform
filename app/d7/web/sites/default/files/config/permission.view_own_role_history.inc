<?php
/**
 * @file
 * permission.view_own_role_history.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view own role history',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'role_watchdog',
);
