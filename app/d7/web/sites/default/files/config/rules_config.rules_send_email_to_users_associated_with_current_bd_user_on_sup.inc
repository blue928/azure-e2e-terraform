<?php
/**
 * @file
 * rules_config.rules_send_email_to_users_associated_with_current_bd_user_on_sup.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_send_email_to_users_associated_with_current_bd_user_on_sup" : {
      "LABEL" : "Send email to users associated with current BD user on Support webform submission.",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "webform_rules" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "user" ], "roles" : { "value" : { "4" : "4" } } } },
        { "webform_has_id" : {
            "form_id" : [ "form-id" ],
            "selected_webform" : { "value" : { "webform-client-form-7" : "webform-client-form-7" } }
          }
        }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "field_bd_reference",
              "value" : [ "user:field-bd-reference" ],
              "limit" : "1000"
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "mail" : {
            "to" : [ "entity-fetched:0:mail" ],
            "subject" : [ "selected-webform:0" ],
            "message" : [ "selected-webform:3" ],
            "from" : [ "user:name" ],
            "language" : [ "" ]
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
  2 => 'webform_rules',
);
