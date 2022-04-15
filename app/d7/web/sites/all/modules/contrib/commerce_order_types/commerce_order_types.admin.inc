<?php

/**
 * @file
 * Provides basic order types management functionality.
 */

/**
 * Creation/editing commerce order type form.
 */
function commerce_order_type_form($form, &$form_state, $commerce_order_type, $op = 'edit') {

  if ($op == 'clone') {
    $commerce_order_type->name .= ' (cloned)';
    $commerce_order_type->type = '';
  }

  $form['name'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => isset($commerce_order_type->name) ? $commerce_order_type->name : '',
    '#description' => t('The human-readable name of this commerce order type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($commerce_order_type->type) ? $commerce_order_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $commerce_order_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'commerce_order_types_order_types',
      'source' => array('name'),
    ),
    '#description' => t('A unique machine-readable name for this commerce order type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['help'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($commerce_order_type->help) ? $commerce_order_type->help : '',
    '#description' => t('Description about the commerce order type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Order Type'),
    '#weight' => 40,
  );

  if (!$commerce_order_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete Order Type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('commerce_order_type_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Submit handler for creating/editing commerce_order_type.
 */
function commerce_order_type_form_submit(&$form, &$form_state) {
  $commerce_order_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $commerce_order_type->save();
  commerce_order_configure_order_type($commerce_order_type->type);

  // Redirect user back to list of commerce order types.
  $form_state['redirect'] = 'admin/commerce/config/order-types';
}

/**
 * Submit handler for deletion button for commerce_order_type.
 */
function commerce_order_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/commerce/config/order-types/manage/' . $form_state['commerce_order_type']->type . '/delete';
}
