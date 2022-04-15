<?php
/**
 * @file
 * permission.administer_line_items.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer line items',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_line_item',
);
