<?php
/**
 * @file
 * permission.administer_workflow.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer workflow',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'workflow_admin_ui',
);
