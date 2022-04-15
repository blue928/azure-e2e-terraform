<?php
/**
 * @file
 * stihl_announcements.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stihl_announcements_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
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
  $export['stihl_announcements'] = $context;

  return $export;
}
