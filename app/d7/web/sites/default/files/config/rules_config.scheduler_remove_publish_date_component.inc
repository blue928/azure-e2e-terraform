<?php
/**
 * @file
 * rules_config.scheduler_remove_publish_date_component.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "scheduler_remove_publish_date_component" : {
      "LABEL" : "Remove scheduled publishing date",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Scheduler" ],
      "REQUIRES" : [ "scheduler" ],
      "USES VARIABLES" : { "scheduler_node" : {
          "type" : "node",
          "label" : "The scheduled node",
          "description" : "The node scheduled for publishing via Scheduler."
        }
      },
      "IF" : [
        { "scheduler_condition_node_is_scheduled_for_publishing" : { "node" : [ "scheduler-node" ] } }
      ],
      "DO" : [
        { "scheduler_remove_publish_date_action" : { "node" : [ "scheduler-node" ] } }
      ]
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'rules',
);
