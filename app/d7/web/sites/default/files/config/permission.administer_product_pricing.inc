<?php
/**
 * @file
 * permission.administer_product_pricing.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer product pricing',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_product_pricing_ui',
);
