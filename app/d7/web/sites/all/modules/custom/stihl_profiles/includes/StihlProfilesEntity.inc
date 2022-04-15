<?php

/**
 * @file
 * Stihl profile entity class.
 */

/**
 * Profile entity class.
 */
class StihlProfilesEntity extends Entity {

  /**
   * Override with a custom URI.
   */
  protected function defaultUri() {
    return array('path' => STIHL_PROFILES_VIEW_URI . '/' . $this->identifier());
  }

}
