<?php

/**
 * @file
 * View handlers for cart selection.
 */

/**
 * Implements hook_views_data_alter().
 */
function commerce_cart_multiple_views_data_alter(&$data) {
  $data['commerce_order']['cart_operations'] = array(
    'field' => array(
      'title' => t('Cart Operations'),
      'help' => t('Add set active and delete options to row.'),
      'handler' => 'commerce_cart_multiple_handler_field_cart_multiple_operations',
    ),
  );
  $data['commerce_order']['order_id']['field']['handler'] = 'commerce_cart_multiple_handler_field_order';
  $data['commerce_order']['order_number']['field']['handler'] = 'commerce_cart_multiple_handler_field_order';
  $data['commerce_order_revision']['order_id']['field']['handler'] = 'commerce_cart_multiple_handler_field_order';
  $data['commerce_order_revision']['order_number']['field']['handler'] = 'commerce_cart_multiple_handler_field_order';
}
