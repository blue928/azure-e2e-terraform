<?php

/**
 * @file
 * Form logic for reviewing an existing order.
 */

/**
 * Landing page for order review and approval.
 *
 * @param int $order_id
 *   The order id from the url.
 *
 * @return array
 *   The form.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_review_form($form, &$form_state, $order_id) {

  $order = entity_metadata_wrapper('commerce_order', $order_id);

  // Attempt to use the order data supplied by the user in the url.
  try {
    $order_submitter = entity_metadata_wrapper('user', $order->uid->value());

    // Current workflow information.
    $field_name = workflow_get_field_name($order->value(), $order->type());
    $current_sid = workflow_node_current_state($order->value(), $order->type(), $field_name);

    // Allow the transition data to be available in the submit handler.
    $form['#transition_data'] = array(
      'field_name' => $field_name,
      'current_sid' => $current_sid,
      'approver_id' => $GLOBALS['user']->uid,
      'order_id' => $order_id,
    );

    // Order overview fieldset.
    $form['overview'] = array(
      '#type' => 'fieldset',
      '#title' => t('Order Overview'),
      'container' => array(
        '#type' => 'container',
        '#prefix' => '<div class="container-fluid">',
        '#suffix' => '</div>',
        'order_title' => array(
          '#markup' => $order->field_order_title->value(),
          '#prefix' => '<h3>',
          '#suffix' => '</h3>',
        ),
        'row1' => array(
          '#type' => 'markup',
          '#prefix' => '<div class="row">',
          '#suffix' => '</div>',
          'order_number' => array(
            '#markup' => l($order->order_number->value(), '/orders/edit/' . $order_id),
            '#prefix' => '<div class="col-sm-6">Order number: ',
            '#suffix' => '</div>',
          ),
          'pricing_year' => array(
            '#markup' => $order->field_pricing_year_reference->pricing_year->value(),
            '#prefix' => '<div class="col-sm-6">Pricing year: ',
            '#suffix' => '</div>',
          ),
        ),
        'row2' => array(
          '#type' => 'markup',
          '#prefix' => '<div class="row">',
          '#suffix' => '</div>',
          'order_submitter' => array(
            '#markup' => $order_submitter->name->value(),
            '#prefix' => '<div class="col-sm-6">Submitted by: ',
            '#suffix' => '</div>',
          ),
          'order_created' => array(
            '#markup' => format_date($order->created->value(), 'short'),
            '#prefix' => '<div class="col-sm-6">Submitted date: ',
            '#suffix' => '</div>',
          ),
        ),
      ),
    );

    // Order summary fieldset.
    module_load_include('inc', 'stihl_orders', 'inc/stihl_orders.summary');
    $summary = new StihlOrdersSummary($order_id);

    $form['summary_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Order Summary'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['summary_fieldset']['summary'] = $summary->render();

    // Workflow transition form fieldset.
    $form['approval'] = array(
      '#type' => 'fieldset',
      '#title' => t('Order Approval'),
      'container' => array(
        '#type' => 'container',
        '#prefix' => '<div class="container-fluid">',
        '#suffix' => '</div>',
        'options' => array(
          '#type' => 'markup',
          '#prefix' => '<div class="row">',
          '#suffix' => '</div>',
          'state_options' => array(
            '#type' => 'radios',
            '#title' => t('Approval status'),
            '#description' => t('Approve or decline this order and optionally supply a comment.'),
            '#default_value' => $current_sid,
            '#prefix' => '<div class="col-sm-12">',
            '#suffix' => '</div>',
            '#options' => stihl_orders_review_approval_options(),
          ),
        ),
        'order_notes' => array(
          '#type' => 'textarea',
          '#title' => t('Approval Comment'),
          '#rows' => 3,
          '#default_value' => $order->field_order_approval_comment->value(),
        ),
      ),
    );

    // Form action buttons.
    $form['form_actions'] = array(
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Update Order'),
        '#attributes' => array(
          'class' => array('btn-success'),
        ),
      ),
      'cancel' => array(
        '#type' => 'markup',
        '#markup' => l(t('Back to orders'), '/orders/list'),
        '#prefix' => '<button class="btn btn-default">',
        '#suffix' => '</button>',
      ),
    );

    return $form;
  }
  catch (Exception $e) {

    // If a user manipulates the url, or an order does not exist, catch the
    // exception.
    // Log this event in Watchdog.
    $message = 'The order approval page failed to load for order attempt: !id and the error message is: !error';
    $replace = array('!id' => $order_id, '!error' => $e->getMessage());
    watchdog('stihl_orders', $message, $replace, WATCHDOG_ERROR);

    // Set a user friendly message and redirect to order list page.
    drupal_set_message(t('Order was not found, please select an order from the list'), 'warning');
    drupal_goto('/orders/list');
  }
}

/**
 * Form submit handler for updating workflow transition from approval page.
 */
function stihl_orders_review_form_submit($form, $form_state) {

  // Variable reference to improve readability.
  $form_values =& $form_state['values'];
  $transition_data =& $form['#transition_data'];

  $order = entity_metadata_wrapper('commerce_order', $transition_data['order_id']);

  // Create a transition and execute it.
  $transition = new WorkflowTransition();
  $transition->setValues(
    $order->type(),
    $order->value(),
    $transition_data['field_name'],
    $transition_data['current_sid'],
    $form_values['state_options'],
    $transition_data['approver_id'],
    REQUEST_TIME,
    $form_values['order_notes']
  );
  workflow_execute_transition($order->type(), $order->value(), $transition_data['field_name'], $transition);

  // Save order approval comment to order entity.
  $order->field_order_approval_comment = $form_values['order_notes'];
  commerce_order_save($order->value());

  // The two transitions that could happen here would be from 'ready for review'
  // to 'approved' or 'ready for review' to 'incomplete'. Send a notification
  // depending on which transition they select.
  $old_state = workflow_get_sid_label($transition->old_sid);
  $new_state = workflow_get_sid_label($transition->new_sid);
  if ($old_state == 'ready for review' && $new_state == 'approved' || $new_state == 'incomplete') {
    $mail_keys = array('order_' . $new_state);

    // If the order is approved, we additionally want to send an order summary
    // email to Classic's internal Stihl team.
    if ($new_state == 'approved') {
      $mail_keys[] = 'order_summary';
    }

    // Send as many emails as required by the workflow state.
    foreach ($mail_keys as $mail_key) {
      stihl_orders_send_order_status_change_email($order, $mail_key);
    }
  }

  // If this order is set as incomplete, unapproved by a RLadmin, then the
  // existing approval csv, print files, & online proofs should be removed so
  // when the order is re-submitted a new file can be generated.
  if ($form_values['state_options'] == 33) {
    stihl_orders_delete_online_proof($transition_data['order_id']);
    file_unmanaged_delete(STIHL_ORDERS_APPROVAL_URI . $transition_data['order_id'] . '.csv');
    if (is_dir($print_files = STIHL_ORDERS_PRINT_URI . $transition_data['order_id'])) {
      file_unmanaged_delete_recursive($print_files);
    }
  }

  // If this order is approved, the proofs can be removed from the site.
  if ($form_values['state_options'] == 32) {
    stihl_orders_delete_online_proof($transition_data['order_id']);
  }

  // Set a message to the user and redirect to orders list page.
  drupal_set_message(t('Order has been updated, and notifications will be sent.'), 'status');
  drupal_goto('/orders/list');
}

/**
 * Helper function for creating the approval state options.
 *
 * @return array
 *   Keyed array of workflow state options.
 *   State ID (sid) => State name.
 */
function stihl_orders_review_approval_options() {
  $states = stihl_orders_get_states_by_workflow();
  $options = array(
    $states['incomplete'] => t('Incomplete'),
    $states['ready for review'] => t('Ready for Review'),
    $states['approved'] => t('Approved'),
  );
  return $options;
}
