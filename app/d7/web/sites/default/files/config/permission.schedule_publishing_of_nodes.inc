<?php
/**
 * @file
 * permission.schedule_publishing_of_nodes.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'schedule publishing of nodes',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'scheduler',
);
