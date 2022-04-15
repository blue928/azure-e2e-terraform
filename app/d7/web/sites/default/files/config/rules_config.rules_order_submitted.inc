<?php
/**
 * @file
 * rules_config.rules_order_submitted.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_order_submitted" : {
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

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'stihl_orders',
  2 => 'rules',
);
