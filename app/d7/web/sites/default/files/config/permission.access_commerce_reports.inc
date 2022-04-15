<?php
/**
 * @file
 * permission.access_commerce_reports.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access commerce reports',
  'roles' => array(
    0 => 'administrator',
    1 => 'POP Admin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'commerce_reports',
);
