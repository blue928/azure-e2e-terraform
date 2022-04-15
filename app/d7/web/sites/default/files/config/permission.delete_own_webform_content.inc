<?php
/**
 * @file
 * permission.delete_own_webform_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'delete own webform content',
  'roles' => array(),
);

$dependencies = array(
  'content_type.webform' => 'content_type.webform',
);

$optional = array();

$modules = array(
  0 => 'node',
);
