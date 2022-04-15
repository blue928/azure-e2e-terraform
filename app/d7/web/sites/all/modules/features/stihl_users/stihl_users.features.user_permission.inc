<?php

/**
 * @file
 * stihl_users.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function stihl_users_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer commerce_order entities'.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      'POP Admin' => 'POP Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'administer order types'.
  $permissions['administer order types'] = array(
    'name' => 'administer order types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order_types',
  );

  // Exported permission: 'configure order settings'.
  $permissions['configure order settings'] = array(
    'name' => 'configure order settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities'.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      'POP User' => 'POP User',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle commerce_order'.
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      'BDuser' => 'BDuser',
      'POP User' => 'POP User',
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle hangtags'.
  $permissions['create commerce_order entities of bundle hangtags'] = array(
    'name' => 'create commerce_order entities of bundle hangtags',
    'roles' => array(),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle pop'.
  $permissions['create commerce_order entities of bundle pop'] = array(
    'name' => 'create commerce_order entities of bundle pop',
    'roles' => array(
      'POP Admin' => 'POP Admin',
      'POP User' => 'POP User',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create field_bd_reference'.
  $permissions['create field_bd_reference'] = array(
    'name' => 'create field_bd_reference',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit any commerce_order entity'.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      'POP Admin' => 'POP Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle commerce_order'.
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'BDuser' => 'BDuser',
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle hangtags'.
  $permissions['edit any commerce_order entity of bundle hangtags'] = array(
    'name' => 'edit any commerce_order entity of bundle hangtags',
    'roles' => array(),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle pop'.
  $permissions['edit any commerce_order entity of bundle pop'] = array(
    'name' => 'edit any commerce_order entity of bundle pop',
    'roles' => array(
      'POP Admin' => 'POP Admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit field_bd_reference'.
  $permissions['edit field_bd_reference'] = array(
    'name' => 'edit field_bd_reference',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own commerce_order entities'.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      'POP Admin' => 'POP Admin',
      'POP User' => 'POP User',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle commerce_order'.
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'BDuser' => 'BDuser',
      'POP Admin' => 'POP Admin',
      'POP User' => 'POP User',
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle hangtags'.
  $permissions['edit own commerce_order entities of bundle hangtags'] = array(
    'name' => 'edit own commerce_order entities of bundle hangtags',
    'roles' => array(),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle pop'.
  $permissions['edit own commerce_order entities of bundle pop'] = array(
    'name' => 'edit own commerce_order entities of bundle pop',
    'roles' => array(
      'POP Admin' => 'POP Admin',
      'POP User' => 'POP User',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own field_bd_reference'.
  $permissions['edit own field_bd_reference'] = array(
    'name' => 'edit own field_bd_reference',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view any commerce_order entity'.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      'POP Admin' => 'POP Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle commerce_order'.
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'BDuser' => 'BDuser',
      'POP Admin' => 'POP Admin',
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle hangtags'.
  $permissions['view any commerce_order entity of bundle hangtags'] = array(
    'name' => 'view any commerce_order entity of bundle hangtags',
    'roles' => array(),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle pop'.
  $permissions['view any commerce_order entity of bundle pop'] = array(
    'name' => 'view any commerce_order entity of bundle pop',
    'roles' => array(
      'POP Admin' => 'POP Admin',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view field_bd_reference'.
  $permissions['view field_bd_reference'] = array(
    'name' => 'view field_bd_reference',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own commerce_order entities'.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      'POP Admin' => 'POP Admin',
      'POP User' => 'POP User',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle commerce_order'.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'BDuser' => 'BDuser',
      'POP Admin' => 'POP Admin',
      'POP User' => 'POP User',
      'RLadmin' => 'RLadmin',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle hangtags'.
  $permissions['view own commerce_order entities of bundle hangtags'] = array(
    'name' => 'view own commerce_order entities of bundle hangtags',
    'roles' => array(),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle pop'.
  $permissions['view own commerce_order entities of bundle pop'] = array(
    'name' => 'view own commerce_order entities of bundle pop',
    'roles' => array(
      'POP Admin' => 'POP Admin',
      'POP User' => 'POP User',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own field_bd_reference'.
  $permissions['view own field_bd_reference'] = array(
    'name' => 'view own field_bd_reference',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
