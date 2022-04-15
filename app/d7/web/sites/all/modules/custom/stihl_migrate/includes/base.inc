<?php

/**
 * @file
 * Contains base migration class for Stihl.
 */

/**
 * Base class providing common utility methods.
 */
class StihlMigrateBase extends Migration {

  /**
   * StihlMigrateBase constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    ini_set('auto_detect_line_endings', TRUE);
  }

  /**
   * Determine and set boolean value based on y, n, or empty csv value.
   *
   * @param string $source
   *   The csv field value.
   *
   * @return bool
   *   Returns 1 or 0.
   */
  protected function setBoolean($source) {
    $field = drupal_strtoupper($source);
    return ($field == 'Y' || $field == 'YES') ? 1 : 0;
  }

}
