<?php
/**
 * @file
 * views_view.commerce_reports_customers.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_reports_customers';
$view->description = '';
$view->tag = 'commerce_reports';
$view->base_table = 'users';
$view->human_name = 'Customer reports';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Customer reports';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access commerce reports';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'order_id' => 'order_id',
  'commerce_order_total_1' => 'commerce_order_total_1',
  'commerce_order_total' => 'commerce_order_total',
);
$handler->display->display_options['style_options']['default'] = 'commerce_order_total_1';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_order_total_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
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
);
/* Relationship: User: Orders */
$handler->display->display_options['relationships']['uid_commerce_orders']['id'] = 'uid_commerce_orders';
$handler->display->display_options['relationships']['uid_commerce_orders']['table'] = 'users';
$handler->display->display_options['relationships']['uid_commerce_orders']['field'] = 'uid_commerce_orders';
$handler->display->display_options['relationships']['uid_commerce_orders']['required'] = TRUE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Customer';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['relationship'] = 'uid_commerce_orders';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Orders';
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total_1']['id'] = 'commerce_order_total_1';
$handler->display->display_options['fields']['commerce_order_total_1']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['relationship'] = 'uid_commerce_orders';
$handler->display->display_options['fields']['commerce_order_total_1']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Total';
$handler->display->display_options['fields']['commerce_order_total_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['commerce_order_total_1']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total_1']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total_1']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
/* Field: AVG(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['relationship'] = 'uid_commerce_orders';
$handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'avg';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Average';
$handler->display->display_options['fields']['commerce_order_total']['element_type'] = '0';
$handler->display->display_options['fields']['commerce_order_total']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['commerce_order_total']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['commerce_order_total']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['fields']['commerce_order_total']['field_api_classes'] = TRUE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'uid_commerce_orders';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'commerce-reports';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'Search customers';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'uid_commerce_orders';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);
$handler->display->display_options['path'] = 'admin/commerce/reports/customers';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Customers';
$handler->display->display_options['menu']['description'] = 'View customer reports.';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Chart (by revenue) */
$handler = $view->new_display('block', 'Chart (by revenue)', 'chart_revenue');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'chart';
$handler->display->display_options['style_options']['library'] = 'google';
$handler->display->display_options['style_options']['label_field'] = 'name';
$handler->display->display_options['style_options']['data_fields'] = array(
  'commerce_order_total_1' => 'commerce_order_total_1',
  'name' => 0,
  'commerce_order_total' => 0,
);
$handler->display->display_options['style_options']['field_colors'] = array(
  'name' => '#2f7ed8',
  'commerce_order_total_1' => '#8bbc21',
  'commerce_order_total' => '#910000',
);
$handler->display->display_options['style_options']['width'] = '';
$handler->display->display_options['style_options']['height'] = '';
$handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
$handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Customer';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['empty'] = '0';
$handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
/* Field: SUM(Commerce Order: Order total) */
$handler->display->display_options['fields']['commerce_order_total_1']['id'] = 'commerce_order_total_1';
$handler->display->display_options['fields']['commerce_order_total_1']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total_1']['relationship'] = 'uid_commerce_orders';
$handler->display->display_options['fields']['commerce_order_total_1']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_order_total_1']['label'] = 'Total';
$handler->display->display_options['fields']['commerce_order_total_1']['element_label_colon'] = FALSE;
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

/* Display: Chart (by orders) */
$handler = $view->new_display('block', 'Chart (by orders)', 'chart_orders');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'chart';
$handler->display->display_options['style_options']['library'] = 'google';
$handler->display->display_options['style_options']['label_field'] = 'name';
$handler->display->display_options['style_options']['data_fields'] = array(
  'order_id' => 'order_id',
  'name' => 0,
  'commerce_order_total_1' => 0,
  'commerce_order_total' => 0,
);
$handler->display->display_options['style_options']['field_colors'] = array(
  'name' => '#2f7ed8',
  'order_id' => '#0d233a',
  'commerce_order_total_1' => '#8bbc21',
  'commerce_order_total' => '#910000',
);
$handler->display->display_options['style_options']['width'] = '';
$handler->display->display_options['style_options']['height'] = '';
$handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
$handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Customer';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['empty'] = '0';
$handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
/* Field: COUNT(Commerce Order: Order ID) */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['relationship'] = 'uid_commerce_orders';
$handler->display->display_options['fields']['order_id']['group_type'] = 'count';
$handler->display->display_options['fields']['order_id']['label'] = 'Orders';
$handler->display->display_options['fields']['order_id']['empty'] = '0';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'user',
  2 => 'commerce_price',
);
