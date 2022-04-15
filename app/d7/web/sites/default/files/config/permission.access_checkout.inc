<?php
/**
 * @file
 * permission.access_checkout.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access checkout',
  'roles' => array(
    0 => 'administrator',
    1 => 'POP Admin',
    2 => 'POP User',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_checkout',
);
