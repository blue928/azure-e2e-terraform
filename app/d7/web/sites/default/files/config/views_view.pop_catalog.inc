<?php
/**
 * @file
 * views_view.pop_catalog.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'pop_catalog';
$view->description = 'List of POP product items for sale';
$view->tag = 'default';
$view->base_table = 'commerce_product';
$view->human_name = 'POP Catalog';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'POP Catalog';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
/* Field: Commerce Product: Preview */
$handler->display->display_options['fields']['field_preview']['id'] = 'field_preview';
$handler->display->display_options['fields']['field_preview']['table'] = 'field_data_field_preview';
$handler->display->display_options['fields']['field_preview']['field'] = 'field_preview';
$handler->display->display_options['fields']['field_preview']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_preview']['settings'] = array(
  'image_style' => 'thumbnail',
  'image_link' => '',
);
/* Field: Commerce Product: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'commerce_product';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_product'] = 0;
/* Field: Commerce Product: Available until */
$handler->display->display_options['fields']['field_available_until']['id'] = 'field_available_until';
$handler->display->display_options['fields']['field_available_until']['table'] = 'field_data_field_available_until';
$handler->display->display_options['fields']['field_available_until']['field'] = 'field_available_until';
$handler->display->display_options['fields']['field_available_until']['label'] = '';
$handler->display->display_options['fields']['field_available_until']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_available_until']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_available_until']['settings'] = array(
  'format_type' => 'short',
  'custom_date_format' => '',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Commerce Product: Price Table */
$handler->display->display_options['fields']['field_price_table']['id'] = 'field_price_table';
$handler->display->display_options['fields']['field_price_table']['table'] = 'field_data_field_price_table';
$handler->display->display_options['fields']['field_price_table']['field'] = 'field_price_table';
$handler->display->display_options['fields']['field_price_table']['label'] = '';
$handler->display->display_options['fields']['field_price_table']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_price_table']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_price_table']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['field_price_table']['settings'] = array(
  'price_label' => 'Price',
  'quantity_label' => 'Quantity',
  'table_orientation' => '0',
);
$handler->display->display_options['fields']['field_price_table']['delta_offset'] = '0';
/* Field: Commerce Product: Description */
$handler->display->display_options['fields']['field_description']['id'] = 'field_description';
$handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
$handler->display->display_options['fields']['field_description']['field'] = 'field_description';
$handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_description']['alter']['text'] = '<h4>[title]</h4>
<p>[field_description]</p>
[field_price_table]<br />
Available Until: [field_available_until]';
$handler->display->display_options['fields']['field_description']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['field_description']['settings'] = array(
  'trim_length' => '150',
);
/* Field: Commerce Product: Price */
$handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
$handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
$handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
$handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_price']['settings'] = array(
  'calculation' => '0',
);
/* Field: Commerce Product: Add to Cart form */
$handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
$handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
$handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
$handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
$handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 1;
$handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
$handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
$handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 1;
$handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 0;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'title' => 'title',
  'field_description' => 'field_description',
);
/* Filter criterion: Commerce Product: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'evergreen' => 'evergreen',
  'pop_item' => 'pop_item',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Commerce Product: Event Type (field_event_type) */
$handler->display->display_options['filters']['field_event_type_tid']['id'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['table'] = 'field_data_field_event_type';
$handler->display->display_options['filters']['field_event_type_tid']['field'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_event_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_event_type_tid']['expose']['operator_id'] = 'field_event_type_tid_op';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['label'] = 'Event Type';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['operator'] = 'field_event_type_tid_op';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['identifier'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['field_event_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_event_type_tid']['vocabulary'] = 'pop_event_category';
/* Filter criterion: Commerce Product: Product Type (field_product_type) */
$handler->display->display_options['filters']['field_product_type_tid']['id'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['table'] = 'field_data_field_product_type';
$handler->display->display_options['filters']['field_product_type_tid']['field'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_product_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_product_type_tid']['expose']['operator_id'] = 'field_product_type_tid_op';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['label'] = 'Product Type';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['operator'] = 'field_product_type_tid_op';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['identifier'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['field_product_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_product_type_tid']['vocabulary'] = 'pop_item_category';

/* Display: POP Catalog */
$handler = $view->new_display('page', 'POP Catalog', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'POP Catalog';
$handler->display->display_options['path'] = 'pop-catalog';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'All POP Items';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: POP Evergreen Page */
$handler = $view->new_display('page', 'POP Evergreen Page', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'POP Evergreen items';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'title' => 'title',
  'field_description' => 'field_description',
);
/* Filter criterion: Commerce Product: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'evergreen' => 'evergreen',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Commerce Product: Event Type (field_event_type) */
$handler->display->display_options['filters']['field_event_type_tid']['id'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['table'] = 'field_data_field_event_type';
$handler->display->display_options['filters']['field_event_type_tid']['field'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_event_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_event_type_tid']['expose']['operator_id'] = 'field_event_type_tid_op';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['label'] = 'Event Type';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['operator'] = 'field_event_type_tid_op';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['identifier'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['field_event_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_event_type_tid']['vocabulary'] = 'pop_event_category';
/* Filter criterion: Commerce Product: Product Type (field_product_type) */
$handler->display->display_options['filters']['field_product_type_tid']['id'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['table'] = 'field_data_field_product_type';
$handler->display->display_options['filters']['field_product_type_tid']['field'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_product_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_product_type_tid']['expose']['operator_id'] = 'field_product_type_tid_op';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['label'] = 'Product Type';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['operator'] = 'field_product_type_tid_op';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['identifier'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['field_product_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_product_type_tid']['vocabulary'] = 'pop_item_category';
$handler->display->display_options['path'] = 'pop-catalog/evergreen';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Evergreen Items';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: POP Campaign Page */
$handler = $view->new_display('page', 'POP Campaign Page', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'POP Campaign Items';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'title' => 'title',
  'field_description' => 'field_description',
);
/* Filter criterion: Commerce Product: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'pop_item' => 'pop_item',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Commerce Product: Event Type (field_event_type) */
$handler->display->display_options['filters']['field_event_type_tid']['id'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['table'] = 'field_data_field_event_type';
$handler->display->display_options['filters']['field_event_type_tid']['field'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_event_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_event_type_tid']['expose']['operator_id'] = 'field_event_type_tid_op';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['label'] = 'Event Type';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['operator'] = 'field_event_type_tid_op';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['identifier'] = 'field_event_type_tid';
$handler->display->display_options['filters']['field_event_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['field_event_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_event_type_tid']['vocabulary'] = 'pop_event_category';
/* Filter criterion: Commerce Product: Product Type (field_product_type) */
$handler->display->display_options['filters']['field_product_type_tid']['id'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['table'] = 'field_data_field_product_type';
$handler->display->display_options['filters']['field_product_type_tid']['field'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_product_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_product_type_tid']['expose']['operator_id'] = 'field_product_type_tid_op';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['label'] = 'Product Type';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['operator'] = 'field_product_type_tid_op';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['identifier'] = 'field_product_type_tid';
$handler->display->display_options['filters']['field_product_type_tid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
  7 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
);
$handler->display->display_options['filters']['field_product_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_product_type_tid']['vocabulary'] = 'pop_item_category';
$handler->display->display_options['path'] = 'pop-catalog/campaign';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Campaign Items';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_product',
  2 => 'image',
  3 => 'date',
  4 => 'commerce_price_table',
  5 => 'text',
  6 => 'commerce_price',
);
