<?php

/**
 * @file
 * Stihl pricing years entity class.
 */

/**
 * Pricing Year entity class.
 */
class StihlPricingYearsEntity extends Entity {

  /**
   * Override with a custom URI.
   */
  protected function defaultUri() {
    return array('path' => STIHL_PRICING_YEARS_VIEW_URI . '/' . $this->identifier());
  }

}
