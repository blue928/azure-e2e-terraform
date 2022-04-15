<?php

/**
 * @file
 * Field handler to present an order's operations links.
 *
 * Based on commerce_order_handler_field_order_operations.
 */

/**
 * Field handler to provide action links.
 */
class commerce_cart_multiple_handler_field_cart_multiple_operations extends views_handler_field {

  /**
   * Construct a new field handler.
   */
  function construct() {
    parent::construct();

    $this->additional_fields['order_id'] = array(
      'field' => 'order_id',
      'table' => 'commerce_order',
    );
    $this->additional_fields['commerce_order_total_amount'] = array(
      'field' => 'commerce_order_total_amount',
      'table' => 'field_data_commerce_order_total',
    );
  }

  /**
   * Adds option to form.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['add_destination'] = TRUE;

    return $options;
  }

  /**
   * Called to add the field to a query.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['add_destination'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add a destination parameter to the delete operation link so users return to this View on form submission.'),
      '#default_value' => $this->options['add_destination'],
    );
  }

  /**
   * Called to add the field and option to a query.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render the field.
   *
   * @param $values
   *   The values retrieved from the database.
   */
  function render($values) {
    global $user;
    $order_id = $this->get_value($values, 'order_id');
    $total = $this->get_value($values, 'commerce_order_total_amount');
    // Get the operations links.
    $links = menu_contextual_links('commerce_cart_multiple', 'user/' . $user->uid . '/carts', array($order_id));
    if ($total) {
      $links[] = menu_get_item('checkout/' . $order_id);
    }
    if (!empty($links)) {
      // Add the destination to the links if specified.
      if ($this->options['add_destination']) {
        foreach ($links as $id => &$link) {
          // Only include the destination for the delete form.
          if (in_array($id, array('commerce_cart_multiple-set ', 'commerce_cart_multiple-delete'))) {
            $link['query'] = drupal_get_destination();
          }
        }
      }

      drupal_add_css(drupal_get_path('module', 'commerce_cart_multiple') . '/theme/commerce_order.admin.css');
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }

}
