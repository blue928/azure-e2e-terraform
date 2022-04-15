<?php
/**
 * @file
 * permission.delete_any_product_display_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'delete any product_display content',
  'roles' => array(),
);

$dependencies = array(
  'content_type.product_display' => 'content_type.product_display',
);

$optional = array();

$modules = array(
  0 => 'node',
);
