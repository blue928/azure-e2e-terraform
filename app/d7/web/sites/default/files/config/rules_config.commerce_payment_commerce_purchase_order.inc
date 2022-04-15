<?php
/**
 * @file
 * rules_config.commerce_payment_commerce_purchase_order.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_payment_commerce_purchase_order" : {
      "LABEL" : "Purchase Order",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Payment" ],
      "REQUIRES" : [ "commerce_payment" ],
      "ON" : { "commerce_payment_methods" : [] },
      "DO" : [
        { "commerce_payment_enable_commerce_purchase_order" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : "commerce_purchase_order"
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
