<?php
/**
 * @file
 * rules_config.commerce_price_table_override_price.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_price_table_override_price" : {
      "LABEL" : "Override price with price table",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_price_table", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "commerce_product" } },
        { "entity_has_field" : {
            "entity" : [ "commerce-line-item:commerce-product" ],
            "field" : "field_price_table"
          }
        }
      ],
      "DO" : [
        { "commerce_price_table_set_price" : {
            "commerce_line_item" : [ "commerce-line-item" ],
            "quantity" : [ "commerce-line-item:quantity" ],
            "price_table" : [ "commerce-line-item:commerce-product:field-price-table" ],
            "component_name" : "base_price"
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
