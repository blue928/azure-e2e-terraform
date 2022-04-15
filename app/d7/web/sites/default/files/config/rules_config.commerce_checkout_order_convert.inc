<?php
/**
 * @file
 * rules_config.commerce_checkout_order_convert.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_checkout_order_convert" : {
      "LABEL" : "Assign an anonymous order to a pre-existing user",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:uid" ], "value" : "0" } },
        { "entity_exists" : {
            "type" : "user",
            "property" : "mail",
            "value" : [ "commerce-order:mail" ]
          }
        },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "commerce-order:mail" ],
              "limit" : 1
            },
            "PROVIDE" : { "entity_fetched" : { "account_fetched" : "Fetched account" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "account-fetched" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "data_set" : { "data" : [ "commerce-order:uid" ], "value" : [ "list-item:uid" ] } },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-billing:uid" ],
                  "value" : [ "list-item:uid" ]
                }
              }
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
  1 => 'rules',
);
