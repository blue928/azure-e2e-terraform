<?php
/**
 * @file
 * menu_link.9e7e365294af1c9bf84ff36489d7da95bf0c12d5.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'devel/reinstall',
  'link_title' => 'Reinstall modules',
  'menu_name' => 'devel',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'Run hook_uninstall() and then hook_install() for a given module.',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'devel/reinstall',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.devel' => 'menu.devel',
);

$optional = array();

$modules = array();
