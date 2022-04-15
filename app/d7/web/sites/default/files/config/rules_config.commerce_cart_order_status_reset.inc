<?php
/**
 * @file
 * rules_config.commerce_cart_order_status_reset.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_cart_order_status_reset" : {
      "LABEL" : "Reset the cart order status on product add or remove",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Cart" ],
      "REQUIRES" : [ "commerce_order", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [], "commerce_cart_product_remove" : [] },
      "DO" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce-order" ], "order_status" : "cart" } }
      ]
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'rules',
);
