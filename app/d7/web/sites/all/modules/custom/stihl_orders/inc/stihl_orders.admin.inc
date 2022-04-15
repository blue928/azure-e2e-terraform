<?php

/**
 * @file
 * Defines the config page for the Stihl Orders module.
 */

/**
 * Admin configuration form for the Stihl Orders module.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_admin_form($form, &$form_state) {
  $form = array();

  $form['#token'] = FALSE;
  $form['pricing_years'] = array(
    '#title' => t('Pricing Years'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['pricing_years'][] = drupal_get_form('stihl_pricing_years_overview_form', 'stihl_pricing_years');

  $form['online_proofs'] = array(
    '#title' => t('Online Proofs'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['online_proofs']['stihl_orders_proofs_timeout'] = array(
    '#title' => t('Timeout'),
    '#description' => t('Time to wait for proofs before aborting the job.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
    '#default_value' => variable_get('stihl_orders_proofs_timeout', 60),
  );

  $form['online_proofs']['stihl_orders_proofs_logging'] = array(
    '#title' => t('Log Reporting Level'),
    '#description' => t('Determines the severity level at which proofing messages are actually reported to the database log.'),
    '#type' => 'select',
    '#options' => array(
      -1 => t('None'),
      WATCHDOG_WARNING => t('Errors Only'),
      WATCHDOG_INFO => t('Normal'),
      WATCHDOG_DEBUG => t('Debug (All)'),
    ),
    '#default_value' => variable_get('stihl_orders_proofs_logging', WATCHDOG_INFO),
  );

  $form['online_proofs']['stihl_orders_proofs_internal_notifications'] = array(
    '#title' => t('On job failure:'),
    '#required' => FALSE,
    '#type' => 'radios',
    '#options' => array(
      'slack' => 'Post the details in Slack',
      'email' => 'Send an email detailing the failure',
      'none' => 'Do nothing',
    ),
    '#default_value' => variable_get('stihl_orders_proofs_internal_notifications', 'slack'),
  );

  $form['online_proofs']['stihl_orders_proofs_failure_emails'] = array(
    '#title' => t('Failure Email Notifications'),
    '#description' => t('Comma separated list email addresses to notify when online proofing fails.'),
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => variable_get('stihl_orders_proofs_failure_emails', 'dev@knowclassic.com'),
    '#states' => array(
      'visible' => array(
        ':input[name="stihl_orders_proofs_internal_notifications"]' => array('value' => 'email'),
      ),
    ),
  );

  $form['online_proofs']['stihl_orders_proofs_failure_slack_channel'] = array(
    '#title' => t('Slack Channel'),
    '#description' => t('Slack channel to post notifications.'),
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => variable_get('stihl_orders_proofs_failure_slack_channel', '#test-alerts'),
    '#states' => array(
      'visible' => array(
        ':input[name="stihl_orders_proofs_internal_notifications"]' => array('value' => 'slack'),
      ),
    ),
  );

  $form['online_proofs']['generate_proofs'] = array(
    '#title' => t('Generate Proofs'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
  );

  $form['online_proofs']['generate_proofs']['stihl_orders_proofs_order_ids'] = array(
    '#title' => t('Order ID(s)'),
    '#description' => t('Comma separated list of order numbers for which to generate proofs.'),
    '#required' => FALSE,
    '#type' => 'textfield',
  );

  $form['online_proofs']['generate_proofs']['stihl_orders_proofs_notify_rlc'] = array(
    '#title' => t('Notify Red Letter Communications, Inc.'),
    '#description' => t('Enable this option to notify RLCI when proofs are ready for review.'),
    '#required' => FALSE,
    '#type' => 'checkbox',
    '#default_value' => 0,
  );

  $form['online_proofs']['generate_proofs']['stihl_orders_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate Proofs'),
    '#submit' => array('stihl_orders_create_proof_submit'),
  );

  $form['order_messages'] = array(
    '#title' => t('Minimum Order Messages'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['order_messages']['stihl_orders_minimum_order_message_default'] = array(
    '#title' => t('Default Minimum Order Message'),
    '#description' => t('Default message displayed on order submit, confirmation, and review pages in red text.'),
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => variable_get('stihl_orders_minimum_order_message_default', 'A minimum cost of $425 must be reached or a set up fee of $250 will be applied.'),
  );

  $form['order_messages']['stihl_orders_minimum_order_message_pacific_island'] = array(
    '#title' => t('Pacific Island Minimum Order Message'),
    '#description' => t('Message displayed on order submit, confirmation, and review pages in red text for Pacific Island.'),
    '#required' => FALSE,
    '#type' => 'textfield',
    '#default_value' => variable_get('stihl_orders_minimum_order_message_pacific_island', 'A minimum cost of $450 must be reached or a set up fee of $250 will be applied.'),
  );

  return system_settings_form($form);
}

/**
 * Form submit for manually regenerating hang tag proofs.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_create_proof_submit(&$form, &$form_values) {
  $order_ids = $form_values['values']['stihl_orders_proofs_order_ids'];

  // Validate Order ID field contains valid characters (digits, commas, spaces).
  if (preg_match('/[^\d,\s]/', $order_ids)) {
    return drupal_set_message(t('Order ID field may only contain digits, commas, and spaces'), 'error');
  }

  // Generate proofs for the given order IDs.
  if ($order_ids = preg_split('/[,\s]+/', $order_ids, NULL, PREG_SPLIT_NO_EMPTY)) {
    foreach ($order_ids as $order_id) {
      stihl_orders_create_online_proof($order_id, $form_values['values']['stihl_orders_proofs_notify_rlc'] == TRUE);
    }
    drupal_set_message(t('Orders submitted for online proofing: @order_ids', array('@order_ids' => implode(', ', $order_ids))));
  }
}
