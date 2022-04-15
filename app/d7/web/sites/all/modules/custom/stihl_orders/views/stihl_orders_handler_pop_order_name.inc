<?php

/**
 * @file
 * Contains the custom POP Order Name views handler.
 */

/**
 * Class StihlOrdersHandlerPopOrderName.
 */
class StihlOrdersHandlerPopOrderName extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Do nothing -- to override the parent query.
  }

  /**
   * Returns order titles with links that vary depending on order status.
   *
   * @param object $data
   *   The data to be manipulated in the rendered output.
   *
   * @return string
   *   The rendered output.
   */
  public function render($data) {
    $commerce_order = entity_load_single('commerce_order', $data->order_id);
    $order_status = $commerce_order->status;

    global $user;
    $check = array_intersect([3, 17], array_keys($user->roles));
    if (count($check)) {
      $output = l(t('@title', array('@title' => $commerce_order->order_number)), '/admin/commerce/orders/' . $commerce_order->order_id, array('html' => TRUE));
    } else {
      if ($order_status == 'completed') {
        $output = t('@title', array('@title' => $commerce_order->order_number));
      } else {
        $output = l(t('@title', array('@title' => $commerce_order->order_number)), '/cart', array('html' => TRUE));
      }
    }

    return $output;
  }

}
