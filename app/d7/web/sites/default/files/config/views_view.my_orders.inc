<?php
/**
 * @file
 * views_view.my_orders.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'my_orders';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'commerce_order';
$view->human_name = 'My Orders';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Orders';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['tags']['first'] = '«';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
$handler->display->display_options['pager']['options']['tags']['next'] = '›';
$handler->display->display_options['pager']['options']['tags']['last'] = '»';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'order_id' => 'order_id',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'order_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = '<h3>Create a New Order</h3>
<p>Please use the button below to create a NEW Order for hang tags.
You may also “clone” a previous order and edit items and pricing and submit it as a new order. If using this feature, please carefully review existing products and pricing.</p>
<p><a class="btn btn-success" href="/orders/new">Create Order</a></p><hr />';
$handler->display->display_options['header']['area']['format'] = 'full_html';
/* Relationship: Commerce Order: Owner */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: User: BD Reference */
$handler->display->display_options['fields']['field_bd_reference']['id'] = 'field_bd_reference';
$handler->display->display_options['fields']['field_bd_reference']['table'] = 'field_data_field_bd_reference';
$handler->display->display_options['fields']['field_bd_reference']['field'] = 'field_bd_reference';
$handler->display->display_options['fields']['field_bd_reference']['relationship'] = 'uid';
$handler->display->display_options['fields']['field_bd_reference']['label'] = 'Branch';
$handler->display->display_options['fields']['field_bd_reference']['settings'] = array(
  'bypass_access' => 0,
  'link' => 0,
);
/* Field: Commerce Order: Order Name */
$handler->display->display_options['fields']['order_name']['id'] = 'order_name';
$handler->display->display_options['fields']['order_name']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_name']['field'] = 'order_name';
/* Field: Commerce Order: Order ID */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
/* Field: Commerce Order: Order Notes */
$handler->display->display_options['fields']['field_order_notes']['id'] = 'field_order_notes';
$handler->display->display_options['fields']['field_order_notes']['table'] = 'field_data_field_order_notes';
$handler->display->display_options['fields']['field_order_notes']['field'] = 'field_order_notes';
$handler->display->display_options['fields']['field_order_notes']['label'] = 'Description';
$handler->display->display_options['fields']['field_order_notes']['alter']['max_length'] = '80';
$handler->display->display_options['fields']['field_order_notes']['alter']['trim'] = TRUE;
/* Field: Realname: Real name */
$handler->display->display_options['fields']['realname']['id'] = 'realname';
$handler->display->display_options['fields']['realname']['table'] = 'realname';
$handler->display->display_options['fields']['realname']['field'] = 'realname';
$handler->display->display_options['fields']['realname']['relationship'] = 'uid';
$handler->display->display_options['fields']['realname']['label'] = 'Author';
$handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Commerce Order: Order Status */
$handler->display->display_options['fields']['field_order_status']['id'] = 'field_order_status';
$handler->display->display_options['fields']['field_order_status']['table'] = 'field_data_field_order_status';
$handler->display->display_options['fields']['field_order_status']['field'] = 'field_order_status';
$handler->display->display_options['fields']['field_order_status']['label'] = 'Status';
/* Field: Commerce Order: Pricing Year */
$handler->display->display_options['fields']['pricing_year_reference']['id'] = 'pricing_year_reference';
$handler->display->display_options['fields']['pricing_year_reference']['table'] = 'commerce_order';
$handler->display->display_options['fields']['pricing_year_reference']['field'] = 'pricing_year_reference';
$handler->display->display_options['fields']['pricing_year_reference']['label'] = 'Year';
/* Field: Commerce Order: Stihl Operations */
$handler->display->display_options['fields']['stihl_operations']['id'] = 'stihl_operations';
$handler->display->display_options['fields']['stihl_operations']['table'] = 'commerce_order';
$handler->display->display_options['fields']['stihl_operations']['field'] = 'stihl_operations';
$handler->display->display_options['fields']['stihl_operations']['label'] = 'Operations';
/* Sort criterion: Commerce Order: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';

/* Display: Admin */
$handler = $view->new_display('page', 'Admin', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = '<none>';
$handler->display->display_options['display_description'] = 'The display of the My Orders view for admin users.';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  3 => '3',
  5 => '5',
);
$handler->display->display_options['path'] = 'orders/list';

/* Display: Non-Admin */
$handler = $view->new_display('page', 'Non-Admin', 'page_1');
$handler->display->display_options['display_description'] = 'The display of the My Orders view for non-admin users.';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  2 => '2',
);
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: User: BD Reference (field_bd_reference) */
$handler->display->display_options['arguments']['field_bd_reference_target_id']['id'] = 'field_bd_reference_target_id';
$handler->display->display_options['arguments']['field_bd_reference_target_id']['table'] = 'field_data_field_bd_reference';
$handler->display->display_options['arguments']['field_bd_reference_target_id']['field'] = 'field_bd_reference_target_id';
$handler->display->display_options['arguments']['field_bd_reference_target_id']['relationship'] = 'uid';
$handler->display->display_options['arguments']['field_bd_reference_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_bd_reference_target_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_bd_reference_target_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_bd_reference_target_id']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Order: Order Status (field_order_status) */
$handler->display->display_options['filters']['field_order_status_value']['id'] = 'field_order_status_value';
$handler->display->display_options['filters']['field_order_status_value']['table'] = 'field_data_field_order_status';
$handler->display->display_options['filters']['field_order_status_value']['field'] = 'field_order_status_value';
$handler->display->display_options['filters']['field_order_status_value']['operator'] = '!=';
$handler->display->display_options['filters']['field_order_status_value']['value']['value'] = '31';
$handler->display->display_options['path'] = 'orders/list';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_order',
  2 => 'entityreference',
  3 => 'text',
  4 => 'workflowfield',
);
