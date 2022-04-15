<?php
/**
 * @file
 * permission.administer_reroute_email.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer reroute email',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'reroute_email',
);
