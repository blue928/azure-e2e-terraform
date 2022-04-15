<?php

/**
 * @file
 * Unit tests for stihl_profiles module.
 */

/**
 * Class StihlProfilesTest.
 */
class StihlProfilesTest extends PHPUnit_Framework_TestCase {

  /**
   * Test for stihl_profiles_entity_info().
   *
   * @group stihl_profiles
   */
  public function testStihlProfilesEntityInfo() {
    $this->assertInternalType('array', stihl_profiles_entity_info());
  }

  /**
   * Test for stihl_profiles_menu().
   *
   * @group stihl_profiles
   */
  public function testStihlProfilesMenu() {
    $this->assertInternalType('array', stihl_profiles_menu());
  }

  /**
   * Test for stihl_profiles_access_callback().
   *
   * @group stihl_profiles
   */
  public function testStihlProfilesAccessCallback() {
    // Anonymous user access test.
    $anonymous_obj = user_load(0);
    $anonymous_user = stihl_profiles_access_callback(NULL, NULL, $anonymous_obj);
    // Administrator user access test.
    $administrative_obj = user_load(1);
    $administrative_user = stihl_profiles_access_callback(NULL, NULL, $administrative_obj);

    $this->assertFalse($anonymous_user);
    $this->assertTrue($administrative_user);
  }

  /**
   * Test for stihl_profiles_view_entity().
   *
   * @group stihl_profiles
   */
  public function testStihlProfilesViewEntity() {
    $this->assertInternalType('array', stihl_profiles_view_entity(1));
  }

}
