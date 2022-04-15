<?php

/**
 * @file
 * Utility functions used across Promail classes.
 */

/**
 * Promail Utility class.
 */
class PromailUtility {

  /**
   * Wrapper function for variable_get().
   *
   * @param string $variable
   *   Name of the promail_mssql variable (without the prefix).
   *
   * @return mixed
   *   Value of the specified variable.
   */
  public static function variableGet($variable) {
    if (function_exists('variable_get')) {
      return variable_get('promail_mssql_' . $variable, NULL);
    }
    return NULL;
  }

  /**
   * Create a Promail watchdog message.
   *
   * @param string $message
   *   Message to display in db log.
   * @param array $variables
   *   Array of string replacement values for $message.
   * @param int $severity
   *   Severity of the message; Ranges from 0 (most severe) to 7 (least severe).
   * @param string $link
   *   A link to associate with the message.
   */
  public static function log($message, array $variables = array(), $severity = WATCHDOG_ERROR, $link = NULL) {
    if (function_exists('watchdog')) {
      watchdog('promail', $message, $variables, $severity, $link);
    }
  }

}
