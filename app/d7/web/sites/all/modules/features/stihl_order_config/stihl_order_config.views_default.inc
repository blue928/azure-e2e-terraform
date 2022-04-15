<?php

/**
 * @file
 * stihl_order_config.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stihl_order_config_views_default_views() {
  $export = array();

  $view = new view();
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
  $export['hang_tags'] = $view;

  $view = new view();
  $view->name = 'my_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'My Orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_id' => 'order_id',
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
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h3>Create a New Order</h3>
<p>Please use the button below to create a NEW Order for hang tags.
You may also “clone” a previous order and edit items and pricing and submit it as a new order. If using this feature, please carefully review existing products and pricing.</p>
<p><a class="btn btn-success" href="/orders/new">Create Order</a></p><hr />';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: User: BD Reference */
  $handler->display->display_options['fields']['field_bd_reference']['id'] = 'field_bd_reference';
  $handler->display->display_options['fields']['field_bd_reference']['table'] = 'field_data_field_bd_reference';
  $handler->display->display_options['fields']['field_bd_reference']['field'] = 'field_bd_reference';
  $handler->display->display_options['fields']['field_bd_reference']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_bd_reference']['label'] = 'Branch';
  $handler->display->display_options['fields']['field_bd_reference']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Commerce Order: Order Name */
  $handler->display->display_options['fields']['order_name']['id'] = 'order_name';
  $handler->display->display_options['fields']['order_name']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_name']['field'] = 'order_name';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  /* Field: Commerce Order: Order Notes */
  $handler->display->display_options['fields']['field_order_notes']['id'] = 'field_order_notes';
  $handler->display->display_options['fields']['field_order_notes']['table'] = 'field_data_field_order_notes';
  $handler->display->display_options['fields']['field_order_notes']['field'] = 'field_order_notes';
  $handler->display->display_options['fields']['field_order_notes']['label'] = 'Description';
  $handler->display->display_options['fields']['field_order_notes']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_order_notes']['alter']['trim'] = TRUE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Author';
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order Status */
  $handler->display->display_options['fields']['field_order_status']['id'] = 'field_order_status';
  $handler->display->display_options['fields']['field_order_status']['table'] = 'field_data_field_order_status';
  $handler->display->display_options['fields']['field_order_status']['field'] = 'field_order_status';
  $handler->display->display_options['fields']['field_order_status']['label'] = 'Status';
  /* Field: Commerce Order: Pricing Year */
  $handler->display->display_options['fields']['pricing_year_reference']['id'] = 'pricing_year_reference';
  $handler->display->display_options['fields']['pricing_year_reference']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['pricing_year_reference']['field'] = 'pricing_year_reference';
  $handler->display->display_options['fields']['pricing_year_reference']['label'] = 'Year';
  /* Field: Commerce Order: Stihl Operations */
  $handler->display->display_options['fields']['stihl_operations']['id'] = 'stihl_operations';
  $handler->display->display_options['fields']['stihl_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['stihl_operations']['field'] = 'stihl_operations';
  $handler->display->display_options['fields']['stihl_operations']['label'] = 'Operations';
  /* Sort criterion: Commerce Order: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pop' => 'pop',
  );

  /* Display: Admin */
  $handler = $view->new_display('page', 'Admin', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'The display of the My Orders view for admin users.';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['path'] = 'orders/list';

  /* Display: Non-Admin */
  $handler = $view->new_display('page', 'Non-Admin', 'page_1');
  $handler->display->display_options['display_description'] = 'The display of the My Orders view for non-admin users.';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: BD Reference (field_bd_reference) */
  $handler->display->display_options['arguments']['field_bd_reference_target_id']['id'] = 'field_bd_reference_target_id';
  $handler->display->display_options['arguments']['field_bd_reference_target_id']['table'] = 'field_data_field_bd_reference';
  $handler->display->display_options['arguments']['field_bd_reference_target_id']['field'] = 'field_bd_reference_target_id';
  $handler->display->display_options['arguments']['field_bd_reference_target_id']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['field_bd_reference_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_bd_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_bd_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_bd_reference_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order Status (field_order_status) */
  $handler->display->display_options['filters']['field_order_status_value']['id'] = 'field_order_status_value';
  $handler->display->display_options['filters']['field_order_status_value']['table'] = 'field_data_field_order_status';
  $handler->display->display_options['filters']['field_order_status_value']['field'] = 'field_order_status_value';
  $handler->display->display_options['filters']['field_order_status_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_order_status_value']['value']['value'] = '31';
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pop' => 'pop',
  );
  $handler->display->display_options['path'] = 'orders/list';
  $export['my_orders'] = $view;

  return $export;
}
