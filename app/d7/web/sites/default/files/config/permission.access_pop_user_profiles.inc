<?php
/**
 * @file
 * permission.access_pop_user_profiles.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access POP User profiles',
  'roles' => array(
    0 => 'POP Admin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'view_profiles_perms',
);
