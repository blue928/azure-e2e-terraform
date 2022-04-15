<?php
/**
 * @file
 * permission.view_any_commerce_order_entity_of_bundle_commerce_order.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view any commerce_order entity of bundle commerce_order',
  'roles' => array(
    0 => 'administrator',
    1 => 'BDuser',
    2 => 'RLadmin',
    3 => 'POP Admin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_order',
);
