<?php

/**
 * @file
 * Administrative form and submit handler.
 */

/**
 * Form array of fields for a stihl_pricing_year entity.
 *
 * @param object $pricing_year
 *   (optional) Stihl pricing year entity object.
 *
 * @return array
 *   A form array excluding the form action buttons.
 */
function stihl_pricing_years_entity_form_fields_array($pricing_year = NULL) {
  $form = array();
  $form['#pricing_year_id'] = $pricing_year->id ?? '';
  $form['pricing_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Order Pricing Year'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => isset($pricing_year->pricing_year) ? $pricing_year->pricing_year : '',
    '#element_validate' => array('element_validate_number'),
    '#ajax' => array(
      'callback' => 'stihl_pricing_years_ajax_callback',
      'wrapper' => 'profile-options',
      'method' => 'replace',
    ),
  );
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => isset($pricing_year->enabled) ? $pricing_year->enabled : 1,
  );
  $form['bulk_one_sided'] = array(
    '#type' => 'textfield',
    '#title' => t('One-Sided Bulk Tags'),
    '#default_value' => isset($pricing_year->bulk_one_sided) ? $pricing_year->bulk_one_sided : '',
    '#element_validate' => array('element_validate_number'),
  );
  $form['kitted_one_sided'] = array(
    '#type' => 'textfield',
    '#title' => t('One-Sided Kitted Tags'),
    '#default_value' => isset($pricing_year->kitted_one_sided) ? $pricing_year->kitted_one_sided : '',
    '#element_validate' => array('element_validate_number'),
  );
  $form['bulk_two_sided'] = array(
    '#type' => 'textfield',
    '#title' => t('Two-Sided Bulk Tags'),
    '#default_value' => isset($pricing_year->bulk_two_sided) ? $pricing_year->bulk_two_sided : '',
    '#element_validate' => array('element_validate_number'),
  );
  $form['kitted_two_sided'] = array(
    '#type' => 'textfield',
    '#title' => t('Two-Sided Kitted Tags'),
    '#default_value' => isset($pricing_year->kitted_two_sided) ? $pricing_year->kitted_two_sided : '',
    '#element_validate' => array('element_validate_number'),
  );
  $form['upc_book'] = array(
    '#type' => 'textfield',
    '#title' => t('UPC Books'),
    '#default_value' => isset($pricing_year->upc_book) ? $pricing_year->upc_book : '',
    '#element_validate' => array('element_validate_number'),
  );
  $form['branch_specific_pricing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Branch Specific Pricing'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['branch_specific_pricing']['default_pricing'] = array(
    '#type' => 'checkbox',
    '#title' => t('Default'),
    '#default_value' => isset($pricing_year->default_pricing) ? $pricing_year->default_pricing : 1,
    '#description' => t('Enable to make this the default pricing for this year. Disable to specify branches to which this pricing applies.'),
  );
  $form['branch_specific_pricing']['customization_wrapper'] = array(
    '#type' => 'container',
    '#states' => array(
      'invisible' => array(
        ':input[name="default_pricing"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['branch_specific_pricing']['customization_wrapper']['details'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('This is used to distinguish between multiple Pricing Years for the same year.'),
    '#size' => 60,
    '#default_value' => isset($pricing_year->details) ? str_replace('Default', '', $pricing_year->details) : '',
    '#states' => array(
      'optional' => array(
        ':input[name="default_pricing"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['branch_specific_pricing']['customization_wrapper']['profiles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Associated Branch Profiles'),
    '#multiple' => TRUE,
    '#options' => array(),
    '#default_value' => stihl_pricing_years_profiles_default($pricing_year),
    '#prefix' => '<div id="profile-options">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Administrative form for creating and editing pricing_year entities.
 */
function stihl_pricing_years_form($form, &$form_state, $pricing_year = NULL) {

  $form = stihl_pricing_years_entity_form_fields_array($pricing_year);
  $form['branch_specific_pricing']['customization_wrapper']['profiles']['#options'] = stihl_pricing_years_profiles_options($form, $form_state);

  // Form actions.
  $form['actions'] = array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($pricing_year->id) ? t('Update Pricing Year') : t('Save Pricing Year'),
    ),
    'cancel' => array(
      '#type' => 'item',
      '#markup' => l(t('Cancel'), STIHL_PRICING_YEARS_MANAGE_URI),
    ),
  );
  return $form;
}

/**
 * Form validation for pricing_year entities.
 */
function stihl_pricing_years_form_validate($form, &$form_state) {
  // Create reference to the form values.
  $values =& $form_state['values'];
  $pricing_year =& $values['pricing_year'];

  // Format the pricing_year as YYYY.
  if ($short_year = DateTime::createFromFormat('y', $pricing_year)) {
    $pricing_year = $short_year->format('Y');
  }

  // If this is not a default pricing year, make the details field required.
  if ($values['default_pricing'] == FALSE && empty($values['details'])) {
    form_set_error('details', t('Description field is required.'));
  }

  // There can only be one default_pricing associated with a pricing_year, so
  // if default_pricing is enabled for this year, we need to make sure a default
  // hasn't previously been created for the same year.
  if ($values['default_pricing'] && $values['enabled']) {
    $pricing_year_id = $form['#pricing_year_id'];
    $default_year = stihl_pricing_years_get_default_pricing_year($pricing_year);

    if ($default_year && $default_year != $pricing_year_id) {
      $message = t('A default pricing year already exists for !pricing_year', array(
        '!pricing_year' => l($pricing_year, STIHL_PRICING_YEARS_MANAGE_URI . '/manage/' . $default_year),
      ));
      form_set_error('default_pricing', $message);
    }
    $values['details'] = 'Default';
  }
}

/**
 * Form submit handler for pricing_year entities.
 */
function stihl_pricing_years_form_submit($form, &$form_state) {
  $pricing_year = entity_ui_form_submit_build_entity($form, $form_state);
  $pricing_year->save();

  // If default pricing is enabled, remove any profiles that may be associated
  // with this pricing year. This way we aren't unnecessarily adding records to
  // the field_data_associated_pricing table in the db and we can add new BD's
  // without first needing to associate them with a "default" pricing year.
  if ($pricing_year->default_pricing) {
    $pricing_year->profiles = array();
  }

  // Load all of the BD Profiles and update their associate_pricing field.
  foreach (entity_load('stihl_profiles', FALSE) as $profile) {
    if (!stihl_pricing_years_update_associated_profile($profile, $pricing_year)) {
      $message = t('Unable to associate pricing year (!pricing_year) with !profile.', array(
        '!pricing_year' => $pricing_year->label(),
        '!profile' => l($profile->name, STIHL_PROFILES_MANAGE_URI . '/manage/' . $profile->id),
      ));
      drupal_set_message(filter_xss($message), 'warning');
    }
  }

  drupal_set_message(t('@pricing_year Pricing Year has been saved', array('@pricing_year' => $pricing_year->label())));
  $form_state['redirect'] = STIHL_PRICING_YEARS_MANAGE_URI;
}

/**
 * AJAX callback for updating the profile options.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_pricing_years_ajax_callback($form, &$form_state) {
  return $form['branch_specific_pricing']['customization_wrapper']['profiles'];
}

/**
 * Gets the default Pricing Year for a specified year.
 *
 * @param string $year
 *   The year for which to search default pricing.
 *
 * @return mixed
 *   Returns the entity id of the default Pricing Year for the specified year;
 *   FALSE otherwise.
 */
function stihl_pricing_years_get_default_pricing_year($year) {
  $sql = 'SELECT id FROM {stihl_pricing_year} WHERE pricing_year = :year AND default_pricing = 1 AND enabled = 1';
  $result = db_query($sql, array(':year' => $year))->fetchField();
  return $result;
}

/**
 * Creates options for the Branch Profile select list.
 *
 * @return array
 *   Returns an array of Stihl Profiles keyed by their entity ID.
 */
function stihl_pricing_years_profiles_options($form, &$form_state) {
  $year = $form_state['values']['pricing_year'] ?? $form['pricing_year']['#default_value'];
  // Make sure we've got profile options to return.
  if (isset($form_state['#profile_options']) == FALSE) {
    stihl_pricing_years_set_profile_options($form, $form_state);
  }
  // Pull the options for the profiles out of the $form_state array.
  $profiles = $form_state['#profile_options'] ?? array();
  $associated_profiles = $form_state['#associated_profile_options'] ?? array();

  // If there are profiles that have already been associated with a Pricing Year
  // with the same value as the Pricing Year being edited, filter those profiles
  // out of the options.
  if ($year && isset($associated_profiles[$year])) {
    $associated_profile_ids = $associated_profiles[$year];
    $profiles = array_filter($profiles, function ($id) use ($associated_profile_ids) {
      return !in_array($id, $associated_profile_ids);
    }, ARRAY_FILTER_USE_KEY);
  }

  return $profiles;
}

/**
 * Sets the valid profile options for this Pricing Year.
 *
 * We're adding the profile options to the form_state array so that we can avoid
 * making multiple calls to the database when the pricing_year field is updated.
 */
function stihl_pricing_years_set_profile_options($form, &$form_state) {
  // Query the database for all profiles.
  $query = db_select('stihl_profile', 'profile')
    ->fields('profile', array('id', 'name'))
    ->fields('py', array('pricing_year', 'id'));
  // Join the profiles table with the associated_pricing to indicate which
  // profiles are already associated with a pricing year. (Using 'LEFT JOIN' so
  // that profiles that aren't associated with a pricing year are returned too).
  $query->leftJoin('field_data_associated_pricing', 'ap', 'ap.entity_id = profile.id');
  // Join the pricing year table to the associated_pricing so that we can key
  // off the pricing_year value (YYYY) rather than the Pricing Year's id.
  $query->leftJoin('stihl_pricing_year', 'py', 'py.id = ap.associated_pricing_target_id');
  $result = $query->execute();

  // Create an array to hold all profiles.
  $profiles = array();
  // Create an array to hold profiles that have already been associated with
  // a Pricing Year. This array will be used to filter $profiles.
  $associated_pricing_years = array();

  // Loop through the result of the query and sort the profiles.
  foreach ($result->fetchAll() as $profile) {
    $pricing_year = $profile->pricing_year;

    // If a pricing_year is defined, and its ID isn't the value of the current
    // Pricing Year being edited, add it to the $associated_pricing_years array.
    if (!is_null($pricing_year) && $form['#pricing_year_id'] != $profile->py_id) {
      if (!isset($associated_pricing_years[$pricing_year])) {
        $associated_pricing_years[$pricing_year] = array();
      }
      $associated_pricing_years[$pricing_year][] = $profile->id;
    }

    // Add the profile to the $profiles array as well.
    $profiles[$profile->id] = $profile->name;
  }

  // Add the values to the $form_state array so we can reference them later
  // without the need for the database query.
  $form_state['#profile_options'] = $profiles;
  $form_state['#associated_profile_options'] = $associated_pricing_years;
}

/**
 * Determines the default value of the Branch Profile select list.
 *
 * @param string $pricing_year
 *   (optional) Stihl pricing year entity object.
 *
 * @return array
 *   Array of Stihl Profile IDs associated with a given Pricing Year.
 */
function stihl_pricing_years_profiles_default($pricing_year = NULL) {
  if (isset($pricing_year->id)) {
    $query = 'SELECT entity_id FROM {field_data_associated_pricing} WHERE associated_pricing_target_id = :id';
    $selected_profiles = db_query($query, array(':id' => $pricing_year->id))->fetchCol();
  }
  return $selected_profiles ?? array();
}
