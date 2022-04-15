<?php
/**
 * @file
 * permission.run_security_checks.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'run security checks',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'security_review',
);
