<?php
/**
 * @file
 * commerce_sp.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commerce_sp_user_default_permissions() {
  $permissions = array();

  // Exported permission: create field_commerce_sp_validity.
  $permissions['create field_commerce_sp_validity'] = array(
    'name' => 'create field_commerce_sp_validity',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_commerce_sp_validity.
  $permissions['edit field_commerce_sp_validity'] = array(
    'name' => 'edit field_commerce_sp_validity',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_commerce_sp_validity.
  $permissions['edit own field_commerce_sp_validity'] = array(
    'name' => 'edit own field_commerce_sp_validity',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_commerce_sp_validity.
  $permissions['view field_commerce_sp_validity'] = array(
    'name' => 'view field_commerce_sp_validity',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_commerce_sp_validity.
  $permissions['view own field_commerce_sp_validity'] = array(
    'name' => 'view own field_commerce_sp_validity',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  return $permissions;
}
