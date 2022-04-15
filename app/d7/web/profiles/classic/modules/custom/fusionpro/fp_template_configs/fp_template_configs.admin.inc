<?php

/**
 * @file
 * Administrative form and submit handler.
 */

/**
 * Form array of fields for a fp_template_configs entity.
 *
 * @param object $config
 *   (optional) FP Template configs entity object.
 *
 * @return array
 *   A form array excluding the form action buttons.
 */
function fp_template_configs_entity_form_fields_array($config = NULL) {
  $form = array();
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Template Configuration Name'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => isset($config->name) ? $config->name : '',
  );
  $form['description'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Description'),
    '#default_value' => isset($config->description) ? $config->description : '',
  );
  $form['cache'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable output caching'),
    '#default_value' => isset($config->cache) ? $config->cache : 0,
    '#description' => t('When enabled, a new output file will only be created when the data differs from the existing file.'),
  );

  // Template configuration fieldset.
  $form['template_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Template Configuration'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );
  $form['template_fieldset']['template'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Template name'),
    '#required' => TRUE,
    '#default_value' => isset($config->template) ? $config->template : '',
  );
  $form['template_fieldset']['file_type'] = array(
    '#type' => 'select',
    '#title' => t('Output file type'),
    '#options' => array(
      'pdf' => 'PDF',
      'jpg' => 'JPG',
    ),
    '#default_value' => isset($config->file_type) ? $config->file_type : 'pdf',
  );
  $form['template_fieldset']['data_format'] = array(
    '#type' => 'select',
    '#title' => t('Template data format'),
    '#options' => array(
      'xml' => 'XML',
      'csv' => 'CSV',
    ),
    '#default_value' => isset($config->data_format) ? $config->data_format : 'xml',
  );
  $form['template_fieldset']['cfg_file'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('CFG file'),
    '#default_value' => isset($config->cfg_file) ? $config->cfg_file : '',
    '#description' => t('Optionally specify a cfg file to use. Path is relative to the template.'),
  );
  return $form;
}

/**
 * Administrative form for creating and editing template config entities.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function fp_template_configs_form($form, &$form_state, $config = NULL) {

  $form = fp_template_configs_entity_form_fields_array($config);

  // Form actions.
  $form['actions'] = array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($config->id) ? t('Update') : t('Save'),
    ),
    'cancel' => array(
      '#type' => 'item',
      '#markup' => l(t('Cancel'), FP_TEMPLATE_CONFIGS_MANAGE_URI),
    ),
  );
  return $form;
}

/**
 * Form submit handler for template config entities.
 */
function fp_template_configs_form_submit($form, &$form_state) {
  $config = entity_ui_form_submit_build_entity($form, $form_state);
  $config->save();
  drupal_set_message(t('@config has been saved.', array('@config' => $config->name)));
  $form_state['redirect'] = FP_TEMPLATE_CONFIGS_MANAGE_URI;
}
