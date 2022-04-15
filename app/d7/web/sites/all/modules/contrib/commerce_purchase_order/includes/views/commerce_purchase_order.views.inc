<?php

/**
 * Export Drupal Commerce Purchase Order to Views.
 */

/**
 * Implements hook_views_data()
 */
function commerce_purchase_order_views_data() {
  $data['commerce_purchase_order']['table']['group'] = t('Purchase order');
  $data['commerce_purchase_order']['table']['join'] = array(
    'commerce_order' => array(
      'left_field' => 'order_id',
      'field' => 'order_id',
    ),
    'commerce_payment_transaction' => array(
      'left_field' => 'transaction_id',
      'field' => 'transaction_id',
    ),
  );
  $data['commerce_purchase_order']['po_number'] = array(
    'title' => t('PO number'),
    'help' => t('The PO number associated with an order.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  return $data;
}
