<?php

/**
 * @file
 * Include file for functionality around creating a new order.
 */

/**
 * Custom form for creating or editing an order.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_new_order_form($form, &$form_state, $order_id = NULL) {

$a = 1;

  // If updating existing order, order id will be from URL parameter.
  $order = $order_id ? entity_metadata_wrapper('commerce_order', $order_id) : NULL;

  $a = 1;

  $form['wrapper'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'col-lg-12',
      ),
    ),
  );

  $form['wrapper']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Order Title'),
    '#required' => TRUE,
    '#default_value' => $order ? $order->field_order_title->value() : NULL,
  );

  $form['wrapper']['pricing_year'] = array(
    '#type' => 'select',
    '#title' => t('Pricing Year'),
    '#options' => stihl_orders_pricing_year_select_options(),
    '#required' => TRUE,
    '#default_value' => $order ? $order->field_pricing_year_reference->id->value() : '',
  );

  // Don't include powerchord data option with an existing order.
  if ($order) {

    // Makes the message accurate based on if they included powerchord data.
    $message_token = ($order->field_include_powerchord_data->value() == 'Yes') ? '' : ' not ';

    $form['wrapper']['powerchord_message'] = array(
      '#prefix' => '<div class="well"><i>',
      '#markup' => t('You chose @message_token to use PowerChord pricing for the initial price values in this order.', array('@message_token' => $message_token)),
      '#suffix' => '</i></div>',
    );
  }
  else {
    $form['wrapper']['include_tags_with_pricing'] = array(
      '#type' => 'radios',
      '#title' => t('Include Hang Tags with Published Pricing from PowerChord'),
      '#options' => array(
        'Yes' => t('Yes'),
        'No' => t('No'),
      ),
      '#default_value' => $order ? $order->field_include_powerchord_data->value() : 'No',
    );
  }

  $form['wrapper']['contains_kit'] = array(
    '#type' => 'radios',
    '#title' => t('This order contains kits.'),
    '#options' => array(
      'Yes' => t('Yes'),
      'No' => t('No'),
    ),
    '#default_value' => $order ? $order->field_order_contains_kits->value() : 'No',
  );

  $form['wrapper']['kit1_qty'] = array(
    '#type' => 'textfield',
    '#title' => t('Kit 1 Quantity'),
    '#states' => array(
      'invisible' => array(
        ':input[name="contains_kit"]' => array('value' => 'No'),
      ),
    ),
    '#default_value' => $order ? $order->field_order_kit_1_qty->value() : NULL,
  );

  $form['wrapper']['kit2_qty'] = array(
    '#type' => 'textfield',
    '#title' => t('Kit 2 Quantity'),
    '#states' => array(
      'invisible' => array(
        ':input[name="contains_kit"]' => array('value' => 'No'),
      ),
    ),
    '#default_value' => $order ? $order->field_order_kit_2_qty->value() : NULL,
  );

  $form['wrapper']['upc_only'] = array(
    '#type' => 'radios',
    '#title' => t('Create this order as a UPC Book order only'),
    '#options' => array(
      'Yes' => t('Yes'),
      'No' => t('No'),
    ),
    '#default_value' => ($order && $order->field_upc_only->value() == 'Yes') ? 'Yes' : 'No',
  );

  $form['wrapper']['notes'] = array(
    '#type' => 'textarea',
    '#title' => t('Notes'),
    '#default_value' => $order ? $order->field_order_notes->value() : NULL,
  );

  $form['wrapper'][($order ? 'update_order' : 'submit')] = array(
    '#type' => 'submit',
    '#value' => t('@conditional Order', array(
      '@conditional' => ($order ? 'Update' : 'Create'),
    )),
  );

  if ($order) {
    drupal_set_title(t('Update Order'));
    $form['#order_id'] = $order_id;
    $form['#submit'] = array('stihl_orders_update_order_form_submit');
  }
  $a = 1;
  return $form;
}

/**
 * Form validation for creating and editing orders in the step 1 form.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
/*function _stihl_orders_new_order_form_validate($form, &$form_state) {

  if ($form_state['values']['contains_kit'] == 'Yes') {

    // Validate a quantity is provided.
    if ($form_state['values']['kit1_qty'] == '' && $form_state['values']['kit2_qty'] == '') {
      form_set_error('contains_kit', t('Kits are selected for this order.'));
      form_set_error('kit1_qty', t('Supply a quantity for Kit 1 and optionally Kit 2'));
    }

    // Validate quantity is a numeric value.
    if ($form_state['values']['kit1_qty'] != '' && !is_numeric($form_state['values']['kit1_qty'])) {
      form_set_error('kit1_qty', t('Provide a numeric value for quantity for Kit 1.'));
    }
    if ($form_state['values']['kit2_qty'] != '' && !is_numeric($form_state['values']['kit2_qty'])) {
      form_set_error('kit2_qty', t('Provide a numeric value for quantity for Kit 2.'));
    }
  }
}
*/

/**
 * Submit handler for creating new orders.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_new_order_form_submit($form, &$form_state) {
  // Use the global user object.
  global $user;
  $order_owner = entity_metadata_wrapper('user', $user);

  // First, make a shortcut variable to the $bd object to make sure it exists.
  $bd_reference = $order_owner->field_bd_reference;
  $bd_reference_value = $bd_reference->raw();
  if (isset($bd_reference_value)) {
    $bid = $order_owner->field_bd_reference->id->value();
  }

  // Create a new order in checkout.
  $order = commerce_order_new($user->uid, 'pending');
  // Get the new order id. This would create a new order with ID
  // regardless if any other orders exist
  commerce_order_save($order);
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $a = 1;
  // Set values from Order Creation form to Order.
  $order_wrapper->field_order_title = $form_state['values']['title'];
  $order_wrapper->field_order_contains_kits = $form_state['values']['contains_kit'];
  $order_wrapper->field_order_notes = $form_state['values']['notes'];
  $order_wrapper->field_pricing_year_reference = $form_state['values']['pricing_year'];
  $order_wrapper->field_include_powerchord_data = $form_state['values']['include_tags_with_pricing'];
  $order_wrapper->field_upc_only = $form_state['values']['upc_only'];
  $order_wrapper->field_order_kit_1_qty = $form_state['values']['kit1_qty'];
  $order_wrapper->field_order_kit_2_qty = $form_state['values']['kit2_qty'];
$a = 1;
  // Save the order to get its ID.
  // commerce_order_save($order);
$a = 1;
  if ($form_state['values']['include_tags_with_pricing'] == 'Yes' && isset($bid)) {
    $product_skus = stihl_orders_get_product_skus_by_bd($bid);
    if (!empty($product_skus)) {
      foreach ($product_skus as $sku) {
        if ($product = commerce_product_load_by_sku(trim($sku))) {
          // Create a new line item from a Product and save it to the Order.
          $order_wrapper->commerce_line_items[] = stihl_orders_add_line_item($product, $order->order_id);
        }
      }
    }
  }
  elseif ($form_state['values']['include_tags_with_pricing'] == 'Yes' && !isset($bid)) {
    drupal_set_message(t("Your user account is not associated with any B/D! Powerchord data couldn't be retrieved."));
  }

  // Save the order again to update its line item reference field.
  commerce_order_save($order);
$a = 1;
  $form_state['redirect'] = array('orders/edit/' . $order->order_id);
}



/**
 * Submit handler for updating data on step 1 for an existing order.
 */
function stihl_orders_update_order_form_submit($form, &$form_state) {
$a = 1;
  $order_wrapper = entity_metadata_wrapper('commerce_order', $form['#order_id']);

  $order_wrapper->field_order_title = $form_state['values']['title'];
  $order_wrapper->field_order_notes = $form_state['values']['notes'];
  $order_wrapper->field_pricing_year_reference = $form_state['values']['pricing_year'];
  $order_wrapper->field_upc_only = $form_state['values']['upc_only'];

  // User has the option to remove kits at this step.
  $order_wrapper->field_order_contains_kits = $form_state['values']['contains_kit'];
  if ($form_state['values']['contains_kit'] == 'No') {
    $order_wrapper->field_order_kit_1_qty = NULL;
    $order_wrapper->field_order_kit_2_qty = NULL;
  }
  else {
    $order_wrapper->field_order_kit_1_qty = $form_state['values']['kit1_qty'];
    $order_wrapper->field_order_kit_2_qty = $form_state['values']['kit2_qty'];
  }

  $order_wrapper->save();
$a = 1;
  drupal_set_message(t('Your order updated successfully'), 'status');
  $form_state['redirect'] = 'orders/edit/' . $order_wrapper->getIdentifier();
}

/**
 * Implements hook_query_TAG_alter().
 */
function stihl_orders_query_random_alter($query) {
  $query->orderRandom();
}

/**
 * Creates select options for "Pricing Year" during new order creation.
 */
function stihl_orders_pricing_year_select_options() {
  // Get the Branch Distributor ID associated with the logged in user.
  $bd_id = stihl_core_get_bd_id();

  // Get a list of enabled Pricing Years associated with the logged in user's
  // Branch Distributor ID as well as the default pricing years (as a fallback).
  $query = 'SELECT y.id, y.pricing_year, p.entity_id, y.details FROM {stihl_pricing_year} y
    LEFT JOIN {field_data_associated_pricing} p ON p.associated_pricing_target_id = y.id
    WHERE y.enabled = 1 AND ( p.entity_id = :bd_id OR y.default_pricing = 1 )';
  $results = db_query($query, array(':bd_id' => $bd_id))->fetchAll();

  $year_options = array();
  $year_option_defaults = array();

  // Loop through the results and sort them into two arrays.
  foreach ($results as $result) {
    $entity_id = $result->entity_id;

    // If the entity_id is NULL, this pricing year is a "default" Pricing Year.
    $array =& ${is_null($entity_id) ? 'year_option_defaults' : 'year_options'};

    // If this is a default Pricing Year, or its entity_id matches the BD of the
    // logged in user, it is a valid option and can be inserted into the array.
    $array[$result->id] = $result->pricing_year;
  }

  // Get default pricing years that don't exists in the branch-specific array.
  $year_option_defaults = array_diff($year_option_defaults, $year_options);

  // Append the unique default options to the branch-specific options.
  $year_options += $year_option_defaults;

  // Sort the options so that they are listed in chronological order.
  asort($year_options);
  return $year_options;
}
