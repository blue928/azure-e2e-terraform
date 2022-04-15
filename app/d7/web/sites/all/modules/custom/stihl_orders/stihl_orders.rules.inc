<?php

/**
 * @file
 * Rules functions for Stihl orders.
 */

/**
 * Implements hook_rules_condition_info().
 */
function stihl_orders_rules_condition_info() {

  // Callback to determine if order is in transition to approved state.
  $conditions['stihl_orders_workflow_is_being_submitted'] = array(
    'label' => t('Workflow state is transitioning to submitted'),
    'group' => t('Stihl Orders'),
    'parameter' => array(
      'order_id' => array(
        'type' => 'integer',
        'label' => t('Order ID'),
      ),
    ),
  );
  return $conditions;
}

/**
 * Implements hook_rules_action_info().
 */
function stihl_orders_rules_action_info() {

  // Callback to export order csv file to hotfolder.
  $actions['stihl_orders_create_online_proof'] = array(
    'label' => t('Create online proofs for order'),
    'group' => t('Stihl Orders'),
    'parameter' => array(
      'order_id' => array(
        'type' => 'integer',
        'label' => t('Order ID'),
      ),
    ),
  );
  return $actions;
}

/**
 * Rules condition function to determine if an order is being submitted.
 *
 * @param int $order_id
 *   The order id of the order to check.
 *
 * @return bool
 *   True if the order has a Workflow transition of being submitted.
 */
function stihl_orders_workflow_is_being_submitted($order_id) {
  $order_is_being_submitted = FALSE;
  $order_entity = commerce_order_load($order_id);
  // In new versions of the workflow module, `workflow_transitions` isn't set
  // unless the workflow state changed, so we should ensure it's set first.
  if ($transition = $order_entity->workflow_transitions['field_order_status'] ?? NULL) {
    // Get old and new state ids to determine state transition.
    $old_sid = $transition->old_sid;
    $new_sid = $transition->new_sid;
    $state_names = stihl_orders_get_states_by_workflow('Order Status');

    $order_is_being_submitted = $state_names['incomplete'] == $old_sid && $state_names['submitted'] == $new_sid;
  }
  return $order_is_being_submitted;
}
