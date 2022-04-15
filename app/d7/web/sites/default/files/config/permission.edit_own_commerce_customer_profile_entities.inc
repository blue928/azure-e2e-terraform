<?php
/**
 * @file
 * permission.edit_own_commerce_customer_profile_entities.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own commerce_customer_profile entities',
  'roles' => array(
    0 => 'administrator',
    1 => 'POP User',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_customer',
);
