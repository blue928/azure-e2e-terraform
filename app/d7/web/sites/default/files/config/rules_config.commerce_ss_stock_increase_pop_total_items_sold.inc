<?php
/**
 * @file
 * rules_config.commerce_ss_stock_increase_pop_total_items_sold.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_ss_stock_increase_pop_total_items_sold" : {
      "LABEL" : "Stock: Increase POP total items sold",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "stock_control" ],
      "REQUIRES" : [ "commerce_ss", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "commerce_ss_increase_by_line_item" : { "commerce_line_item" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'commerce_checkout',
  2 => 'commerce_ss',
  3 => 'rules',
);
