<?php

/**
 * @file
 * Administrative form and submit handler.
 */

/**
 * Administrative form for creating and editing pricing entities.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_pricing_form($form, &$form_state, $price = NULL) {

  $form['product_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Product name'),
    '#size' => 30,
    '#default_value' => isset($price->product_name) ? $price->product_name : '',
  );
  $form['hangtag_code'] = array(
    '#type' => 'textfield',
    '#title' => t('RLC SKU hangtag code'),
    '#size' => 30,
    '#default_value' => isset($price->hangtag_code) ? $price->hangtag_code : '',
  );
  $form['display_product'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display product'),
    '#default_value' => isset($price->display_product) ? $price->display_product : 0,
  );
  $form['display_price'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display price'),
    '#default_value' => isset($price->display_price) ? $price->display_price : 0,
  );

  // Pricing fieldset.
  $form['pricing_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pricing Information'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );
  $form['pricing_fieldset']['current_year_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Current year price'),
    '#size' => 30,
    '#default_value' => isset($price->current_year_price) ? $price->current_year_price : '',
  );
  $form['pricing_fieldset']['next_year_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Next year price'),
    '#size' => 30,
    '#default_value' => isset($price->next_year_price) ? $price->next_year_price : '',
  );
  $form['pricing_fieldset']['msrp'] = array(
    '#type' => 'textfield',
    '#title' => t('Product MSRP'),
    '#size' => 30,
    '#default_value' => isset($price->msrp) ? $price->msrp : '',
  );

  // Entity reference fieldset.
  $form['reference_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Distributor reference'),
    '#description' => t('Reference ID to distributors'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );
  $form['reference_fieldset']['bd_reference'] = array(
    '#type' => 'textfield',
    '#title' => t('Distributor ID reference'),
    '#size' => 30,
    '#default_value' => isset($price->bd_reference) ? $price->bd_reference : '',
  );

  // Form actions.
  $form['actions'] = array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($price->id) ? t('Update pricing') : t('Save pricing'),
    ),
    'cancel' => array(
      '#type' => 'item',
      '#markup' => l(t('Cancel'), STIHL_PRICING_MANAGE_URI),
    ),
  );
  return $form;
}

/**
 * Form submit handler for profile entities.
 */
function stihl_pricing_form_submit($form, &$form_state) {
  $profile = entity_ui_form_submit_build_entity($form, $form_state);
  $profile->save();
  drupal_set_message(t('Your pricing has been saved'));
  $form_state['redirect'] = STIHL_PRICING_MANAGE_URI;
}
