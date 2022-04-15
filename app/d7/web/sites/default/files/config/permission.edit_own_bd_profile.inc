<?php
/**
 * @file
 * permission.edit_own_bd_profile.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own bd profile',
  'roles' => array(
    0 => 'administrator',
    1 => 'BDuser',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'stihl_profiles',
);
