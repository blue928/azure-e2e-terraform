<?php
/**
 * @file
 * permission.access_all_webform_results.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access all webform results',
  'roles' => array(
    0 => 'administrator',
    1 => 'RLadmin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'webform',
);
