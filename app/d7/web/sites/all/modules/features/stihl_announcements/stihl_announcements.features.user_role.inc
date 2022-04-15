<?php
/**
 * @file
 * stihl_announcements.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function stihl_announcements_user_default_roles() {
  $roles = array();

  // Exported role: RLadmin.
  $roles['RLadmin'] = array(
    'name' => 'RLadmin',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
