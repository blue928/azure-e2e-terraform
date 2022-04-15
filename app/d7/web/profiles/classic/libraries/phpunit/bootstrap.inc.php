<?php

/**
 * @file
 * Bootstrap file for PHPUnit testing.
 *
 * Original concept from From:
 * http://devblog.more-onion.com/content/writing-unit-tests-drupal-7
 * https://gist.github.com/torotil/3003998
 */

// Start from the current path.
$path = '.';

$site_dir = NULL;
$dpl_dir = NULL;

// Verify if the current path is within a Drupal install and if the current
// Drupal instance is configured with a proper settings.php file.
while ($path != '/') {
  if (file_exists($path . '/settings.php')) {
    $site_dir = $path;
  }
  if (file_exists($path . '/index.php') && file_exists($path . '/includes/bootstrap.inc')) {
    $dpl_dir = $path;
    break;
  }
  $path = dirname($path);
}

if (!$dpl_dir) {
  echo "No drupal directory found in or above current working directory. Aborting. \n";
  exit(1);
}
if (!$site_dir) {
  $site_dir = $dpl_dir . '/sites/default';
  if (!file_exists($site_dir . '/settings.php')) {
    echo "No configured site found. Aborting.\n";
    exit(1);
  }
}


// Setup the environment for bootstrapping Drupal.
$_SERVER['HTTP_HOST'] = basename($site_dir);
$_SERVER['REMOTE_ADDR'] = '127.0.0.1';
define('DRUPAL_ROOT', $dpl_dir);
set_include_path($dpl_dir . PATH_SEPARATOR . get_include_path());

// Bootstrap Drupal.
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
