<?php
/**
 * @file
 * rules_config.rules_stock_disable_add_to_cart.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_stock_disable_add_to_cart" : {
      "LABEL" : "Stock: disable add to cart ",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_ss", "rules", "commerce_stock" ],
      "ON" : { "commerce_stock_check_add_to_cart_form_state" : [] },
      "IF" : [
        { "commerce_ss_stock_enabled_on_product" : { "commerce_product" : [ "commerce_product" ] } },
        { "commerce_ss_stock_not_disabled" : { "commerce_product" : [ "commerce_product" ] } },
        { "NOT data_is" : {
            "data" : [ "commerce-product:commerce-stock" ],
            "op" : "\\u003E",
            "value" : "0"
          }
        }
      ],
      "DO" : [
        { "commerce_stock_set_add_to_cart_form_state" : { "disabled" : 1, "text" : "Out of stock", "class_name" : "out-of-stock" } }
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
