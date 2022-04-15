<?php
/**
 * @file
 * permission.flush_caches.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'flush caches',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'admin_menu',
);
