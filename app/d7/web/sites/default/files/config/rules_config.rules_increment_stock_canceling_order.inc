<?php
/**
 * @file
 * rules_config.rules_increment_stock_canceling_order.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_increment_stock_canceling_order" : {
      "LABEL" : "Stock: Increase when canceling the order process",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "stock_control" ],
      "REQUIRES" : [ "rules", "commerce_ss", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "canceled" } },
        { "data_is" : {
            "data" : [ "commerce-order-unchanged:status" ],
            "op" : "IN",
            "value" : { "value" : {
                "pending" : "pending",
                "processing" : "processing",
                "completed" : "completed"
              }
            }
          }
        }
      ],
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
  1 => 'commerce_ss',
  2 => 'rules',
);
