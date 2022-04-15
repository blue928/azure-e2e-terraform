<?php
/**
 * @file
 * permission.access_rladmin_profiles.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access RLadmin profiles',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'view_profiles_perms',
);
