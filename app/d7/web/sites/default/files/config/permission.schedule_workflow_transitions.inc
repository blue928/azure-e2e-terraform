<?php
/**
 * @file
 * permission.schedule_workflow_transitions.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'schedule workflow transitions',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'workflow',
);
