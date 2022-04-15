<?php

/**
 * @file
 * Class for interfacing with a PromailDatabaseConnection.
 */

/**
 * Promail Database class.
 */
class PromailDatabase {

  /**
   * Connection to the Promail Database.
   *
   * @var PromailDatabaseConnection
   */
  private $connection = NULL;

  /**
   * Promail server host.
   *
   * @var string
   */
  private $host;

  /**
   * Promail database name.
   *
   * @var string
   */
  private $dbname;

  /**
   * Promail database username.
   *
   * @var string
   */
  private $user;

  /**
   * Promail database password.
   *
   * @var string
   */
  private $pass;

  /**
   * Character encoding for the PromailDatabaseConnection.
   *
   * @var string
   */
  private $charset;

  /**
   * Constructor.
   */
  public function __construct(array $config_options = array()) {
    $options = array('host', 'dbname', 'user', 'pass', 'charset');
    foreach ($options as $option) {
      $this->$option = isset($config_options[$option]) ? $config_options[$option] : NULL;
    }
  }

  /**
   * Open a connection to the Promail Database.
   *
   * @return bool
   *   Returns TRUE on success; FALSE otherwise.
   */
  public function connect() {
    if ($this->connection = $this->getConnection()) {
      // Set error mode to throw exceptions.
      $this->connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
      // Set the default fetch mode to return an array indexed by column name.
      $this->connection->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Get the connection to the Promail Database.
   *
   * @return PromailDatabaseConnection
   *   Returns a newly instantiated PromailDatabaseConnection class on success;
   *   NULL otherwise.
   */
  protected function getConnection() {
    try {
      return $this->connection ?: new PromailDatabaseConnection($this->host, $this->dbname, $this->user, $this->pass, $this->charset);
    }
    catch (PDOException $e) {
      $message = 'Caught exception (@method) – Unable to connect to PromailDatabase: @error';
      $replacement = array('@method' => __METHOD__, '@error' => $e->getMessage());
      PromailUtility::log($message, $replacement);
      return NULL;
    }
  }

  /**
   * Close connection to the Promail Database.
   *
   * @return bool
   *   Returns TRUE on success; FALSE if database wasn't connected.
   */
  public function close() {
    if (is_null($this->connection)) {
      return FALSE;
    }
    $this->connection = NULL;
    return TRUE;
  }

  /**
   * Caller method for PromailDatabaseConnection connection.
   *
   * @param string $method
   *   Name of the method to call on $this->connection.
   * @param array $args
   *   Arguments to be passed to the specified method.
   */
  public function __call($method, array $args) {
    try {
      // Determine if the method exists on the PromailDatabaseConnection object.
      if ($this->connection && method_exists($this->connection, $method)) {
        // If the method exists, try to call it & catch thrown PDOExceptions.
        return call_user_func_array(array($this->connection, $method), $args);
      }
      else {
        PromailUtility::log('Unable to call PromailDatabaseConnection::@method', array('@method' => $method));
        return FALSE;
      }
    }
    catch (PDOException $e) {
      $message = 'Caught exception (@method): @error';
      $replacement = array('@method' => $method, '@error' => $e->getMessage());
      PromailUtility::log($message, $replacement);
      return FALSE;
    }
  }

  /**
   * Destructor closes connection.
   */
  public function __destruct() {
    $this->close();
  }

}
