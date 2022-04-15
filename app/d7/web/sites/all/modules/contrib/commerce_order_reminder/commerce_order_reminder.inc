<?php

/**
 * @file
 * Custom module functions.
 */

/**
 * Sends email reminders by order ID and reminder number.
 *
 * @param int $order_id
 *   ID of the order to send reminders of.
 * @param int $remind_number
 *   Number of letter reminder to send.
 */
function commerce_order_reminder_send_reminder($order_id, $remind_number = 1) {
  $order = commerce_order_load($order_id);
  $a=1;
  if (empty($order->mail)) {
    return;
  }

  $reminder_settings = variable_get('commerce_order_reminder_settings');
  // Do not send reminder if cart is empty and specified in options.
  if (!$reminder_settings['commerce_order_reminder_send_if_empty'] && !count($order->commerce_line_items)) {
    return;
  }

  $from = $reminder_settings['commerce_order_reminder_from_email'];
  $to = $order->mail;
  // Get subject and body, pass them through token_replace() with a given order.
  $subject = $reminder_settings['commerce_order_reminder_email_texts'][$remind_number]['commerce_order_reminder_subject'];
  $subject = token_replace($subject, array('commerce-order' => $order), array('clear' => TRUE));
  $body = $reminder_settings['commerce_order_reminder_email_texts'][$remind_number]['commerce_order_reminder_body'];
  $body = token_replace($body, array('commerce-order' => $order), array('clear' => TRUE));
  $params = array();
  $params['subject'] = $subject;
  $params['body'] = $body;
  $params['from_full'] = '"' . $reminder_settings['commerce_order_reminder_from_name'] . '" <' . $reminder_settings['commerce_order_reminder_from_email'] . '>';
  if (!empty($reminder_settings['commerce_order_reminder_bcc'])) {
    $params['headers'] = array(
      'Bcc' => $reminder_settings['commerce_order_reminder_bcc'],
    );
  }
  drupal_mail('commerce_order_reminder', 'email_reminder', $to, language_default(), $params, $from);
  watchdog('commerce_order_reminder', 'Sending email reminder number %remind_number of order %order_id to %to.',
    array(
      '%remind_number' => $remind_number,
      '%order_id' => $order_id,
      '%to' => $to,
    )
  );
  // Save changes to the database.
  if ($remind_number > 1) {
    db_update('commerce_order_reminder')
      ->condition('order_id', $order_id, '=')
      ->fields(array(
        'reminders' => $remind_number,
        'last_reminded' => REQUEST_TIME,
      ))
      ->execute();
  }
  else {
    db_insert('commerce_order_reminder')
      ->fields(array(
        'reminders' => $remind_number,
        'last_reminded' => REQUEST_TIME,
        'order_id' => $order_id,
      ))
      ->execute();
  }
}

/**
 * Sends test emails of the all saved templates using info of the latest order.
 */
function commerce_order_reminder_send_test_email() {
  $reminder_settings = variable_get('commerce_order_reminder_settings');
  // Select the latest order id which has email attached.
  $latest_order_id = db_query_range("SELECT co.order_id FROM {commerce_order} co WHERE co.mail <> '' ORDER BY co.changed DESC", 0, 1);
  $a=1;
  $latest_order_id = $latest_order_id->fetchField();
  if (!$latest_order_id) {
    drupal_set_message(t('Could not find an appropriate order to use for tests emails. Please, create at least one order first.'), 'error');
    return;
  }
  $order = commerce_order_load($latest_order_id);

$a = 1;
  foreach ($reminder_settings['commerce_order_reminder_email_texts'] as $email) {
    $subject = token_replace($email['commerce_order_reminder_subject'], array('commerce-order' => $order), array('clear' => TRUE));
    $body = token_replace($email['commerce_order_reminder_body'], array('commerce-order' => $order), array('clear' => TRUE, 'sanitize' => FALSE));
    $from = $reminder_settings['commerce_order_reminder_from_email'];
    $to = $reminder_settings['commerce_order_reminder_test_email_address'];
    $params = array();
    $params['subject'] = $subject;
    $params['body'] = $body;
    $params['from_full'] = '"' . $reminder_settings['commerce_order_reminder_from_name'] . '" <' . $reminder_settings['commerce_order_reminder_from_email'] . '>';
    if (!empty($reminder_settings['commerce_order_reminder_bcc'])) {
      $params['headers'] = array(
        'Bcc' => $reminder_settings['commerce_order_reminder_bcc'],
      );
    }
    // test with drupal set message before sending emails
    $testMessage = '';
    $testMessage .= $to .' ';
    $testMessage .= var_dump($params) . ' ';
    $testMessage .= $from .' ';
    //drupal_set_message($testMessage); 
    if(_commerce_order_reminder_test_for_expiring_items($order)){
          drupal_mail('commerce_order_reminder', 'test_email', $to, language_default(), $params, $from);
    }
    
  }
}

/**
 * Undocumented function
 *
 * @param [commerce_order] $order
 * @return bool
 */
function _commerce_order_reminder_test_for_expiring_items($order){
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  foreach($order_wrapper->commerce_line_items as $delta => $line_item_wrapper){
    $line_item = $line_item_wrapper->value();
    $product_type = $line_item_wrapper->commerce_product->type->value();
    $product = $line_item_wrapper->commerce_product;
    //$available_until = $line_item_wrapper->commerce_product->field_available_until->value();
    $a=1;

    $current_time = time();
    
    // else return false. cart does not contain items with
    // a future expiration date.
  }
    return TRUE;
}