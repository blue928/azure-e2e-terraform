<?php
/**
 * @file
 * stihl_support.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function stihl_support_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_support:node/7.
  $menu_links['user-menu_support:node/7'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Support',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_support:node/7',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Support');

  return $menu_links;
}
