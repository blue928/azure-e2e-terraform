<?php
/**
 * @file
 * rules_config.scheduler_set_publish_date_component.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "scheduler_set_publish_date_component" : {
      "LABEL" : "Set scheduled publishing date",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Scheduler" ],
      "REQUIRES" : [ "scheduler" ],
      "USES VARIABLES" : {
        "scheduler_node" : {
          "type" : "node",
          "label" : "Node",
          "description" : "The node for publishing via Scheduler."
        },
        "scheduler_publish_on_date" : {
          "type" : "date",
          "label" : "Publish-on Date",
          "description" : "The publishing date to be used by Scheduler."
        }
      },
      "IF" : [
        { "scheduler_condition_publishing_is_enabled" : { "node" : [ "scheduler-node" ] } }
      ],
      "DO" : [
        { "scheduler_set_publish_date_action" : {
            "node" : [ "scheduler-node" ],
            "date" : [ "scheduler-publish-on-date" ]
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
