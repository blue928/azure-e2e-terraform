<?php
/**
 * @file
 * rules_config.rules_line_item_and_product_type_reference_rule.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_line_item_and_product_type_reference_rule" : {
      "LABEL" : "Line item and Product type reference rule",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "POP" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "commerce_line_item" : { "label" : "Line Item", "type" : "commerce_line_item" },
        "commerce_product_stock" : { "label" : "Commerce Product Stock", "type" : "commerce_product" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-line-item:type" ], "value" : "product" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:type" ],
            "value" : "pop_item"
          }
        }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-line-item:commerce-product:field-total-units-sold-to-date" ],
              "op" : "+",
              "input_2" : [ "commerce-product-stock:commerce-stock" ]
            },
            "PROVIDE" : { "result" : { "new_total_amount_sold" : "New Total Amount Sold" } }
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
