<?php
/**
 * @file
 * permission.configure_order_settings.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'configure order settings',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_order',
);
