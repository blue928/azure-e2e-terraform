<?php
/**
 * @file
 * permission.participate_in_workflow.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'participate in workflow',
  'roles' => array(
    0 => 'anonymous user',
    1 => 'authenticated user',
    2 => 'administrator',
    3 => 'BDuser',
    4 => 'RLadmin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'workflow',
);
