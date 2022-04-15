<?php
/**
 * @file
 * permission.administer_fusionpro_template_configs.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'administer FusionPro template configs',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'fp_template_configs',
);
