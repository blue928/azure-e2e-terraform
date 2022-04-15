<?php
/**
 * @file
 * stihl_announcements.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stihl_announcements_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
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
  $field_groups['group_announcement_content|node|announcements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_announcement_title|node|announcements|form';
  $field_group->group_name = 'group_announcement_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'announcements';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title and Type',
    'weight' => '2',
    'children' => array(
      0 => 'field_announcement_type',
      1 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-announcement-title field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_announcement_title|node|announcements|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Announcement content');
  t('Title and Type');

  return $field_groups;
}
