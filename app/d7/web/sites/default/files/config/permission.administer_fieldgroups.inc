<?php
/**
 * @file
 * permission.administer_fieldgroups.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer fieldgroups',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_group',
);
