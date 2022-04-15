<?php
/**
 * @file
 * permission.view_any_commerce_order_entity.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view any commerce_order entity',
  'roles' => array(
    0 => 'administrator',
    1 => 'POP Admin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_order',
);
