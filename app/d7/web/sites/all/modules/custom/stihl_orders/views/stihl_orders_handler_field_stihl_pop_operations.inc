<?php

/**
 * @file
 * Contains StihlOrdersHandlerFieldStihlOperations class.
 */

/**
 * Class StihlOrdersHandlerFieldStihlPopOperations.
 *
 * @see commerce_order_handler_field_order_operations()
 */
class StihlOrdersHandlerFieldStihlPopOperations extends views_handler_field {

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
    $order_status = $values->commerce_order_status;

    $links = array();

    if ($order_status != 'completed' && $order_status != 'canceled') {
      $links['stihl-order-cancel'] = array(
        'title' => t('Cancel'),
        'href' => 'pop-catalog/orders/cancel/' . $order_id,
      );
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
