<?php
/**
 * @file
 * menu_link.e5cc8f7115cfa3ce904f7d946698c2c445d35dd8.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'devel/settings',
  'link_title' => 'Devel settings',
  'menu_name' => 'devel',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'Helper functions, pages, and blocks to assist Drupal developers. The devel blocks can be managed via the <a href="/admin/structure/block">block administration</a> page.',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'devel/settings',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.devel' => 'menu.devel',
);

$optional = array();

$modules = array();
