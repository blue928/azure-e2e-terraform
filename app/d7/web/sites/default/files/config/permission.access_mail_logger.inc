<?php
/**
 * @file
 * permission.access_mail_logger.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'access mail logger',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'mail_logger',
);
