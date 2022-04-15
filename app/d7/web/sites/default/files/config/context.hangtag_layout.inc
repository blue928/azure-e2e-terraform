<?php
/**
 * @file
 * context.hangtag_layout.inc
 */

$api = '2.0.0';

$data = $context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'hangtag_layout';
$context->description = '';
$context->tag = 'Stihl';
$context->conditions = array(
  'user' => array(
    'values' => array(
      'BDuser' => 'BDuser',
      'administrator' => 'administrator',
      'developer' => 'developer',
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


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'context',
);
