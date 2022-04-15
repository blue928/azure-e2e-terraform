<?php
/**
 * @file
 * permission.edit_workflow_comment.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit workflow comment',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'workflow',
);
