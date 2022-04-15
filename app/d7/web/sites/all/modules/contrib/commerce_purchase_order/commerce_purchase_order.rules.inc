<?php

/**
 * Implements hook_rules_action_info().
 */
function commerce_purchase_order_rules_action_info() {
  $actions = array();

  $actions['commerce_purchase_order_issue_po'] = array(
    'label' => t('charge an order with a purchase order'),
    'group' => t('Commerce Purchase Order'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'charge' => array(
        'type' => 'commerce_price',
        'label' => t('Charge'),
        'description' => t('The charge amount and currency. If not provided, then the order balance will be used.'),
        'optional' => TRUE,
      ),
      'po_number' => array(
        'type' => 'text',
        'label' => t('Purchase Order number'),
        'description' => t('If not provided, current timestamp and order ID will be used'),
        'optional' => TRUE,
      ),
      'forced_instance_id' => array(
        'type' => 'text',
        'label' => t('Payment method instance id'),
        'options list' => 'commerce_purchase_order_rules_payment_instance_charge_options_list',
        'optional' => TRUE,
      ),
    ),
    'provides' => array(
      'issue_po_response' => array(
        'type' => 'commerce_purchase_order_issue_po_response',
        'label' => t('issue PO Response'),
        'save' => FALSE,
      ),
    ),
    'callbacks' => array(
      'execute' => 'commerce_purchase_order_rules_issue_po_action',
    ),
  );

  return $actions;
}

function commerce_purchase_order_rules_issue_po_action($order, $charge = NULL, $po_number = NULL, $forced_instance_id = NULL) {
  $response = array(
    'status' => FALSE,
    'code' => 'insufficient',
    'message' => '',
    'message_variables' => array(),
  );

  // Exit if the order does not have order_id.
  if (empty($order->order_id)) {
    $response['message'] = 'Order ID is not provided.';
    return $response;
  }
  $response['message_variables'] += array(
    '@order_id' => $order->order_id,
  );

  // Exit if no user associated with the order.
  if (empty($order->uid)) {
    $response['message'] = 'Order owner not provided for order @order_id.';
    return $response;
  }
  $response['message_variables'] += array(
    '@uid' => $order->uid,
  );

  // Set charge to order balance if none provided.
  if (empty($charge)) {
    $charge = commerce_payment_order_balance($order);
  }

  // Exit if no charge.
  if (empty($charge) || empty($charge['amount']) || empty($charge['currency_code'])) {
    $response['message'] = 'Charge amount not provided for order @order_id.';
    return $response;
  }
  $response['message_variables'] += array(
    '@charge' => commerce_currency_format($charge['amount'], $charge['currency_code']),
  );

  // Default PO number to timestamp-order_id.
  if (empty($po_number)) {
    $po_number = time() . '-' . $order->order_id;
  }

  // Load payment method.
  $payment_method = commerce_payment_method_load('commerce_purchase_order');

  // Set forced instance ID
  if(!empty($forced_instance_id)) {
    $order->data['payment_method'] = $forced_instance_id;
    $response['message_variables'] += array(
      '@instance_id' => $forced_instance_id,
    );
    $payment_method['instance_id'] = $forced_instance_id;
  }

  // Void function! Assume success.
  commerce_purchase_order_transaction($payment_method, $order, $charge, $po_number);
  $response['status'] = TRUE;
  $response['code'] = 'success';
  $response['message'] = 'The payment method  @method instance (@instance_id) was successful for order @order_id, user @uid, charge amount @charge.';

  return array('charge_po_response' => $response);
}

/**
 * Options list for payment method instances that provide a charge callback
 */
function commerce_purchase_order_rules_payment_instance_charge_options_list() {
  $options = array('' => t('- None -'));
  $payment_method_instances = commerce_purchase_order_payment_method_instances();

  foreach ($payment_method_instances as $instance_id) {
    list($method_id_part, $rule_name) = explode('|', $instance_id);
    $options[$instance_id] = $rule_name;
  }

  return $options;
}
