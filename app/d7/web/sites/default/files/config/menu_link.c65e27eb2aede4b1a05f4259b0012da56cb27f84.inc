<?php
/**
 * @file
 * menu_link.c65e27eb2aede4b1a05f4259b0012da56cb27f84.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'devel/phpinfo',
  'link_title' => 'PHPinfo()',
  'menu_name' => 'devel',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'View your server\'s PHP configuration',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'devel/phpinfo',
  'parent_identifier' => NULL,
);

$dependencies = array(
  'menu.devel' => 'menu.devel',
);

$optional = array();

$modules = array();
