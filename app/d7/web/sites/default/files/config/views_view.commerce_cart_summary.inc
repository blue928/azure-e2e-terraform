<?php
/**
 * @file
 * views_view.commerce_cart_summary.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_cart_summary';
$view->description = 'Cart line item summary displayed during checkout.';
$view->tag = 'commerce';
$view->base_table = 'commerce_order';
$view->human_name = 'Shopping cart summary';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Shopping cart';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'line_item_title' => 'line_item_title',
  'commerce_unit_price' => 'commerce_unit_price',
  'quantity' => 'quantity',
  'commerce_total' => 'commerce_total',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'line_item_title' => array(
    'align' => '',
    'separator' => '',
  ),
  'commerce_unit_price' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'quantity' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'commerce_total' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => 'views-align-right',
    'separator' => '',
  ),
);
/* Footer: Commerce Order: Order total */
$handler->display->display_options['footer']['order_total']['id'] = 'order_total';
$handler->display->display_options['footer']['order_total']['table'] = 'commerce_order';
$handler->display->display_options['footer']['order_total']['field'] = 'order_total';
/* Relationship: Commerce Order: Referenced line items */
$handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
$handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
$handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
$handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
/* Field: Commerce Line Item: Title */
$handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
$handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
$handler->display->display_options['fields']['line_item_title']['relationship'] = 'commerce_line_items_line_item_id';
$handler->display->display_options['fields']['line_item_title']['label'] = 'Product';
/* Field: Commerce Line item: Unit price */
$handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
$handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
$handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
$handler->display->display_options['fields']['commerce_unit_price']['relationship'] = 'commerce_line_items_line_item_id';
$handler->display->display_options['fields']['commerce_unit_price']['label'] = 'Price';
$handler->display->display_options['fields']['commerce_unit_price']['element_class'] = 'price';
$handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
  'calculation' => FALSE,
);
/* Field: Commerce Line Item: Quantity */
$handler->display->display_options['fields']['quantity']['id'] = 'quantity';
$handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['quantity']['field'] = 'quantity';
$handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
$handler->display->display_options['fields']['quantity']['precision'] = '0';
/* Field: Commerce Line item: Total */
$handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
$handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_line_items_line_item_id';
$handler->display->display_options['fields']['commerce_total']['element_class'] = 'price';
$handler->display->display_options['fields']['commerce_total']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_total']['settings'] = array(
  'calculation' => FALSE,
);
/* Sort criterion: Commerce Line Item: Line item ID */
$handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
$handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
$handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
$handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
/* Contextual filter: Commerce Order: Order ID */
$handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
$handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
$handler->display->display_options['arguments']['order_id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Commerce Line Item: Line item is of a product line item type */
$handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
$handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
$handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
$handler->display->display_options['filters']['product_line_item_type']['relationship'] = 'commerce_line_items_line_item_id';
$handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
$handler->display->display_options['filters']['product_line_item_type']['group'] = 0;


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_order',
  2 => 'commerce_price',
);
