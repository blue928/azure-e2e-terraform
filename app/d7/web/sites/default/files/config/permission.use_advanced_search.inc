<?php
/**
 * @file
 * permission.use_advanced_search.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'use advanced search',
  'roles' => array(
    0 => 'administrator',
    1 => 'POP User',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'search',
);
