<?php
/**
 * @file
 * menu_link.d28d3b320a6220c270549973f210f1ea188ab649.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'devel/variable',
  'link_title' => 'Variable editor',
  'menu_name' => 'devel',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'Edit and delete site variables.',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'devel/variable',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.devel' => 'menu.devel',
);

$optional = array();

$modules = array();
