<?php
/**
 * @file
 * permission.access_administration_menu.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access administration menu',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'admin_menu',
);
