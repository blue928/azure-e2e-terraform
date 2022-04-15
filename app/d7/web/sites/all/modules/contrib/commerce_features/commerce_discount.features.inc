<?php

/**
 * @file
 * Features integration on behalf of Commerce Discount.
 */

/**
 * Implements hook_features_export_options().
 *
 * Features component callback.
 */
function commerce_discount_features_export_options() {
  return entity_features_get_controller('commerce_discount')->export_options();
}

/**
 * Implements hook_features_export().
 *
 * Features component callback.
 */
function commerce_discount_features_export($data, &$export, $module_name = '') {
  // Add required dependencies.
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['entity'] = 'entity';
  $export['dependencies']['commerce_features'] = 'commerce_features';

  return entity_features_get_controller('commerce_discount')->export($data, $export, $module_name);
}

/**
 * Implements hook_features_export_render().
 *
 * Features component callback.
 */
function commerce_discount_features_export_render($module, $data, $export = NULL) {
  return entity_features_get_controller('commerce_discount')->export_render($module, $data, $export);
}

/**
 * Implements hook_features_revert().
 *
 * Features component callback.
 */
function commerce_discount_features_revert($module = NULL) {
  if (module_hook($module, 'default_commerce_discount')) {
    $defaults = module_invoke($module, 'default_commerce_discount');
    $names = array_keys($defaults);
    $existing = entity_load_multiple_by_name('commerce_discount', $names);

    foreach ($defaults as $name => $discount) {
      if (isset($existing[$name])) {
        $discount->discount_id = $existing[$name]->discount_id;
        $discount->is_new = FALSE;
      }
      entity_save('commerce_discount', $discount);
    }
  }
}

/**
 * Implements hook_features_rebuild().
 */
function commerce_discount_features_rebuild($module) {
  return commerce_discount_features_revert($module);
}
