<?php
/**
 * @file
 * permission.unblock_expired_accounts.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'unblock expired accounts',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'password_policy',
);
