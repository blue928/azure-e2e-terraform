<?php
/**
 * @file
 * menu_link.c06da4f934c60c508e7f56dc7bcdec144530ca9a.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'devel/session',
  'link_title' => 'Session viewer',
  'menu_name' => 'devel',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'List the contents of $_SESSION.',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'devel/session',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.devel' => 'menu.devel',
);

$optional = array();

$modules = array();
