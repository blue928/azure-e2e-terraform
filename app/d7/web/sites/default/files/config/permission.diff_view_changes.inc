<?php
/**
 * @file
 * permission.diff_view_changes.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'diff view changes',
  'roles' => array(
    0 => 'anonymous user',
    1 => 'authenticated user',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'diff',
);
