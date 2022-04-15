<?php
/**
 * @file
 * permission.administer_customer_profile_types.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer customer profile types',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_customer',
);
