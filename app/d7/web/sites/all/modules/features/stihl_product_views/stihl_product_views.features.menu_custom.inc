<?php

/**
 * @file
 * stihl_product_views.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function stihl_product_views_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-hangtags.
  $menus['menu-hangtags'] = array(
    'menu_name' => 'menu-hangtags',
    'title' => 'Hangtags',
    'description' => '',
  );
  // Exported menu: menu-pop-catalog.
  $menus['menu-pop-catalog'] = array(
    'menu_name' => 'menu-pop-catalog',
    'title' => 'POP Catalog',
    'description' => 'POP Products',
  );
  // Exported menu: menu-product-categories.
  $menus['menu-product-categories'] = array(
    'menu_name' => 'menu-product-categories',
    'title' => 'Product Categories',
    'description' => 'Product category taxonomy menu.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Hangtags');
  t('POP Catalog');
  t('POP Products');
  t('Product Categories');
  t('Product category taxonomy menu.');

  return $menus;
}
