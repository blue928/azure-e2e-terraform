<?php
/**
 * @file
 * template.php
 */

/**
 * Get color variables from classic_bootstrap theme settings and write css.
 *
 * Implements hook_preprocess_html().
 */
function classic_bootstrap_preprocess_html(&$vars) {
  // If current path is classic_bootstrap settings & user has admin permission.
  $thispage = request_path();
  if ($thispage == 'admin/appearance/settings/classic_bootstrap' && $vars['is_admin']) {
    drupal_add_library('system', 'farbtastic');
  }
}

/**
 * Get color variables from classic_bootstrap theme settings and write css.
 *
 * Implements hook_preprocess_page().
 */
function classic_bootstrap_preprocess_page(&$vars) {
  if (theme_get_setting('logo_bgcolor')) {
    // Get colors from theme settings.
    $vars['logo_bgcolor'] = theme_get_setting('logo_bgcolor');
    $vars['navbar_bgcolor'] = theme_get_setting('navbar_bgcolor');
    $vars['links_color'] = theme_get_setting('links_color');
    // Add colors to the colors.css.php file vars.
    extract($vars, EXTR_SKIP);
    ob_start();
    include path_to_theme() . '/css/colors.css.php';
    $dcss = ob_get_contents();
    ob_end_clean();
    // Adds inline css after style.css
    drupal_add_css($dcss, array(
      'group' => CSS_THEME,
      'type' => 'inline',
      'preprocess' => FALSE,
      'weight' => '9999',
    ));
  }
}

/**
 * Get selected dropdown variables from classic_bootstrap theme settings.
 *
 * Implements hook_js_alter().
 */
function classic_bootstrap_js_alter(&$javascript) {
  // Get vars from theme settings.
  $settings = theme_get_setting('bootstrap_dropdown_options');
  // If selected option is nested dropdowns, use the custom dropdown.js file.
  if ($settings === 'nested') {
    drupal_add_js(drupal_get_path('theme', 'classic_bootstrap') . '/js/dropdown.js');
  }
  // Otherwise, use the dropdown.js file from the bootstrap library.
  elseif ($settings === 'default' || is_null($settings)) {
    drupal_add_js(libraries_get_path('bootstrap') . '/js/dropdown.js');
  }
}
