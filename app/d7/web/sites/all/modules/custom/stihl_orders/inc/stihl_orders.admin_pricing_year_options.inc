<?php

/**
 * @file
 * Defines the config page for enabling next year pricing option.
 */

/**
 * Admin configuration form to enable next year pricing option for new orders.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_admin_pricing_year_option_form($form, &$form_state) {

  $form['pricing_options_fieldset'] = [
    '#type' => 'fieldset',
    '#title' => t('Next Year Pricing Option'),
    '#description' => t('Manually enable next year pricing option for new order creation.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  ];
  $form['pricing_options_fieldset']['enable_next_year_pricing_option'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable next year pricing option'),
    '#default_value' => variable_get('enable_next_year_pricing_option', 0),
  ];

  $form['cron_on_fieldset'] = [
    '#type' => 'fieldset',
    '#title' => t('Schedule Next Year Pricing Option On'),
    '#description' => t('This setting is implemented during a scheduled server maintenance cron task.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  ];
  $form['cron_on_fieldset']['cron_next_year_pricing_on'] = [
    '#type' => 'checkbox',
    '#title' => t('Schedule next year pricing on'),
    '#default_value' => variable_get('cron_next_year_pricing_on', 0),
  ];
  $form['cron_on_fieldset']['cron_next_year_pricing_on_month'] = [
    '#type' => 'select',
    '#title' => t('Select month to enable'),
    '#options' => stihl_orders_admin_month_select_options(),
    '#required' => FALSE,
    '#default_value' => variable_get('cron_next_year_pricing_on_month', 0),
  ];

  $form['cron_off_fieldset'] = [
    '#type' => 'fieldset',
    '#title' => t('Schedule Next Year Pricing Option Off'),
    '#description' => t('This setting is implemented during a scheduled server maintenance cron task.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  ];
  $form['cron_off_fieldset']['cron_next_year_pricing_off'] = [
    '#type' => 'checkbox',
    '#title' => t('Schedule next year pricing off'),
    '#default_value' => variable_get('cron_next_year_pricing_off', 0),
  ];
  $form['cron_off_fieldset']['cron_next_year_pricing_off_month'] = [
    '#type' => 'select',
    '#title' => t('Select month to disable'),
    '#options' => stihl_orders_admin_month_select_options(),
    '#required' => FALSE,
    '#default_value' => variable_get('cron_next_year_pricing_off_month', 0),
  ];

  return system_settings_form($form);
}

/**
 * Form validation for settings form.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_admin_pricing_year_option_form_validate($form, &$form_state) {

  if ($form_state['values']['cron_next_year_pricing_on'] == 1 && $form_state['values']['cron_next_year_pricing_on_month'] == 0 ) {
    form_set_error('cron_next_year_pricing_on_month', t('You must provide a month to enable scheduling'));
  }

  if ($form_state['values']['cron_next_year_pricing_off'] == 1 && $form_state['values']['cron_next_year_pricing_off_month'] == 0 ) {
    form_set_error('cron_next_year_pricing_off_month', t('You must provide a month to disable scheduling'));
  }
}

/**
 * Returns month select list options.
 *
 * @return array
 */
function stihl_orders_admin_month_select_options() {
  return [
    t('- Select a Month -'),
    t('January'),
    t('February'),
    t('March'),
    t('April'),
    t('May'),
    t('June'),
    t('July'),
    t('August'),
    t('September'),
    t('October'),
    t('November'),
    t('December'),
  ];
}