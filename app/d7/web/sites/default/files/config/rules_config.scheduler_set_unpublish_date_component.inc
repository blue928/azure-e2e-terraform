<?php
/**
 * @file
 * rules_config.scheduler_set_unpublish_date_component.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "scheduler_set_unpublish_date_component" : {
      "LABEL" : "Set scheduled unpublishing date",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Scheduler" ],
      "REQUIRES" : [ "scheduler" ],
      "USES VARIABLES" : {
        "scheduler_node" : {
          "type" : "node",
          "label" : "Node",
          "description" : "The node for unpublishing via Scheduler."
        },
        "scheduler_unpublish_on_date" : {
          "type" : "date",
          "label" : "Unpublish-on Date",
          "description" : "The unpublishing date to be used by Scheduler."
        }
      },
      "IF" : [
        { "scheduler_condition_unpublishing_is_enabled" : { "node" : [ "scheduler-node" ] } }
      ],
      "DO" : [
        { "scheduler_set_unpublish_date_action" : {
            "node" : [ "scheduler-node" ],
            "date" : [ "scheduler-unpublish-on-date" ]
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
