<?php
/**
 * @file
 * permission.create_commerce_order_entities.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'create commerce_order entities',
  'roles' => array(
    0 => 'administrator',
    1 => 'POP User',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_order',
);
