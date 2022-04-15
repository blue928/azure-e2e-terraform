<?php
/**
 * @file
 * context.pop_user_layout.inc
 */

$api = '2.0.0';

$data = $context = new stdClass();
$context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'pop_user_layout';
$context->description = 'Layout for the POP User only';
$context->tag = 'Stihl';
$context->conditions = array(
  'path' => array(
    'values' => array(
      'pop-catalog' => 'pop-catalog',
      'pop-catalog/*' => 'pop-catalog/*',
    ),
  ),
  'user' => array(
    'values' => array(
      'POP User' => 'POP User',
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'menu-menu-pop-catalog' => array(
        'module' => 'menu',
        'delta' => 'menu-pop-catalog',
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
  'menu' => array(
    0 => 'menu-pop-catalog:pop-catalog',
  ),
);
$context->condition_mode = 1;

// Translatables
// Included for use with string extractors like potx.
t('Layout for the POP User only');
t('Stihl');


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'context',
);
