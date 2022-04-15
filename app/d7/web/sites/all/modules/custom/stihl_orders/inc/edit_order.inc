<?php

/**
 * @file
 * Include file for functionality around editing an existing order.
 */

/**
 * Display a custom interface for user to add/remove line items from order.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_render_edit_line_items_form($form, &$form_state, $order_id) {
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order_id);

  try {
    $form['#prefix'] = '<div class="div-table">';
    $form['#suffix'] = '</div>';

    $line_items = $order_wrapper->commerce_line_items->value();

    // Variable to keep track of number of line items that belong to a
    // taxonomy term.
    $product_group_totals = array();

    // Set up key in array to hold fieldset data.
    $form['fieldsets'] = array(
      '#type' => 'container',
    );

    foreach ($line_items as $key => $line_item) {
      $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);

      // Skip rows with bad Line Item data.
      if (!$tid = stihl_orders_get_product_line_item_term_id($line_item_wrapper, $order_id)) {
        $msg = t('The item <em>@label</em> does not have a product category and cannot be displayed. Please contact <a href="@support-page">support</a>.', [
          '@label' => $line_item_wrapper->line_item_label->value(),
          '@support-page' => url('content/support'),
        ]);
        $link = l(t('Edit Product'), "admin/commerce/products/{$line_item_wrapper->commerce_product->getIdentifier()}/edit");
        drupal_set_message($msg, 'warning');
        watchdog('stihl_orders', $msg, [], WATCHDOG_WARNING, $link);
        unset($line_items[$key]);
        continue;
      }

      $term_name = $line_item_wrapper->commerce_product->field_product_category->name->value();

      // If the term of the product has a parent, use the $tid of the parent
      // term.
      $parent_term = taxonomy_get_parents($tid);
      if (!empty($parent_term)) {
        $tid = key($parent_term);
        $term_name = $parent_term[$tid]->name;
      }
      $lid = $line_item_wrapper->line_item_id->value();

      $form['fieldsets'][$tid]['#type'] = 'fieldset';
      $form['fieldsets'][$tid]['#title'] = $term_name;
      $form['fieldsets'][$tid]['#collapsible'] = TRUE;
      $form['fieldsets'][$tid]['#collapsed'] = TRUE;

      if (!isset($product_group_totals[$tid])) {
        $product_group_totals[$tid] = 0;
      }

      // Generate a new table for each taxonomy category term.
      $form['fieldsets'][$tid]['row']['#prefix'] = '<div id="category-' . $tid . '">';
      $form['fieldsets'][$tid]['row']['#suffix'] = '<span id="select-tid-' . $tid . '" class="node-link">Select All / None</span></div>';

      $form['fieldsets'][$tid]['row'][$lid] = array(
        '#prefix' => '<div id="lid-' . $lid . '" class="row">',
        '#suffix' => '</div>',
        '#tree' => TRUE,
      );
      $form['fieldsets'][$tid]['row'][$lid]['remove'] = array(
        '#type' => 'checkbox',
        '#prefix' => '<div class="col-sm-1">',
        '#suffix' => '</div>',
      );
      $form['fieldsets'][$tid]['row'][$lid]['title'] = array(
        '#markup' => $line_item_wrapper->commerce_product->title->value(),
        '#prefix' => '<div class="col-sm-4">',
        '#suffix' => '</div>',
        '#title' => t('Title'),
      );
      $form['fieldsets'][$tid]['row'][$lid]['special_pricing_language'] = array(
        '#markup' => $line_item_wrapper->field_special_pricing_language->value(),
        '#prefix' => '<div class="col-sm-7">',
        '#suffix' => '</div>',
        '#title' => t('Special Pricing Language'),
      );

      $product_group_totals[$tid]++;
    }

    // Add product group totals to fieldset titles.
    foreach ($product_group_totals as $tid => $total) {

      $format_plural_message = format_plural($total, '1 product', '@count products');
      $products_selected_message = " - <span class=\"small\">$format_plural_message</span>";

      $form['fieldsets'][$tid]['#title'] = $form['fieldsets'][$tid]['#title'] . $products_selected_message;
    }

    $form['scripts'] = array(
      '#attached' => array(
        'css' => array(
          drupal_get_path('module', 'stihl_orders') . '/assets/js/stihl_orders.css',
        ),
        'js' => array(
          'type' => 'file',
          'data' => drupal_get_path('module', 'stihl_orders') . '/assets/js/stihl_orders.edit.js',
        ),
      ),
    );

    // Pass order id to submit handler.
    $form['#order_id'] = $order_id;

    // Add modal markup to page.
    $form['modal'] = array(
      '#markup' => _stihl_orders_get_modal_markup('stihl-orders-modal'),
    );

    $form['remove_selected'] = array(
      '#type' => 'submit',
      '#value' => t('Remove Selected'),
      '#attributes' => array(
        'class' => array('btn-danger'),
      ),
    );
    $form['add_more_hangtags'] = array(
      '#type' => 'submit',
      '#value' => t('Add Hang Tags'),
      '#submit' => array('stihl_orders_add_more_hangtags'),
    );
    $form['configure_tags'] = array(
      '#type' => 'submit',
      '#value' => t('Configure Hang Tags'),
    );

    // Get vocab id and pass to function to sort fieldsets by the order they
    // appear in the left nav bar.
    // - We're checking to see if the order has line items before trying to
    //   sort the fielsets within the order.
    if (!empty($line_items)) {
      $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', reset($line_items));
      $vid = $line_item_wrapper->commerce_product->field_product_category->value()->vid;

      _stihl_orders_sort_by_term($form, $vid);

      // After sorting form, ensure that first fieldset is expanded.
      $fieldset_key = array_keys($form['fieldsets'])[0];
      $form['fieldsets'][$fieldset_key]['#collapsed'] = FALSE;
    }

    return $form;
  }
  catch (Exception $e) {
    // If the order doesn't exist, present the 'Page Not Found' message.
    watchdog('stihl_orders',
      'The Configure Order form failed to build with the following exception: @exception.',
      array('@exception' => $e->getMessage()),
      WATCHDOG_ERROR
    );
    $msg = t('The application encountered an error loading this order. Please <a href="@support-page">contact support</a>.', array(
      '@support-page' => url('content/support'),
    ));
    drupal_set_message($msg, 'error');
    drupal_not_found();
  }
}

/**
 * Submit handler for _stihl_orders_render_edit_line_items_form().
 */
function _stihl_orders_render_edit_line_items_form_submit($form, &$form_state) {
  $order_id = $form['#order_id'];
  if ($form_state['triggering_element']['#id'] == 'edit-remove-selected') {
    array_walk($form_state['values'], function ($v, $k) use ($order_id) {
      if (is_numeric($k) && $v['remove'] == TRUE) {
        _stihl_orders_edit_order_delete_line_item($order_id, $k);
      }
    });
  }
  else {
    $form_state['redirect'] = array('/orders/configure/' . $order_id);
  }
}

/**
 * Custom function to remove a line item from an order.
 *
 * @param int $order_id
 *   Order ID.
 * @param int $line_item_id
 *   Line Item id.
 */
function _stihl_orders_edit_order_delete_line_item($order_id, $line_item_id) {
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order_id);

  // Deny the action if the user can't delete line items on an order.
  // @TODO: Add logic that restricts who can remove line items.
  $can_remove = FALSE;

  if ($can_remove) {
    drupal_set_message(t("You don't have permission to remove items."));
  }
  else {
    $order = $order_wrapper->value();

    // Store item so we can let the user know about removed item.
    $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item_id);

    if (isset($line_item_wrapper->commerce_product)) {
      $product_title = $line_item_wrapper->commerce_product->title->value();

      // Remove the line item from the order.
      commerce_entity_reference_delete($order, 'commerce_line_items', 'line_item_id', $line_item_id);

      // Delete the line item.
      commerce_line_item_delete($line_item_id);

      // Save the order.
      commerce_order_save($order);

      // Display message to user.
      drupal_set_message(t('Removed %item from order.', array('%item' => $product_title)));
    }
  }

  // Redirect to $destination if it's passed as a parameter.
  $params = drupal_get_query_parameters();
  if ($destination = $params['destination'] ?? FALSE) {
    drupal_goto($destination);
  }
}

/**
 * Submit callback to take users from the Order view to the Add Hang Tags view.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_add_more_hangtags(&$form, &$form_state) {
  $a = 1;
  drupal_goto('orders/add-hang-tags/' . $form['#order_id']);
}

/**
 * Confirmation form builder for canceling orders.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_cancel_order($form, &$form_state, $order_id) {
  $form['order'] = array(
    '#type' => 'value',
    '#value' => commerce_order_load($order_id),
  );

  return confirm_form($form,
    t('Are you sure you want to cancel this order?'),
    'orders/list'
  );
}

/**
 * Submit callback for order cancellation confirmation form.
 */
function stihl_orders_cancel_order_submit($form, &$form_state) {
  $order_id = $form['order']['#value']->order_id;
  $order_deleted = _stihl_orders_update_order_workflow_transition($order_id, 'deleted');
  if ($order_deleted) {
    stihl_orders_delete_online_proof($order_id);
    drupal_set_message(t('Order #: @order_id has been canceled.', array('@order_id' => $order_id)));
    $form_state['redirect'] = 'orders/list';
  }
}

/**
 * Confirmation form builder for canceling orders.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_cancel_pop_order($form, &$form_state, $order_id) {
  $form['order'] = array(
    '#type' => 'value',
    '#value' => commerce_order_load($order_id),
  );

  return confirm_form($form,
    t('Are you sure you want to cancel this order?'),
    'pop-catalog/orders/list'
  );
}

/**
 * Submit callback for order cancellation confirmation form.
 */
function stihl_orders_cancel_pop_order_submit($form, &$form_state) {
  $order_id = $form['order']['#value']->order_id;
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order_id);
  $order = $order_wrapper->value();
  $order_canceled = commerce_order_status_update($order, 'canceled');
  if ($order_canceled->status == 'canceled') {
    drupal_set_message(t('Order #: @order_id has been canceled.', array('@order_id' => $order_id)));
    $form_state['redirect'] = 'pop-catalog/orders/list';
  }
}
