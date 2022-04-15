<?php
/**
 * @file
 * permission.update_payments.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'update payments',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_payment',
);
