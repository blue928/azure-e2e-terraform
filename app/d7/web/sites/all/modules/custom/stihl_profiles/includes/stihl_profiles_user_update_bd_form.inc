<?php

/**
 * @file
 * Custom form for updating a BD location information.
 */

/**
 * Custom form allowing a BD user to edit their BD information.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_profiles_user_update_bd_form($form, &$form_state) {

  // Return a message if user does not have a BD referenced in their account.
  if (!$user_bd = stihl_core_get_bd_id($GLOBALS['user']->uid)) {

    return array(
      'message' => array(
        '#markup' => t('Your account does not have an assigned distribution branch. Please contact support.'),
        '#prefix' => '<div class="alert alert-warning">',
        '#suffix' => '</div>',
      ),
      'support' => array(
        '#markup' => l(t('Contact Support'), '/content/support',
          array(
            'attributes' => array('class' => array('btn', 'btn-success')),
          )
        ),
        '#prefix' => '<div class="btn">',
        '#suffix' => '</div>',
      ),
    );
  }

  $bd_profile = stihl_profiles_load($user_bd);

  // Access the entity form fields array.
  module_load_include('inc', 'stihl_profiles', 'stihl_profiles.admin');

  $form = stihl_profiles_entity_form_fields_array($bd_profile);

  // The BD user should not have access to the distributor options.
  unset($form['options_fieldset']);

  // Pass the BD profile object to the form submit handler.
  $form['#bd_profile'] = $bd_profile;

  $form['shipping_fieldset']['#collapsed'] = FALSE;
  $form['shipping_fieldset']['#attributes']['id'] = 'shipping-address';

  $form['actions'] = array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Update Profile'),
    ),
    'cancel' => array(
      '#type' => 'item',
      '#markup' => l(t('Cancel'), '/orders/list',
        array(
          'attributes' => array('class' => array('btn', 'btn-default')),
        )
      ),
      '#prefix' => '<div class="btn">',
      '#suffix' => '</div>',
    ),
  );

  return $form;
}

/**
 * Submit handler for a BD user updating their distributor (BD) information.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_profiles_user_update_bd_form_submit($form, &$form_state) {

  // Remove the form_state value fields that are not saved to the entity.
  $excluded_fields = array(
    'submit',
    'form_build_id',
    'form_token',
    'form_id',
    'op',
    'bd_id',
  );
  $form_fields = array_filter(array_keys($form_state['values']), function ($field) use ($excluded_fields) {
    return !in_array($field, $excluded_fields);
  });

  $bd_profile = $form['#bd_profile'];

  foreach ($form_fields as $field) {
    $bd_profile->$field = $form_state['values'][$field];
  }

  entity_save('stihl_profiles', $bd_profile);

  $message = 'BD profile: @bd was updated by: @user';
  $replacements = array('@bd' => $bd_profile->name, '@user' => $GLOBALS['user']->name);
  watchdog('stihl_profiles', $message, $replacements, WATCHDOG_INFO);

  drupal_set_message(t('Distributor profile updated successfully'));
  $form_state['redirect'] = '/orders/list';
}
