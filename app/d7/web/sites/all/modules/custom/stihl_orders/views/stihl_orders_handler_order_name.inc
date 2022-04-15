<?php

/**
 * @file
 * Contains the custom Order Name views handler.
 */

/**
 * Class StihlOrdersHandlerOrderName.
 */
class StihlOrdersHandlerOrderName extends views_handler_field {

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
    $order_status = $commerce_order->field_order_status;
    $states = stihl_orders_get_states_by_workflow();
    $sub_path =  $order_status && $order_status[LANGUAGE_NONE][0]['value'] == $states['incomplete'] ? 'edit' : 'submit';
    $output = l(t('@title', array('@title' => $commerce_order->field_order_title[LANGUAGE_NONE][0]['value'])), '/orders/' . $sub_path . '/' . $commerce_order->order_id, array('html' => TRUE));
    return $output;
  }

}
