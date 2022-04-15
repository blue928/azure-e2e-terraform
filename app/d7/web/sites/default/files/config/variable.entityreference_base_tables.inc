<?php
/**
 * @file
 * variable.entityreference_base_tables.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'entityreference:base-tables',
  'content' => array(
    'comment' => array(
      0 => 'comment',
      1 => 'cid',
    ),
    'commerce_customer_profile' => array(
      0 => 'commerce_customer_profile',
      1 => 'profile_id',
    ),
    'commerce_line_item' => array(
      0 => 'commerce_line_item',
      1 => 'line_item_id',
    ),
    'commerce_order' => array(
      0 => 'commerce_order',
      1 => 'order_id',
    ),
    'commerce_payment_transaction' => array(
      0 => 'commerce_payment_transaction',
      1 => 'transaction_id',
    ),
    'commerce_product' => array(
      0 => 'commerce_product',
      1 => 'product_id',
    ),
    'fp_template_configs' => array(
      0 => 'fp_template_config',
      1 => 'id',
    ),
    'node' => array(
      0 => 'node',
      1 => 'nid',
    ),
    'search_api_server' => array(
      0 => 'search_api_server',
      1 => 'id',
    ),
    'search_api_index' => array(
      0 => 'search_api_index',
      1 => 'id',
    ),
    'search_api_page' => array(
      0 => 'search_api_page',
      1 => 'id',
    ),
    'stihl_pricing' => array(
      0 => 'stihl_pricing',
      1 => 'id',
    ),
    'stihl_pricing_years' => array(
      0 => 'stihl_pricing_year',
      1 => 'id',
    ),
    'stihl_profiles' => array(
      0 => 'stihl_profile',
      1 => 'id',
    ),
    'file' => array(
      0 => 'file_managed',
      1 => 'fid',
    ),
    'taxonomy_term' => array(
      0 => 'taxonomy_term_data',
      1 => 'tid',
    ),
    'taxonomy_vocabulary' => array(
      0 => 'taxonomy_vocabulary',
      1 => 'vid',
    ),
    'user' => array(
      0 => 'users',
      1 => 'uid',
    ),
    'Workflow' => array(
      0 => 'workflows',
      1 => 'wid',
    ),
    'WorkflowState' => array(
      0 => 'workflow_states',
      1 => 'sid',
    ),
    'WorkflowConfigTransition' => array(
      0 => 'workflow_transitions',
      1 => 'tid',
    ),
    'WorkflowTransition' => array(
      0 => 'workflow_node_history',
      1 => 'hid',
    ),
    'WorkflowScheduledTransition' => array(
      0 => 'workflow_scheduled_transition',
      1 => 'tid',
    ),
    'rules_config' => array(
      0 => 'rules_config',
      1 => 'id',
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array();
