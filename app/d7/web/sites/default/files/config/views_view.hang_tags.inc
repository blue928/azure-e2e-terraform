<?php
/**
 * @file
 * views_view.hang_tags.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'hang_tags';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'commerce_product';
$view->human_name = 'Add Hang Tags';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Add Hang Tags';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '15';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['tags']['first'] = '«';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
$handler->display->display_options['pager']['options']['tags']['next'] = '›';
$handler->display->display_options['pager']['options']['tags']['last'] = '»';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'field_model' => 'field_model',
  'field_model_subhead' => 'field_model_subhead',
  'field_main_length' => 'field_main_length',
  'field_special_pricing_language' => 'field_special_pricing_language',
  'field_horizontal_hangtag' => 'field_horizontal_hangtag',
  'sku' => 'sku',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_model' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_model_subhead' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_main_length' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 1,
  ),
  'field_special_pricing_language' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_horizontal_hangtag' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => 'views-align-center',
    'separator' => '',
    'empty_column' => 0,
  ),
  'sku' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: Bulk operations: Commerce Product */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_commerce_product';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'action::stihl_orders_add_hang_tags_action' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 1,
    'override_label' => 1,
    'label' => 'Add Hang Tags',
  ),
);
/* Field: Commerce Product: Model */
$handler->display->display_options['fields']['field_model']['id'] = 'field_model';
$handler->display->display_options['fields']['field_model']['table'] = 'field_data_field_model';
$handler->display->display_options['fields']['field_model']['field'] = 'field_model';
/* Field: Commerce Product: Model Subhead */
$handler->display->display_options['fields']['field_model_subhead']['id'] = 'field_model_subhead';
$handler->display->display_options['fields']['field_model_subhead']['table'] = 'field_data_field_model_subhead';
$handler->display->display_options['fields']['field_model_subhead']['field'] = 'field_model_subhead';
/* Field: Commerce Product: Main Length */
$handler->display->display_options['fields']['field_main_length']['id'] = 'field_main_length';
$handler->display->display_options['fields']['field_main_length']['table'] = 'field_data_field_main_length';
$handler->display->display_options['fields']['field_main_length']['field'] = 'field_main_length';
/* Field: Field: Special Pricing Language */
$handler->display->display_options['fields']['field_special_pricing_language']['id'] = 'field_special_pricing_language';
$handler->display->display_options['fields']['field_special_pricing_language']['table'] = 'field_data_field_special_pricing_language';
$handler->display->display_options['fields']['field_special_pricing_language']['field'] = 'field_special_pricing_language';
/* Field: Commerce Product: Horizontal Hangtag */
$handler->display->display_options['fields']['field_horizontal_hangtag']['id'] = 'field_horizontal_hangtag';
$handler->display->display_options['fields']['field_horizontal_hangtag']['table'] = 'field_data_field_horizontal_hangtag';
$handler->display->display_options['fields']['field_horizontal_hangtag']['field'] = 'field_horizontal_hangtag';
$handler->display->display_options['fields']['field_horizontal_hangtag']['label'] = 'Horizontal Format Available';
$handler->display->display_options['fields']['field_horizontal_hangtag']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_horizontal_hangtag']['alter']['text'] = 'Yes';
$handler->display->display_options['fields']['field_horizontal_hangtag']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_horizontal_hangtag']['empty_zero'] = TRUE;
$handler->display->display_options['fields']['field_horizontal_hangtag']['type'] = 'list_key';
/* Field: Commerce Product: SKU */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['link_to_product'] = 0;
/* Sort criterion: Commerce Product: Model (field_model) */
$handler->display->display_options['sorts']['field_model_value']['id'] = 'field_model_value';
$handler->display->display_options['sorts']['field_model_value']['table'] = 'field_data_field_model';
$handler->display->display_options['sorts']['field_model_value']['field'] = 'field_model_value';
/* Filter criterion: Commerce Product: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product' => 'product',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Commerce Product: Status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'commerce_product';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: Commerce Product: Product Category (field_product_category) */
$handler->display->display_options['filters']['field_product_category_tid']['id'] = 'field_product_category_tid';
$handler->display->display_options['filters']['field_product_category_tid']['table'] = 'field_data_field_product_category';
$handler->display->display_options['filters']['field_product_category_tid']['field'] = 'field_product_category_tid';
$handler->display->display_options['filters']['field_product_category_tid']['value'] = array(
  20 => '20',
  25 => '25',
  23 => '23',
  24 => '24',
  21 => '21',
  22 => '22',
  19 => '19',
  44 => '44',
  48 => '48',
  27 => '27',
  26 => '26',
  28 => '28',
  30 => '30',
  29 => '29',
  32 => '32',
  31 => '31',
  49 => '49',
  33 => '33',
  34 => '34',
  35 => '35',
  36 => '36',
  38 => '38',
  37 => '37',
  39 => '39',
  40 => '40',
  41 => '41',
  42 => '42',
  43 => '43',
  46 => '46',
  45 => '45',
  47 => '47',
);
$handler->display->display_options['filters']['field_product_category_tid']['group'] = 1;
$handler->display->display_options['filters']['field_product_category_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_product_category_tid']['expose']['operator_id'] = 'field_product_category_tid_op';
$handler->display->display_options['filters']['field_product_category_tid']['expose']['label'] = 'Product Category';
$handler->display->display_options['filters']['field_product_category_tid']['expose']['operator'] = 'field_product_category_tid_op';
$handler->display->display_options['filters']['field_product_category_tid']['expose']['identifier'] = 'field_product_category_tid';
$handler->display->display_options['filters']['field_product_category_tid']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['field_product_category_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
);
$handler->display->display_options['filters']['field_product_category_tid']['expose']['reduce'] = TRUE;
$handler->display->display_options['filters']['field_product_category_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_product_category_tid']['vocabulary'] = 'product_category';
$handler->display->display_options['filters']['field_product_category_tid']['hierarchy'] = 1;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'orders/add-hang-tags/%';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_product',
  2 => 'text',
  3 => 'list',
);
