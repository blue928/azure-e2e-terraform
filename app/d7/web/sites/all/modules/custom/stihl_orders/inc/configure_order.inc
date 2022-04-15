<?php

/**
 * @file
 * Include file for functionality around configuring pricing on an order.
 */

/**
 * Render a custom form for each line item in an order.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_render_configure_line_items_form($form, &$form_state, $order_id) {
  try {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order_id);

    // If a recent product migration removed products from this order,
    // display a user message containing the SKUs removed.
    $form['migrate_message'] = stihl_orders_render_product_removed_message($order_wrapper);

    // Duplicate form submit buttons on top of form.
    $form['submit_order_top'] = array(
      '#type' => 'submit',
      '#value' => t('Proceed to Checkout'),
      '#attributes' => array(
        'class' => array('btn-default'),
      ),
    );
    $form['save_order_top'] = array(
      '#type' => 'submit',
      '#value' => t('Save Order'),
      '#attributes' => array(
        'class' => array('btn-success'),
      ),
    );

    $form['#prefix'] = '<div class="div-table">';
    $form['#suffix'] = '</div>';

    $line_items = $order_wrapper->commerce_line_items->value();
    $contains_kits = $order_wrapper->field_order_contains_kits->value();
    $order_pricing_year = $order_wrapper->field_pricing_year_reference->pricing_year->value();
    $bd_id = stihl_core_get_bd_id($order_wrapper->uid->value());

    // Variable to keep track of number of line items that belong to a
    // taxonomy term.
    $product_group_totals = array();

    // Set up key in array to hold fieldset data.
    $form['fieldsets'] = array(
      '#type' => 'container',
    );

    // Get current uri so that we can pass it as a 'destination' parameter and
    // redirect back to this page after removing a line item from an order.
    $destination = drupal_get_destination();
    $params = array('query' => array($destination));

    // Loop through line items and create form rows and elements.
    foreach ($line_items as $line_item) {
      $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);

      // Skip rows with bad Line Item data.
      if (!$tid = stihl_orders_get_product_line_item_term_id($line_item_wrapper, $order_id)) {
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
      $form['fieldsets'][$tid]['row']['#prefix'] = '<div id="category-' . $tid . '" class="category">';
      $form['fieldsets'][$tid]['row']['#suffix'] = '</div>';

      // Adds each fieldset navigation for the user.
      $form['fieldsets'][$tid]['nav'] = array(
        '#prefix' => '<div class="fieldset-nav"><button class="btn prev" href="#">Previous Selection</button>',
        '#suffix' => '<button class="btn next" href="#">Next Selection</button></div>',
      );

      $form['fieldsets'][$tid]['row'][$lid] = array(
        '#prefix' => '<div id="lid-' . $lid . '" class="row">',
        '#suffix' => '</div>',
        '#tree' => TRUE,
      );

      // Line item remove link.
      $remove_link = l(t('remove'), 'remove-hangtag/' . $order_id . '/' . $line_item->line_item_id, $params);

      $form['fieldsets'][$tid]['row'][$lid]['title'] = array(
        '#markup' => $line_item_wrapper->commerce_product->title->value(),
        '#prefix' => '<div class="line-col sku"><label class="control-label">SKU</label><p class="product">',
        '#suffix' => " <small>$remove_link</small></p></div>",
        '#title' => t('Title'),
      );

      // If the order contains kits, show the Kit Quantity fields,
      // otherwise, show the 'Quantity' field.
      if ($contains_kits == 'Yes') {
        $form['fieldsets'][$tid]['row'][$lid]['field_kit_1_qty'] = array(
          '#type' => 'textfield',
          '#prefix' => '<div class="line-col kit kit-1">',
          '#suffix' => '</div>',
          '#title' => t('Tag Qty Kit 1'),
          '#default_value' => $line_item_wrapper->field_kit_1_qty->value(),
          '#element_validate' => array('_stihl_orders_qty_validation'),
        );
        $form['fieldsets'][$tid]['row'][$lid]['field_kit_2_qty'] = array(
          '#type' => 'textfield',
          '#prefix' => '<div class="line-col kit kit-2">',
          '#suffix' => '</div>',
          '#title' => t('Tag Qty Kit 2'),
          '#default_value' => $line_item_wrapper->field_kit_2_qty->value(),
          '#element_validate' => array('_stihl_orders_qty_validation'),
        );
      }

      $form['fieldsets'][$tid]['row'][$lid]['field_order_bulk'] = array(
        '#type' => 'textfield',
        '#prefix' => '<div class="line-col bulk">',
        '#suffix' => '</div>',
        '#title' => t('Bulk Quantity'),
        '#default_value' => $line_item_wrapper->field_order_bulk->value(),
        '#element_validate' => array('_stihl_orders_qty_validation'),
      );

      $hangtag_price = $line_item_wrapper->field_tag_price->value();

      // Hang tag price is conditional based on including Powerchord data,
      // a specific BD, and the pricing year for the order.
      if ($order_wrapper->field_include_powerchord_data->value() == 'Yes') {
        // Look up price for new orders containing Powerchord data.
        if (empty($hangtag_price)) {
          $sku = $line_item_wrapper->commerce_product->sku->value();
          $hangtag_price = stihl_orders_get_product_price_by_year($bd_id, $sku, $order_pricing_year);
        }
      }

      $form['fieldsets'][$tid]['row'][$lid]['field_tag_price'] = array(
        '#type' => 'textfield',
        '#prefix' => '<div class="line-col price">',
        '#suffix' => '</div>',
        '#title' => t('Price'),
        '#default_value' => $hangtag_price,
        '#maxlength' => 7,
        '#element_validate' => array('_stihl_orders_price_validation'),
      );

      // Add sign style to order form if the BD user is not STIHL Southeast.
      $sign_style = stihl_orders_get_sign_type_field($line_item_wrapper);
      $form['fieldsets'][$tid]['row'][$lid]['sign_style'] = $sign_style;
      if ($bd_id == '10') {
        // BD 10 doesn't need to see Sign styles.
        // - Rather than omitting the field, we're setting the type to
        //   'disabled'.
        // - The default value is 'vertical one sided'.
        $form['fieldsets'][$tid]['row'][$lid]['sign_style']['#disabled'] = TRUE;
      }

      // Conditionally generate the form for extra options for line item.
      // If $line_item is a chainsaw, load the chainsaw extra fields.
      if ($line_item_wrapper->commerce_product->field_chainsaw->value()) {
        $chainsaw_sub_form = stihl_orders_chainsaws_extra_form_fields($line_item_wrapper);
        $form['fieldsets'][$tid]['row'][$lid]['extras']['variations'] = $chainsaw_sub_form;
      }

      // Display the battery accessory pricing form when present. If the
      // accessories include discreet pricing, then we need to present extra
      // fields so that the user may change that pricing.
      if ($special_pricing_string = $line_item_wrapper->field_special_pricing_language->value()) {
        $pattern = strtr('/^Includes :unit, :battery and :charger$/iu', array(
          ':unit' => stihl_orders_special_pricing_create_named_capture_group('unit'),
          ':battery' => stihl_orders_special_pricing_create_named_capture_group('battery'),
          ':charger' => stihl_orders_special_pricing_create_named_capture_group('charger'),
        ));

        preg_match($pattern, $special_pricing_string, $matches);
        $form['fieldsets'][$tid]['row'][$lid]['extras']['special_pricing'] = stihl_orders_battery_special_pricing_language_subform($special_pricing_string, $matches);
      }

      $product_group_totals[$tid]++;
    }

    // Add product group totals to fieldset titles.
    foreach ($product_group_totals as $tid => $total) {
      $count = ' - <span class="small">completed <span class="tid-completed">0</span> of ' . $total . '</span>';
      $form['fieldsets'][$tid]['#title'] = $form['fieldsets'][$tid]['#title'] . $count;
    }

    // Pass order id to the submit handler.
    $form['#order_id'] = $order_id;

    $form['scripts'] = array(
      '#attached' => array(
        'js' => array(
          drupal_get_path('module', 'stihl_orders') . '/assets/js/stihl_orders.js',
        ),
        'css' => array(
          drupal_get_path('module', 'stihl_orders') . '/assets/js/stihl_orders.css',
        ),
      ),
    );
    $form['submit_order'] = array(
      '#type' => 'submit',
      '#value' => t('Proceed to Checkout'),
      '#attributes' => array(
        'class' => array('btn-default'),
      ),
    );
    $form['save_order'] = array(
      '#type' => 'submit',
      '#value' => t('Save Order'),
      '#attributes' => array(
        'class' => array('btn-success'),
      ),
    );

    // Get vocab id and pass to function to sort fieldsets by the order they
    // appear in the left nav bar.
    // - We're checking to see if the order has line items before trying to
    //   sort the fielsets within the order.
    if (!empty($line_items)) {
      $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_items[0]);
      $vid = $line_item_wrapper->commerce_product->field_product_category->value()->vid;

      _stihl_orders_sort_by_term($form, $vid);
    }

    return $form;
  }
  catch (Exception $e) {
    // If the order doesn't exist, present the 'Page Not Found' message.
    watchdog('stihl_orders',
      'The Configure Order form failed to build with the following exception: exception.',
      array('exception' => $e->getMessage()),
      WATCHDOG_ERROR
    );
    drupal_not_found();
  }
}

/**
 * Validation for _stihl_orders_render_configure_line_items_form().
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_render_configure_line_items_form_validate($form, &$form_state) {

}

/**
 * Validation for the price field.
 *
 * @param array $element
 *   Commerce line item form field.
 *
 * @TODO: Use form_set_value to correct the values and submit the form.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_price_validation(array $element, $form, &$form_state) {
  // Strip out non-numeric characters from the value except decimals.
  $price = $element['#value'];
  if (!empty($price) && !is_numeric($price)) {
    $new_price = preg_replace("/[^0-9.]/", "", $price);
    // Let the user know the specific errors.
    // Ideally, we'd use form_set_value() to correct the value and submit it.
    form_error($element, t('Please replace price :price with :new_price.', array(':price' => $price, ':new_price' => $new_price)));
  }
  // Show error if value does not have a decimal.
  // We should insert the decimal for them, but form_set_value() isn't working.
  /*
  if (!empty($element['#value']) && !is_float($element['#value'] + 0)) {
    form_error($element, t('The price field must have a decimal.'));
  }
  */
}

/**
 * Validation for quantity fields.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function _stihl_orders_qty_validation($element, $form, &$form_state) {
  if (strlen($element['#value']) > 0 && !is_numeric($element['#value'])) {
    form_error($element, t('Please enter a valid number or remove entry.'));
  }
}

/**
 * Submit handler for _stihl_orders_render_configure_line_items_form().
 */
function _stihl_orders_render_configure_line_items_form_submit($form, &$form_state) {
  $order_id = $form['#order_id'];
  $values = $form_state['values'];

  // Filter out array keys that aren't numeric. (Not a line item ID).
  $lid_keys = array_filter(array_keys($values), function ($k) {
    return is_numeric($k);
  });
  $lid_values = array_intersect_key($values, array_flip($lid_keys));

  $order_wrapper = entity_metadata_wrapper('commerce_order', $order_id);
  $contains_kits = $order_wrapper->field_order_contains_kits->value();

  // Save form values back to line items.
  foreach ($lid_values as $lid => $value) {
    $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $lid);

    // If order contains kits, save those values to line item.
    if ($contains_kits == 'Yes') {
      $kit1_qty = $value['field_kit_1_qty'];
      $kit2_qty = $value['field_kit_2_qty'];

      $line_item_wrapper->field_kit_1_qty = (is_numeric($kit1_qty)) ? $kit1_qty : NULL;
      $line_item_wrapper->field_kit_2_qty = (is_numeric($kit2_qty)) ? $kit2_qty : NULL;
    }

    $bulk = $value['field_order_bulk'];
    $hangtag_price = $value['field_tag_price'];

    // If $bulk is not empty set value to $bulk. Otherwise set to 0.
    $line_item_wrapper->field_order_bulk = (is_numeric($bulk)) ? $bulk : NULL;

    if (!empty($hangtag_price)) {
      $line_item_wrapper->field_tag_price = $hangtag_price;
    }

    // See STIHL-146.  Sign style is required for every order.
    $line_item_wrapper->field_sign_style = $value['sign_style'];

    // Check to see if there are any 'extras' for this line item.
    if (array_key_exists('extras', $value)) {
      // If line item is a chain saw, save it's "variations" to the line item.
      if ($line_item_wrapper->commerce_product->field_chainsaw->value() && array_key_exists('variations', $value['extras'])) {
        // Save the variations for different chainsaw lengths.
        $variations = $value['extras']['variations'];
        foreach ($variations as $key => $variation) {
          $line_item_wrapper->{$key} = $variation;
        }
      }

      // If there is a `special_pricing` key in `$form_state['values']['extras']
      // and it contains more than one value in its array, then it's Special
      // Pricing Language input with discreet prices. We need to convert the
      // prices back to a string and save it to the line item.
      if (array_key_exists('special_pricing', $value['extras']) && count($value['extras']['special_pricing']) > 1) {
        $line_item_wrapper->field_special_pricing_language = stihl_orders_set_special_pricing_language_value($value['extras']['special_pricing']);
      }
    }

    // Save the line item.
    $line_item_wrapper->save();
  }

  switch ($form_state['triggering_element']['#id']) {
    case 'edit-submit-order-top':
    case 'edit-submit-order':
      // Generate a downloadable csv file for RL approval.
      stihl_orders_export_approval_csv($order_id);
      $form_state['redirect'] = array('/orders/submit/' . $order_id);
      break;

    case 'edit-save-order-top':
    case 'edit-save-order':
      drupal_set_message(t('Order saved!'));
      $form_state['redirect'] = 'orders/configure/' . $order_id;
      break;

    default:
      $form_state['redirect'] = 'orders/list';

  }
}

/**
 * Returns custom form fields for chainsaw hangtags on order config page.
 *
 * @param EntityMetadataWrapper $line_item_wrapper
 *   Commerce line item.
 *
 * @return array
 *   Renderable array of form fields.
 */
function stihl_orders_chainsaws_extra_form_fields(EntityMetadataWrapper $line_item_wrapper) {
  $form = array();

  // Create three form groups to correspond to the 3 max product variations
  // that a user can add to a Hangtag.
  $variations = stihl_orders_get_hangtag_variations($line_item_wrapper);

  // Make sure there are variations then return the extra fields. Otherwise
  // we could return an empty wrapper div without contents.
  if (!empty($variations)) {
    $form = array(
      '#prefix' => '<div class="line-col extra-fields">',
      '#suffix' => '</div>',
    );
  }

  // We need to make sure that there are some variations before going through
  // the process of creating these form elements.
  if (!empty($variations)) {
    // Initialize counter.
    $count = count($variations) <= 3 ? count($variations) : 3;
    for ($i = 1; $i <= $count; $i++) {
      // Using the $key as the default value if value hasn't been previously
      // selected.
      $form['field_variation_name_' . $i] = array(
        '#type' => 'select',
        '#prefix' => '<div class="line-col extra">',
        '#suffix' => '</div>',
        '#options' => $variations,
        '#title' => t('Extra') . ' ' . $i,
        '#empty_value' => '',
        '#default_value' => $line_item_wrapper->{'field_variation_name_' . $i}->value() ?: NULL,
      );

      $form['field_variation_price_' . $i] = array(
        '#type' => 'textfield',
        '#prefix' => '<div class="line-col extra">',
        '#suffix' => '</div>',
        '#title' => t('Price for') . ' ' . $i,
        '#default_value' => $line_item_wrapper->{'field_variation_price_' . $i}->value(),
        '#element_validate' => array('_stihl_orders_price_validation'),
      );
    }
  }

  return $form;
}

/**
 * Returns custom form fields for lithium ion hang tags on order config page.
 *
 * @param string $special_pricing_string
 *   String containing Special Pricing Language from the Line Item.
 * @param array $special_pricing_matches
 *   Array containing the matches from the discreet pricing regex.
 *
 * @return array
 *   The Special Pricing Language sub-form.
 */
function stihl_orders_battery_special_pricing_language_subform($special_pricing_string, array $special_pricing_matches = array()) {
  $form = array(
    '#prefix' => '<div class="line-col extra-fields">',
    '#suffix' => '</div>',
  );

  if (!empty($special_pricing_matches)) {
    $form['unit'] = array(
      '#type' => 'textfield',
      '#prefix' => '<div class="line-col extra">',
      '#suffix' => '</div>',
      '#title' => t('Unit Price'),
      '#element_validate' => array('_stihl_orders_price_validation'),
      '#default_value' => $special_pricing_matches['unit'] ?? NULL,
    );
    $form['battery_model'] = array(
      '#type' => 'select',
      '#prefix' => '<div class="line-col extra">',
      '#suffix' => '</div>',
      '#title' => t('Battery Model'),
      '#options' => stihl_orders_get_battery_accessories(),
      '#empty_value' => 'Battery',
      '#default_value' => $special_pricing_matches['battery_model'] ?? NULL,
    );
    $form['battery'] = array(
      '#type' => 'textfield',
      '#prefix' => '<div class="line-col extra">',
      '#suffix' => '</div>',
      '#title' => t('Battery Price'),
      '#element_validate' => array('_stihl_orders_price_validation'),
      '#default_value' => $special_pricing_matches['battery'] ?? NULL,
    );
    $form['charger_model'] = array(
      '#type' => 'select',
      '#prefix' => '<div class="line-col extra">',
      '#suffix' => '</div>',
      '#title' => t('Charger Model'),
      '#options' => stihl_orders_get_charger_accessories(),
      '#empty_value' => 'Charger',
      '#default_value' => $special_pricing_matches['charger_model'] ?? NULL,
    );
    $form['charger'] = array(
      '#type' => 'textfield',
      '#prefix' => '<div class="line-col extra">',
      '#suffix' => '</div>',
      '#title' => t('Charger Price'),
      '#element_validate' => array('_stihl_orders_price_validation'),
      '#default_value' => $special_pricing_matches['charger'] ?? NULL,
    );
  }
  $form['string'] = array(
    '#type' => 'textfield',
    '#prefix' => $special_pricing_matches ? '<div hidden>' : '<div class="line-col extra full">',
    '#suffix' => '</div>',
    '#title' => t('Special Pricing Language'),
    '#default_value' => $special_pricing_string,
    '#attributes' => array(
      'disabled' => TRUE,
    ),
  );

  return $form;
}

/**
 * Returns custom form fields for battery hangtags on order config page.
 *
 * @param EntityMetadataWrapper $line_item_wrapper
 *   Commerce line item.
 *
 * @return array
 *   Renderable array of form fields.
 */
function stihl_orders_get_sign_type_field(EntityMetadataWrapper $line_item_wrapper) {
  // Select the default value as "Vertical 1-Sided" unless the form value has
  // been previously saved.
  $default_value = 'vertical_one_sided';
  $saved_sign_style = $line_item_wrapper->field_sign_style->value();
  if (isset($saved_sign_style)) {
    $default_value = $saved_sign_style;
  }

  $form = array(
    '#type' => 'select',
    '#title' => t('Layout Style'),
    '#prefix' => '<div class="line-col sign-style">',
    '#suffix' => '</div>',
    '#options' => stihl_orders_get_hangtag_sign_styles($line_item_wrapper),
    '#empty_option' => t('Select Sign Style'),
    '#required' => TRUE,
    '#default_value' => $default_value,
  );

  return $form;
}

/**
 * Helper function to define sign style options.
 *
 * @param EntityMetadataWrapper $line_item_wrapper
 *   Commerce line item.
 *
 * @return array
 *   Array of select list items.
 */
function stihl_orders_get_hangtag_sign_styles(EntityMetadataWrapper $line_item_wrapper) {
  // Get the boolean value of the current line item's field_horizontal_hangtag.
  $horizontal_value = $line_item_wrapper->commerce_product->field_horizontal_hangtag->value();
  // Create the select list options.
  $list = array(
    'vertical_one_sided' => t('Vertical 1-Sided'),
    'vertical_two_sided' => t('Vertical 2-Sided'),
  );
  // If the field_horizontal_hangtag value is true add horizontal to the list.
  if ($horizontal_value) {
    $list = array('horizontal' => t('Horizontal')) + $list;
  }

  return $list;
}

/**
 * Helper function to return 'variations' of a hangtag.
 *
 * This should query for other products with the same SKU and return an
 * associative array.
 *
 * @param EntityMetadataWrapper $line_item_wrapper
 *   A line item wrapper object.
 */
function stihl_orders_get_hangtag_variations(EntityMetadataWrapper $line_item_wrapper) {
  // Get the model number of the current line item.
  $model_number = $line_item_wrapper->commerce_product->field_model->value();

  // Don't include the current product in the query below.
  $current_product_id = $line_item_wrapper->commerce_product->product_id->value();

  // We only want to get variants that have matching Special Pricing Language.
  $special_pricing_language = $line_item_wrapper->commerce_product->field_special_pricing_language->value();

  // Select products with the same SKU and not include current line item.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'commerce_product')
    ->propertyCondition('product_id', $current_product_id, '!=')
    ->addMetaData('account', user_load(1))
    ->fieldCondition('field_model', 'value', $model_number, '=');

  if ($special_pricing_language) {
    $query->fieldCondition('field_special_pricing_language', 'value', $special_pricing_language, '=');
  }

  $result = $query->execute();

  // Array to contain key=>val pairs for 'variation' options.
  $variation_options = array();

  if (isset($result['commerce_product'])) {
    $product_ids = array_keys($result['commerce_product']);

    foreach ($product_ids as $product_id) {
      $temp_line_emw = entity_metadata_wrapper('commerce_product', $product_id);

      // Get a two digit value for "extra" bar lengths.
      $bar_length = stihl_orders_convert_extra_bar_length($temp_line_emw);

      $variation_options[$bar_length] = $temp_line_emw->title->value();
    }
  }
  return $variation_options;
}

/**
 * Get "extras" optional chain saw bar length from product entity.
 *
 * The bar length sent to Fusion Pro needs to be the two digits of the
 * length. All other character need to be removed.
 *
 * @param EntityMetadataWrapper $product
 *   The product to match additional bar lengths.
 *
 * @return int
 *   The two digit "extras" value to be printed on a hang tag.
 */
function stihl_orders_convert_extra_bar_length(EntityMetadataWrapper $product) {

  // The SKU number for chain saws seem consistent example: MS461R-25.
  // Remove the bar length from the SKU number.
  if (($position = strpos($product->sku->value(), '-')) !== FALSE) {
    return substr($product->sku->value(), ($position + 1));
  }
  return $product->sku->value();
}

/**
 * Returns the input prices in the form of the Special Pricing Language string.
 *
 * @param array $special_pricing
 *   The input Special Pricing Language form state values.
 *
 * @return string
 *   The input prices in the form of the Special Pricing Language string.
 */
function stihl_orders_set_special_pricing_language_value(array $special_pricing) {
  return t('Includes $!unit Unit, $!battery !battery_model and $!charger !charger_model', array(
    '!unit' => $special_pricing['unit'] ?: '000.00',
    '!battery' => $special_pricing['battery'] ?: '000.00',
    '!battery_model' => $special_pricing['battery_model'] ?: 'Battery',
    '!charger' => $special_pricing['charger'] ?: '000.00',
    '!charger_model' => $special_pricing['charger_model'] ?: 'Charger',
  ));
}

/**
 * Generate a downloadable csv file for a submitted order.
 *
 * This csv file is downloaded by a Red Letter admin used for order approval.
 *
 * @param int $order_id
 *   The id of the order being submitted.
 */
function stihl_orders_export_approval_csv($order_id) {
  $order = entity_metadata_wrapper('commerce_order', $order_id);
  $order_year = $order->field_pricing_year_reference->pricing_year->value();

  // User submitting order and their bd location.
  $submitter = entity_metadata_wrapper('user', $order->uid->value());
  $bd = $submitter->field_bd_reference->value();

  // Remove existing approval csv file.
  $file_path = STIHL_ORDERS_APPROVAL_URI . "{$order_id}.csv";
  if (stihl_orders_attempt_file_resource($file_path, 'r', FALSE) !== FALSE) {
    file_unmanaged_delete($file_path);
  }

  // Iterate line items to create csv row of field data.
  foreach ($order->commerce_line_items as $line_item) {

    $product = entity_metadata_wrapper('commerce_product', $line_item->commerce_product->value());

    // File path for downloadable csv file. File path must be an array.
    $file_paths_array = array($file_path);

    // Build an array of fields for a csv row.
    $fields['Order ID'] = $order_id;
    $fields['Order Name'] = $order->field_order_title->value();
    $fields['Pricing Year'] = $order_year;
    $fields['Ordered By'] = $submitter->name->value();
    $fields['Ordered For'] = $bd->name;
    $fields['Ordered For ID'] = $bd->id;
    $fields['Format'] = $line_item->field_sign_style->value();
    $fields['Model'] = $product->field_model->value();
    $fields['Model Subhead'] = $product->field_model_subhead->value();
    $fields['RLC SKU'] = $product->sku->value();
    $fields['Kit #1 Quantity'] = $order->field_order_kit_1_qty->value();
    $fields['# Product Tags - Kit #1'] = $line_item->field_kit_1_qty->value();
    $fields['Kit #2 Quantity'] = $order->field_order_kit_2_qty->value();
    $fields['# Product Tags - Kit #2'] = $line_item->field_kit_2_qty->value();
    $fields['Bulk Tag Qty'] = $line_item->field_order_bulk->value();

    // Stihl Southeast (BD ID #10) should not see pricing information.
    $fields['Product Price'] = ($bd->id != 10) ? $line_item->field_tag_price->value() : '';
    $fields['Chain Saw Main Price'] = ($product->field_chainsaw->value() && $bd->id != 10) ? $line_item->field_tag_price->value() : '';
    $fields['Bar Length 1'] = $line_item->field_variation_name_1->value();
    $fields['Chain Saw Price 1'] = ($bd->id != 10) ? $line_item->field_variation_price_1->value() : '';
    $fields['Bar Length 2'] = $line_item->field_variation_name_2->value();
    $fields['Chain Saw Price 2'] = ($bd->id != 10) ? $line_item->field_variation_price_2->value() : '';
    $fields['Bar Length 3'] = $line_item->field_variation_name_3->value();
    $fields['Chain Saw Price 3'] = ($bd->id != 10) ? $line_item->field_variation_price_3->value() : '';
    $fields['Main Length'] = $product->field_main_length->value();
    $fields['Pricing Language'] = $line_item->field_special_pricing_language->value();

    // Write the fields to a csv row.
    stihl_orders_write_row_to_csv($file_paths_array, $fields);
  }

  // Watchdog successful csv file creation.
  $message = t('Successfully exported RL approval csv file(s) for order !order_id');
  $replace = array('!order_id' => $order_id);
  watchdog('stihl_orders', $message, $replace, WATCHDOG_INFO);
}

/**
 * Creates a named capture group pattern for a Regular Expression.
 *
 * @param string $name
 *   Name of the group.
 *
 * @return string
 *   Returns a Regular Expression pattern.
 */
function stihl_orders_special_pricing_create_named_capture_group($name) {
  return strtr('\\$(?<:name>\d{1,4}\.\d{2}) (?<:name_model>[\w\s]+)', array(
    ':name' => $name,
  ));
}

/**
 * Query the database for enabled product titles in an array of categories.
 *
 * @param array $categories
 *   An array of taxonomy term names.
 *
 * @return array
 *   Returns an array of product titles.
 */
function stihl_orders_query_products_by_category(array $categories) {
  if ($categories) {
    $sql = 'SELECT product.title FROM {taxonomy_term_data} AS term
      JOIN {field_data_field_product_category} AS category ON term.tid = category.field_product_category_tid
      JOIN {commerce_product} AS product ON category.entity_id = product.product_id
      WHERE term.name IN (:categories) AND status = :status ORDER BY product.title';

    $variables = array(':categories' => $categories, ':status' => TRUE);
    $result = db_query($sql, $variables)->fetchAllKeyed(0, 0);
  }
  return $result ?: array();
}

/**
 * Get a list of all product titles in an array of categories.
 *
 * @param array $categories
 *   An array of taxonomy term names.
 *
 * @return array
 *   Returns an array of product titles.
 */
function stihl_orders_get_products_by_categories(array $categories) {
  // Statically cache the products.
  $products_by_category =& drupal_static(__FUNCTION__, array());
  // Create an 8 character hash of the $categories so to be used to identify the
  // results for future requests.
  $category_hash = substr(md5(implode('|', $categories)), 0, 8);
  if (is_null($products = &$products_by_category[$category_hash])) {
    $products = stihl_orders_query_products_by_category($categories);
  }
  return $products;
}

/**
 * Get a list of all available products defined as "Battery Accessories".
 *
 * @return array
 *   Returns an array of product titles.
 */
function stihl_orders_get_battery_accessories() {
  return stihl_orders_get_products_by_categories(array(
    'Battery Accessories – Batteries',
    'Battery Accessories – Backpack Batteries',
  ));
}

/**
 * Get a list of all available products defined as "Charger Accessories".
 *
 * @return array
 *   Returns an array of product titles.
 */
function stihl_orders_get_charger_accessories() {
  return stihl_orders_get_products_by_categories(array(
    'Battery Accessories – Chargers',
  ));
}
