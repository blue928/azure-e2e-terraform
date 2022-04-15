<?php
/**
 * @file
 * permission.view_any_commerce_product_entity_of_bundle_product.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view any commerce_product entity of bundle product',
  'roles' => array(
    0 => 'BDuser',
    1 => 'RLadmin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_product',
);
