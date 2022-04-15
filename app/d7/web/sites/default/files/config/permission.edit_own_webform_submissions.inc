<?php
/**
 * @file
 * permission.edit_own_webform_submissions.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own webform submissions',
  'roles' => array(
    0 => 'administrator',
    1 => 'RLadmin',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'webform',
);
