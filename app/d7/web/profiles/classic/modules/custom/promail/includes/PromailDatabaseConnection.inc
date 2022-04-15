<?php

/**
 * @file
 * Extends PDO class for Promail module.
 */

/**
 * Promail Database Connection class.
 */
class PromailDatabaseConnection extends PDO {

  /**
   * Connection options for creating the PDO Data Source Name (DSN).
   *
   * @var array
   */
  private $connectionOptions;

  /**
   * Constructor.
   */
  public function __construct($host = NULL, $db = NULL, $user = NULL, $pass = NULL, $charset = NULL) {
    $connect_opts = array(
      'host' => $host ?: PromailUtility::variableGet('server_host'),
      'dbname' => $db ?: PromailUtility::variableGet('db_name'),
      'charset' => $charset,
    );
    $user = $user ?: PromailUtility::variableGet('server_user');
    $pass = $pass ?: PromailUtility::variableGet('server_password');

    $this->connectionOptions = array_filter($connect_opts);
    $dsn = $this->dataSourceName();
    parent::__construct($dsn, $user, $pass);
  }

  /**
   * Get the data source name to connect to the database.
   *
   * @return string
   *   Returns the driver invocation required to connect to the DB.
   */
  protected function dataSourceName() {
    $dsn_options = array();
    // Loop through the defined options and format per DSN syntax.
    array_walk($this->connectionOptions, function ($val, $key) use (&$dsn_options) {
      $dsn_options[] = $key . '=' . $val;
    });
    return strtr('dblib:@dsn_options', array('@dsn_options' => implode(';', $dsn_options)));
  }

  /**
   * Helper function for querying the PromailDatabase.
   *
   * @param string $sql
   *   SQL statement to be executed.
   * @param array $params
   *   An array of values with as many elements as there are bound parameters in
   *   the SQL statement being executed.
   *
   * @return mixed
   *   Returns an array of results indexed by column name; FALSE on failure.
   */
  public function fetchAll($sql, array $params = array()) {
    try {
      $query = $this->prepare($sql);
      $query->execute($params);
      $result = $query->fetchAll();
      return $result;
    }
    catch (PDOException $e) {
      $message = 'Caught exception (@method) – Unable to query PromailDatabaseConnection: @error';
      $replacement = array('@method' => __METHOD__, '@error' => $e->getMessage());
      PromailUtility::log($message, $replacement);
      return FALSE;
    }
  }

}
