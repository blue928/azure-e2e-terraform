<?php
/**
 * @file
 * permission.view_payments.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view payments',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_payment',
);
