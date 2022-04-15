<?php

/**
 * @file
 * stihl_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function stihl_users_user_default_roles() {
  $roles = array();

  // Exported role: POP Admin.
  $roles['POP Admin'] = array(
    'name' => 'POP Admin',
    'weight' => 8,
  );

  // Exported role: POP User.
  $roles['POP User'] = array(
    'name' => 'POP User',
    'weight' => 9,
  );

  return $roles;
}
