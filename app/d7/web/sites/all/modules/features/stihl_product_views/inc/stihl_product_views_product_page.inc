<?php

/**
 * @file
 * Code for the Stihl Product page.
 */

/**
 * Get current incomplete orders limited by user's BD.
 *
 * Anyone from a given BD should have access to any order authored by
 * another user in that BD.
 *
 * @return array
 *   An array of incomplete Order objects the current user can edit/complete.
 */
function stihl_product_views_get_incomplete_orders_by_bd() {

  $current_user = entity_metadata_wrapper('user', $GLOBALS['user']->uid);

  // Attempt to get current user's BD reference. (RLadmin may not have BD id)
  try {
    $user_bd = $current_user->field_bd_reference->id->value();
  }
  // If user does not have a BD referenced, log this exception to Watchdog.
  // Assign a null value to their BD reference so no orders match in the
  // $incomplete_orders list below.
  catch (Exception $e) {
    $message = 'Caught exception - User BD reference in function: stihl_orders_get_incomplete_orders_by_bd(): @exception';
    $replace = array('@exception' => $e->getMessage());
    watchdog('stihl_orders', $message, $replace, WATCHDOG_ERROR);

    $user_bd = NULL;
  }

  $incomplete_orders = commerce_order_load_multiple(stihl_product_views_get_incomplete_order_ids());

  // The current user must belong to the same BD as the order submitter.
  return array_filter($incomplete_orders, function ($order) use ($user_bd) {

    // User of submitted order.
    $submitter = entity_metadata_wrapper('user', $order->uid);
    try {
      $order_bd = $submitter->field_bd_reference->id->value();
    }
    // If order submitter does not have a BD, return false.
    catch (Exception $e) {
      $message = 'Caught exception - Order submitter BD reference in function: stihl_orders_get_incomplete_orders_by_bd(): @exception';
      $replace = array('@exception' => $e->getMessage());
      watchdog('stihl_orders', $message, $replace, WATCHDOG_ERROR);

      return FALSE;
    }

    return ($user_bd == $order_bd) ? TRUE : FALSE;
  });
}

/**
 * Get ids of orders that have workflow status of incomplete.
 *
 * @return array
 *   An array of order ids, or an empty array.
 */
function stihl_product_views_get_incomplete_order_ids() {

  // Get the workflow states.
  $states = stihl_orders_get_states_by_workflow('Order Status');

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'commerce_order')
    ->propertyCondition('uid', 0, '!=')
    ->fieldCondition('field_order_status', 'value', $states['incomplete'])
    ->addMetaData('account', user_load(1));
  $result = $query->execute();

  return isset($result['commerce_order']) ? array_keys($result['commerce_order']) : array();
}

/**
 * Form for listing incomplete orders filtered by a user's BD.
 *
 * This is used to add a product to an existing incomplete order
 * from the individual product display page.
 *
 * @param int $product_id
 *   The id of product being displayed on the product display page.
 *
 * @return array
 *   A form array.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_product_views_incomplete_order_form($form, &$form_state, $product_id) {

  $form['container'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="container-fluid">',
    '#suffix' => '</div>',
  );

  // A user may add to an order if they belong to the same BD as in the order.
  $incomplete_orders = stihl_product_views_get_incomplete_orders_by_bd();

  // If there are no orders to list, show a message to the user.
  if (empty($incomplete_orders)) {
    return array(
      'message' => array(
        '#markup' => t('There are no available orders to display.'),
        '#prefix' => '<p>',
        '#suffix' => '</p>',
      ),
    );
  }

  foreach ($incomplete_orders as $order) {

    // If an order is for UPC Books only, note that in the view.
    $upc_only_indicator = '';
    if (isset($order->field_upc_only[LANGUAGE_NONE][0]['value']) && $order->field_upc_only[LANGUAGE_NONE][0]['value'] == 'Yes') {
      $upc_only_indicator = '<span class="text-muted">&nbsp;' . t('(UPC Book Only)') . '</span>';
    }

    $form[$order->order_id] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="row">',
      '#suffix' => '</div>',
      'order_branch' => array(
        '#prefix' => '<div class="col-md-3">',
        '#suffix' => '</div>',
        '#markup' => stihl_core_get_bd_name(stihl_core_get_bd_id($order->uid)),
      ),
      'order_title' => array(
        '#prefix' => '<div class="col-md-3">',
        '#suffix' => "{$upc_only_indicator}</div>",
        '#markup' => $order->field_order_title[LANGUAGE_NONE][0]['safe_value'],
      ),
      'order_date' => array(
        '#prefix' => '<div class="col-md-2 text-center">',
        '#suffix' => '</div>',
        '#markup' => format_date($order->created, 'short'),
      ),
      'order_number' => array(
        '#prefix' => '<div class="col-md-2 text-center">Order # ',
        '#suffix' => '</div>',
        '#markup' => $order->order_number,
      ),
      'submit' => array(
        '#prefix' => '<div class="col-md-2 text-center">',
        '#suffix' => '</div>',
        '#type' => 'submit',
        '#value' => t('Add to Order'),
        '#name' => $order->order_id,
        '#attributes' => array(
          'class' => array(
            'btn-success',
            'btn-xs',
          ),
        ),
      ),
    );
  }
  // Pass the product id to the form submit handler.
  $form['product_id'] = array(
    '#type' => 'hidden',
    '#value' => $product_id,
  );

  return $form;
}

/**
 * Form submit handler for adding a product to an incomplete existing order.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_product_views_incomplete_order_form_submit($form, &$form_state) {

  $order_wrapper = entity_metadata_wrapper('commerce_order', $form_state['triggering_element']['#name']);

  $product = commerce_product_load($form_state['values']['product_id']);

  // Create a new line item from a Product and save it to the Order.
  $order_wrapper->commerce_line_items[] = stihl_orders_add_line_item($product, $order_wrapper->getIdentifier());
  $order_wrapper->save();

  // Show user a message.
  drupal_set_message(t('Product %product was successfully added to order# %order_number',
    array('%product' => $product->title, '%order_number' => $order_wrapper->order_id->value())
  ));

  // Log this product was manually added to an existing order.
  $message = t('Product !product was manually added to order# !order_number');
  $replace = array('!product' => $product->title, '!order_number' => $order_wrapper->order_id->value());
  watchdog('stihl_orders', $message, $replace);
}

/**
 * Product display page.
 */
function stihl_product_views_product_page($product_id) {

  // Get product from url input.
  $product = entity_metadata_wrapper('commerce_product', $product_id);

  try {
    $horizontal = $product->field_horizontal_hangtag->value();

    $render['container'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="container-fluid">',
      '#suffix' => '</div>',
    );
    $render['container']['preview_row'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="row">',
      '#suffix' => '</div>',
    );
    $render['container']['preview_row']['vertical_preview_image'] = array(
      '#markup' => '<img src="' . stihl_product_views_image_preview_url($product->sku->value()) . '"/>',
      '#prefix' => '<div id="vertical-preview-image" class="left-column">',
      '#suffix' => '</div>',
    );
    // Not all products have a horizontal hang tag option.
    if ($horizontal) {
      $render['container']['preview_row']['horizontal_preview_image'] = array(
        '#markup' => '<img src="' . stihl_product_views_image_preview_url($product->sku->value(), FALSE) . '"/>',
        '#prefix' => '<div id="horizontal-preview-image" class="left-column">',
        '#suffix' => '</div>',
      );
    }
    $render['container']['preview_row']['product_information'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="right-column">',
      '#suffix' => '</div>',
      'title' => array(
        '#markup' => $product->title->value(),
        '#prefix' => '<h3>',
        '#suffix' => '</h3>',
      ),
      'sku' => array(
        '#markup' => $product->sku->value(),
        '#prefix' => '<p>SKU: ',
        '#suffix' => '</p>',
      ),
      'main_length' => array(
        '#markup' => $product->field_main_length->value(),
        '#prefix' => '<p>',
        '#suffix' => '</p>',
      ),
      'special_pricing_language' => array(
        '#markup' => $product->field_special_pricing_language->value() ? '<p>' . $product->field_special_pricing_language->value() . '</p>' : NULL,
      ),
      'orders_below_note' => array(
        '#markup' => l(
          t('View available orders below'),
          '/product/' . $product_id,
          array('fragment' => 'stihl-product-views-incomplete-order-form')),
        '#prefix' => '<p><span class="glyphicon glyphicon-arrow-down"></span>',
        '#suffix' => '</p>',
      ),
    );

    $render['container']['icons_row'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="row icon-row">',
      '#suffix' => '</div>',
    );
    $render['container']['icons_row']['vertical_icon'] = array(
      '#markup' => '<img class="icon-border" src="' . stihl_product_views_image_preview_url($product->sku->value()) . '"/>',
      '#prefix' => '<div id="vertical-icon">',
      '#suffix' => '</div>',
    );
    // Not all products have a horizontal hang tag option.
    if ($horizontal) {
      $render['container']['icons_row']['horizontal_icon'] = array(
        '#markup' => '<img src="' . stihl_product_views_image_preview_url($product->sku->value(), FALSE) . '"/>',
        '#prefix' => '<div id="horizontal-icon">',
        '#suffix' => '</div>',
      );
    }
    else {
      $render['container']['icons_row']['horizontal_icon'] = array(
        '#markup' => t('not available'),
        '#prefix' => '<div id="horizontal-not-available-icon"><span class="horizontal-not-available">',
        '#suffix' => '</span></div>',
      );
    }
  }
  // Catch if a product id given in the url doesn't match a valid product.
  catch (Exception $e) {

    drupal_set_message(t('Product number not found'), 'warning');

    $message = 'Caught exception - $render array in function: stihl_orders_product_display() on product display page: @exception';
    $replace = array('@exception' => $e->getMessage());
    watchdog('stihl_orders', $message, $replace, WATCHDOG_ERROR);

    return array(
      'message' => array(
        '#markup' => t('Please select a product from the navigation or perform a search.'),
        '#prefix' => '<p>',
        '#suffix' => '</p>',
      ),
    );
  }

  // Available orders are incomplete orders that the user has the same BD.
  $available_orders_form = drupal_get_form('stihl_product_views_incomplete_order_form', $product_id);

  // Fieldset for listing available orders form.
  $render['form'] = array(
    '#title' => t('Add product to an order below'),
    '#type' => 'fieldset',
    'order_list' => array(
      '#markup' => drupal_render($available_orders_form),
    ),
    '#attributes' => array(
      'class' => array(
        'stihl-orders-incomplete-order-form-wrapper',
      ),
    ),
  );

  return $render;
}

/**
 * Creates a hang tag preview image file URL.
 *
 * @param string $sku
 *   The product SKU.
 * @param bool $vertical
 *   True if a vertical image is requested. (optional) Default vertical.
 *
 * @return string
 *   A preview image URL. Will return generic image if no file exits.
 */
function stihl_product_views_image_preview_url($sku, $vertical = TRUE) {

  if ($vertical) {
    $default_file_path = 'public://product-images/V/vertical-default.png';
    $file_name = "{$sku}_V.jpg";
    $file_path = 'public://product-images/V/' . $file_name;
  }
  else {
    $default_file_path = 'public://product-images/H/horizontal-default.png';
    $file_name = "{$sku}_H.jpg";
    $file_path = 'public://product-images/H/' . $file_name;
  }

  $file_exists = stihl_orders_attempt_file_resource($file_path, 'r', FALSE);

  return $file_exists ? file_create_url($file_path) : file_create_url($default_file_path);
}
