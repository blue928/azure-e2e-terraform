<?php

/**
 * @file
 * Mock Promail Database used for unit tests.
 */

require_once dirname(__FILE__) . '/../../includes/PromailDatabaseConnection.inc';

/**
 * Creates a mock database connection for Promail tests.
 */
class MockPromailDatabaseConnection extends PHPUnit_Framework_TestCase {

  /**
   * SQLite DB connection.
   *
   * @var PDO
   */
  public $connection;

  /**
   * Creates a database in memory for testing.
   *
   * @param array $tables
   *   Array of tables defined in the schema to include in the database.
   */
  public function __construct(array $tables) {
    // Create mock PromailDatabaseConnection.
    $this->connection = $this->mockDatabaseConnection();
    if ($tables) {
      foreach ($tables as $table) {
        $this->createDatabaseTable($table);
      }
    }
  }

  /**
   * Mocks the PromailDatabaseConnection class for testing.
   *
   * @return object
   *   Returns the mock PromailDatabaseConnection.
   */
  protected function mockDatabaseConnection() {
    // Create mock PromailDatabaseConnection.
    $connection = $this->getMockBuilder('PromailDatabaseConnection')
      // Stub the dataSourceName method so we can override it.
      ->setMethods(array('dataSourceName'))
      // Don't call the constructor until we've overridden `dataSourceName`.
      ->disableOriginalConstructor()
      // Create the mock.
      ->getMock();

    // The `dataSourceName` called by PromailDatabaseConnection::__construct()
    // returns a DSN that uses a dblib driver. For these tests, we want it to
    // return a DSN for an in-memory database using a sqlite driver so that we
    // have control over the DB content & it isn't dependent on an internet
    // connection or database credentials for testing.
    $connection->expects($this->once())
      // Tell the mock PromailDatabaseConnection that we are expecting the
      // dataSourceName method to be called once (when we call the constructor).
      ->method('dataSourceName')
      // And when we call it, we want it to return a DSN string to be used for
      // creating an in-memory sqlite database connection.
      ->will($this->returnValue('sqlite::memory:'));

    // Now that the method is overridden, we can call the constructor.
    $connection->__construct();
    return $connection;
  }

  /**
   * Clean up the PDO connection.
   */
  public function __destruct() {
    $this->connection = NULL;
  }

  /**
   * Static Table definitions.
   *
   * @param string $table
   *   Name of the table to be returned.
   *
   * @return array
   *   Array of data used to create the named table ($table) in the database.
   */
  private static function getTables($table) {
    $tables = array();
    $tables['INPULL'] = array(
      array(
        'INPULL_Seqid' => '112233',
        'SHPORD_Seqid' => NULL,
        'SYSTEM_ID' => 'test_id',
        'INPULL_PPId' => NULL,
        'INPULL_OrderId' => '1',
      ),
      array(
        'INPULL_Seqid' => '123456',
        'SHPORD_Seqid' => NULL,
        'SYSTEM_ID' => 'test_id',
        'INPULL_PPId' => NULL,
        'INPULL_OrderId' => '2',
      ),
      array(
        'INPULL_Seqid' => '123457',
        'SHPORD_Seqid' => NULL,
        'SYSTEM_ID' => 'test_id',
        'INPULL_PPId' => NULL,
        'INPULL_OrderId' => '2',
      ),
      array(
        'INPULL_Seqid' => '123458',
        'SHPORD_Seqid' => NULL,
        'SYSTEM_ID' => 'test_id',
        'INPULL_PPId' => '123456',
        'INPULL_OrderId' => '2',
      ),
      array(
        'INPULL_Seqid' => NULL,
        'SHPORD_Seqid' => NULL,
        'SYSTEM_ID' => 'test_id',
        'INPULL_PPId' => '123456',
        'INPULL_OrderId' => '4',
      ),
    );
    $tables['SYSTEM'] = array(
      array(
        'SYSTEM_ID' => 'test_id',
      ),
    );
    $tables['dbo.SHPORD'] = array(
      array(
        'INPULL_Seqid' => '112233',
        'SHPORD_Customization' => '<font face="Arial Black" >FullName:</font>    <font face="Verdana">Julie Soto</font><br><font face="Arial Black" >OrderLineNID:</font>    <font face="Verdana">1481611</font><br><font face="Arial Black" >BranchNumber:</font>    <font face="Verdana">1456148</font><br><font face="Arial Black" >ActiveDate:</font>    <font face="Verdana">2017-10-19T16:16:50-04:00</font>',
      ),
      array(
        'INPULL_Seqid' => '123456',
        'SHPORD_Customization' => '<font face="Arial Black" >FullName:</font>    <font face="Verdana">Julie Soto</font><br><font face="Arial Black" >OrderLineNID:</font>    <font face="Verdana">1481616</font><br><font face="Arial Black" >BranchNumber:</font>    <font face="Verdana">1456148</font><br><font face="Arial Black" >ActiveDate:</font>    <font face="Verdana">2017-10-19T16:16:50-04:00</font>',
      ),
      array(
        'INPULL_Seqid' => '123457',
        'SHPORD_Customization' => '<font face="Arial Black" >FullName:</font>    <font face="Verdana">Julie Soto</font><br><font face="Arial Black" >OrderLineNID:</font>    <font face="Verdana">1481617</font><br><font face="Arial Black" >BranchNumber:</font>    <font face="Verdana">1456148</font><br><font face="Arial Black" >ActiveDate:</font>    <font face="Verdana">2017-10-19T16:16:50-04:00</font>',
      ),
    );
    return $tables[$table];
  }

  /**
   * Create tables in the database using the defined schema.
   *
   * @param string $table
   *   Name of the table schema defined in self::getTables().
   */
  private function createDatabaseTable($table) {
    $table_data = self::getTables($table);

    $schema = reset($table_data);
    $schema = array_map(function ($col) {
      return $col . ' VARCHAR(50)';
    }, array_keys($schema));

    $create = 'CREATE TABLE ":table" (:schema)';
    $create_params = array(
      ':table' => $table,
      ':schema' => implode(', ', $schema),
    );
    $sql_create = strtr($create, $create_params);
    $this->connection->exec($sql_create);

    foreach ($table_data as $row) {
      $sql = "INSERT INTO \":table\" (:fields) VALUES (':field_values')";
      $replace = array(
        ':table' => $table,
        ':fields' => implode(", ", array_keys($row)),
        ':field_values' => implode("', '", $row),
      );

      $sql_insert = strtr($sql, $replace);
      $sql_insert = str_replace("''", "NULL", $sql_insert);

      $this->connection->exec($sql_insert);
    }
  }

}
