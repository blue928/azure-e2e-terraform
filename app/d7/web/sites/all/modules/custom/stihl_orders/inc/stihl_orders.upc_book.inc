<?php

/**
 * @file
 * Contains the logic for creating an order's UPC books.
 */

/**
 * The hook_menu() callback for upc-books.
 */
function stihl_orders_upc_callback($order_id, $include_price) {
  global $user;

  // If we're tracking downloads for this user, we need to prompt them
  // to accept the charges associated with downloading.
  if (stihl_orders_track_download()) {

    // When a user accepts charges, they accept charges on behalf of their BD.
    // So we need to check the array of BDs who have accepted and make sure that
    // their acceptance hasn't expired.
    $bd_id = stihl_core_get_bd_id($user->uid);
    $accepted = variable_get('upc_download_accept', array());
    $timestamp = format_date(REQUEST_TIME, 'custom', 'Ymd');

    // If user's BD has yet to accept the prompt this year, we need to display
    // the prompt to them so that they can accept/reject the charges.
    if (empty($accepted[$bd_id]) || $accepted[$bd_id] <= $timestamp) {
      $prompt = drupal_get_form('stihl_orders_confirm_download_form', $order_id, $include_price, $bd_id);
      return render($prompt);
    }
  }

  // Otherwise, we can go ahead and download the requested UPC Book.
  stihl_orders_download_upc_book($order_id, $include_price);
}

/**
 * Form used ensure user accepts charges associated with downloading UPC Books.
 *
 * @param int $order_id
 *   ID of the order for which to download the UPC Book.
 * @param string $include_price
 *   Indicates whether the UPC Book should contain pricing.
 *   The value is 'pricing' or 'no-pricing'.
 * @param int $bd_id
 *   The ID of the Branch Distributor associated with the user's account.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_confirm_download_form($form, &$form_state, $order_id, $include_price, $bd_id) {

  // The BD's will have to renew their agreement every year on October 1st.
  $upc_download_expire = variable_get('upc_download_expire', '10/1');
  $next_year = format_date(strtotime('+1 year', REQUEST_TIME), 'custom', 'Y');
  $expiration = date_create($upc_download_expire . '/' . $next_year)->format('Ymd');

  $form = array();
  $form['order_id'] = array(
    '#type' => 'value',
    '#value' => $order_id,
  );
  $form['include_price'] = array(
    '#type' => 'value',
    '#value' => $include_price,
  );
  $form['expiration'] = array(
    '#type' => 'value',
    '#value' => $expiration,
  );
  $form['bd_id'] = array(
    '#type' => 'value',
    '#value' => $bd_id,
  );

  $question = t('Are you sure?');
  $redirect = "orders/submit/{$order_id}";
  $bd = stihl_core_get_bd_name($bd_id) ?: 'your branch distributor';
  $description = t('Downloading this UPC book will result in an annual fee of $200 being charged to @bd.', array('@bd' => $bd));
  return confirm_form($form, $question, $redirect, $description, t('Yes'), t('Cancel'));
}

/**
 * Form submission handler for stihl_orders_confirm_download_form().
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_orders_confirm_download_form_submit($form, &$form_state) {
  $order_id = $form['order_id']['#value'];

  // If an expiration date and a Branch Distributor's ID has been supplied,
  // the BD has accepted the charges associated with downloading UPC Books.
  if (($expiration = $form['expiration']['#value']) && ($bd_id = $form['bd_id']['#value'])) {

    // Add this BD to the list of BDs that have accepted the charges so we won't
    // prompt them again until the $expiration date.
    $accepted = variable_get('upc_download_accept', array());
    $accepted[$bd_id] = $expiration;
    variable_set('upc_download_accept', $accepted);
  }

  // Notify the appropriate parties that the BD has opted into the program.
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order_id);
  stihl_orders_send_order_status_change_email($order_wrapper, 'fee_acknowledged');

  // Download the UPC Book associated with the order.
  stihl_orders_download_upc_book($order_id, $form['include_price']['#value']);
}

/**
 * Download the UPC Book associated with an order.
 */
function stihl_orders_download_upc_book($order_id, $include_price) {

  // Determine if the request is for a UPC Book with/without pricing:
  // With pricing: $include_price = 'pricing'.
  // Without pricing: $include_price = 'no-pricing'.
  $include_price = $include_price == 'pricing';

  // Attempt to create a UPC Book for this $order_id.
  $file_path = stihl_orders_create_upc_book($order_id, $include_price);

  // If the UPC Book was generated successfully and we can access the file,
  // track the download if necessary and download the file.
  if (isset($file_path) && file_exists($file_path)) {

    // Determine if we need to track this UPC Download.
    if (stihl_orders_track_download()) {
      $order = commerce_order_load($order_id);

      // If this is the first download, initialize the counter at 0.
      if (empty($order->field_upc_downloads[LANGUAGE_NONE][0]['value'])) {
        $order->field_upc_downloads[LANGUAGE_NONE][0]['value'] = 0;
      }

      // Increment the download counter.
      $order->field_upc_downloads[LANGUAGE_NONE][0]['value']++;

      // Save the order.
      commerce_order_save($order);
    }

    // Download the file.
    classic_core_force_download($file_path);
  }
  else {
    drupal_not_found();
  }
}

/**
 * Create a UPC Book for a given order.
 *
 * @param int $order_id
 *   The id associated with the order.
 * @param bool $include_price
 *   Indicates if the UPC Book should include the prices
 *   of the items associated with the order.
 *
 * @return string
 *   Returns the path to the UPC Book file on success,
 *   and returns NULL on failure.
 */
function stihl_orders_create_upc_book($order_id, $include_price = TRUE) {

  // Load the order.
  $order = commerce_order_load($order_id);

  // User submitting order and their bd location.
  $submitter = entity_metadata_wrapper('user', $order->uid);
  $bd = $submitter->field_bd_reference->value();

  // Initialize an array to hold the data required to create the UPC Book.
  $data = [];

  // Iterate line items to create csv row of field data.
  foreach ($order->commerce_line_items[LANGUAGE_NONE] as $line_item) {

    $line_item = entity_metadata_wrapper('commerce_line_item', $line_item['line_item_id']);
    $product = entity_metadata_wrapper('commerce_product', $line_item->commerce_product->value());

    // Each $line_item creates a unique "record" to be sent to FusionPro.
    // Match the FP field names to their corresponding $line_item value and
    // push the record to the $data array.
    $data[] = [
      'Order ID' => $order->order_id,
      'Ordered For' => $bd->name,
      'Ordered For ID' => $bd->id,
      'RLC SKU' => $product->sku->value(),
      'Price' => $line_item->field_tag_price->value(),
      'Pricing Language' => $line_item->field_special_pricing_language->value(),
      'Include Price' => $include_price == TRUE ? 'Y' : 'N',
      'Model' => stihl_orders_convert_fusionpro_characters($product->field_model->value()),
      'Model Subhead' => stihl_orders_convert_fusionpro_characters($product->field_model_subhead->value()),
      'Main Length' => stihl_orders_convert_fusionpro_characters($product->field_main_length->value()),
      'Part Number' => $product->field_part_number->value(),
      'UPC Code' => $product->field_upc_code->value(),
      'UPC Heading' => stihl_orders_convert_fusionpro_characters($product->field_upc_heading->value()),
    ];
  }

  // Sort the data alphabetically by UPC Heading.
  usort($data, function ($a, $b) {
    return strnatcasecmp($a['UPC Heading'], $b['UPC Heading']);
  });

  // Determine the name of this UPC Book.
  $pricing_indicator = $include_price == TRUE ? 'P' : 'NP';
  $file_name = "{$order_id}_{$pricing_indicator}_UPC";

  // Attempt the load the FusionPro template configuration
  // associated with "UPC Books".
  $template_config = fp_template_configs_load_by_name(STIHL_ORDERS_UPC_TEMPLATE_CONFIG);

  // If a config is found and it is able to successfully
  // compose the data, we're done.
  if ($template_config && $output = $template_config->compose($data, $file_name)) {
    return $output;
  }

  // Otherwise, something went wrong and we need to report that to the log.
  else {
    $message = t('Unable to retrieve UPC Book file for order !order_id');
    $replace = array('!order_id' => $order->order_id);
    watchdog('stihl_orders', $message, $replace, WATCHDOG_WARNING);

    return NULL;
  }
}
