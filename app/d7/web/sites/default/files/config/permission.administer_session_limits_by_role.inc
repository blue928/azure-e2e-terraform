<?php
/**
 * @file
 * permission.administer_session_limits_by_role.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer session limits by role',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'session_limit',
);
