<?php
/**
 * @file
 * content_type.product_display.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'product_display',
  'name' => 'Product Display',
  'description' => '',
  'has_title' => '1',
  'title_label' => 'Title',
  'base' => 'node_content',
  'help' => '',
);

$dependencies = array();

$optional = array(
  'field.node.body.product_display' => 'field.node.body.product_display',
  'field.node.field_product.product_display' => 'field.node.field_product.product_display',
  'permission.create_product_display_content' => 'permission.create_product_display_content',
  'permission.edit_own_product_display_content' => 'permission.edit_own_product_display_content',
  'permission.edit_any_product_display_content' => 'permission.edit_any_product_display_content',
  'permission.delete_own_product_display_content' => 'permission.delete_own_product_display_content',
  'permission.delete_any_product_display_content' => 'permission.delete_any_product_display_content',
);

$modules = array(
  0 => 'node',
);
