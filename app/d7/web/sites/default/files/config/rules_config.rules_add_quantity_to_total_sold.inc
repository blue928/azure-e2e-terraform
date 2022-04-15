<?php
/**
 * @file
 * rules_config.rules_add_quantity_to_total_sold.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_add_quantity_to_total_sold" : {
      "LABEL" : "Add Quantity to Total Sold",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "POP" ],
      "REQUIRES" : [ "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : []
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'commerce_checkout',
  2 => 'rules',
);
