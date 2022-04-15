<?php

/**
 * @file
 * Provided library.
 */

/*
 This file is part of, or distributed with, libXMLRPC - a C library for
 xml-encoded function calls.

 Author: Dan Libby (dan@libby.com)
 Epinions.com may be contacted at feedback@epinions-inc.com
 */

/*
 Copyright 2001 Epinions, Inc.

 Subject to the following 3 conditions, Epinions, Inc.  permits you, free
 of charge, to (a) use, copy, distribute, modify, perform and display this
 software and associated documentation files (the "Software"), and (b)
 permit others to whom the Software is furnished to do so as well.

 1) The above copyright notice and this permission notice shall be included
 without modification in all copies or substantial portions of the
 Software.

 2) THE SOFTWARE IS PROVIDED "AS IS", WITHOUT ANY WARRANTY OR CONDITION OF
 ANY KIND, EXPRESS, IMPLIED OR STATUTORY, INCLUDING WITHOUT LIMITATION ANY
 IMPLIED WARRANTIES OF ACCURACY, MERCHANTABILITY, FITNESS FOR A PARTICULAR
 PURPOSE OR NONINFRINGEMENT.

 3) IN NO EVENT SHALL EPINIONS, INC. BE LIABLE FOR ANY DIRECT, INDIRECT,
 SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES OR LOST PROFITS ARISING OUT
 OF OR IN CONNECTION WITH THE SOFTWARE (HOWEVER ARISING, INCLUDING
 NEGLIGENCE), EVEN IF EPINIONS, INC.  IS AWARE OF THE POSSIBILITY OF SUCH
 DAMAGES.

 */

/* xmlrpc utilities (xu)
 * author: Dan Libby (dan@libby.com)
 */

/**
 * Generic function to call an http server with post method.
 */
function xu_query_http_post($request, $host, $uri, $port, $debug, $timeout, $user, $pass, $secure = TRUE) {
  $response_buf = '';
  if ($host && $uri && $port) {
    // If $secure is TRUE, use TLS.
    if ($secure) {
      $fsock_host = 'tls://' . $host;
    }
    else {
      $fsock_host = $host;
    }
    $content_len = strlen($request);
    dbg1("opening socket to host: $fsock_host, port: $port, uri: $uri", $debug);
    $query_fd = fsockopen($fsock_host, $port, $errno, $errstr, 10);
    if ($query_fd) {
      $http_request = "POST $uri HTTP/1.0\r\n";
      $http_request .= "User-Agent: " . $_SERVER['HTTP_USER_AGENT'] . "\r\n";
      $http_request .= "Host: $host:$port\r\n";
      if ($user) {
        $http_request .= "Authorization: Basic " . base64_encode($user . ":" . $pass) . "\r\n";
      }
      $http_request .= "Content-Type: text/xml\r\n";
      $http_request .= "Content-Length: $content_len\r\n";
      $http_request .= "Connection: close\r\n\r\n";
      $http_request .= "$request \r\n\r\n";

      dbg1("sending http request:</h3> <xmp>\n$http_request\n</xmp>", $debug);

      fwrite($query_fd, $http_request, strlen($http_request));

      dbg1("receiving response...", $debug);

      $header_parsed = FALSE;

      $line = fgets($query_fd, 4096);
      while ($line) {
        if (!$header_parsed) {
          if ($line === "\r\n" || $line === "\n") {
            $header_parsed = 1;
          }
          dbg2("got header - $line", $debug);
        }
        else {
          $response_buf .= $line;
        }
        $line = fgets($query_fd, 4096);
      }
      fclose($query_fd);
    }
    else {
      dbgn($errno . ' : ' . $errstr . "\n");
      dbg1("socket open failed", $debug);
    }
  }
  else {
    dbg1('missing param(s)', $debug);
  }
  dbg1("got response:</h3>. <xmp>\n$response_buf\n</xmp>\n", $debug);
  return $response_buf;
}

/**
 * Structure fault code array.
 */
function xu_fault_code($code, $string) {
  return array(
    'faultCode' => $code,
    'faultString' => $string,
  );
}

/**
 * Find and decode XML.
 */
function find_and_decode_xml($buf, $debug) {
  if (strlen($buf)) {
    $xml_begin = substr($buf, strpos($buf, '<?xml'));
    if (strlen($xml_begin)) {
      $retval = xmlrpc_decode($xml_begin);
    }
    else {
      dbg1('xml start token not found', $debug);
    }
  }
  else {
    dbg1('no data', $debug);
  }
  return $retval;
}

/**
 * Structure and make xmlrpc call.
 *
 * @param array $params
 *   An array containing 3 or more of these key/val pairs:
 *     output_type: return data as either php native data types or xml
 *                  encoded. ifphp is used, then the other values are ignored.
 *                  default = xml
 *     verbosity:   determine compactness of generated xml. options are
 *                  no_white_space, newlines_only, and pretty. default = pretty
 *     escaping:    determine how/whether to escape certain characters. 1 or
 *                  more values are allowed. If multiple, they need to be
 *                  specified as a sub-array. options are: cdata, non-ascii,
 *                  non-print, and markup.
 *                  default = non-ascii | non-print | markup
 *     version:     version of xml vocabulary to use. currently, three are
 *                  supported: xmlrpc, soap 1.1, and simple. The keyword auto is
 *                  also recognized to mean respond in whichever version the
 *                  request came in. default = auto (when applicable), xmlrpc
 *     encoding:    the encoding that the data is in. Since PHP defaults to
 *                  iso-8859-1 you will usually want to use that. Change it if
 *                  you know what you are doing. default=iso-8859-1
 *   Example usage:
 *     $output_options = array(
 *       'output_type' => 'xml',
 *       'verbosity' => 'pretty',
 *       'escaping' => array(
 *         'markup',
 *         'non-ascii',
 *         'non-print'
 *       ),
 *       'version' => 'xmlrpc',
 *       'encoding' => 'utf-8'
 *     );
 *     or
 *     $output_options = array('output_type' => 'php');.
 */
function xu_rpc_http_concise(array $params) {
  $host = $uri = $port = $method = $args = $debug = NULL;
  $timeout = $user = $pass = $secure = $output = NULL;
  extract($params);
  // Default values.
  if (!$port) {
    $port = 443;
  }
  if (!$uri) {
    $uri = '/';
  }
  if (!isset($output)) {
    $output = array('version' => 'xmlrpc');
  }
  // Default to a secure connection.
  if ($secure !== NULL) {
    $secure = TRUE;
  }
  $response_buf = '';
  if ($host && $uri && $port) {
    $request_xml = xmlrpc_encode_request($method, $args, $output);
    $response_buf = xu_query_http_post($request_xml, $host, $uri, $port, $debug, $timeout, $user, $pass, $secure);
    $retval = find_and_decode_xml($response_buf, $debug);
  }
  return $retval;
}

/**
 * Call an xmlrpc method on a remote http server (legacy support).
 */
function xu_rpc_http($method, $args, $host, $uri = '/', $port = 80, $debug = FALSE, $timeout = 0, $user = FALSE, $pass = FALSE, $secure = TRUE) {
  return xu_rpc_http_concise(
    array(
      method => $method,
      args => $args,
      host => $host,
      uri => $uri,
      port => $port,
      debug => $debug,
      timeout => $timeout,
      user => $user,
      pass => $pass,
      secure => $secure,
    )
  );
}

/**
 * Determine if an array value represents an XMLRPC fault.
 */
function xu_is_fault($arg) {
  // Xmlrpc extension finally supports this.
  return is_array($arg) ? xmlrpc_is_fault($arg) : FALSE;
}

/**
 * Sets some http headers and prints xml.
 */
function xu_server_send_http_response($xml) {
  header('Content-type: text/xml');
  header('Content-length: ' . strlen($xml));
  echo $xml;
}

/**
 * Send a debug message when debug mode is on.
 */
function dbg($msg) {
  echo $msg;
  flush();
}

/**
 * Send a debug message with a new line when debug mode is on.
 */
function dbgn($msg) {
  echo "$msg\n";
  flush();
}

/**
 * Send this debug message if debug level is set to 1 or higher.
 */
function dbg1($msg, $debug_level) {
  if ($debug_level >= 1) {
    dbg($msg);
  }
}

/**
 * Send this debug message if debug level is set to 2 or higher.
 */
function dbg2($msg, $debug_level) {
  if ($debug_level >= 2) {
    dbg($msg);
  }
}
