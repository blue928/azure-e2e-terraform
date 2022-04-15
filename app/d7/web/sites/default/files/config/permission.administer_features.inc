<?php
/**
 * @file
 * permission.administer_features.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer features',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'features',
);
