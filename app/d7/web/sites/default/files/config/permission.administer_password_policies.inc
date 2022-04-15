<?php
/**
 * @file
 * permission.administer_password_policies.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer password policies',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'password_policy',
);
