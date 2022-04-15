<?php

/**
 * @file
 * stihl_order_config.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function stihl_order_config_default_rules_configuration() {
  $items = array();
  $items['rules_order_submitted'] = entity_import('rules_config', '{ "rules_order_submitted" : {
      "LABEL" : "Order Submitted",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Stihl Orders" ],
      "REQUIRES" : [ "stihl_orders", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "stihl_orders_workflow_is_being_submitted" : { "order_id" : [ "commerce-order:order-id" ] } }
      ],
      "DO" : [
        { "stihl_orders_create_online_proof" : { "order_id" : [ "commerce-order:order-id" ] } }
      ]
    }
  }');
  return $items;
}
