<?php
/**
 * @file
 * rules_config.commerce_price_table_table_override_price_based_on_total_sold.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_price_table_table_override_price_based_on_total_sold" : {
      "LABEL" : "Override price based on total sold",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "OWNER" : "rules",
      "TAGS" : [ "POP" ],
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
            "commerce_line_item" : [ "commerce_line_item" ],
            "quantity" : [ "commerce-line-item:commerce-product:commerce-stock" ],
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
  1 => 'commerce_price_table',
  2 => 'commerce_product_reference',
  3 => 'rules',
);
