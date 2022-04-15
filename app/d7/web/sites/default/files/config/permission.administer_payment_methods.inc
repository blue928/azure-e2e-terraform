<?php
/**
 * @file
 * permission.administer_payment_methods.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer payment methods',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_payment',
);
