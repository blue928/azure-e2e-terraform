<?php
/**
 * @file
 * rules_config.rules_stock_validate_add_to_cart.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_stock_validate_add_to_cart" : {
      "LABEL" : "Stock: validate add to cart",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_ss", "rules", "commerce_stock" ],
      "ON" : { "commerce_stock_add_to_cart_check_product" : [] },
      "IF" : [
        { "commerce_ss_stock_enabled_on_product" : { "commerce_product" : [ "commerce_product" ] } },
        { "commerce_ss_stock_not_disabled" : { "commerce_product" : [ "commerce_product" ] } },
        { "data_is" : {
            "data" : [ "stock-requested-total" ],
            "op" : "\\u003E",
            "value" : [ "commerce-product:commerce-stock" ]
          }
        }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-product:commerce-stock" ],
              "op" : "-",
              "input_2" : [ "stock-already-ordered" ]
            },
            "PROVIDE" : { "result" : { "approved_quantity" : "approved quantity" } }
          }
        },
        { "commerce_stock_add_to_cart_set_state" : {
            "stock_action" : "1",
            "message" : "The maximum quantity for [commerce-product:title] that can be ordered is [commerce-product:commerce-stock-int].\\r\\n",
            "approved_quantity" : [ "approved-quantity" ]
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
