<?php
/**
 * @file
 * permission.administer_autologout.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer autologout',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'autologout',
);
