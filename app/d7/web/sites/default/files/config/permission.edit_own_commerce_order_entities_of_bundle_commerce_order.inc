<?php
/**
 * @file
 * permission.edit_own_commerce_order_entities_of_bundle_commerce_order.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own commerce_order entities of bundle commerce_order',
  'roles' => array(
    0 => 'administrator',
    1 => 'BDuser',
    2 => 'RLadmin',
    3 => 'POP Admin',
    4 => 'POP User',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_order',
);
