<?php
/**
 * @file
 * stihl_announcements.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stihl_announcements_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stihl_announcements_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stihl_announcements_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Announcements'),
      'base' => 'node_content',
      'description' => t('Use <em>Announcements</em> for general notifications and scheduled maintenance.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'banner_image' => array(
      'name' => t('Banner Image'),
      'base' => 'node_content',
      'description' => t('Banner image used on the homepage, or other places tbd.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
