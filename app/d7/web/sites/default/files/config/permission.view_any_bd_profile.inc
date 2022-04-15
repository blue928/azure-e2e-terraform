<?php
/**
 * @file
 * permission.view_any_bd_profile.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view any bd profile',
  'roles' => array(
    0 => 'authenticated user',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'stihl_profiles',
);
