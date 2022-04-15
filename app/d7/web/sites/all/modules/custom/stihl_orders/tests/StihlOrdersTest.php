<?php

/**
 * @file
 * Unit tests for stihl_orders module.
 */

/**
 * Class StihlOrdersTest.
 */
class StihlOrdersTest extends StihlOrdersTestBase {

  /**
   * {@inheritdoc}
   */
  public static function tearDownAfterClass() {
    // Delete orders created during tests.
    db_delete('commerce_order')->condition('mail', 'test-delete@example.com')->execute();
  }

  /**
   * Test for stihl_orders_get_price_year_column().
   *
   * @group stihl_orders
   */
  public function testStihlOrdersGetPriceYearColumn() {

    $current_year = format_date(REQUEST_TIME, 'custom', 'Y');
    $next_year = $current_year + 1;

    $current_year_price = stihl_orders_get_price_year_column($current_year);
    $next_year_price = stihl_orders_get_price_year_column($next_year);

    $this->assertEquals('current_year_price', $current_year_price);
    $this->assertEquals('next_year_price', $next_year_price);

  }

  /**
   * Test for stihl_orders_get_states_by_workflow().
   *
   * @group stihl_orders
   */
  public function testStihlOrdersGetStatesByWorkflow() {

    $state_ids = stihl_orders_get_states_by_workflow('Order Status');

    // We are testing the values of the array keys.
    $state_names = array_keys($state_ids);

    $this->assertContains('approved', $state_names);
    $this->assertContains('submitted', $state_names);
    $this->assertContains('ready for review', $state_names);
  }

  /**
   * Data provider for testStihlOrdersConvertFusionproCharacters.
   */
  public function fusionproCharacterData() {
    return array(
      // Data: pattern, expected.
      array('', ''),
      array(' ', ''),
      array(NULL, NULL),
      array('string', 'string'),
      array('string  ', 'string'),
      array(' string ', 'string'),
      array(' string string ', 'string string'),
      array('string†', 'string(t)'),
      array('string †', 'string (t)'),
      array(' string † ', 'string (t)'),
      array('string©', 'string(c)'),
      array('string®', 'string(r)'),
      array('string™', 'string(tm)'),
      array('string°', 'string(d)'),
      array('string"', 'string(in)'),
    );
  }

  /**
   * Test for stihl_orders_convert_fusionpro_characters().
   *
   * @dataProvider fusionproCharacterData
   *
   * @group stihl_orders
   */
  public function testStihlOrdersConvertFusionproCharacters($pattern, $expected) {

    // Filter string with callback function.
    $filtered = stihl_orders_convert_fusionpro_characters($pattern);
    // Confirm characters are replaced as needed and trimmed.
    $this->assertEquals($expected, $filtered);
  }

}
