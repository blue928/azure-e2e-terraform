<?php

/**
 * @file
 * Unit tests for stihl_core module.
 */

/**
 * Class StihlCoreTest.
 */
class StihlCoreTest extends PHPUnit_Framework_TestCase {

  /**
   * Test for stihl_core_states_list_array().
   *
   * @group stihl_core
   */
  public function testStihlCoreStatesListArray() {
    $actual = stihl_core_states_list_array();
    $this->assertInternalType('array', $actual);
    $this->assertArrayHasKey('NC', $actual);
    $this->assertCount(51, $actual);

  }

  /**
   * Test for stihl_core_get_bd_user_addresses().
   *
   * @group stihl_core
   */
  public function testStihlCoreMail() {
    $expected = 'STIHLOrderAdmins@rlci.com';
    $mail = new StihlCoreMail();
    $this->assertInternalType('array', $mail->recipients()->getArray());
    $this->assertInternalType('string', $mail->recipients()->getList());

    $this->assertContains($expected, $mail->recipients()->getArray());
    $this->assertRegExp('/' . $expected . '/', $mail->recipients()->getList());

    $mail = new StihlCoreMail(5);
    $this->assertNotContains($expected, $mail->recipients()->getArray());
    $this->assertContains($expected, $mail->recipients()->withAdmin()->getArray());
    $this->assertRegExp('/' . $expected . '/', $mail->recipients()->withAdmin()->getList());
  }

  /**
   * Data provider for testStihlCoreGetBdName().
   */
  public function dataGetBdName() {
    return array(
      // Data: attempt BD ID, result type.
      array(1, 'string'),
      array(111111, 'boolean'),
      array('string', 'boolean'),
      array('', 'boolean'),
    );
  }

  /**
   * Test for stihl_core_get_bd_name().
   *
   * @dataProvider dataGetBdName
   *
   * @group stihl_core
   */
  public function testStihlCoreGetBdName($attempt, $expected) {

    $actual = stihl_core_get_bd_name($attempt);

    $this->assertInternalType($expected, $actual);
  }

}
