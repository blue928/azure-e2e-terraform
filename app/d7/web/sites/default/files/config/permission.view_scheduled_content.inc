<?php
/**
 * @file
 * permission.view_scheduled_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view scheduled content',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'scheduler',
);
