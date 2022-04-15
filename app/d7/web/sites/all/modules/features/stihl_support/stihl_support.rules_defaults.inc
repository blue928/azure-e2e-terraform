<?php
/**
 * @file
 * stihl_support.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function stihl_support_default_rules_configuration() {
  $items = array();
  $items['rules_send_email_to_users_associated_with_current_bd_user_on_sup'] = entity_import('rules_config', '{ "rules_send_email_to_users_associated_with_current_bd_user_on_sup" : {
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
  return $items;
}
