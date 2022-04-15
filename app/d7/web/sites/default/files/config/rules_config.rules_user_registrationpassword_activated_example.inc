<?php
/**
 * @file
 * rules_config.rules_user_registrationpassword_activated_example.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_user_registrationpassword_activated_example" : {
      "LABEL" : "An example rule for the activated user rule.",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "user_registrationpassword" ],
      "ON" : { "user_registrationpassword_activated" : [] },
      "DO" : [ { "drupal_message" : { "message" : "Your account is now activate." } } ]
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'rules',
  2 => 'user_registrationpassword',
);
