<?php
/**
 * @file
 * rules_config.commerce_checkout_order_email.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "commerce_checkout_order_email" : {
      "LABEL" : "Send an order notification e-mail",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Order [commerce-order:order-number] at [site:name]",
            "message" : "Thanks for your order [commerce-order:order-number] at [site:name].\\n\\nIf this is your first order with us, you will receive a separate e-mail with login instructions. You can view your order history with us at any time by logging into our website at:\\n\\n[site:login-url]\\n\\nYou can find the status of your current order at:\\n\\n[commerce-order:customer-url]\\n\\nPlease contact us if you have any questions about your order.",
            "from" : ""
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
