<?php
/**
 * @file
 * rules_config.rules_stock_validate_checkout.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_stock_validate_checkout" : {
      "LABEL" : "Stock: validate checkout",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_ss", "rules", "commerce_stock" ],
      "ON" : { "commerce_stock_check_product_checkout" : [] },
      "IF" : [
        { "commerce_ss_stock_enabled_on_product" : { "commerce_product" : [ "commerce_product" ] } },
        { "commerce_ss_stock_not_disabled" : { "commerce_product" : [ "commerce_product" ] } },
        { "data_is" : {
            "data" : [ "stock-already-ordered" ],
            "op" : "\\u003E",
            "value" : [ "commerce-product:commerce-stock" ]
          }
        }
      ],
      "DO" : [
        { "commerce_stock_checkout_state" : {
            "stock_action" : "1",
            "message" : "The maximum quantity for [commerce-product:title] that can be ordered is [commerce-product:commerce-stock-int].",
            "approved_quantity" : [ "commerce-product:commerce-stock" ]
          }
        }
      ]
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'commerce_ss',
  2 => 'commerce_stock',
  3 => 'rules',
);
