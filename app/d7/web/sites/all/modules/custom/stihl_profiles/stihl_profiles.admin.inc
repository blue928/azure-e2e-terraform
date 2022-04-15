<?php

/**
 * @file
 * Administrative form and submit handler.
 */

/**
 * Form array of fields for a stihl_profiles entity.
 *
 * @param object $profile
 *   (optional) Stihl profiles entity object.
 *
 * @return array
 *   A form array excluding the form action buttons.
 */
function stihl_profiles_entity_form_fields_array($profile = NULL) {

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Distributor Name'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => isset($profile->name) ? $profile->name : '',
  );
  $form['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone Number'),
    '#default_value' => isset($profile->phone) ? $profile->phone : '',
  );
  $form['api_bd_identifier'] = array(
    '#type' => 'textfield',
    '#title' => t('BDIdentifier'),
    '#default_value' => isset($profile->api_bd_identifier) ? $profile->api_bd_identifier : '',
    '#access' => user_has_role(3),
  );

  // Options fieldset.
  $form['options_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Distributor Options'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );
  $form['options_fieldset']['number_on_tag'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display part numbers on hangtags'),
    '#default_value' => isset($profile->number_on_tag) ? $profile->number_on_tag : 0,
  );
  $form['options_fieldset']['only_vertical_tag'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display vertical hangtags'),
    '#default_value' => isset($profile->only_vertical_tag) ? $profile->only_vertical_tag : 0,
  );
  $form['options_fieldset']['hangtag_without_pricing'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display hangtags without pricing'),
    '#default_value' => isset($profile->hangtag_without_pricing) ? $profile->hangtag_without_pricing : 0,
  );

  // Address fieldset.
  $form['address_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Address Information'),
    '#description' => t('Address Information for this Distributor'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );
  $form['address_fieldset']['address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 1'),
    '#default_value' => isset($profile->address_1) ? $profile->address_1 : '',
  );
  $form['address_fieldset']['address_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 2'),
    '#default_value' => isset($profile->address_2) ? $profile->address_2 : '',
  );
  $form['address_fieldset']['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' => isset($profile->city) ? $profile->city : '',
  );
  $form['address_fieldset']['state'] = array(
    '#type' => 'select',
    '#options' => stihl_core_states_list_array(),
    '#title' => t('State'),
    '#default_value' => isset($profile->state) ? $profile->state : '',
  );
  $form['address_fieldset']['zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip'),
    '#default_value' => isset($profile->zip) ? $profile->zip : '',
  );

  // Shipping fieldset.
  $form['shipping_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Shipping Information'),
    '#description' => t('Shipping Information for this Distributor'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
  );
  $form['shipping_fieldset']['shipping_address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Address 1'),
    '#default_value' => isset($profile->shipping_address_1) ? $profile->shipping_address_1 : '',
  );
  $form['shipping_fieldset']['shipping_address_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Address 2'),
    '#default_value' => isset($profile->shipping_address_2) ? $profile->shipping_address_2 : '',
  );
  $form['shipping_fieldset']['shipping_city'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping City'),
    '#default_value' => isset($profile->shipping_city) ? $profile->shipping_city : '',
  );
  $form['shipping_fieldset']['shipping_state'] = array(
    '#type' => 'select',
    '#options' => stihl_core_states_list_array(),
    '#title' => t('Shipping State'),
    '#default_value' => isset($profile->shipping_state) ? $profile->shipping_state : '',
  );
  $form['shipping_fieldset']['shipping_zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Zip'),
    '#default_value' => isset($profile->shipping_zip) ? $profile->shipping_zip : '',
  );
  $form['shipping_fieldset']['shipping_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Phone Number'),
    '#default_value' => isset($profile->shipping_phone) ? $profile->shipping_phone : '',
  );
  $form['shipping_fieldset']['shipping_method_details'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Shipping Method Details'),
    '#default_value' => isset($profile->shipping_method_details) ? $profile->shipping_method_details : '',
  );

  // Freight carrier fieldset.
  $form['freight_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Freight Carrier Information'),
    '#description' => t('Additional Freight Carrier Account Information'),
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
  );
  $form['freight_fieldset']['shipping_provider_name_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Provider Name 1'),
    '#default_value' => isset($profile->shipping_provider_name_1) ? $profile->shipping_provider_name_1 : '',
  );
  $form['freight_fieldset']['shipping_provider_account_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Provider Account 1'),
    '#default_value' => isset($profile->shipping_provider_account_1) ? $profile->shipping_provider_account_1 : '',
  );
  $form['freight_fieldset']['shipping_provider_name_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Provider Name 2'),
    '#default_value' => isset($profile->shipping_provider_name_2) ? $profile->shipping_provider_name_2 : '',
  );
  $form['freight_fieldset']['shipping_provider_account_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Provider Account 2'),
    '#default_value' => isset($profile->shipping_provider_account_2) ? $profile->shipping_provider_account_2 : '',
  );
  $form['freight_fieldset']['shipping_provider_name_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Provider Name 3'),
    '#default_value' => isset($profile->shipping_provider_name_3) ? $profile->shipping_provider_name_3 : '',
  );
  $form['freight_fieldset']['shipping_provider_account_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Shipping Provider Account 3'),
    '#default_value' => isset($profile->shipping_provider_account_3) ? $profile->shipping_provider_account_3 : '',
  );
  return $form;
}

/**
 * Administrative form for creating and editing profile entities.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_profiles_form($form, &$form_state, $profile = NULL) {

  $form = stihl_profiles_entity_form_fields_array($profile);

  // Attach the entity reference fields to this form.
  field_attach_form('stihl_profiles', $profile, $form, $form_state);

  // Form actions.
  $form['actions'] = array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($profile->id) ? t('Update profile') : t('Save profile'),
    ),
    'cancel' => array(
      '#type' => 'item',
      '#markup' => l(t('Cancel'), STIHL_PROFILES_MANAGE_URI),
    ),
  );
  return $form;
}

/**
 * Form submit handler for profile entities.
 */
function stihl_profiles_form_submit($form, &$form_state) {
  $profile = entity_ui_form_submit_build_entity($form, $form_state);
  $profile->save();
  drupal_set_message(t('Your profile has been saved'));
  $form_state['redirect'] = STIHL_PROFILES_MANAGE_URI;
}
