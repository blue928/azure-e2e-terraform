<?php
/**
 * @file
 * rules_config.rules_increase_total_sold_to_date_by_quantity.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_increase_total_sold_to_date_by_quantity" : {
      "LABEL" : "Increase Total Sold to Date by Quantity",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "POP" ],
      "USES VARIABLES" : { "line_item_reference" : { "label" : "Line item reference", "type" : "commerce_line_item" } },
      "ACTION SET" : []
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'rules',
);
