<?php
/**
 * @file
 * menu_link.5db1e4fbc4ea0479c2b5119320ab8533bb3b5194.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'devel/cache/clear',
  'link_title' => 'Clear cache',
  'menu_name' => 'devel',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'Clear the CSS cache and all database cache tables which store page, node, theme and variable caches.',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'devel/cache/clear',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.devel' => 'menu.devel',
);

$optional = array();

$modules = array();
