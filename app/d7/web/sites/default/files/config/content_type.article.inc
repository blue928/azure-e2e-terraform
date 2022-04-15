<?php
/**
 * @file
 * content_type.article.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'article',
  'name' => 'Announcements',
  'description' => 'Use <em>Announcements</em> for general notifications and scheduled maintenance.',
  'has_title' => '1',
  'title_label' => 'Title',
  'base' => 'node_content',
  'help' => '',
);

$dependencies = array(
  'variable.node_options_article' => 'variable.node_options_article',
  'variable.node_preview_article' => 'variable.node_preview_article',
  'variable.node_submitted_article' => 'variable.node_submitted_article',
  'variable.comment_default_per_page_article' => 'variable.comment_default_per_page_article',
  'variable.comment_form_location_article' => 'variable.comment_form_location_article',
  'variable.comment_preview_article' => 'variable.comment_preview_article',
  'variable.comment_subject_field_article' => 'variable.comment_subject_field_article',
);

$optional = array(
  'field.node.body.article' => 'field.node.body.article',
  'field.node.field_image.article' => 'field.node.field_image.article',
  'field.node.field_announcement_type.article' => 'field.node.field_announcement_type.article',
  'permission.create_article_content' => 'permission.create_article_content',
  'permission.edit_own_article_content' => 'permission.edit_own_article_content',
  'permission.edit_any_article_content' => 'permission.edit_any_article_content',
  'permission.delete_own_article_content' => 'permission.delete_own_article_content',
  'permission.delete_any_article_content' => 'permission.delete_any_article_content',
);

$modules = array(
  0 => 'node',
);
