<?php

/**
 * @file
 * Initiate the Profiler library.
 */

!function_exists('profiler_v2') ? require_once('libraries/profiler/profiler.inc') : FALSE;
profiler_v2('guardr');

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter install profile selection form.
 *
 * We have to call 'system' here because drupal doesn't seem to pick up on
 * the hook ('guardr') at this level in the install process.
 */
function system_form_install_select_profile_form_alter(&$form, $form_state) {
   foreach($form['profile'] as $key => $element) {
     $form['profile'][$key]['#value'] = 'guardr';
   }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function guardr_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}
