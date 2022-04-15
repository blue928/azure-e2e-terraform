<?php
/**
 * @file
 * rules_config.scheduler_send_email_after_unpublishing_node.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "scheduler_send_email_after_unpublishing_node" : {
      "LABEL" : "Send e-mail when content is unpublished by Scheduler",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "Scheduler" ],
      "REQUIRES" : [ "rules", "scheduler" ],
      "ON" : { "scheduler_node_has_been_unpublished_event" : [] },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:author:mail" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "\\u0027[node:title]\\u0027 has been unpublished on [site:name]",
            "message" : "Dear [node:author:name],\\r\\nYour [node:type] \\u0027[node:title]\\u0027 has been unpublished on [site:name].\\r\\nThe link is [node:url]\\r\\n"
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
