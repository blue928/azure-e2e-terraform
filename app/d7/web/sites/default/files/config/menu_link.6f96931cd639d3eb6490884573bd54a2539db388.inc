<?php
/**
 * @file
 * menu_link.6f96931cd639d3eb6490884573bd54a2539db388.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'pop-catalog',
  'link_title' => 'POP Admin',
  'menu_name' => 'main-menu',
  'weight' => '-48',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'Menu items for the POP Admin to manage POP items',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'pop-catalog',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.main_menu' => 'menu.main_menu',
);

$optional = array();

$modules = array();
