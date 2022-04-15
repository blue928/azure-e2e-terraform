<?php
/**
 * Initiate the Profiler library
 */
!function_exists('profiler_v2') ? require_once('libraries/profiler/profiler.inc') : FALSE;
profiler_v2('classic');

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function classic_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_batch_alter().
 *
 * This is implemented for the sole purpose of skipping the 7201 version of the
 * ldap_servers schema when running database updates.
 */
function classic_batch_alter(&$batch) {
  if (isset($batch['sets'])) {
    foreach ($batch['sets'] as &$set) {
      if (!isset($set['operations'])) {
        continue;
      }

      foreach ($set['operations'] as $index => $operation) {
        list($function, $args) = $operation;
        // When running database updates, the callback function will either be
        // 'drush_update_do_one' (if fired from drush updb) or 'update_do_one'
        // (if fired from update.php).
        if (($function == 'drush_update_do_one' || $function == 'update_do_one')
          // If we're running updates, the first element in the $args array is
          // the module name and the second element is the schema version. If
          // we're attempting to update the ldap_servers to 7201, skip it.
          && $args[0] == 'ldap_servers' && $args[1] == 7201) {

          // Remove the 7201 update for the ldap_servers module since this will
          // be handled by the classic_update_7000 in classic.install.
          unset($set['operations'][$index]);
          // Adjust the set's counts so that the update won't hang.
          $set['total']--;
          $set['count']--;
        }
      }
    }
  }
}
