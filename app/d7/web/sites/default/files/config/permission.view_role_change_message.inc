<?php
/**
 * @file
 * permission.view_role_change_message.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view role change message',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'role_watchdog',
);
