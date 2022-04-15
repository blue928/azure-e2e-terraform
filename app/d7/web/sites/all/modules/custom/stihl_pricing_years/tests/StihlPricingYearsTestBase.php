<?php

/**
 * @file
 * Unit tests for stihl_pricing_years module.
 */

/**
 * Class StihlPricingYearsTestBase.
 */
class StihlPricingYearsTestBase extends PHPUnit_Framework_TestCase {

  /**
   * Creates a test Pricing Year.
   *
   * @param array $properties
   *   (Optional) keyed array used to set properties of the Pricing Year object.
   *
   * @return object
   *   Returns a test Pricing Year as an EntityMetadataWrapper object.
   */
  protected static function createTestPricingYear(array $properties = array()) {
    $default_properties = array(
      'pricing_year' => '2018',
      'details' => 'Test Pricing Year',
      'enabled' => TRUE,
      'bulk_one_sided' => (float) 0.305,
      'kitted_one_sided' => (float) 0.335,
      'bulk_two_sided' => (float) 0.345,
      'kitted_two_sided' => (float) 0.375,
      'upc_book' => (float) 0,
      'default_pricing' => FALSE,
    );
    $pricing_year = new stdClass();
    $pricing_year->type = 'stihl_pricing_years';
    foreach ($default_properties as $property => $value) {
      $pricing_year->{$property} = $properties[$property] ?? $value;
    }
    $wrapper = entity_metadata_wrapper('stihl_pricing_years', $pricing_year);
    $wrapper->save();
    return $wrapper;
  }

}
