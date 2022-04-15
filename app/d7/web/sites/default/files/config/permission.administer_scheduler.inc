<?php
/**
 * @file
 * permission.administer_scheduler.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer scheduler',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'scheduler',
);
