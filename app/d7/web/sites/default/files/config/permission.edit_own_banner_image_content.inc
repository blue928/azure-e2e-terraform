<?php
/**
 * @file
 * permission.edit_own_banner_image_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own banner_image content',
  'roles' => array(
    0 => 'administrator',
    1 => 'RLadmin',
  ),
);

$dependencies = array(
  'content_type.banner_image' => 'content_type.banner_image',
);

$optional = array();

$modules = array(
  0 => 'node',
);
