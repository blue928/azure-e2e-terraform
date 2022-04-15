<?php

/**
 * @file
 * Unit tests for stihl_product_views module.
 */

/**
 * Class StihlProductViewsTest.
 */
class StihlProductViewsTest extends PHPUnit_Framework_TestCase {

  /**
   * Make the include file functions available to tests.
   */
  public function setUp() {
    module_load_include('inc', 'stihl_product_views', 'inc/stihl_product_views_product_page');
  }

  /**
   * Test stihl_product_views_image_preview_url().
   *
   * @group stihl_product_views
   */
  public function testStihlProductViewsImagePreviewUrl() {

    // Test a default preview image URL string.
    $default_vertical = stihl_product_views_image_preview_url('nonexitent_sku');
    $this->assertInternalType('string', $default_vertical);
    $this->assertContains('vertical-default.png', $default_vertical);

    $default_horizontal = stihl_product_views_image_preview_url('nonexitent_sku', FALSE);
    $this->assertInternalType('string', $default_horizontal);
    $this->assertContains('horizontal-default.png', $default_horizontal);
  }

}
