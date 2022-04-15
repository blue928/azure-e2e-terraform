<?php

/**
 * @file
 * stihl_product_views.features.inc
 */

/**
 * Implements hook_default_commerce_order_type().
 */
function stihl_product_views_default_commerce_order_type() {
  $items = array();
  $items['hangtags'] = entity_import('commerce_order_type', '{
    "type" : "hangtags",
    "help" : "",
    "data" : null,
    "name" : "hangtags",
    "rdf_mapping" : []
  }');
  $items['pop'] = entity_import('commerce_order_type', '{
    "type" : "pop",
    "help" : "",
    "data" : null,
    "name" : "pop",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function stihl_product_views_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function stihl_product_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
