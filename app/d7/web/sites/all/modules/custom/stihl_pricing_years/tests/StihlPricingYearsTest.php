<?php

/**
 * @file
 * Unit tests for stihl_pricing_years module.
 */

$base_path = drupal_get_path('module', 'stihl_pricing_years');
include_once "$base_path/tests/StihlPricingYearsTestBase.php";

/**
 * Class StihlPricingYears.
 */
class StihlPricingYearsTest extends StihlPricingYearsTestBase {

  protected static $testPricingYear;

  protected static $cleanUpIds = array();

  protected static $testProfileWrapper;

  protected static $testProfilePricing;

  /**
   * {@inheritdoc}
   */
  public static function setUpBeforeClass() {
    $test_pricing_year = self::createTestPricingYear();
    $test_pricing_year_id = $test_pricing_year->getIdentifier();
    self::$cleanUpIds[] = $test_pricing_year_id;
    self::$testPricingYear = $test_pricing_year;

    $profile_wrapper = entity_metadata_wrapper('stihl_profiles', 12);
    self::$testProfilePricing = $profile_wrapper->associated_pricing->value();
    $profile_wrapper->associated_pricing = array($test_pricing_year_id);
    $profile_wrapper->save();
    self::$testProfileWrapper = $profile_wrapper;
  }

  /**
   * {@inheritdoc}
   */
  public static function tearDownAfterClass() {
    self::$testProfileWrapper->associated_pricing = self::$testProfilePricing;
    self::$testProfileWrapper->save();
    entity_delete_multiple('stihl_pricing_years', self::$cleanUpIds);
  }

  /**
   * Test for stihl_pricing_years_entity_info().
   *
   * @group stihl_pricing_years
   */
  public function testStihlProfilesEntityInfo() {
    $this->assertInternalType('array', stihl_pricing_years_entity_info());
  }

  /**
   * Test for stihl_pricing_years_menu().
   *
   * @group stihl_pricing_years
   */
  public function testStihlProfilesMenu() {
    $this->assertInternalType('array', stihl_pricing_years_menu());
  }

  /**
   * Test for stihl_pricing_years_access_callback().
   *
   * @group stihl_pricing_years
   */
  public function testStihlProfilesAccessCallback() {
    // Anonymous user access test.
    $anonymous_obj = user_load(0);
    $anonymous_user = stihl_pricing_years_access_callback(NULL, NULL, $anonymous_obj);
    // Administrator user access test.
    $administrative_obj = user_load(1);
    $administrative_user = stihl_pricing_years_access_callback(NULL, NULL, $administrative_obj);

    $this->assertFalse($anonymous_user);
    $this->assertTrue($administrative_user);
  }

  /**
   * Test for stihl_pricing_years_view_entity().
   *
   * @group stihl_pricing_years
   */
  public function testStihlProfilesViewEntity() {
    $this->assertInternalType('array', stihl_pricing_years_view_entity(self::$testPricingYear->getIdentifier()));
  }

  /**
   * Test for stihl_pricing_years_get_year_by_id().
   *
   * @group stihl_pricing_years
   */
  public function testStihlPricingYearsGetYearById() {
    $id = self::$testPricingYear->getIdentifier();
    $year = stihl_pricing_years_get_year_by_id($id);

    $this->assertInternalType('string', $year);
    $this->assertEquals('2018', $year);
  }

  /**
   * Test for stihl_pricing_years_label_callback().
   *
   * @group stihl_pricing_years
   */
  public function testStihlPricingYearsLabelCallback() {
    $pricing_year_id = self::$testPricingYear->getIdentifier();
    $label = entity_label('stihl_pricing_years', stihl_pricing_years_load($pricing_year_id));

    $this->assertEquals('2018 - Test Pricing Year', $label);
  }

  /**
   * Test for stihl_pricing_years_update_associated_profile().
   *
   * @group stihl_pricing_years
   */
  public function testStihlPricingYearsUpdateAssociatedProfile() {
    $profile_id = self::$testProfileWrapper->getIdentifier();
    $profile = reset(entity_load('stihl_profiles', array($profile_id)));

    $pricing_year_id = self::$testPricingYear->getIdentifier();
    $pricing_year = stihl_pricing_years_load($pricing_year_id);

    $this->assertGreaterThan(FALSE, stihl_pricing_years_update_associated_profile($profile, $pricing_year));

    $profile_wrapper = entity_metadata_wrapper('stihl_profiles', $profile_id);
    $this->assertEquals(array(), $profile_wrapper->associated_pricing->value());
  }

  /**
   * Test to ensure references are removed when a Pricing Year is deleted.
   *
   * @group stihl_pricing_years
   */
  public function testStihlPricingYearsDelete() {
    $profile = self::$testProfileWrapper;
    $profile_id = $profile->getIdentifier();
    self::$testPricingYear->delete();
    $this->assertNotContains($profile_id, $profile->associated_pricing->value());
  }

}
