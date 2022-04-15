<?php
/**
 * @file
 * rules_config.rules_is_pop_item_and_has_field.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_is_pop_item_and_has_field" : {
      "LABEL" : "Is POP item and has field",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "TAGS" : [ "POP" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "commerce_pop_type" : { "label" : "Commerce pop type", "type" : "commerce_product" } },
      "AND" : [
        { "entity_has_field" : {
            "entity" : [ "commerce-pop-type" ],
            "field" : "field_total_units_sold_to_date"
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
