<?php
/**
 * @file
 * permission.change_own_logout_threshold.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'change own logout threshold',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'autologout',
);
