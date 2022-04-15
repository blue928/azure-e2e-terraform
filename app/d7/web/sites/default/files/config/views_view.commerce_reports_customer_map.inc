<?php
/**
 * @file
 * views_view.commerce_reports_customer_map.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_reports_customer_map';
$view->description = '';
$view->tag = 'commerce_reports';
$view->base_table = 'commerce_customer_profile';
$view->human_name = 'Customer Map';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Customer Map';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'chart';
$handler->display->display_options['style_options']['type'] = 'geomap';
$handler->display->display_options['style_options']['library'] = 'google';
$handler->display->display_options['style_options']['label_field'] = 'commerce_customer_address';
$handler->display->display_options['style_options']['data_fields'] = array(
  'profile_id' => 'profile_id',
  'commerce_customer_address' => 0,
);
$handler->display->display_options['style_options']['field_colors'] = array(
  'commerce_customer_address' => '#2f7ed8',
  'profile_id' => '#2e8a6a',
);
$handler->display->display_options['style_options']['width'] = '';
$handler->display->display_options['style_options']['height'] = '';
$handler->display->display_options['style_options']['xaxis_labels_rotation'] = '0';
$handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
/* Field: Commerce Customer profile: Address */
$handler->display->display_options['fields']['commerce_customer_address']['id'] = 'commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['table'] = 'field_data_commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['field'] = 'commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['label'] = 'Country';
$handler->display->display_options['fields']['commerce_customer_address']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['commerce_customer_address']['alter']['text'] = '[commerce_customer_address-country] ';
$handler->display->display_options['fields']['commerce_customer_address']['element_type'] = '0';
$handler->display->display_options['fields']['commerce_customer_address']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['commerce_customer_address']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['commerce_customer_address']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['commerce_customer_address']['click_sort_column'] = 'country';
$handler->display->display_options['fields']['commerce_customer_address']['settings'] = array(
  'use_widget_handlers' => 0,
  'format_handlers' => array(
    'address' => 'address',
  ),
);
$handler->display->display_options['fields']['commerce_customer_address']['group_column'] = 'entity_id';
$handler->display->display_options['fields']['commerce_customer_address']['group_columns'] = array(
  'country' => 'country',
);
/* Field: COUNT(Commerce Customer Profile: Profile ID) */
$handler->display->display_options['fields']['profile_id']['id'] = 'profile_id';
$handler->display->display_options['fields']['profile_id']['table'] = 'commerce_customer_profile';
$handler->display->display_options['fields']['profile_id']['field'] = 'profile_id';
$handler->display->display_options['fields']['profile_id']['group_type'] = 'count';
$handler->display->display_options['fields']['profile_id']['label'] = 'Customers';
$handler->display->display_options['fields']['profile_id']['element_type'] = '0';
$handler->display->display_options['fields']['profile_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['profile_id']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['profile_id']['element_default_classes'] = FALSE;
/* Filter criterion: Commerce Customer Profile: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_customer_profile';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'billing' => 'billing',
);

/* Display: Billing Profile Map */
$handler = $view->new_display('block', 'Billing Profile Map', 'billing_profiles_block');

/* Display: Shipping Profile Map */
$handler = $view->new_display('block', 'Shipping Profile Map', 'shipping_profiles_block');
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Customer Profile: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_customer_profile';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'shipping' => 'shipping',
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_customer',
  2 => 'addressfield',
);
