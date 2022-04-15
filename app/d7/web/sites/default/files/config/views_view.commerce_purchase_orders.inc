<?php
/**
 * @file
 * views_view.commerce_purchase_orders.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'commerce_purchase_orders';
$view->description = 'Display a list of purchase orders for the store admin.';
$view->tag = 'default';
$view->base_table = 'commerce_payment_transaction';
$view->human_name = 'Purchase orders';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Purchase orders';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view payments';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'po_number' => 'po_number',
  'created' => 'created',
  'order_id' => 'order_id',
  'name' => 'name',
  'amount' => 'amount',
  'status' => 'status',
  'operations' => 'operations',
);
$handler->display->display_options['style_options']['default'] = 'created';
$handler->display->display_options['style_options']['info'] = array(
  'po_number' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'amount' => array(
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
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['label'] = 'Empty text';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no purchase orders to display.';
/* Relationship: Commerce Order: Owner */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Purchase order: PO number */
$handler->display->display_options['fields']['po_number']['id'] = 'po_number';
$handler->display->display_options['fields']['po_number']['table'] = 'commerce_purchase_order';
$handler->display->display_options['fields']['po_number']['field'] = 'po_number';
/* Field: Commerce Payment Transaction: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_payment_transaction';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
$handler->display->display_options['fields']['created']['format_date_sql'] = 0;
/* Field: Commerce Order: Order ID */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['link_to_order'] = 'admin';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
/* Field: Commerce Payment Transaction: Amount */
$handler->display->display_options['fields']['amount']['id'] = 'amount';
$handler->display->display_options['fields']['amount']['table'] = 'commerce_payment_transaction';
$handler->display->display_options['fields']['amount']['field'] = 'amount';
/* Field: Commerce Payment Transaction: Status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_payment_transaction';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['display_style'] = 'title';
/* Field: Commerce Payment Transaction: Operations links */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'commerce_payment_transaction';
$handler->display->display_options['fields']['operations']['field'] = 'operations';
/* Filter criterion: Commerce Payment Transaction: Payment method */
$handler->display->display_options['filters']['payment_method']['id'] = 'payment_method';
$handler->display->display_options['filters']['payment_method']['table'] = 'commerce_payment_transaction';
$handler->display->display_options['filters']['payment_method']['field'] = 'payment_method';
$handler->display->display_options['filters']['payment_method']['value'] = array(
  'commerce_purchase_order' => 'commerce_purchase_order',
);

/* Display: Admin page */
$handler = $view->new_display('page', 'Admin page', 'admin_page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'admin/commerce/purchase-orders/list';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Purchase orders';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Purchase orders';
$handler->display->display_options['tab_options']['weight'] = '0';
$handler->display->display_options['tab_options']['name'] = 'management';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_payment',
);
