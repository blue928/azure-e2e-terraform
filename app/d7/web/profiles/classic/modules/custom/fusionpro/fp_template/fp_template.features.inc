<?php
// $Id$
/**
 * @file
 * Provides Fusion Pro templating node feature integration.
 */

/**
 * FP Template are a **faux-exportable** component.
 */

/**
 * Implements hook_features_export().
 */
function fp_template_features_export($data, &$export, $module_name = '') {
  // fontyourface_default_fonts integration is provided by Features.
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['fp_template'] = 'fp_template';
  foreach (_fp_template_get_configurations() as $fp_template) {
    if (in_array($fp_template->name, $data)) {
      $export['features']['fp_template'][$fp_template->name] = $fp_template->name;
    }
  }
  return $export;
}

/**
 * Implements hook_features_export_render().
 */
function fp_template_features_export_render($module, $data) {
  $code = array();
  $fp_templates = _fp_template_get_configurations();
  foreach ($data as $name) {
    foreach ($fp_templates as $fp_template) {
      if ($fp_template->name == $name) {
        if ($this_template = _fp_template_get_configuration($fp_template->name)) {
          unset($this_template->wid);
          $code[$name] = $this_template;
        }
      }
    }
  }
  $code = "  return " . features_var_export($code, '  ') . ";";
  return array('fp_template_features_default_fp_template' => $code);
}

/**
 * Implements hook_features_export_options().
 */
function fp_template_features_export_options() {
  $workflows = array();
  foreach (_fp_template_get_configurations() as $fp_template) {
    $fp_templates[$fp_template->name] = $fp_template->name;
  }
  return $fp_templates;
}

/**
 * Implements hook_features_revert().
 */
function fp_template_features_revert($module) {
  $saved_fp_templates = module_invoke($module, 'fp_template_features_default_fp_template');
  foreach ($saved_fp_templates as $key => $fp_template) {
    $saved = _fp_template_save_configuration($fp_template);
  }
}

/**
 * Implements hook_features_export_rebuild().
 */
function fp_template_features_export_rebuild($module) {
  fp_template_features_revert($module);
}
