<?php

/**
 * @file
 * Defines the administrative form for the pricing API settings.
 */

/**
 * Admin configuration form for the pricing API settings.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_pricing_admin_pricing_api_form($form, &$form_state) {

  // API settings.
  $form['enable_api_fieldset'] = [
    '#type' => 'fieldset',
    '#title' => t('Pricing API Settings'),
    '#description' => t('This API calls the Red Letter pricing system and updates the pricing in this application'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  ];
  $form['enable_api_fieldset']['stihl_pricing_api_enable'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable the pricing API system'),
    '#description' => t('This should be disabled on development and testing environments'),
    '#default_value' => variable_get('stihl_pricing_api_enable', 0),
  ];
  $form['enable_api_fieldset']['stihl_pricing_api_endpoint'] = [
    '#type' => 'textfield',
    '#title' => t('API URL'),
    '#description' => t('The full URL to the API endpoint including the protocol "https://"'),
    '#default_value' => variable_get('stihl_pricing_api_endpoint', NULL),
  ];
  $form['enable_api_fieldset']['stihl_pricing_api_authorization'] = [
    '#type' => 'textfield',
    '#title' => t('API Authorization'),
    '#default_value' => variable_get('stihl_pricing_api_authorization', 'MOD0-31CR-QVEL'),
  ];
  $form['enable_api_fieldset']['stihl_pricing_api_timeout'] = [
    '#type' => 'textfield',
    '#title' => t('Timeout'),
    '#description' => t('The maximum number of seconds to allow the cURL function to execute.'),
    '#default_value' => variable_get('stihl_pricing_api_timeout', 60),
  ];
  $form['enable_api_fieldset']['stihl_pricing_api_max_redirect'] = [
    '#type' => 'textfield',
    '#title' => t('Maximum allowed redirections'),
    '#description' => t('The maximum amount of HTTP redirections to follow.'),
    '#default_value' => variable_get('stihl_pricing_api_max_redirect', 1),
  ];

  // Cron settings.
  $form['cron_fieldset'] = [
    '#type' => 'fieldset',
    '#title' => t('Cron Settings'),
    '#description' => t('Configure the settings for the cron task associated with the pricing API'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];
  $form['cron_fieldset']['stihl_pricing_api_cron_enable_timeframe'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable Time Window'),
    '#description' => t('Enabling this option restricts cron runs to a start/stop timeframe.'),
    '#default_value' => variable_get('stihl_pricing_api_cron_enable_timeframe', 0),
  ];
  $form['cron_fieldset']['stihl_pricing_api_cron_start_time'] = [
    '#type' => 'select',
    '#title' => t('Start time'),
    '#options' => _stihl_pricing_get_hours_options(),
    '#default_value' => variable_get('stihl_pricing_api_cron_start_time', ''),
    '#states' => [
      'visible' => [
        ':input[name="stihl_pricing_api_cron_enable_timeframe"]' => ['checked' => TRUE],
      ],
    ],
  ];
  $form['cron_fieldset']['stihl_pricing_api_cron_end_time'] = [
    '#type' => 'select',
    '#title' => t('Stop time'),
    '#options' => _stihl_pricing_get_hours_options(),
    '#default_value' => variable_get('stihl_pricing_api_cron_end_time', ''),
    '#states' => [
      'visible' => [
        ':input[name="stihl_pricing_api_cron_enable_timeframe"]' => ['checked' => TRUE],
      ],
    ],
  ];

  // Logging settings.
  $form['log_fieldset'] = [
    '#type' => 'fieldset',
    '#title' => t('Log Settings'),
    '#description' => t('Select the logging desired for the pricing API'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];
  $form['log_fieldset']['stihl_pricing_api_log_success'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable logging of successful price updates'),
    '#description' => t('This will log a message for every successful price update'),
    '#default_value' => variable_get('stihl_pricing_api_log_success', 1),
  ];
  $form['log_fieldset']['stihl_pricing_api_log_failure'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable logging of API endpoint failure'),
    '#description' => t('This will log a message when the endpoint fails'),
    '#default_value' => variable_get('stihl_pricing_api_log_failure', 1),
  ];

  $form['stihl_pricing_api_debug'] = [
    '#type' => 'submit',
    '#value' => t('Test / Debug'),
    '#submit' => ['stihl_pricing_api_debug'],
    '#states' => [
      'disabled' => [
        ':input[name="stihl_pricing_api_enable"]' => ['checked' => FALSE],
      ],
    ],
  ];

  return system_settings_form($form);
}

/**
 * Form validation for the API settings form.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_pricing_admin_pricing_api_form_validate($form, &$form_state) {

  // Make sure an API URL is provided.
  if ($form_state['values']['stihl_pricing_api_enable'] && !$form_state['values']['stihl_pricing_api_endpoint']) {
    form_set_error('stihl_pricing_api_url', t('Provide an API URL if enabling the API system.'));
  }

  // Make sure start/stop times are different.
  if ($form_state['values']['stihl_pricing_api_cron_enable_timeframe']
    && $form_state['values']['stihl_pricing_api_cron_start_time'] == $form_state['values']['stihl_pricing_api_cron_end_time']) {
    form_set_error('stihl_pricing_api_cron_end_time', t('Start/Stop times must differ.'));
  }
}

/**
 * Function for debugging the pricing API.
 */
function stihl_pricing_api_debug() {
  $api = stihl_pricing_api_init();
  $api->debug();
}

/**
 * Helper function to return time options.
 *
 * @return array
 *   An array of times (in 15 minute intervals) for the select list.
 */
function _stihl_pricing_get_hours_options() {
  return [
    '00:00' => '12:00 AM',
    '00:15' => '12:15 AM',
    '00:30' => '12:30 AM',
    '00:45' => '12:45 AM',
    '01:00' => '1:00 AM',
    '01:15' => '1:15 AM',
    '01:30' => '1:30 AM',
    '01:45' => '1:45 AM',
    '02:00' => '2:00 AM',
    '02:15' => '2:15 AM',
    '02:30' => '2:30 AM',
    '02:45' => '2:45 AM',
    '03:00' => '3:00 AM',
    '03:15' => '3:15 AM',
    '03:30' => '3:30 AM',
    '03:45' => '3:45 AM',
    '04:00' => '4:00 AM',
    '04:15' => '4:15 AM',
    '04:30' => '4:30 AM',
    '04:45' => '4:45 AM',
    '05:00' => '5:00 AM',
    '05:15' => '5:15 AM',
    '05:30' => '5:30 AM',
    '05:45' => '5:45 AM',
    '06:00' => '6:00 AM',
    '06:15' => '6:15 AM',
    '06:30' => '6:30 AM',
    '06:45' => '6:45 AM',
    '07:00' => '7:00 AM',
    '07:15' => '7:15 AM',
    '07:30' => '7:30 AM',
    '07:45' => '7:45 AM',
    '08:00' => '8:00 AM',
    '08:15' => '8:15 AM',
    '08:30' => '8:30 AM',
    '08:45' => '8:45 AM',
    '09:00' => '9:00 AM',
    '09:15' => '9:15 AM',
    '09:30' => '9:30 AM',
    '09:45' => '9:45 AM',
    '10:00' => '10:00 AM',
    '10:15' => '10:15 AM',
    '10:30' => '10:30 AM',
    '10:45' => '10:45 AM',
    '11:00' => '11:00 AM',
    '11:15' => '11:15 AM',
    '11:30' => '11:30 AM',
    '11:45' => '11:45 AM',
    '12:00' => '12:00 PM',
    '12:15' => '12:15 PM',
    '12:30' => '12:30 PM',
    '12:45' => '12:45 PM',
    '13:00' => '1:00 PM',
    '13:15' => '1:15 PM',
    '13:30' => '1:30 PM',
    '13:45' => '1:45 PM',
    '14:00' => '2:00 PM',
    '14:15' => '2:15 PM',
    '14:30' => '2:30 PM',
    '14:45' => '2:45 PM',
    '15:00' => '3:00 PM',
    '15:15' => '3:15 PM',
    '15:30' => '3:30 PM',
    '15:45' => '3:45 PM',
    '16:00' => '4:00 PM',
    '16:15' => '4:15 PM',
    '16:30' => '4:30 PM',
    '16:45' => '4:45 PM',
    '17:00' => '5:00 PM',
    '17:15' => '5:15 PM',
    '17:30' => '5:30 PM',
    '17:45' => '5:45 PM',
    '18:00' => '6:00 PM',
    '18:15' => '6:15 PM',
    '18:30' => '6:30 PM',
    '18:45' => '6:45 PM',
    '19:00' => '7:00 PM',
    '19:15' => '7:15 PM',
    '19:30' => '7:30 PM',
    '19:45' => '7:45 PM',
    '20:00' => '8:00 PM',
    '20:15' => '8:15 PM',
    '20:30' => '8:30 PM',
    '20:45' => '8:45 PM',
    '21:00' => '9:00 PM',
    '21:15' => '9:15 PM',
    '21:30' => '9:30 PM',
    '21:45' => '9:45 PM',
    '22:00' => '10:00 PM',
    '22:15' => '10:15 PM',
    '22:30' => '10:30 PM',
    '22:45' => '10:45 PM',
    '23:00' => '11:00 PM',
    '23:15' => '11:15 PM',
    '23:30' => '11:30 PM',
    '23:45' => '11:45 PM',
  ];
}
