<?php
/**
 * @file
 * permission.administer_hide_fatal_error.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer hide fatal error',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'hide_php_fatal_error',
);
