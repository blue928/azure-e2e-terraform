<?php

/**
 * @file
 * stihl_product_views.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stihl_product_views_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hangtag_layout';
  $context->description = '';
  $context->tag = 'Stihl';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'hangtags' => 'hangtags',
        'hangtags/*' => 'hangtags/*',
        'product-category/*' => 'product-category/*',
        'orders/*' => 'orders/*',
        'upc/*' => 'upc/*',
        'order/review/*' => 'order/review/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'BDuser' => 'BDuser',
        'RLadmin' => 'RLadmin',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-hangtags' => array(
          'module' => 'menu',
          'delta' => 'menu-hangtags',
          'region' => 'primary_nav',
          'weight' => '-10',
        ),
        'menu-menu-product-categories' => array(
          'module' => 'menu',
          'delta' => 'menu-product-categories',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'region' => array(
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'stihl' => array(
        'disable' => array(
          'cart_popout' => 'cart_popout',
          'search' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'primary_nav' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Stihl');
  $export['hangtag_layout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pop_layout';
  $context->description = '';
  $context->tag = 'Stihl';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'pop' => 'pop',
        'pop-catalog' => 'pop-catalog',
        'pop-catalog/*' => 'pop-catalog/*',
        'admin/commerce/orders' => 'admin/commerce/orders',
        'admin/commerce/orders/*' => 'admin/commerce/orders/*',
        'admin/commerce/products/add/evergreen' => 'admin/commerce/products/add/evergreen',
        'admin/commerce/products/add/pop-item' => 'admin/commerce/products/add/pop-item',
        'cart' => 'cart',
        'cart/*' => 'cart/*',
        'checkout' => 'checkout',
        'checkout/*' => 'checkout/*',
        'checkout/*/*' => 'checkout/*/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'POP Admin' => 'POP Admin',
        'POP User' => 'POP User',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-pop-catalog' => array(
          'module' => 'menu',
          'delta' => 'menu-pop-catalog',
          'region' => 'primary_nav',
          'weight' => '-10',
        ),
        'stihl_product_views-pop_catalog_menu_block' => array(
          'module' => 'stihl_product_views',
          'delta' => 'pop_catalog_menu_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'commerce_cart-cart' => array(
          'module' => 'commerce_cart',
          'delta' => 'cart',
          'region' => 'cart_popout',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Stihl');
  $export['pop_layout'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'stihl_layout';
  $context->description = 'Controls general layout of blocks and menus.';
  $context->tag = 'Stihl';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-product-categories' => array(
          'module' => 'menu',
          'delta' => 'menu-product-categories',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Controls general layout of blocks and menus.');
  t('Stihl');
  $export['stihl_layout'] = $context;

  return $export;
}
