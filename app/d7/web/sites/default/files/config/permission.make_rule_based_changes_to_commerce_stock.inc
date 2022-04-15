<?php
/**
 * @file
 * permission.make_rule_based_changes_to_commerce_stock.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'make rule based changes to commerce_stock',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_stock',
);
