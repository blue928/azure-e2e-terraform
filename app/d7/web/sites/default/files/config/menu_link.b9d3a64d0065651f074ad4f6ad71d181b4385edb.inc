<?php
/**
 * @file
 * menu_link.b9d3a64d0065651f074ad4f6ad71d181b4385edb.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'devel/reference',
  'link_title' => 'Function reference',
  'menu_name' => 'devel',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'View a list of currently defined user functions with documentation links.',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'devel/reference',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.devel' => 'menu.devel',
);

$optional = array();

$modules = array();
