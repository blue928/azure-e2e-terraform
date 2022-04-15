<?php
/**
 * @file
 * views_view.product_individual_report.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'product_individual_report';
$view->description = '';
$view->tag = 'commerce_reports';
$view->base_table = 'commerce_line_item';
$view->human_name = 'Product individual report';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Product individual report';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access commerce reports';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
/* Relationship: Commerce Line Item: Order ID */
$handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['table'] = 'commerce_line_item';
$handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['required'] = TRUE;
/* Relationship: Commerce Line item: Referenced products */
$handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
$handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
$handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
$handler->display->display_options['relationships']['commerce_product_product_id']['required'] = TRUE;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['relationship'] = 'order_id';
$handler->display->display_options['fields']['created']['label'] = 'Order date';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
$handler->display->display_options['fields']['created']['format_date_sql'] = 1;
/* Field: SUM(Commerce Line Item: Quantity) */
$handler->display->display_options['fields']['quantity']['id'] = 'quantity';
$handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['quantity']['field'] = 'quantity';
$handler->display->display_options['fields']['quantity']['group_type'] = 'sum';
$handler->display->display_options['fields']['quantity']['label'] = 'Sold';
$handler->display->display_options['fields']['quantity']['precision'] = '0';
/* Field: SUM(Commerce Line item: Total) */
$handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
$handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_total']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_total']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
/* Sort criterion: Commerce Line Item: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_line_item';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['exposed'] = TRUE;
$handler->display->display_options['sorts']['created']['expose']['label'] = 'Order date';
$handler->display->display_options['sorts']['created']['granularity'] = 'month';
/* Contextual filter: Commerce Product: Product ID */
$handler->display->display_options['arguments']['product_id']['id'] = 'product_id';
$handler->display->display_options['arguments']['product_id']['table'] = 'commerce_product';
$handler->display->display_options['arguments']['product_id']['field'] = 'product_id';
$handler->display->display_options['arguments']['product_id']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['arguments']['product_id']['default_action'] = 'access denied';
$handler->display->display_options['arguments']['product_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['product_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['product_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['product_id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Commerce Line Item: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product' => 'product',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/commerce/products/%/reports';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Reports';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_line_item',
  2 => 'commerce_price',
);
