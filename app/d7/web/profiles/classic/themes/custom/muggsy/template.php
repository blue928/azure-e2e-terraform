<?php


/**
 * Implementation of template_preprocess_page().
 */

function muggsy_preprocess_html(&$vars) {
  //Add a variable html.tpl for modernizr.
  //This can't be done with drupal_add_js()
  //and have it in the header and footer
  $path = base_path() . drupal_get_path('theme', 'muggsy');
  $vars['modernizr'] = '<script src="' . $path . '/js/libs/modernizr-2.5.3.js' . '" type="text/javascript"></script>';

  //Set viewport to device-width for mobile
  $meta_viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width',
    ),
  );
  drupal_add_html_head($meta_viewport, 'meta_viewport');

}

/**
 * Implementation of hook_css_alter().
 */


function muggsy_css_alter(&$css) {
  if (isset($css[drupal_get_path('theme', 'boron') . '/css/layout.css'])) {
    unset($css[drupal_get_path('theme', 'boron') . '/css/layout.css']);
  }
}