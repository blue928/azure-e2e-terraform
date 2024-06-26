<?php
/**
 * @file
 * views_view.commerce_user_orders.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_user_orders';
$view->description = 'Display a list of completed orders for a user.';
$view->tag = 'commerce';
$view->base_table = 'commerce_order';
$view->human_name = 'User orders';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Orders';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view own commerce_order entities';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = 25;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'order_number' => 'order_number',
  'placed' => 'placed',
  'changed' => 'changed',
  'commerce_order_total' => 'commerce_order_total',
  'status' => 'status',
);
$handler->display->display_options['style_options']['default'] = 'order_number';
$handler->display->display_options['style_options']['info'] = array(
  'order_number' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'placed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total' => array(
    'sortable' => 0,
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
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['text']['id'] = 'text';
$handler->display->display_options['empty']['text']['table'] = 'views';
$handler->display->display_options['empty']['text']['field'] = 'area';
$handler->display->display_options['empty']['text']['content'] = 'You have not placed any orders with us yet.';
$handler->display->display_options['empty']['text']['format'] = 'plain_text';
/* Field: Commerce Order: Order number */
$handler->display->display_options['fields']['order_number']['id'] = 'order_number';
$handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_number']['field'] = 'order_number';
$handler->display->display_options['fields']['order_number']['link_to_order'] = 'customer';
/* Field: Commerce Order: Placed date */
$handler->display->display_options['fields']['placed']['id'] = 'placed';
$handler->display->display_options['fields']['placed']['table'] = 'commerce_order';
$handler->display->display_options['fields']['placed']['field'] = 'placed';
$handler->display->display_options['fields']['placed']['label'] = 'Placed';
/* Field: Commerce Order: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Updated';
/* Field: Commerce Order: Order total */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
  'calculation' => FALSE,
);
/* Field: Commerce Order: Order status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_order';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Contextual filter: Commerce Order: Uid */
$handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
$handler->display->display_options['arguments']['uid_1']['table'] = 'commerce_order';
$handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
$handler->display->display_options['arguments']['uid_1']['default_action'] = 'not found';
$handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['uid_1']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['uid_1']['validate']['type'] = 'current_user_or_role';
$handler->display->display_options['arguments']['uid_1']['validate_options']['restrict_roles'] = TRUE;
$handler->display->display_options['arguments']['uid_1']['validate_options']['roles'] = array(
  3 => '3',
);
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['operator'] = 'not in';
$handler->display->display_options['filters']['state']['value'] = array(
  'cart' => 'cart',
  'checkout' => 'checkout',
);

/* Display: User Orders */
$handler = $view->new_display('page', 'User Orders', 'order_page');
$handler->display->display_options['path'] = 'user/%/orders';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Orders';
$handler->display->display_options['menu']['weight'] = '15';
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Orders';
$handler->display->display_options['tab_options']['description'] = 'User orders in the store.';
$handler->display->display_options['tab_options']['weight'] = '';
$handler->display->display_options['tab_options']['name'] = 'user-menu';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_order',
  2 => 'commerce_price',
);
