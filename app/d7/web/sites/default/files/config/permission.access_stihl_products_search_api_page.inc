<?php
/**
 * @file
 * permission.access_stihl_products_search_api_page.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access stihl_products search_api_page',
  'roles' => array(
    0 => 'BDuser',
    1 => 'RLadmin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'search_api_page',
);
