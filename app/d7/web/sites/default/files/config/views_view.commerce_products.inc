<?php
/**
 * @file
 * views_view.commerce_products.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_products';
$view->description = 'Display a list of products for store admin.';
$view->tag = 'commerce';
$view->base_table = 'commerce_product';
$view->human_name = 'Products';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Products';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer commerce_product entities';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = 50;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'sku' => 'sku',
  'title' => 'title',
  'type' => 'type',
  'commerce_price' => 'commerce_price',
  'status' => 'status',
  'operations' => 'operations',
);
$handler->display->display_options['style_options']['default'] = 'sku';
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
  'type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_price' => array(
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
  'operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['empty_table'] = TRUE;
/* No results behavior: Commerce Product: Empty text */
$handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
$handler->display->display_options['empty']['empty_text']['table'] = 'commerce_product';
$handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
$handler->display->display_options['empty']['empty_text']['add_path'] = 'admin/commerce/products/add';
/* Field: Commerce Product: SKU */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['link_to_product'] = 0;
/* Field: Commerce Product: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['link_to_product'] = 1;
/* Field: Commerce Product: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'commerce_product';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['link_to_product'] = 0;
/* Field: Commerce Product: Price */
$handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
$handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
$handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
$handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
/* Field: Commerce Product: Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_product';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['type'] = 'active-disabled';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Commerce Product: Operations links */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'commerce_product';
$handler->display->display_options['fields']['operations']['field'] = 'operations';
$handler->display->display_options['fields']['operations']['label'] = 'Operations';
$handler->display->display_options['fields']['operations']['add_destination'] = 1;
/* Sort criterion: Commerce Product: SKU */
$handler->display->display_options['sorts']['sku']['id'] = 'sku';
$handler->display->display_options['sorts']['sku']['table'] = 'commerce_product';
$handler->display->display_options['sorts']['sku']['field'] = 'sku';
/* Filter criterion: Commerce Product: SKU */
$handler->display->display_options['filters']['sku']['id'] = 'sku';
$handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
$handler->display->display_options['filters']['sku']['field'] = 'sku';
$handler->display->display_options['filters']['sku']['operator'] = 'contains';
$handler->display->display_options['filters']['sku']['exposed'] = TRUE;
$handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['label'] = 'Filter by SKUs containing';
$handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';

/* Display: Admin page */
$handler = $view->new_display('page', 'Admin page', 'admin_page');
$handler->display->display_options['path'] = 'admin/commerce/products/list';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'List';
$handler->display->display_options['menu']['weight'] = '-10';
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Products';
$handler->display->display_options['tab_options']['description'] = 'Manage products and product types in the store.';
$handler->display->display_options['tab_options']['weight'] = '';
$handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Manage POP Products */
$handler = $view->new_display('page', 'Manage POP Products', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Manage POP Products';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Product: SKU */
$handler->display->display_options['filters']['sku']['id'] = 'sku';
$handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
$handler->display->display_options['filters']['sku']['field'] = 'sku';
$handler->display->display_options['filters']['sku']['operator'] = 'contains';
$handler->display->display_options['filters']['sku']['exposed'] = TRUE;
$handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['label'] = 'Filter by SKUs containing';
$handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
/* Filter criterion: Commerce Product: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'evergreen' => 'evergreen',
  'pop_item' => 'pop_item',
);
$handler->display->display_options['path'] = 'pop-catalog/admin/products/list';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Manage POP Products';
$handler->display->display_options['menu']['description'] = 'Manage POP Products';
$handler->display->display_options['menu']['weight'] = '-10';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Products';
$handler->display->display_options['tab_options']['description'] = 'Manage products and product types in the store.';
$handler->display->display_options['tab_options']['weight'] = '';
$handler->display->display_options['tab_options']['name'] = 'management';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_product',
  2 => 'commerce_price',
);
