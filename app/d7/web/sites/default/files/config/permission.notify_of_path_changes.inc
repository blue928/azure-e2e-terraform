<?php
/**
 * @file
 * permission.notify_of_path_changes.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'notify of path changes',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'pathauto',
);
