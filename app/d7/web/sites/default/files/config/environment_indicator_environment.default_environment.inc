<?php
/**
 * @file
 * environment_indicator_environment.default_environment.inc
 */

$api = '2.0.0';

$data = $environment = new stdClass();
$environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
$environment->api_version = 1;
$environment->machine = 'default_environment';
$environment->name = 'Default environment';
$environment->regexurl = '.*';
$environment->settings = array(
  'color' => '#aa3333',
  'text_color' => '#ffffff',
  'weight' => 99,
  'position' => 'top',
  'fixed' => FALSE,
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'environment_indicator',
);
