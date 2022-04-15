<?php

/**
 * @file
 * Contains the logic around Step 5, the order confirmation page.
 */

/**
 * Form builder callback for the Step 5, order confirmation page.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_confirm_order_form($form, $form_state, $order_id) {
  module_load_include('inc', 'stihl_orders', 'inc/stihl_orders.summary');
  $summary = new StihlOrdersSummary($order_id);
  $form = $summary->render();

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Return to Order History'),
    '#attributes' => array(
      'class' => array('btn-success'),
    ),
  );

  return $form;
}

/**
 * Submit handler for the order confirmation form.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_confirm_order_form_submit($form, &$form_state) {
  $form_state['redirect'] = '/orders/list';
}
