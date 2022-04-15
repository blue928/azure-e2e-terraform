<?php
/**
 * @file
 * permission.access_administrator_profiles.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access administrator profiles',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'view_profiles_perms',
);
