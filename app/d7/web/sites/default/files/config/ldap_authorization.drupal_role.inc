<?php
/**
 * @file
 * ldap_authorization.drupal_role.inc
 */

$api = '2.0.0';

$data = $consumer_type = new stdClass();
$consumer_type->disabled = FALSE; /* Edit this to true to make a default consumer_type disabled initially */
$consumer_type->api_version = 1;
$consumer_type->sid = 'CG';
$consumer_type->consumer_type = 'drupal_role';
$consumer_type->consumer_module = 'ldap_authorization_drupal_role';
$consumer_type->status = TRUE;
$consumer_type->only_ldap_authenticated = TRUE;
$consumer_type->use_first_attr_as_groupid = TRUE;
$consumer_type->mappings = 'a:21:{i:0;a:6:{s:12:"user_entered";s:18:"classic accounting";s:4:"from";s:10:"Accounting";s:10:"normalized";s:18:"classic accounting";s:10:"simplified";s:18:"classic accounting";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:1;a:6:{s:12:"user_entered";s:18:"classic accounting";s:4:"from";s:18:"Accounting Writers";s:10:"normalized";s:18:"classic accounting";s:10:"simplified";s:18:"classic accounting";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:2;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:17:"Apple Power Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:3;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:16:"CG Mac RDS Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:4;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:11:"CG TS Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:5;a:6:{s:12:"user_entered";s:17:"classic executive";s:4:"from";s:18:"Classic Executives";s:10:"normalized";s:17:"classic executive";s:10:"simplified";s:17:"classic executive";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:6;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:19:"Charlotte MAC Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:7;a:6:{s:12:"user_entered";s:15:"classic manager";s:4:"from";s:18:"Charlotte Managers";s:10:"normalized";s:15:"classic manager";s:10:"simplified";s:15:"classic manager";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:8;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:18:"Charlotte PC Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:9;a:6:{s:12:"user_entered";s:13:"classic sales";s:4:"from";s:15:"Charlotte Sales";s:10:"normalized";s:13:"classic sales";s:10:"simplified";s:13:"classic sales";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:10;a:6:{s:12:"user_entered";s:13:"administrator";s:4:"from";s:23:"Classic Graphics Admins";s:10:"normalized";s:13:"administrator";s:10:"simplified";s:13:"administrator";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:11;a:6:{s:12:"user_entered";s:9:"developer";s:4:"from";s:27:"Classic Graphics Developers";s:10:"normalized";s:9:"developer";s:10:"simplified";s:9:"developer";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:12;a:6:{s:12:"user_entered";s:13:"classic sales";s:4:"from";s:22:"Classic Graphics Sales";s:10:"normalized";s:13:"classic sales";s:10:"simplified";s:13:"classic sales";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:13;a:6:{s:12:"user_entered";s:15:"classic manager";s:4:"from";s:6:"CLTMGR";s:10:"normalized";s:15:"classic manager";s:10:"simplified";s:15:"classic manager";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:14;a:6:{s:12:"user_entered";s:9:"developer";s:4:"from";s:10:"Developers";s:10:"normalized";s:9:"developer";s:10:"simplified";s:9:"developer";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:15;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:12:"Domain Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:16;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:8:"Internet";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:17;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:12:"Jabber Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:18;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:9:"NAT Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:19;a:6:{s:12:"user_entered";s:18:"classic accounting";s:4:"from";s:7:"Payroll";s:10:"normalized";s:18:"classic accounting";s:10:"simplified";s:18:"classic accounting";s:5:"valid";b:1;s:13:"error_message";s:0:"";}i:20;a:6:{s:12:"user_entered";s:16:"classic employee";s:4:"from";s:14:"Wireless Users";s:10:"normalized";s:16:"classic employee";s:10:"simplified";s:16:"classic employee";s:5:"valid";b:1;s:13:"error_message";s:0:"";}}';
$consumer_type->use_filter = TRUE;
$consumer_type->synch_to_ldap = FALSE;
$consumer_type->synch_on_logon = TRUE;
$consumer_type->revoke_ldap_provisioned = TRUE;
$consumer_type->create_consumers = TRUE;
$consumer_type->regrant_ldap_provisioned = TRUE;


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'ldap_authorization',
);
