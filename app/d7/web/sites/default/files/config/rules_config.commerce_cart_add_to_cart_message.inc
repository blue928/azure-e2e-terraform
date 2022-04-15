<?php
/**
 * @file
 * rules_config.commerce_cart_add_to_cart_message.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_cart_add_to_cart_message" : {
      "LABEL" : "Display an Add to Cart message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Cart" ],
      "REQUIRES" : [ "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "DO" : [
        { "commerce_cart_add_to_cart_message" : { "commerce_product" : [ "commerce-product" ] } }
      ]
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'rules',
);
