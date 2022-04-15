<?php
/**
 * @file
 * views_view.commerce_order_revisions.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_order_revisions';
$view->description = 'Display a list of order revisions for the store admin.';
$view->tag = 'commerce';
$view->base_table = 'commerce_order_revision';
$view->human_name = 'Order revisions';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Revisions';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'revision_id' => 'revision_id',
  'revision_timestamp' => 'revision_timestamp',
  'order_number' => 'order_number',
  'name' => 'name',
  'mail' => 'mail',
  'status' => 'status',
  'log' => 'log',
);
$handler->display->display_options['style_options']['default'] = 'revision_id';
$handler->display->display_options['style_options']['info'] = array(
  'revision_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'revision_timestamp' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_number' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'mail' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'log' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: Commerce Order revision: User */
$handler->display->display_options['relationships']['revision_uid']['id'] = 'revision_uid';
$handler->display->display_options['relationships']['revision_uid']['table'] = 'commerce_order_revision';
$handler->display->display_options['relationships']['revision_uid']['field'] = 'revision_uid';
/* Field: Commerce Order revision: Revision ID */
$handler->display->display_options['fields']['revision_id']['id'] = 'revision_id';
$handler->display->display_options['fields']['revision_id']['table'] = 'commerce_order_revision';
$handler->display->display_options['fields']['revision_id']['field'] = 'revision_id';
$handler->display->display_options['fields']['revision_id']['label'] = 'Revision';
/* Field: Commerce Order revision: Revision date */
$handler->display->display_options['fields']['revision_timestamp']['id'] = 'revision_timestamp';
$handler->display->display_options['fields']['revision_timestamp']['table'] = 'commerce_order_revision';
$handler->display->display_options['fields']['revision_timestamp']['field'] = 'revision_timestamp';
$handler->display->display_options['fields']['revision_timestamp']['label'] = 'Created on';
$handler->display->display_options['fields']['revision_timestamp']['date_format'] = 'short';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'revision_uid';
$handler->display->display_options['fields']['name']['label'] = 'Created by';
/* Field: Commerce Order revision: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'commerce_order_revision';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['label'] = 'Order e-mail';
$handler->display->display_options['fields']['mail']['render_as_link'] = 0;
/* Field: Commerce Order revision: Order status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_order_revision';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: Commerce Order revision: Log message */
$handler->display->display_options['fields']['log']['id'] = 'log';
$handler->display->display_options['fields']['log']['table'] = 'commerce_order_revision';
$handler->display->display_options['fields']['log']['field'] = 'log';
/* Contextual filter: Commerce Order revision: Order ID */
$handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
$handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order_revision';
$handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
$handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
$handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';

/* Display: Order Revisions */
$handler = $view->new_display('page', 'Order Revisions', 'order_revisions_page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'admin/commerce/orders/%/revisions';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Revisions';
$handler->display->display_options['menu']['description'] = 'View revisions of this order.';
$handler->display->display_options['menu']['weight'] = '20';
$handler->display->display_options['menu']['context'] = 0;


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_order',
);
