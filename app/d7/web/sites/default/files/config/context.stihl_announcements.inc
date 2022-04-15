<?php
/**
 * @file
 * context.stihl_announcements.inc
 */

$api = '2.0.0';

$data = $context = new stdClass();
$context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'stihl_announcements';
$context->description = 'Control announcements view block display.';
$context->tag = 'Announcements';
$context->conditions = array(
  'path' => array(
    'values' => array(
      '<front>' => '<front>',
    ),
  ),
  'user' => array(
    'values' => array(
      'authenticated user' => 'authenticated user',
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'views-banners-block' => array(
        'module' => 'views',
        'delta' => 'banners-block',
        'region' => 'content',
        'weight' => '-10',
      ),
      'views-news_announcements-block' => array(
        'module' => 'views',
        'delta' => 'news_announcements-block',
        'region' => 'content',
        'weight' => '-9',
      ),
    ),
  ),
);
$context->condition_mode = 1;

// Translatables
// Included for use with string extractors like potx.
t('Announcements');
t('Control announcements view block display.');


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'context',
);
