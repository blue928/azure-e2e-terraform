<?php

/**
 * @file
 * Stihl pricing entity class.
 */

/**
 * Profile entity class.
 */
class StihlPricingEntity extends Entity {

  /**
   * Override with a custom URI.
   */
  protected function defaultUri() {
    return array('path' => STIHL_PRICING_VIEW_URI . '/' . $this->identifier());
  }

  /**
   * BD profile entity reference getter method.
   */
  public function bdReference() {
    return stihl_profiles_load($this->bd_reference);
  }

  /**
   * BD profile entity reference setter method.
   */
  public function setBdReference($id) {
    $this->bd_reference = is_object($id) ? $id->id : $id;
  }

}
