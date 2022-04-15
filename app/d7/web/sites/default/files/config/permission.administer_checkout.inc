<?php
/**
 * @file
 * permission.administer_checkout.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer checkout',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_checkout',
);
