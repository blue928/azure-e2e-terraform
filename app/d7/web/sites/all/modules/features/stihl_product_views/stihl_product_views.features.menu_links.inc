<?php

/**
 * @file
 * stihl_product_views.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function stihl_product_views_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_hangtag-orders:hangtags.
  $menu_links['main-menu_hangtag-orders:hangtags'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'hangtags',
    'router_path' => 'hangtags',
    'link_title' => 'Hangtag Orders',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_hangtag-orders:hangtags',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -36,
    'customized' => 1,
  );
  // Exported menu link: main-menu_pop-orders:pop-catalog.
  $menu_links['main-menu_pop-orders:pop-catalog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'pop-catalog',
    'router_path' => 'pop-catalog',
    'link_title' => 'POP Orders',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_pop-orders:pop-catalog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -35,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Hangtag Orders');
  t('POP Orders');

  return $menu_links;
}
