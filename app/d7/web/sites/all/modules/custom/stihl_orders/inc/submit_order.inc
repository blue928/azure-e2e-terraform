<?php

/**
 * @file
 * Include file for functionality around showing order confirmation.
 */

/**
 * Custom function to render order confirmation page.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_submit_order_form($form, &$form_state, $order_id) {
  module_load_include('inc', 'stihl_orders', 'inc/stihl_orders.summary');
  $summary = new StihlOrdersSummary($order_id);

  $form['#order_id'] = $summary->orderWrapper->getIdentifier();

  // If a recent product migration removed products from this order,
  // display a user message containing the SKUs removed.
  $form['migrate_message'] = stihl_orders_render_product_removed_message($summary->orderWrapper);

  $form['summary'] = $summary->render();

  $author_uid = $summary->orderWrapper->uid->value() ?: NULL;
  $form['shipping_details'] = stihl_orders_render_bd_shipping_information($author_uid);

  // Form submit button(s) are conditional based on order status.
  $incomplete = $summary->orderWrapper->field_order_status->value() == stihl_orders_get_states_by_workflow()['incomplete'];

  // Only order status "incomplete" can be edited.
  if ($incomplete) {
    $form['add_hang_tags'] = array(
      '#type' => 'submit',
      '#value' => t('Add Hang Tags'),
      '#attributes' => array(
        'class' => array('btn-default'),
      ),
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit Order'),
      '#attributes' => array(
        'class' => array('btn-success'),
      ),
    );
  }

  return $form;
}

/**
 * Submit handler for the submitted order form.
 */
function _stihl_orders_submit_order_form_submit($form, &$form_state) {

  // If order already in submitted status, redirect to order list page,
  // otherwise submit the order.
  if ($form_state['triggering_element']['#id'] == 'edit-submit') {
    // The user is 'finishing' the order, so place order into 'submitted' state.
    if (_stihl_orders_update_order_workflow_transition($form['#order_id'], 'submitted')) {
      $order_wrapper = entity_metadata_wrapper('commerce_order', $form['#order_id']);

      // Send a status change notification email to the Stihl users and send an
      // order summary notification to Classic's internal Stihl team.
      foreach (array('order_submitted', 'order_summary') as $key) {
        stihl_orders_send_order_status_change_email($order_wrapper, $key);
      }

      // If a product migration added a product removal message, we remove it
      // when the order is submitted because the message is not applicable
      // after submission and not desired if the order is cloned.
      $order_wrapper->field_order_migrate_message->set(NULL);
      $order_wrapper->save();

      $message = t('Thank you for submitting your order. After it has been
      reviewed, it will be printed and shipped to the <a href="@profile">address
      on file</a> unless otherwise noted. Upon shipment, you will receive email
      notification with tracking information. Please <a href="@support">contact
      us</a> with any questions or concerns.', array(
        '@profile' => '/branch-distributor-profile/#shipping-address',
        '@support' => url('content/support'),
      ));

      drupal_set_message($message, 'status');
    }
    else {
      // User cannot 'submit' an order based on their role/permission.
      drupal_set_message(t('Cannot submit order. Please contact customer support.'), 'error');
    }
  }

  $destination = ($form_state['triggering_element']['#id'] == 'edit-add-hang-tags') ? '/orders/add-hang-tags/' . $form['#order_id'] : '/orders/confirmation/' . $form['#order_id'];

  $form_state['redirect'] = $destination;
}

/**
 * Render Branch Distributor (BD) shipping information.
 *
 * By default will get BD for currently logged in user.
 * Request a specific user's BD by passing their user ID.
 *
 * @param int $uid
 *   (optional) An ID for a specific user.
 *
 * @return array
 *   A render array.
 */
function stihl_orders_render_bd_shipping_information($uid = NULL) {

  if (!$bd_id = stihl_core_get_bd_id($uid)) {
    return [
      '#type' => 'markup',
      '#prefix' => '<div class="well">',
      '#suffix' => '</div>',
      'message' => [
        '#prefix' => '<p>',
        '#markup' => ' No shipping address information available',
        '#suffix' => '</p>',
      ],
    ];
  }

  $bd = stihl_profiles_load($bd_id);

  $render['shipping_details'] = [
    '#type' => 'markup',
    '#prefix' => '<div class="well">',
    '#suffix' => '</div>',
    'label' => [
      '#prefix' => '<h4>',
      '#markup' => 'Shipping Information',
      '#suffix' => '</h4>',
    ],
  ];
  $render['shipping_details']['bd_name'] = [
    '#prefix' => '<p>',
    '#markup' => "<b>$bd->name</b>",
    '#suffix' => '<br/>',
  ];
  $render['shipping_details']['street_address_1'] = [
    '#markup' => $bd->shipping_address_1,
    '#suffix' => '<br/>',
  ];
  if ($bd->shipping_address_2) {
    $render['shipping_details']['street_address_2'] = [
      '#markup' => $bd->shipping_address_2,
      '#suffix' => '<br/>',
    ];
  }
  $render['shipping_details']['address'] = [
    '#markup' => "$bd->shipping_city, $bd->shipping_state $bd->shipping_zip<br/>$bd->shipping_phone",
    '#suffix' => '</p>',
  ];
  if ($bd->shipping_method_details) {
    $render['shipping_details']['method_details'] = [
      '#prefix' => '<p>',
      '#markup' => "<b>Shipping Notes:</b><br/>$bd->shipping_method_details",
      '#suffix' => '</p>',
    ];
  }
  return $render;
}
