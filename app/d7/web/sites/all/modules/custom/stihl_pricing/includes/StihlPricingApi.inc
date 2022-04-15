<?php

/**
 * @file
 * Stihl pricing API class.
 */

/**
 * Stihl pricing API class.
 */
class StihlPricingAPI {

  protected $apiResponse;
  protected $curlError;
  protected $curlInfo = [];

  /**
   * Constructor.
   */
  public function __construct() {
    if (variable_get('stihl_pricing_api_enable', 1)) {
      $this->products = $this->getCommerceProductSkus();
      $this->profiles = $this->getBdProfiles();
      $this->apiResponse = $this->curlGetRequest();
      $this->logApiFailure();
    }
  }

  /**
   * Curl GET request for API.
   *
   * @param string $endpoint
   *   (Optional) URL to be used as the API's endpoint.
   */
  protected function curlGetRequest($endpoint = NULL) {
    static $requests = 0;

    $http_headers = ['cache-control: no-cache'];
    // When making a request, older versions of cURL (< 7.58.0) send the custom
    // authorization header to the redirect location which will cause the AWS
    // endpoint to reject the call. As a workaround, we will intercept the
    // redirect headers, remove the authorization headers, and finally make an
    // additional request to the redirect location.
    // {@link https://stackoverflow.com/questions/37865875/stopping-curl-from-sending-authorization-header-on-302-redirect}
    if (!$requests) {
      $http_headers[] = t('Authorization: @auth', [
        '@auth' => variable_get('stihl_pricing_api_authorization', 'MOD0-31CR-QVEL'),
      ]);
    }

    $curl = curl_init();
    curl_setopt_array($curl, [
      CURLOPT_URL => $endpoint ?: variable_get('stihl_pricing_api_endpoint', NULL),
      CURLOPT_RETURNTRANSFER => TRUE,
      CURLOPT_FOLLOWLOCATION => TRUE,
      CURLOPT_ENCODING => '',
      CURLOPT_MAXREDIRS => variable_get('stihl_pricing_api_max_redirect', 1),
      CURLOPT_TIMEOUT => variable_get('stihl_pricing_api_timeout', 60),
      CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
      CURLOPT_CUSTOMREQUEST => 'GET',
      CURLOPT_HTTPHEADER => $http_headers,
    ]);

    $response = curl_exec($curl);
    $this->curlError = curl_error($curl);
    $this->curlInfo = curl_getinfo($curl);
    curl_close($curl);

    // Clean up the UTF-8 BOM special characters so the JSON can be decoded.
    // {@link https://stackoverflow.com/questions/689185/json-decode-returns-null-after-webservice-call}
    $response = preg_replace('/[\x00-\x1F\x80-\xFF]/', '', $response);

    // If this is our first request, we can grab the redirect URL, remove the
    // custom authorization header and try again.
    if (!$this->curlError && $this->curlInfo['http_code'] != 200 && isset($this->curlInfo['url'])) {
      if (!($requests++)) {
        return $this->curlGetRequest($this->curlInfo['url']);
      }
      $this->curlError = $response;
    }
    return $response;
  }

  /**
   * Log API failure as set in settings form.
   */
  protected function logApiFailure() {
    if ($this->curlError) {
      // Log failure to watchdog.
      if (variable_get('stihl_pricing_api_log_failure', 1)) {
        watchdog('stihl_pricing',
          'Red Letter Pricing API GET request failed with error: @error',
          ['@error' => $this->curlError], WATCHDOG_ERROR);
      }
    }
  }

  /**
   * Helper function to return the products in our system.
   *
   * @return array
   *   An array of SKUs.
   */
  protected function getCommerceProductSkus() {
    $products = db_query('SELECT sku FROM {commerce_product}')->fetchCol();
    return $products;
  }

  /**
   * Helper function.
   *
   * Gets the branch profiles in our system that are currently
   * associated with a branch identifier in the PowerChord API system.
   *
   * @return array
   *   An array of branch identifiers ($api_bd_identifier).
   */
  protected function getBdProfiles() {
    $sql = 'SELECT api_bd_identifier,id FROM {stihl_profile} WHERE api_bd_identifier IS NOT NULL';
    $query = db_query($sql);
    $profiles = $query->fetchAllKeyed();
    return $profiles;
  }

  /**
   * Public API.
   *
   * @return Generator
   *   Associative array of the API response.
   */
  public function getRedLetterPricing() {
    if ($this->curlInfo['http_code'] == 200) {
      $response = drupal_json_decode($this->apiResponse);

      // Remove SKUs that aren't in our system.
      $response = array_filter($response, function ($sku) {
        return in_array($sku['HangTag'], $this->products)
          && isset($this->profiles[$sku['BDIdentifier']])
          && !empty($sku['HangTag']);
      });

      foreach ($response as $sku_price) {
        $bdid = $sku_price['BDIdentifier'];
        yield [
          'api_bd_identifier' => $bdid,
          'product_name' => $sku_price['Name'],
          'sku' => $sku_price['HangTag'],
          'msrp' => $sku_price['MSRP'],
          'current_year_price' => $sku_price['DSRP'],
          'next_year_price' => $sku_price['DSRP'],
          'display_product' => $sku_price['DisplayProduct'] == TRUE,
          'display_price' => $sku_price['DisplayPrice'] == TRUE,
          'bd_reference' => $this->profiles[$bdid],
        ];
      }
    }
  }

  /**
   * Debugging and maintenance method.
   */
  public function debug() {
    $api_response = drupal_json_decode($this->apiResponse);
    $res = [
      'curl_error' => $this->curlError,
      'curl_info' => $this->curlInfo,
      'api_response' => $api_response,
    ];

    // Dump the response to the screen.
    $debug = t('<br /><textarea rows="15" cols="75">@debug</textarea>', [
      '@debug' => print_r($res, TRUE),
    ]);
    drupal_set_message($debug);
  }

}
