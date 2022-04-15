<?php
/**
 * @file
 * views_view.commerce_reports_sales.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_reports_sales';
$view->description = 'View commerce daily and monthly sales totals.';
$view->tag = 'commerce_reports';
$view->base_table = 'commerce_order';
$view->human_name = 'Sales reports';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Sales report';
$handler->display->display_options['css_class'] = 'commerce-reports';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access commerce reports';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Refresh report';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'sales_data' => 'sales_data',
  'order_id' => 'order_id',
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
);
$handler->display->display_options['style_options']['default'] = 'sales_data';
$handler->display->display_options['style_options']['info'] = array(
  'sales_data' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
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
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
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
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
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
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;

/* Display: Sales reports (Month) */
$handler = $view->new_display('page', 'Sales reports (Month)', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Monthly sales report';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'created' => 'created',
  'order_id' => 'order_id',
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Order date';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F Y';
$handler->display->display_options['fields']['created']['format_date_sql'] = 1;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
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
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Commerce Order: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['sorts']['created']['exposed'] = TRUE;
$handler->display->display_options['sorts']['created']['expose']['label'] = 'Order date';
$handler->display->display_options['sorts']['created']['granularity'] = 'month';
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
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
/* Filter criterion: Date: Date (commerce_order) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = 'between';
$handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Order date';
$handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
);
$handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
$handler->display->display_options['filters']['date_filter']['default_date'] = '-12 months';
$handler->display->display_options['filters']['date_filter']['default_to_date'] = 'now';
$handler->display->display_options['filters']['date_filter']['year_range'] = '-4:+0';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'commerce_order.created' => 'commerce_order.created',
);
$handler->display->display_options['path'] = 'admin/commerce/reports/sales';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Sales';
$handler->display->display_options['menu']['description'] = 'View sales reports.';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Sales totals';
$handler->display->display_options['tab_options']['description'] = 'View daily and monthly sales totals.';
$handler->display->display_options['tab_options']['weight'] = '-10';
$handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Sales reports (Weekly) */
$handler = $view->new_display('page', 'Sales reports (Weekly)', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Weekly sales report';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'created' => 'created',
  'order_id' => 'order_id',
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Order date';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = '\\w\\e\\e\\k W \\o\\f Y';
$handler->display->display_options['fields']['created']['format_date_sql'] = 1;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
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
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Commerce Order: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['sorts']['created']['exposed'] = TRUE;
$handler->display->display_options['sorts']['created']['expose']['label'] = 'Order date';
$handler->display->display_options['sorts']['created']['granularity'] = 'week';
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
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
/* Filter criterion: Date: Date (commerce_order) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = 'between';
$handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Order date';
$handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
);
$handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
$handler->display->display_options['filters']['date_filter']['default_date'] = '-12 months';
$handler->display->display_options['filters']['date_filter']['default_to_date'] = 'now';
$handler->display->display_options['filters']['date_filter']['year_range'] = '-4:+0';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'commerce_order.created' => 'commerce_order.created',
);
$handler->display->display_options['path'] = 'admin/commerce/reports/sales/weekly';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Weekly';
$handler->display->display_options['menu']['description'] = 'View sales reports.';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Sales totals';
$handler->display->display_options['tab_options']['description'] = 'View daily and monthly sales totals.';
$handler->display->display_options['tab_options']['weight'] = '-10';
$handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Sales reports (Daily) */
$handler = $view->new_display('page', 'Sales reports (Daily)', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Daily sales report';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'created' => 'created',
  'order_id' => 'order_id',
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Order date';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'j F Y';
$handler->display->display_options['fields']['created']['format_date_sql'] = 1;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
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
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Commerce Order: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['sorts']['created']['exposed'] = TRUE;
$handler->display->display_options['sorts']['created']['expose']['label'] = 'Order date';
$handler->display->display_options['sorts']['created']['granularity'] = 'day';
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
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
/* Filter criterion: Date: Date (commerce_order) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = 'between';
$handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Order date';
$handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
);
$handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
$handler->display->display_options['filters']['date_filter']['default_date'] = '-1 months';
$handler->display->display_options['filters']['date_filter']['default_to_date'] = 'now';
$handler->display->display_options['filters']['date_filter']['year_range'] = '-4:+0';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'commerce_order.created' => 'commerce_order.created',
);
$handler->display->display_options['path'] = 'admin/commerce/reports/sales/daily';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Daily';
$handler->display->display_options['menu']['description'] = 'View sales reports.';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Sales totals';
$handler->display->display_options['tab_options']['description'] = 'View daily and monthly sales totals.';
$handler->display->display_options['tab_options']['weight'] = '-10';
$handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Sales reports (Yearly) */
$handler = $view->new_display('page', 'Sales reports (Yearly)', 'page_3');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Yearly sales report';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'created' => 'created',
  'order_id' => 'order_id',
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Order date';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'Y';
$handler->display->display_options['fields']['created']['format_date_sql'] = 1;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
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
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Commerce Order: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['sorts']['created']['exposed'] = TRUE;
$handler->display->display_options['sorts']['created']['expose']['label'] = 'Order date';
$handler->display->display_options['sorts']['created']['granularity'] = 'year';
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
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
/* Filter criterion: Date: Date (commerce_order) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = 'between';
$handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Order date';
$handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
);
$handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
$handler->display->display_options['filters']['date_filter']['default_date'] = '-10 years';
$handler->display->display_options['filters']['date_filter']['default_to_date'] = 'now';
$handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+0';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'commerce_order.created' => 'commerce_order.created',
);
$handler->display->display_options['path'] = 'admin/commerce/reports/sales/yearly';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Yearly';
$handler->display->display_options['menu']['description'] = 'View sales reports.';
$handler->display->display_options['menu']['weight'] = '20';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Sales totals';
$handler->display->display_options['tab_options']['description'] = 'View yearly sales totals.';
$handler->display->display_options['tab_options']['weight'] = '-10';
$handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Chart (one year) */
$handler = $view->new_display('block', 'Chart (one year)', 'chart_year');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'chart';
$handler->display->display_options['style_options']['type'] = 'line';
$handler->display->display_options['style_options']['library'] = 'google';
$handler->display->display_options['style_options']['label_field'] = 'created';
$handler->display->display_options['style_options']['data_fields'] = array(
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
  'order_id' => 0,
  'created' => 0,
);
$handler->display->display_options['style_options']['field_colors'] = array(
  'order_id' => '#0d233a',
  'commerce_order_total' => '#8bbc21',
  'commerce_order_total_1' => '#910000',
  'created' => '#910000',
);
$handler->display->display_options['style_options']['width'] = '1140';
$handler->display->display_options['style_options']['height'] = '225';
$handler->display->display_options['style_options']['xaxis_labels_rotation'] = '45';
$handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'M Y';
$handler->display->display_options['fields']['created']['format_date_sql'] = 1;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
$handler->display->display_options['fields']['order_id']['empty'] = '0';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
$handler->display->display_options['fields']['commerce_order_total']['empty'] = '0';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_reports_visualization';
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
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['empty'] = '0';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['type'] = 'commerce_reports_visualization';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Commerce Order: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['granularity'] = 'month';
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
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
/* Filter criterion: Commerce Order: Created date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'commerce_order';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = '>=';
$handler->display->display_options['filters']['created']['value']['value'] = '-1 year';
$handler->display->display_options['filters']['created']['value']['type'] = 'offset';

/* Display: Chart (one month) */
$handler = $view->new_display('block', 'Chart (one month)', 'chart_month');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'chart';
$handler->display->display_options['style_options']['type'] = 'line';
$handler->display->display_options['style_options']['library'] = 'google';
$handler->display->display_options['style_options']['label_field'] = 'created';
$handler->display->display_options['style_options']['data_fields'] = array(
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
  'created' => 0,
  'order_id' => 0,
);
$handler->display->display_options['style_options']['field_colors'] = array(
  'created' => '#2f7ed8',
  'order_id' => '#0d233a',
  'commerce_order_total' => '#8bbc21',
  'commerce_order_total_1' => '#910000',
);
$handler->display->display_options['style_options']['width'] = '1140';
$handler->display->display_options['style_options']['height'] = '225';
$handler->display->display_options['style_options']['xaxis_labels_rotation'] = '45';
$handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'd M';
$handler->display->display_options['fields']['created']['format_date_sql'] = 1;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
$handler->display->display_options['fields']['order_id']['empty'] = '0';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
$handler->display->display_options['fields']['commerce_order_total']['empty'] = '0';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_reports_visualization';
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
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['empty'] = '0';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['type'] = 'commerce_reports_visualization';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Commerce Order: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['granularity'] = 'day';
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
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
/* Filter criterion: Commerce Order: Created date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'commerce_order';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = '>=';
$handler->display->display_options['filters']['created']['value']['value'] = '-1 month';
$handler->display->display_options['filters']['created']['value']['type'] = 'offset';

/* Display: Chart (one week) */
$handler = $view->new_display('block', 'Chart (one week)', 'chart_week');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'chart';
$handler->display->display_options['style_options']['type'] = 'line';
$handler->display->display_options['style_options']['library'] = 'google';
$handler->display->display_options['style_options']['label_field'] = 'created';
$handler->display->display_options['style_options']['data_fields'] = array(
  'commerce_order_total' => 'commerce_order_total',
  'commerce_order_total_1' => 'commerce_order_total_1',
  'created' => 0,
  'order_id' => 0,
);
$handler->display->display_options['style_options']['field_colors'] = array(
  'created' => '#2f7ed8',
  'order_id' => '#0d233a',
  'commerce_order_total' => '#8bbc21',
  'commerce_order_total_1' => '#910000',
);
$handler->display->display_options['style_options']['width'] = '1140';
$handler->display->display_options['style_options']['height'] = '225';
$handler->display->display_options['style_options']['xaxis_labels_rotation'] = '45';
$handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'j F';
$handler->display->display_options['fields']['created']['format_date_sql'] = 1;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Number of Orders';
$handler->display->display_options['fields']['order_id']['empty'] = '0';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total Revenue';
$handler->display->display_options['fields']['commerce_order_total']['empty'] = '0';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_reports_visualization';
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
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Average Order';
$handler->display->display_options['fields']['commerce_order_total_1']['empty'] = '0';
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['type'] = 'commerce_reports_visualization';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Commerce Order: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['granularity'] = 'day';
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
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
/* Filter criterion: Commerce Order: Created date */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'commerce_order';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['operator'] = '>=';
$handler->display->display_options['filters']['created']['value']['value'] = '-1 week';
$handler->display->display_options['filters']['created']['value']['type'] = 'offset';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_order',
  2 => 'commerce_price',
);
