<?php
/**
 * @file
 * rules_config.commerce_payment_commerce_payment_example.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_payment_commerce_payment_example" : {
      "LABEL" : "Example payment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Payment" ],
      "REQUIRES" : [ "commerce_payment" ],
      "ON" : { "commerce_payment_methods" : [] },
      "DO" : [
        { "commerce_payment_enable_commerce_payment_example" : {
            "commerce_order" : [ "commerce-order" ],
            "payment_method" : "commerce_payment_example"
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
