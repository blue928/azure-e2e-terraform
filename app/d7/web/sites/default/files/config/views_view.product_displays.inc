<?php
/**
 * @file
 * views_view.product_displays.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'product_displays';
$view->description = 'Display a list of products for store admin.';
$view->tag = 'commerce';
$view->base_table = 'commerce_product';
$view->human_name = 'Product Displays';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Products';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer commerce_product entities';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '518400';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '518400';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
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
$handler->display->display_options['filters']['sku']['expose']['label'] = 'Filter by SKUs Containing';
$handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
$handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
);
/* Filter criterion: Commerce Product: Status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'commerce_product';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';

/* Display: BD page */
$handler = $view->new_display('page', 'BD page', 'page_1');
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  2 => '2',
);
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '15';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['tags']['first'] = '‹‹';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
$handler->display->display_options['pager']['options']['tags']['next'] = '›';
$handler->display->display_options['pager']['options']['tags']['last'] = '››';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'product';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Product: Product ID */
$handler->display->display_options['fields']['product_id']['id'] = 'product_id';
$handler->display->display_options['fields']['product_id']['table'] = 'commerce_product';
$handler->display->display_options['fields']['product_id']['field'] = 'product_id';
$handler->display->display_options['fields']['product_id']['label'] = '';
$handler->display->display_options['fields']['product_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['product_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['product_id']['link_to_product'] = 0;
/* Field: Commerce Product: Link */
$handler->display->display_options['fields']['view_product']['id'] = 'view_product';
$handler->display->display_options['fields']['view_product']['table'] = 'commerce_product';
$handler->display->display_options['fields']['view_product']['field'] = 'view_product';
$handler->display->display_options['fields']['view_product']['label'] = '';
$handler->display->display_options['fields']['view_product']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['view_product']['alter']['text'] = 'link';
$handler->display->display_options['fields']['view_product']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['view_product']['alter']['path'] = '/product/[product_id]';
$handler->display->display_options['fields']['view_product']['element_class'] = 'btn btn-default display-link';
$handler->display->display_options['fields']['view_product']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_product']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['view_product']['element_default_classes'] = FALSE;
/* Field: Commerce Product: Horizontal Hangtag */
$handler->display->display_options['fields']['field_horizontal_hangtag']['id'] = 'field_horizontal_hangtag';
$handler->display->display_options['fields']['field_horizontal_hangtag']['table'] = 'field_data_field_horizontal_hangtag';
$handler->display->display_options['fields']['field_horizontal_hangtag']['field'] = 'field_horizontal_hangtag';
$handler->display->display_options['fields']['field_horizontal_hangtag']['label'] = '';
$handler->display->display_options['fields']['field_horizontal_hangtag']['element_class'] = 'hangtag-1';
$handler->display->display_options['fields']['field_horizontal_hangtag']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_horizontal_hangtag']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_horizontal_hangtag']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_horizontal_hangtag']['type'] = 'list_key';
/* Field: Commerce Product: Model */
$handler->display->display_options['fields']['field_model']['id'] = 'field_model';
$handler->display->display_options['fields']['field_model']['table'] = 'field_data_field_model';
$handler->display->display_options['fields']['field_model']['field'] = 'field_model';
$handler->display->display_options['fields']['field_model']['label'] = '';
$handler->display->display_options['fields']['field_model']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_model']['element_type'] = 'h4';
$handler->display->display_options['fields']['field_model']['element_class'] = 'model';
$handler->display->display_options['fields']['field_model']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_model']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_model']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_model']['element_default_classes'] = FALSE;
/* Field: Commerce Product: SKU */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['exclude'] = TRUE;
$handler->display->display_options['fields']['sku']['element_class'] = 'sku';
$handler->display->display_options['fields']['sku']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['sku']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['sku']['link_to_product'] = 0;
/* Field: Commerce Product: Main Length */
$handler->display->display_options['fields']['field_main_length']['id'] = 'field_main_length';
$handler->display->display_options['fields']['field_main_length']['table'] = 'field_data_field_main_length';
$handler->display->display_options['fields']['field_main_length']['field'] = 'field_main_length';
$handler->display->display_options['fields']['field_main_length']['label'] = '';
$handler->display->display_options['fields']['field_main_length']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_main_length']['element_class'] = 'length';
$handler->display->display_options['fields']['field_main_length']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_main_length']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_main_length']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_main_length']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_main_length']['empty_zero'] = TRUE;
/* Field: Commerce Product: Top Level Category */
$handler->display->display_options['fields']['field_top_level_category']['id'] = 'field_top_level_category';
$handler->display->display_options['fields']['field_top_level_category']['table'] = 'field_data_field_top_level_category';
$handler->display->display_options['fields']['field_top_level_category']['field'] = 'field_top_level_category';
$handler->display->display_options['fields']['field_top_level_category']['label'] = '';
$handler->display->display_options['fields']['field_top_level_category']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_top_level_category']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h4 class="model">[field_model]</h4>
<div class="sku">SKU: [sku]</div>
<div class="length">[field_main_length]</div>';
$handler->display->display_options['fields']['nothing']['element_type'] = 'div';
$handler->display->display_options['fields']['nothing']['element_class'] = 'info';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Commerce Product: Product Category (field_product_category) */
$handler->display->display_options['arguments']['field_product_category_tid']['id'] = 'field_product_category_tid';
$handler->display->display_options['arguments']['field_product_category_tid']['table'] = 'field_data_field_product_category';
$handler->display->display_options['arguments']['field_product_category_tid']['field'] = 'field_product_category_tid';
$handler->display->display_options['arguments']['field_product_category_tid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_product_category_tid']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['field_product_category_tid']['title'] = '%1';
$handler->display->display_options['arguments']['field_product_category_tid']['default_argument_type'] = 'taxonomy_tid';
$handler->display->display_options['arguments']['field_product_category_tid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_product_category_tid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_product_category_tid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_product_category_tid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_product_category_tid']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['field_product_category_tid']['validate_options']['vocabularies'] = array(
  'product_category' => 'product_category',
);
$handler->display->display_options['arguments']['field_product_category_tid']['validate_options']['transform'] = TRUE;
$handler->display->display_options['path'] = 'taxonomy/term/%';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'List';
$handler->display->display_options['menu']['weight'] = '-10';
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
  3 => 'list',
  4 => 'text',
);
