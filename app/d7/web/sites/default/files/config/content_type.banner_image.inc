<?php
/**
 * @file
 * content_type.banner_image.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'banner_image',
  'name' => 'Banner Image',
  'description' => 'Banner image used on the homepage, or other places tbd.',
  'has_title' => '1',
  'title_label' => 'Title',
  'base' => 'node_content',
  'help' => '',
);

$dependencies = array(
  'variable.node_options_banner_image' => 'variable.node_options_banner_image',
  'variable.node_preview_banner_image' => 'variable.node_preview_banner_image',
  'variable.node_submitted_banner_image' => 'variable.node_submitted_banner_image',
  'variable.comment_default_per_page_banner_image' => 'variable.comment_default_per_page_banner_image',
  'variable.comment_form_location_banner_image' => 'variable.comment_form_location_banner_image',
  'variable.comment_preview_banner_image' => 'variable.comment_preview_banner_image',
  'variable.comment_subject_field_banner_image' => 'variable.comment_subject_field_banner_image',
);

$optional = array(
  'field.node.field_banner_description.banner_image' => 'field.node.field_banner_description.banner_image',
  'field.node.field_banner_image.banner_image' => 'field.node.field_banner_image.banner_image',
  'permission.create_banner_image_content' => 'permission.create_banner_image_content',
  'permission.edit_own_banner_image_content' => 'permission.edit_own_banner_image_content',
  'permission.edit_any_banner_image_content' => 'permission.edit_any_banner_image_content',
  'permission.delete_own_banner_image_content' => 'permission.delete_own_banner_image_content',
  'permission.delete_any_banner_image_content' => 'permission.delete_any_banner_image_content',
);

$modules = array(
  0 => 'node',
);
