<?php
/**
 * @file
 * views_view.commerce_reports_sales_overview.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_reports_sales_overview';
$view->description = '';
$view->tag = 'commerce_reports';
$view->base_table = 'commerce_order';
$view->human_name = 'Sales reports overview';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'order_id' => 'order_id',
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
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
  'commerce_order_total' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['empty_table'] = TRUE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'Empty text';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No orders.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Sales';
$handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['order_id']['empty'] = 'None';
$handler->display->display_options['fields']['order_id']['empty_zero'] = TRUE;
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Gross';
$handler->display->display_options['fields']['commerce_order_total']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['commerce_order_total']['empty'] = 'None';
$handler->display->display_options['fields']['commerce_order_total']['empty_zero'] = TRUE;
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
/* Field: AVG(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total_1']['id'] = 'commerce_order_total_1';
$handler->display->display_options['fields']['commerce_order_total_1']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['group_type'] = 'avg';
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average';
$handler->display->display_options['fields']['commerce_order_total_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['commerce_order_total_1']['empty'] = 'None';
$handler->display->display_options['fields']['commerce_order_total_1']['empty_zero'] = TRUE;
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);

/* Display: Today */
$handler = $view->new_display('block', 'Today', 'today');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Today';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);
/* Filter criterion: Date: Date (commerce_order) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = '>';
$handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date (commerce_order)';
$handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['granularity'] = 'second';
$handler->display->display_options['filters']['date_filter']['default_date'] = 'today';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'commerce_order.created' => 'commerce_order.created',
);
$handler->display->display_options['block_description'] = 'Sales Reports: Overview (Today)';

/* Display: Yesterday */
$handler = $view->new_display('block', 'Yesterday', 'yesterday');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Yesterday';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);
/* Filter criterion: Date: Date (commerce_order) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = 'between';
$handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date (commerce_order)';
$handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['granularity'] = 'second';
$handler->display->display_options['filters']['date_filter']['default_date'] = 'yesterday';
$handler->display->display_options['filters']['date_filter']['default_to_date'] = 'today';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'commerce_order.created' => 'commerce_order.created',
);
$handler->display->display_options['block_description'] = 'Sales Reports: Overview (Yesterday)';

/* Display: Month */
$handler = $view->new_display('block', 'Month', 'month');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Month-to-date';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);
/* Filter criterion: Commerce Order: Created date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'commerce_order';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = '>=';
$handler->display->display_options['filters']['created']['value']['value'] = '-30 day';
$handler->display->display_options['filters']['created']['value']['type'] = 'offset';
$handler->display->display_options['block_description'] = 'Sales Reports: Overview (Month)';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_order',
  2 => 'commerce_price',
);
