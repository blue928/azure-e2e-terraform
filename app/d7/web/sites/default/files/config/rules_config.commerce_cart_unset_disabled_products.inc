<?php
/**
 * @file
 * rules_config.commerce_cart_unset_disabled_products.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_cart_unset_disabled_products" : {
      "LABEL" : "Unset the price of disabled products in the cart",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Cart" ],
      "REQUIRES" : [ "rules", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "commerce-line-item:line-item-id" ] } },
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "commerce_product" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:status" ],
            "value" : "0"
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "commerce-line-item:commerce-unit-price:amount" ] } }
      ]
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'rules',
);
