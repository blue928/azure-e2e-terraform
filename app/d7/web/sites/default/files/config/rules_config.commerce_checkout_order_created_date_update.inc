<?php
/**
 * @file
 * rules_config.commerce_checkout_order_created_date_update.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_checkout_order_created_date_update" : {
      "LABEL" : "Set the order created date to the checkout completion date",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "data_set" : {
            "data" : [ "commerce-order:created" ],
            "value" : [ "site:current-date" ]
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
