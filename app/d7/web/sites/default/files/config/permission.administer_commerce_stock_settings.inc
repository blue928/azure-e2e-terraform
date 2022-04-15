<?php
/**
 * @file
 * permission.administer_commerce_stock_settings.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer commerce_stock settings',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_stock',
);
