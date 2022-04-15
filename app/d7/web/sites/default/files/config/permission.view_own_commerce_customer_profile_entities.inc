<?php
/**
 * @file
 * permission.view_own_commerce_customer_profile_entities.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view own commerce_customer_profile entities',
  'roles' => array(
    0 => 'administrator',
    1 => 'POP Admin',
    2 => 'POP User',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_customer',
);
