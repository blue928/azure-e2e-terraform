<?php

/**
 * @file
 * Unit tests for promail module.
 */

require_once dirname(__FILE__) . '/../includes/PromailDatabase.inc';
require_once dirname(__FILE__) . '/../includes/PromailUtility.inc';
require_once dirname(__FILE__) . '/includes/MockPromailDatabaseConnection.php';

define('WATCHDOG_ERROR', 7);

/**
 * Class PromailTest.
 */
class PromailTest extends PHPUnit_Framework_TestCase {

  /**
   * PromailDatabase being tested.
   *
   * @var PromailDatabase
   */
  private $promailDatabase = NULL;

  /**
   * Clean up after tests.
   */
  protected function tearDown() {
    parent::tearDown();
    $this->promailDatabase = NULL;
  }

  /**
   * Create the PromailDatabase mock.
   */
  public function createPromailDatabase(array $tables) {
    // Create mock PromailDatabaseConnection.
    $db = new MockPromailDatabaseConnection($tables);

    // Create mock PromailDatabase.
    $this->promailDatabase = $this->getMockBuilder('PromailDatabase')
      // Stub the `getConnection` method.
      ->setMethods(array('getConnection'))
      ->getMock();

    // Have `getConnection` method return the mock PromailDatabaseConnection.
    $this->promailDatabase->expects($this->any())
      ->method('getConnection')
      ->will($this->returnValue($db->connection));

    // Open connection.
    $this->promailDatabase->connect();
  }

  /**
   * Mocks promail_query_promail_db function.
   */
  public function queryPromailDatabase($sql, array $params = array()) {
    $result = $this->promailDatabase->fetchAll($sql, $params);
    $result = $result ? $result : FALSE;
    $this->promailDatabase->close();
    return $result;
  }

  /**
   * Test that the MOD numbers returned for each order are correct.
   *
   * @dataProvider providerTestGetModNumbers
   *
   * @group Promail
   */
  public function testGetModNumbers($order, $expected) {
    $this->createPromailDatabase(array('SYSTEM', 'INPULL'));
    $query = 'SELECT * FROM INPULL
      INNER JOIN SYSTEM ON INPULL.SYSTEM_ID = SYSTEM.SYSTEM_ID
      WHERE SYSTEM.SYSTEM_ID = :system_id AND INPULL_OrderId = :order_id';
    $replace = array(':system_id' => 'test_id', ':order_id' => $order);

    $result = $this->queryPromailDatabase($query, $replace);

    if (is_array($result)) {
      foreach ($result as &$row) {
        $row = isset($row['INPULL_PPId']) ? NULL : $row['INPULL_Seqid'];
      }
      $result = array_filter($result);
    }

    $this->assertEquals($expected, $result);
  }

  /**
   * Data Provider for testGetModNumbers.
   */
  public function providerTestGetModNumbers() {
    return array(
      'Order contains 1 MOD line-item' => array(
        '1', array('112233'),
      ),
      'Order contains inventory & MOD line-items' => array(
        '2', array('123456', '123457'),
      ),
      'Order does not exist in the DB' => array(
        '3', FALSE,
      ),
      'Inventory items only' => array(
        '4', array(),
      ),
    );
  }

  /**
   * Test that the line-items returned for MODs are correct.
   *
   * @dataProvider providerTestLineItemsByMods
   *
   * @group Promail
   */
  public function testLineItemsByMods($mod_numbers, $expected) {
    $this->createPromailDatabase(array('dbo.SHPORD'));
    $query = 'SELECT SHPORD_Customization FROM "dbo.SHPORD" WHERE INPULL_Seqid IN (:mod_numbers)';
    $query = strtr($query, array(':mod_numbers' => implode(',', $mod_numbers)));

    $result = $this->queryPromailDatabase($query);

    if (is_array($result)) {
      foreach ($result as &$row) {
        $promail_custom_fields = strip_tags($row['SHPORD_Customization']);
        preg_match('/OrderLineNID:\s*(?<line_id>\d+)/', $promail_custom_fields, $matches);
        $row = $matches['line_id'];
      }
      $result = array_filter($result);
    }

    $this->assertEquals($expected, $result);
  }

  /**
   * Data Provider for testLineItemsByMods.
   */
  public function providerTestLineItemsByMods() {
    return array(
      array(array('123456', '123457'), array('1481616', '1481617')),
      array(array('112233'), array('1481611')),
      array(array('111111'), FALSE),
    );
  }

  /**
   * Tests the PDOStatement fetch method from PromailDatabase class.
   *
   * @group Promail
   */
  public function testFetchMethod() {
    $this->createPromailDatabase(array('INPULL'));
    $query = $this->promailDatabase->prepare('SELECT * FROM INPULL');
    $query->execute();

    $expectation = array(1, 2, 2, 2, 4);

    while (($row = $query->fetch()) && $expectation) {
      $this->assertEquals(array_shift($expectation), $row['INPULL_OrderId']);
    }
  }

  /**
   * Tests the PDOStatement fetchAll method from PromailDatabase class.
   *
   * @dataProvider providerTestFetchAllMethod
   *
   * @group Promail
   */
  public function testFetchAllMethod($args, $expectation) {
    $this->createPromailDatabase(array('INPULL'));
    $query = $this->promailDatabase->prepare('SELECT INPULL_Seqid, INPULL_OrderId FROM INPULL');
    $query->execute();
    $result = call_user_func_array(array($query, 'fetchAll'), $args);
    $this->assertEquals($expectation, $result);
  }

  /**
   * Data Provider for testFetchAllMethod.
   */
  public function providerTestFetchAllMethod() {
    return array(
      array(
        array(),
        array(
          array('INPULL_Seqid' => 112233, 'INPULL_OrderId' => 1),
          array('INPULL_Seqid' => 123456, 'INPULL_OrderId' => 2),
          array('INPULL_Seqid' => 123457, 'INPULL_OrderId' => 2),
          array('INPULL_Seqid' => 123458, 'INPULL_OrderId' => 2),
          array('INPULL_Seqid' => NULL, 'INPULL_OrderId' => 4),
        ),
      ),
      array(
        array(PDO::FETCH_ASSOC),
        array(
          array('INPULL_Seqid' => 112233, 'INPULL_OrderId' => 1),
          array('INPULL_Seqid' => 123456, 'INPULL_OrderId' => 2),
          array('INPULL_Seqid' => 123457, 'INPULL_OrderId' => 2),
          array('INPULL_Seqid' => 123458, 'INPULL_OrderId' => 2),
          array('INPULL_Seqid' => NULL, 'INPULL_OrderId' => 4),
        ),
      ),
      array(
        array(PDO::FETCH_COLUMN, 0),
        array(112233, 123456, 123457, 123458, NULL),
      ),
      array(
        array(PDO::FETCH_COLUMN, 1),
        array(1, 2, 2, 2, 4),
      ),
    );
  }

  /**
   * Tests closing the connection to the PromailDatabase.
   *
   * @group Promail
   */
  public function testClosingDatabaseConnection() {
    $this->createPromailDatabase(array('INPULL'));
    $this->promailDatabase->connect();
    $result = $this->promailDatabase->close();
    $this->assertTrue($result);
  }

  /**
   * Tests that calling non PromailDatabaseConnection methods cause an error.
   *
   * @group Promail
   */
  public function testNonExistentPromailDatabaseConnectionMethod() {
    $this->createPromailDatabase(array('INPULL'));
    $this->promailDatabase->connect();
    $result = $this->promailDatabase->run();
    $this->assertFalse($result);
    $this->promailDatabase->close();
  }

}
