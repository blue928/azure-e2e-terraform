<?php
/**
 * @file
 * views_view.commerce_reports_customer_statistics.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_reports_customer_statistics';
$view->description = '';
$view->tag = 'commerce_reports';
$view->base_table = 'commerce_order';
$view->human_name = 'Commerce Reports Customer Statistics';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Customer Statistics';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'row';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Commerce Order: Owner */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
$handler->display->display_options['fields']['commerce_order_total']['element_type'] = 'span';
$handler->display->display_options['fields']['commerce_order_total']['element_label_type'] = 'span';
$handler->display->display_options['fields']['commerce_order_total']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'entity_id';
$handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
  'amount' => 'amount',
);
/* Field: AVG(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total_1']['id'] = 'commerce_order_total_1';
$handler->display->display_options['fields']['commerce_order_total_1']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['group_type'] = 'avg';
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['element_type'] = 'span';
$handler->display->display_options['fields']['commerce_order_total_1']['element_label_type'] = 'span';
$handler->display->display_options['fields']['commerce_order_total_1']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'entity_id';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'amount' => 'amount',
);
/* Field: COUNT(DISTINCT Commerce Order: Uid) */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'commerce_order';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['group_type'] = 'count_distinct';
$handler->display->display_options['fields']['uid']['label'] = 'Customers Total';
/* Filter criterion: Commerce Order: Order type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_order';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'commerce_order' => 'commerce_order',
);
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);

/* Display: Customer Order Statistics */
$handler = $view->new_display('block', 'Customer Order Statistics', 'customer_statistics');


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_order',
  2 => 'commerce_price',
);
