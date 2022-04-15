<?php
/**
 * @file
 * rules_config.rules_redirect_pop_users_to_pop_catalog_on_login.inc
 */

$api = '2.0.0';

$data = entity_import('rules_config', '{ "rules_redirect_pop_users_to_pop_catalog_on_login" : {
      "LABEL" : "Redirect Pop Users to POP Catalog on Login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "POP" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "18" : "18" } } } }
      ],
      "DO" : [ { "redirect" : { "url" : "pop-catalog" } } ]
    }
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'rules',
);
