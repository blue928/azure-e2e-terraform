<?php
/**
 * @file
 * field_group.group_announcement_content_node_announcements_form.inc
 */

$api = '2.0.0';

$data = $field_group = new stdClass();
$field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
$field_group->api_version = 1;
$field_group->identifier = 'group_announcement_content|node|announcements|form';
$field_group->group_name = 'group_announcement_content';
$field_group->entity_type = 'node';
$field_group->bundle = 'announcements';
$field_group->mode = 'form';
$field_group->parent_name = '';
$field_group->data = array(
  'label' => 'Announcement content',
  'weight' => '5',
  'children' => array(
    0 => 'body',
  ),
  'format_type' => 'tab',
  'format_settings' => array(
    'formatter' => 'closed',
    'instance_settings' => array(
      'description' => '',
      'classes' => 'group-announcement-content field-group-tab',
      'required_fields' => 1,
    ),
  ),
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'field_group',
);
