<?php
/**
 * @file
 * permission.edit_any_webform_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit any webform content',
  'roles' => array(),
);

$dependencies = array(
  'content_type.webform' => 'content_type.webform',
);

$optional = array();

$modules = array(
  0 => 'node',
);
