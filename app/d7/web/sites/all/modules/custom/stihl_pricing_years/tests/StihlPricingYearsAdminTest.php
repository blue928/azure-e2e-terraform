<?php

/**
 * @file
 * Unit tests for stihl_pricing_years admin functions.
 */

$base_path = drupal_get_path('module', 'stihl_pricing_years');
include_once "$base_path/tests/StihlPricingYearsTestBase.php";
include_once "$base_path/inc/stihl_pricing_years.admin.inc";

/**
 * Class StihlPricingYearsAdmin.
 */
class StihlPricingYearsAdminTest extends StihlPricingYearsTestBase {

  protected static $cleanUpIds = array();

  /**
   * {@inheritdoc}
   */
  public static function tearDownAfterClass() {
    entity_delete_multiple('stihl_pricing_years', self::$cleanUpIds);
  }

  /**
   * Data provider for testStihlPricingYearsGetDefaultPricingYear.
   */
  public function defaultPricingYearData() {
    $data = array();

    // Default pricing year.
    $default_pricing_year = self::createTestPricingYear(array(
      'pricing_year' => '1999',
      'default_pricing' => TRUE,
    ));
    self::$cleanUpIds[] = $default_pricing_year->getIdentifier();
    $data[] = array($default_pricing_year, $default_pricing_year->getIdentifier());

    // Non-default pricing year.
    $pricing_year = self::createTestPricingYear(array(
      'pricing_year' => '1999',
      'default_pricing' => FALSE,
    ));
    self::$cleanUpIds[] = $pricing_year->getIdentifier();
    $data[] = array($pricing_year, $default_pricing_year->getIdentifier());

    // Disabled pricing year.
    $disabled_pricing_year = self::createTestPricingYear(array(
      'pricing_year' => '1800',
      'enabled' => FALSE,
    ));
    self::$cleanUpIds[] = $disabled_pricing_year->getIdentifier();
    $data[] = array($disabled_pricing_year, FALSE);

    return $data;
  }

  /**
   * Tests stihl_pricing_years_get_default_pricing_year().
   *
   * @dataProvider defaultPricingYearData
   *
   * @group stihl_pricing_years
   */
  public function testStihlPricingYearsGetDefaultPricingYear($pricing_year, $expected) {
    $year = $pricing_year->pricing_year->value();
    $actual = stihl_pricing_years_get_default_pricing_year($year);
    $this->assertEquals($expected, $actual);
  }

  /**
   * Tests stihl_pricing_years_profiles_default().
   *
   * @group stihl_pricing_years
   */
  public function testStihlPricingYearsProfilesDefault() {
    $pricing_year = self::createTestPricingYear();
    self::$cleanUpIds[] = $pricing_year->getIdentifier();
    $pricing_year = stihl_pricing_years_load($pricing_year->getIdentifier());

    $profile = entity_metadata_wrapper('stihl_profiles', 12);
    $associated_pricing = $profile->associated_pricing->value() ?? array();
    $profile->associated_pricing = array($pricing_year->id);
    $profile->save();

    $this->assertContains(12, stihl_pricing_years_profiles_default($pricing_year));

    $profile->associated_pricing = $associated_pricing;
    $profile->save();
  }

}
