<?php
/**
 * @file
 * permission.administer_search_api.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer search_api',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'search_api',
);
