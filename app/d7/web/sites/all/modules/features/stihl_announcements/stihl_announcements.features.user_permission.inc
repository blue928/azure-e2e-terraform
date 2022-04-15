<?php
/**
 * @file
 * stihl_announcements.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stihl_announcements_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create banner_image content'.
  $permissions['create banner_image content'] = array(
    'name' => 'create banner_image content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any banner_image content'.
  $permissions['delete any banner_image content'] = array(
    'name' => 'delete any banner_image content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own banner_image content'.
  $permissions['delete own banner_image content'] = array(
    'name' => 'delete own banner_image content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any banner_image content'.
  $permissions['edit any banner_image content'] = array(
    'name' => 'edit any banner_image content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own banner_image content'.
  $permissions['edit own banner_image content'] = array(
    'name' => 'edit own banner_image content',
    'roles' => array(
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
