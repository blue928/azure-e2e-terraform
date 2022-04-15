<?php

/**
 * @file
 * Contains StihlOrdersHandlerFieldStihlOperations class.
 */

/**
 * Class StihlOrdersHandlerFieldStihlOperations.
 *
 * @see commerce_order_handler_field_order_operations()
 */
class StihlOrdersHandlerFieldStihlOperations extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();

    $this->additional_fields['order_id'] = 'order_id';
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $order_id = $this->get_value($values, 'order_id');
    $order_status = $values->field_field_order_status[0]['rendered']['#markup'];

    $links = array();

    if ($order_status != 'submitted' && $order_status != 'ready for review') {
      $links['stihl-order-cancel'] = array(
        'title' => t('Cancel'),
        'href' => 'orders/cancel/' . $order_id,
      );
    }

    // If an order is in the approved state, allow BDUsers to clone it.
    if ($order_status == 'approved') {
      if (user_has_role(user_role_load_by_name('bduser')->rid) || user_has_role(user_role_load_by_name('administrator')->rid)) {
        $links['stihl-order-clone'] = array(
          'title' => t('Clone'),
          'href' => 'orders/clone/' . $order_id,
        );
      }
    }

    if ($order_status == 'ready for review') {
      // Restrict to admin role (3) and RLadmin role (5).
      if (user_has_role(3) || user_has_role(5)) {
        $links['stihl-order-approval'] = array(
          'title' => t('Review'),
          'href' => 'order/review/' . $order_id,
        );
      }
    }

    drupal_add_css(drupal_get_path('module', 'commerce_order') . '/theme/commerce_order.admin.css');
    return theme('links', array(
      'links' => $links,
      'attributes' => array(
        'class' => array('links', 'inline', 'operations'),
      ),
    ));
  }

}
