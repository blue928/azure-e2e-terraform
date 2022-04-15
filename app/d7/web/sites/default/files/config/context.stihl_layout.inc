<?php
/**
 * @file
 * context.stihl_layout.inc
 */

$api = '2.0.0';

$data = $context = new stdClass();
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


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'context',
);
