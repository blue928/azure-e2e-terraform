<?php

/**
 * @file
 * Contains functions & logic for the automatic sending of order-related emails.
 */

/**
 * Sets the Order Created message for the external notification email.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 * @param array $params
 *   Contains email-specific parameters.
 */
function stihl_orders_order_created_email(array &$message, array $params) {
  $message['headers']['Cc'] = 'STIHLOrderAdmins@rlci.com';
  $message['subject'] = t('Re: Order started for @bd_name', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('An order for Hang Tags has been started but has not been submitted. Please continue and complete your order and submit.', array());
  $message['body'][] = t('Order Details:<br />Order name: @order_name<br />Order description: @order_description', array(
    '@order_name' => $params['order_name'],
    '@order_description' => $params['order_description'],
  ));
  stihl_orders_get_email_footer($message);
}

/**
 * Sets the Order Submitted message for the external notification email.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 * @param array $params
 *   Contains email-specific parameters.
 */
function stihl_orders_order_submitted_email(array &$message, array $params) {
  $message['subject'] = t('Re: Order submitted for review for @bd_name', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('An order for Hang Tags has been submitted for review for @bd_name.', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('We have received your order for Hangtags and will review promptly. Once we validate the data, you will receive notification of approval and submission to print.');
  $message['body'][] = t('Order Details:<br />Order name: @order_name<br />Description: @order_description', array(
    '@order_name' => $params['order_name'],
    '@order_description' => $params['order_description'],
  ));
  stihl_orders_get_email_footer($message);
}

/**
 * Sets the Order Approved message for the external notification email.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 * @param array $params
 *   Contains email-specific parameters.
 */
function stihl_orders_order_approved_email(array &$message, array $params) {
  stihl_orders_get_email_headers($message);
  $message['subject'] = t('Re: Order review and approved for @bd_name', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('Your order for Hang Tags has been reviewed and approved for @bd_name.', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('Your Hang Tag order is now being processed. Upon completion you will receive an email with tracking information.');
  $message['body'][] = t('Order Details:<br />Order name: @order_name<br />Description: @order_description', array(
    '@order_name' => $params['order_name'],
    '@order_description' => $params['order_description'],
  ));
  stihl_orders_get_email_footer($message);
}

/**
 * Sets the Order Incomplete message for the external notification email.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 * @param array $params
 *   Contains email-specific parameters.
 */
function stihl_orders_order_incomplete_email(array &$message, array $params) {
  $message['headers']['Cc'] = 'STIHLOrderAdmins@rlci.com';
  $message['subject'] = t('Re: Order requires action for @bd_name', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('An order for Hang Tags needs review & input for @bd_name. Please resolve any issues as listed in the comments below that exist with this order and resubmit when you are ready.', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('Order Details:<br />Order name: @order_name<br />Description: @order_description<br />Feedback: @order_feedback', array(
    '@order_name' => $params['order_name'],
    '@order_description' => $params['order_description'],
    '@order_feedback' => $params['order_feedback'],
  ));
  stihl_orders_get_email_footer($message);
}

/**
 * Attaches the BCC & CC headers for external order notification emails.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 */
function stihl_orders_get_email_headers(array &$message) {
  $message['headers']['Bcc'] = 'stihl-hangtag-orders@knowclassic.com';
  $message['headers']['Cc'] = 'STIHLOrderAdmins@rlci.com';
}

/**
 * Attaches the footer information for order notification emails.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 */
function stihl_orders_get_email_footer(array &$message) {
  $message['body'][] = t('You can view more about the order here: @orders_link', array(
    '@orders_link' => $GLOBALS['base_url'] . '/orders/list',
  ));
  $message['body'][] = t('Thank you,');
  $message['body'][] = t('Red Letter Shared Resources');
}

/**
 * The internal summary email to be sent when an order is submitted or approved.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 * @param array $params
 *   Contains email-specific parameters.
 */
function stihl_orders_order_summary_email(array &$message, array $params) {
  $message['subject'] = t('Order update regarding order @order_id for @bd_name', array(
    '@order_id' => $params['order_id'],
    '@bd_name' => $params['bd_name'],
  ));
  $message['body'][] = t('This order for @bd_name is updated in the STIHL Hang Tag Portal.', array(
    '@bd_name' => $params['bd_name'],
  ));
  $message['body'][] = t('ORDER DETAILS:<br />Order Status: @order_workflow_state<br />Order ID: @order_id<br />Order Name: @order_name<br />Description: @order_description<br />Ordered by: @order_creator_full_name', array(
    '@order_workflow_state' => $params['order_workflow_state'],
    '@order_id' => $params['order_id'],
    '@order_name' => $params['order_name'],
    '@order_description' => $params['order_description'],
    '@order_creator_full_name' => $params['order_creator_full_name'],
  ));
  $message['body'][] = check_plain($params['order_summary']);
  $message['body'][] = t('You can view more about the order here: @orders_link', array(
    '@orders_link' => $GLOBALS['base_url'] . '/orders/list',
  ));
  $message['body'][] = t('This is an automated e-mail from the hang tag application.');
}

/**
 * Sets the UPC Download agreement message for the external notification email.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 * @param array $params
 *   Contains email-specific parameters.
 */
function stihl_orders_fee_acknowledged_email(array &$message, array $params) {

  // Set the headers for the email.
  $message['headers']['Bcc'] = 'Stihl Portal Support <stihl-portal-support@knowclassic.com>, Order Admins <STIHLOrderAdmins@rlci.com>';

  // The fee acknowledgement email is almost identical to the summary email.
  // There are just a few minor tweaks that need to be made:
  //
  // Instead of 'Order State: @order_workflow_state' the fee_acknowledged email
  // will read: 'Order Action: Annual fee acknowledgement for UPC Books'.
  $params['order_workflow_state'] = 'Annual fee acknowledgement for UPC Books';

  // Instead of 'Ordered by: {full name of order creator}', the fee_acknowledged
  // email will read: 'Action by: {full name of user who performed the action}'.
  $params['order_creator_full_name'] = stihl_users_get_full_name($GLOBALS['user']->uid);

  // There will be no order_summary but we'll pass a value to the order_summary
  // function to avoid 'undefined index' notices in the watchdog log.
  $params['order_summary'] = '';

  // Call the order_summary function to generate the $message.
  stihl_orders_order_summary_email($message, $params);

  // Perform the replacements on the "ORDER DETAILS" string to fit our needs.
  $message['body'][1] = str_replace('Order Status', 'Order Action', $message['body'][1]);
  $message['body'][1] = str_replace('Ordered by', 'Action by', $message['body'][1]);

  // Remove the unnecessary "order_summary" index.
  unset($message['body'][2]);
}

/**
 * Sets the Ready For Review message for the external notification email.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 * @param array $params
 *   Contains email-specific parameters.
 */
function stihl_orders_order_ready_for_review_email(array &$message, array $params) {
  $message['subject'] = t('Order available for review for @bd_name', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('An order for Hang Tags is available for review for @bd_name.', array('@bd_name' => $params['bd_name']));
  $message['body'][] = t('Order name: @order_name<br />Description: @order_description', array(
    '@order_name' => $params['order_name'],
    '@order_description' => $params['order_description'],
  ));
  $message['body'][] = t('You can view more about the order here: @orders_link', array(
    '@orders_link' => $GLOBALS['base_url'] . '/order/review/' . $params['order_id'],
  ));
  $message['body'][] = t('This is an automated e-mail from the hang tag application.');
}

/**
 * Sets the proofing failure message for the internal notification email.
 *
 * @param array $message
 *   The message array used by drupal_mail().
 * @param array $params
 *   Contains email-specific parameters.
 */
function stihl_orders_proof_failure_email(array &$message, array $params) {
  $message['subject'] = t('Order #@order_id: Encountered @severity on @environment during proofing process.', array(
    '@order_id' => $params['order_id'],
    '@severity' => $params['severity'],
    '@environment' => $params['environment'],
  ));
  $message['body'][] = t('The following @severity was encountered on @host while creating proofs for order #@order_id:', array(
    '@severity' => $params['severity'],
    '@host' => $GLOBALS['base_url'],
    '@order_id' => $params['order_id'],
  ));
  $message['body'][] = t('--- BEGIN MESSAGE ---');
  $message['body'][] = t('@message', array('@message' => $params['message']));
  $message['body'][] = t('---- END MESSAGE ----');
}
