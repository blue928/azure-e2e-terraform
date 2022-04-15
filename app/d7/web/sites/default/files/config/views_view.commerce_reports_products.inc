<?php
/**
 * @file
 * views_view.commerce_reports_products.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_reports_products';
$view->description = '';
$view->tag = 'commerce_reports';
$view->base_table = 'commerce_line_item';
$view->human_name = 'Product reports';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Product reports';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access commerce reports';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'sku' => 'sku',
  'title' => 'title',
  'quantity' => 'quantity',
  'commerce_total' => 'commerce_total',
);
$handler->display->display_options['style_options']['default'] = 'commerce_total';
$handler->display->display_options['style_options']['info'] = array(
  'sku' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'quantity' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_total' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
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
/* Field: Commerce Product: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'commerce_product';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['fields']['type']['link_to_product'] = 0;
$handler->display->display_options['fields']['type']['use_raw_value'] = 0;
/* Field: Commerce Product: SKU */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['fields']['sku']['label'] = 'Product';
$handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['sku']['link_to_product'] = 1;
/* Field: Commerce Product: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_product'] = 0;
/* Field: SUM(Commerce Line Item: Quantity) */
$handler->display->display_options['fields']['quantity']['id'] = 'quantity';
$handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['quantity']['field'] = 'quantity';
$handler->display->display_options['fields']['quantity']['group_type'] = 'sum';
$handler->display->display_options['fields']['quantity']['label'] = 'Sold';
$handler->display->display_options['fields']['quantity']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['quantity']['precision'] = '0';
/* Field: SUM(Commerce Line item: Total) */
$handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
$handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_total']['label'] = 'Revenue';
$handler->display->display_options['fields']['commerce_total']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_total']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_total']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_total']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
/* Sort criterion: COUNT(Commerce Line Item: Line item ID) */
$handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
$handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
$handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
$handler->display->display_options['sorts']['line_item_id']['group_type'] = 'count';
$handler->display->display_options['sorts']['line_item_id']['order'] = 'DESC';
/* Filter criterion: Commerce Line Item: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product' => 'product',
);
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'order_id';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'commerce-reports';
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Line Item: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product' => 'product',
);
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'order_id';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);
/* Filter criterion: Commerce Product: SKU */
$handler->display->display_options['filters']['sku']['id'] = 'sku';
$handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
$handler->display->display_options['filters']['sku']['field'] = 'sku';
$handler->display->display_options['filters']['sku']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['filters']['sku']['operator'] = 'word';
$handler->display->display_options['filters']['sku']['exposed'] = TRUE;
$handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['label'] = 'Search products (SKU)';
$handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
/* Filter criterion: Date: Date (commerce_order) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['relationship'] = 'order_id';
$handler->display->display_options['filters']['date_filter']['operator'] = 'between';
$handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
$handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
);
$handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
$handler->display->display_options['filters']['date_filter']['default_date'] = '-1 year';
$handler->display->display_options['filters']['date_filter']['default_to_date'] = 'now';
$handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'commerce_order.created' => 'commerce_order.created',
);
$handler->display->display_options['path'] = 'admin/commerce/reports/products';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Products';
$handler->display->display_options['menu']['description'] = 'View product reports.';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Chart (by revenue) */
$handler = $view->new_display('block', 'Chart (by revenue)', 'chart_revenue');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'chart';
$handler->display->display_options['style_options']['type'] = 'bar';
$handler->display->display_options['style_options']['library'] = 'google';
$handler->display->display_options['style_options']['label_field'] = 'title';
$handler->display->display_options['style_options']['data_fields'] = array(
  'title' => 'title',
  'commerce_total' => 'commerce_total',
  'sku' => 0,
  'quantity' => 0,
);
$handler->display->display_options['style_options']['field_colors'] = array(
  'sku' => '#2f7ed8',
  'title' => '#0d233a',
  'quantity' => '#8bbc21',
  'commerce_total' => '#005f91',
);
$handler->display->display_options['style_options']['legend_position'] = 'bottom';
$handler->display->display_options['style_options']['width'] = '';
$handler->display->display_options['style_options']['height'] = '';
$handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
$handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Product: SKU */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['fields']['sku']['label'] = 'Product';
$handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['sku']['empty'] = '0';
$handler->display->display_options['fields']['sku']['link_to_product'] = 1;
/* Field: Commerce Product: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['empty'] = '0';
$handler->display->display_options['fields']['title']['link_to_product'] = 0;
/* Field: SUM(Commerce Line Item: Quantity) */
$handler->display->display_options['fields']['quantity']['id'] = 'quantity';
$handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['quantity']['field'] = 'quantity';
$handler->display->display_options['fields']['quantity']['group_type'] = 'sum';
$handler->display->display_options['fields']['quantity']['label'] = 'Sold';
$handler->display->display_options['fields']['quantity']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['quantity']['empty'] = '0';
$handler->display->display_options['fields']['quantity']['precision'] = '0';
/* Field: SUM(Commerce Line item: Total) */
$handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
$handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['group_type'] = 'sum';
$handler->display->display_options['fields']['commerce_total']['label'] = 'Revenue';
$handler->display->display_options['fields']['commerce_total']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['commerce_total']['empty'] = '0';
$handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_total']['type'] = 'commerce_reports_visualization';
$handler->display->display_options['fields']['commerce_total']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_total']['group_column'] = 'amount';
$handler->display->display_options['fields']['commerce_total']['group_columns'] = array(
  'currency_code' => 'currency_code',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: SUM(Commerce Line item: Total (commerce_total:amount)) */
$handler->display->display_options['sorts']['commerce_total_amount']['id'] = 'commerce_total_amount';
$handler->display->display_options['sorts']['commerce_total_amount']['table'] = 'field_data_commerce_total';
$handler->display->display_options['sorts']['commerce_total_amount']['field'] = 'commerce_total_amount';
$handler->display->display_options['sorts']['commerce_total_amount']['group_type'] = 'sum';
$handler->display->display_options['sorts']['commerce_total_amount']['order'] = 'DESC';

/* Display: Chart (by quantity sold) */
$handler = $view->new_display('block', 'Chart (by quantity sold)', 'chart_quantity');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'chart';
$handler->display->display_options['style_options']['type'] = 'bar';
$handler->display->display_options['style_options']['library'] = 'google';
$handler->display->display_options['style_options']['label_field'] = 'title';
$handler->display->display_options['style_options']['data_fields'] = array(
  'title' => 'title',
  'quantity' => 'quantity',
  'sku' => 0,
  'commerce_total' => 0,
);
$handler->display->display_options['style_options']['field_colors'] = array(
  'sku' => '#2f7ed8',
  'title' => '#0d233a',
  'quantity' => '#8bbc21',
  'commerce_total' => '#910000',
);
$handler->display->display_options['style_options']['width'] = '';
$handler->display->display_options['style_options']['height'] = '';
$handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
$handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Product: SKU */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['fields']['sku']['label'] = 'Product';
$handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['sku']['empty'] = '0';
$handler->display->display_options['fields']['sku']['link_to_product'] = 1;
/* Field: Commerce Product: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['empty'] = '0';
$handler->display->display_options['fields']['title']['link_to_product'] = 0;
/* Field: SUM(Commerce Line Item: Quantity) */
$handler->display->display_options['fields']['quantity']['id'] = 'quantity';
$handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['quantity']['field'] = 'quantity';
$handler->display->display_options['fields']['quantity']['group_type'] = 'sum';
$handler->display->display_options['fields']['quantity']['label'] = 'Sold';
$handler->display->display_options['fields']['quantity']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['quantity']['empty'] = '0';
$handler->display->display_options['fields']['quantity']['precision'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: SUM(Commerce Line Item: Quantity) */
$handler->display->display_options['sorts']['quantity']['id'] = 'quantity';
$handler->display->display_options['sorts']['quantity']['table'] = 'commerce_line_item';
$handler->display->display_options['sorts']['quantity']['field'] = 'quantity';
$handler->display->display_options['sorts']['quantity']['group_type'] = 'sum';
$handler->display->display_options['sorts']['quantity']['order'] = 'DESC';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_line_item',
  2 => 'commerce_price',
);
