<?php
/**
 * @file
 * menu_link.24c9fb8016685edecb48acac4964259a7f620f27.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'devel/menu/reset',
  'link_title' => 'Rebuild menus',
  'menu_name' => 'devel',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'Rebuild menu based on hook_menu() and revert any custom changes. All menu items return to their default settings.',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'devel/menu/reset',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.devel' => 'menu.devel',
);

$optional = array();

$modules = array();
