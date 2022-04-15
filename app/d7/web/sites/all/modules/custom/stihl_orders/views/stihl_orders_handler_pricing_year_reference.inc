<?php

/**
 * @file
 * Contains the custom Pricing Year Reference views handler.
 */

/**
 * Class StihlOrdersHandlerPricingYearReference.
 */
class StihlOrdersHandlerPricingYearReference extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Do nothing -- to override the parent query.
  }

  /**
   * Returns Pricing Year without description.
   *
   * @param object $data
   *   The data to be manipulated in the rendered output.
   *
   * @return string
   *   The rendered output.
   */
  public function render($data) {
    $commerce_order = entity_load_single('commerce_order', $data->order_id);
    if($commerce_order->field_pricing_year_reference) {
      $pricing = entity_load_single('stihl_pricing_years', $commerce_order->field_pricing_year_reference[LANGUAGE_NONE][0]['target_id']);
      $pricing_year = $pricing->pricing_year;
    } else {
      $pricing_year = null;
    }
    return t('@pricing_year', array('@pricing_year' => $pricing_year));
  }

}
