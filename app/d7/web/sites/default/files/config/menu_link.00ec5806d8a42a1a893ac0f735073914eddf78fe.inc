<?php
/**
 * @file
 * menu_link.00ec5806d8a42a1a893ac0f735073914eddf78fe.inc
 */

$api = '2.0.0';

$data = array(
  'link_path' => 'admin/reports/permission_watchdog',
  'link_title' => 'Permission change report',
  'menu_name' => 'management',
  'weight' => '0',
  'expanded' => '0',
  'options' => array(
    'attributes' => array(
      'title' => 'Display a log of changes to role permissions.',
    ),
    'alter' => TRUE,
  ),
  'router_path' => 'admin/reports/permission_watchdog',
  'parent_identifier' => '6e9b944c771415a0ccba38da3b419ea22c255640',
);

$dependencies = array(
  'menu_link.6e9b944c771415a0ccba38da3b419ea22c255640' => 'menu_link.6e9b944c771415a0ccba38da3b419ea22c255640',
);

$optional = array();

$modules = array();
