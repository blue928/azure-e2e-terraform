<?php

/**
 * @file
 * Admin setting form and its handlers.
 */

/**
 * Admin form constructor.
 */
function commerce_order_reminder_settings_form($form, &$form_state) {
  $defaults = variable_get('commerce_order_reminder_settings');
  $form['#prefix'] = '<div id="commerce-order-reminder-settings-form-wrapper">';
  $form['#suffix'] = '</div>';

  $form['commerce_order_reminder_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable email reminders'),
    '#default_value' => !empty($defaults['commerce_order_reminder_status']) ? $defaults['commerce_order_reminder_status'] : 0,
    '#description' => t('Check this to enable reminders and enable the rest of the fields'),
  );

  $form['commerce_order_reminder_send_if_empty'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send email reminders even if the order cart is empty'),
    '#default_value' => !empty($defaults['commerce_order_reminder_send_if_empty']) ? $defaults['commerce_order_reminder_send_if_empty'] : 0,
    '#description' => t('Check to send emails about open carts with no products.'),
  );

  $available_order_statuses = commerce_order_statuses();
  $status_options = array();
  foreach ($available_order_statuses as $status_machine_name => $status) {
    $status_options[$status_machine_name] = $status['title'];
  }
  $form['commerce_order_reminder_send_order_status'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Order status filter'),
    '#description' => t('Reminders will be sent only for orders that have any of the checked statuses.'),
    '#options' => $status_options,
    '#default_value' => !empty($defaults['commerce_order_reminder_send_order_status']) ? $defaults['commerce_order_reminder_send_order_status'] : array(),
  );

  $form['commerce_order_reminder_first_reminder'] = array(
    '#required' => TRUE,
    '#description' => t('The minimum age of open carts orders for reminders to be sent about.'),
    '#type' => 'select',
    '#options' => array(
      '900' => t('15 min ago'),
      '21600' => t('6 hours ago'),
      '43200' => t('12 hours ago'),
      '86400' => t('1 day ago'),
      '172800' => t('2 days ago'),
      '259200' => t('3 days ago'),
      '432000' => t('5 days ago'),
      '604800' => t('A week ago'),
      '30' => t('30 seconds TEST ONLY'),
      '300' => t('5 min TEST ONLY'),
    ),
    '#title' => t('How long to wait to notify customer of an open cart?'),
    '#default_value' => !empty($defaults['commerce_order_reminder_first_reminder']) ? $defaults['commerce_order_reminder_first_reminder'] : 900,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['commerce_order_reminder_last_reminder'] = array(
    '#required' => TRUE,
    '#description' => t('The owners with open carts older than this option will not be reminded. (note this is currently a check against a process sending unliited spam)'),
    '#type' => 'select',
    '#options' => array(
      '86400' => t('One day ago'),
      '172800' => t('2 days ago'),
      '259200' => t('3 days ago'),
      '432000' => t('5 days ago'),
      '604800' => t('A week ago'),
      '2419200' => t('A month'),
    ),
    '#title' => t('This setting will stop sending reminders after a certain time period'),
    '#default_value' => !empty($defaults['commerce_order_reminder_last_reminder']) ? $defaults['commerce_order_reminder_last_reminder'] : 2419200,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['commerce_order_reminder_period'] = array(
    '#required' => TRUE,
    '#description' => t('Choose how often reminder emails should be sent'),
    '#type' => 'select',
    '#options' => array(
      '1800' => t('Every 30 min - TEST'),
      '43200' => t('Every 12 hours'),
      '86400' => t('Every day'),
      '172800' => t('Every 2 days'),
      '259200' => t('Every 3 days'),
      '432000' => t('Every 5 days'),
      '604800' => t('Every week'),
    ),
    '#title' => t('Reminders frequency'),
    '#default_value' => !empty($defaults['commerce_order_reminder_period']) ? $defaults['commerce_order_reminder_period'] : 1800,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['commerce_order_reminder_user_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Send reminders to users of following roles:'),
    '#options' => user_roles(),
    '#default_value' => !empty($defaults['commerce_order_reminder_user_roles']) ? $defaults['commerce_order_reminder_user_roles'] : FALSE,
  );

  $form['reminder_from'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sender information'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['reminder_from']['commerce_order_reminder_from_name'] = array(
    '#type' => 'textfield',
    '#title' => t("Remind on behalf of"),
    '#decription' => t("Enter the name to be displayed in 'from' line"),
    '#required' => TRUE,
    '#default_value' => $defaults['commerce_order_reminder_from_name'],
  );

  $form['reminder_from']['commerce_order_reminder_from_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Remind from Email'),
    '#description' => t("Enter the email address reminders will be sent from"),
    '#required' => TRUE,
    '#default_value' => $defaults['commerce_order_reminder_from_email'],
  );

  $number_emails = !empty($form_state['values']['commerce_order_reminder_number']) ? $form_state['values']['commerce_order_reminder_number'] : $defaults['commerce_order_reminder_number'];

  $form['commerce_order_reminder_number'] = array(
    '#required' => TRUE,
    '#default_value' => $number_emails,
    '#description' => t('Enter the number of reminders that will be sent. The default is 1.'),
    '#type' => 'textfield',
    '#title' => t('Number of reminders'),
    '#element_validate' => array('element_validate_integer_positive'),
    '#ajax' => array(
      'callback' => 'commerce_order_reminder_settings_ajax_callback',
      'wrapper' => 'commerce-order-reminder-settings-form-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $form['commerce_order_reminder_bcc'] = array(
    '#type' => 'textfield',
    '#title' => t('Send a copy of all reminder emails to:'),
    '#default_value' => $defaults['commerce_order_reminder_bcc'],
    '#description' => t('All email reminders will also be sent as a BCC to the provided e-mail address. This may be useful to make sure that the module is correctly configured.'),
  );

  $form['commerce_order_reminder_email_texts'] = array(
    '#weight' => '3',
    '#title' => t('Reminder emails'),
    '#type' => 'fieldset',
    '#collapsible' => '1',
    '#tree' => TRUE,
    '#description' => t('Emails do not currently support tokens. Working on that'),
  );

  // Reminder emails subject and bodies.
  for ($i = 0; $i < $number_emails; $i++) {
    $number = $i + 1;
    $form['commerce_order_reminder_email_texts'][$number] = array(
      '#weight' => $i,
      '#title' => t('Email #@number', array('@number' => $number)),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
    );

    $form['commerce_order_reminder_email_texts'][$number]['commerce_order_reminder_subject'] = array(
      '#type' => 'textfield',
      '#title' => t('Email subject'),
      '#default_value' => isset($defaults['commerce_order_reminder_email_texts'][$number]['commerce_order_reminder_subject']) ? $defaults['commerce_order_reminder_email_texts'][$number]['commerce_order_reminder_subject'] : '',
      '#weight' => $i,
      '#required' => TRUE,
    );

    $form['commerce_order_reminder_email_texts'][$number]['commerce_order_reminder_body'] = array(
      '#description' => t('The text of the email #@number. Use [commerce-order] token to refer fields of the order.', array('@number' => $number)),
      '#type' => 'textarea',
      '#rows' => 10,
      '#title' => t('Email body'),
      '#default_value' => isset($defaults['commerce_order_reminder_email_texts'][$number]['commerce_order_reminder_body']) ? $defaults['commerce_order_reminder_email_texts'][$number]['commerce_order_reminder_body'] : '',
      '#weight' => $number,
      '#required' => TRUE,
    );

    if (module_exists('token')) {
      $form['commerce_order_reminder_email_texts'][$number]['tokens'] = array(
        '#theme' => 'token_tree',
        '#token_types' => array('commerce-order', 'commerce-line-item', 'user'),
        '#dialog' => TRUE,
        '#weight' => 3,
      );
    }
  }

  // Test Email Fieldset.
  $form['test_email'] = array(
    '#weight' => '4',
    '#title' => t('Send test email'),
    '#type' => 'fieldset',
    '#collapsible' => '1',
    '#collapsed' => '1',
  );

  $form['test_email']['commerce_order_reminder_send_test_email'] = array(
    '#weight' => '0',
    '#type' => 'checkbox',
    '#title' => t('Send test email'),
    '#default_value' => 0,
  );

  $form['test_email']['commerce_order_reminder_test_email_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Email for test messages'),
    '#description' => t('This will send a test email. Your latest order data will be used. Latest order must have expiring items to work correctly'),
    '#default_value' => isset($defaults['commerce_order_reminder_test_email_address']) ? $defaults['commerce_order_reminder_test_email_address'] : variable_get('commerce_order_reminder_test_email_address', variable_get('site_mail')),
    '#weight' => '1',
    '#states' => array(
      'enabled' => array(
        'input[name="commerce_order_reminder_send_test_email"]' => array(
          'checked' => TRUE,
        ),
      ),
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t("Save settings"),
    '#weight' => 228,
  );
$a=1;
  return $form;
}

/**
 * Validation handler.
 *
 * Check if email fields have correct values.
 */
function commerce_order_reminder_settings_form_validate($form, &$form_state) {
  $email_fields = array(
    'commerce_order_reminder_from_email',
    'commerce_order_reminder_test_email_address',
    'commerce_order_reminder_bcc',
  );
  foreach ($email_fields as $email) {
    if (!empty($form_state['values'][$email]) && !valid_email_address($form_state['values'][$email])) {
      form_set_error($email, t('Incorrect email address: @address', array('@address' => $form_state['values'][$email])));
    }
  }

  // Check if period is not more than last reminder.
  if ($form_state['values']['commerce_order_reminder_period'] > $form_state['values']['commerce_order_reminder_last_reminder']) {
    form_set_error('commerce_order_reminder_period', t('The reminder periodicity cannot be more than the last reminder. In such case, no reminders would be sent.'));
  };
  $a=1;
}

/**
 * Submit handler. Rebuild the form. Filter input. Save values.
 */
function commerce_order_reminder_settings_form_submit($form, &$form_state) {
  $form['rebuild'] = TRUE;
  if ($form_state['triggering_element']['#id'] === 'edit-submit') {
    // Save values.
    variable_set('commerce_order_reminder_settings', $form_state['values']);
    drupal_set_message(t('Settings have been successfully saved.'));
    // Send test emails.
    if ($form_state['values']['commerce_order_reminder_send_test_email']) {
      module_load_include('inc', 'commerce_order_reminder', 'commerce_order_reminder');
      commerce_order_reminder_send_test_email();
    }
    // Check if total time for all reminders to sent exceeds the max age of
    // orders to remind of.
    $period = $form_state['values']['commerce_order_reminder_period'];
    $number = $form_state['values']['commerce_order_reminder_number'];
    $max_age = $form_state['values']['commerce_order_reminder_last_reminder'];
    if ($period * $number > $max_age) {
      $will_be_sent = floor($max_age / $period);
      drupal_set_message(t('Even though you have set up @number notifications, only @will_be_sent of them will be sent. The time needed to sent all notifications exceeds the maximum order age. You might want to consider changing these settings.', array('!number' => $number, '!will_be_sent' => $will_be_sent)), 'warning');
    }
  }
}

/**
 * Ajax callback. Simply rebuild the form.
 */
function commerce_order_reminder_settings_ajax_callback($form) {
  return $form;
}
