<?php
/**
 * @file
 * views_view.pop_orders.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'pop_orders';
$view->description = 'Display a list of orders for the store admin.';
$view->tag = 'commerce';
$view->base_table = 'commerce_order';
$view->human_name = 'POP Orders';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'POP Orders';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view any commerce_order entity';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = 50;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'order_number' => 'order_number',
  'placed' => 'placed',
  'changed' => 'changed',
  'commerce_customer_address' => 'commerce_customer_address',
  'name' => 'name',
  'commerce_order_total' => 'commerce_order_total',
  'status' => 'status',
  'operations' => 'operations',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'order_number' => array(
    'sortable' => 0,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'placed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'commerce_customer_address' => array(
    'sortable' => 0,
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
  'commerce_order_total' => array(
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
/* Header: Global: View order form */
$handler->display->display_options['header']['view_order_form']['id'] = 'view_order_form';
$handler->display->display_options['header']['view_order_form']['table'] = 'views';
$handler->display->display_options['header']['view_order_form']['field'] = 'view_order_form';
/* No results behavior: Commerce Order: Empty text */
$handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
$handler->display->display_options['empty']['empty_text']['table'] = 'commerce_order';
$handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
$handler->display->display_options['empty']['empty_text']['add_path'] = 'admin/commerce/orders/add';
/* Relationship: Commerce Order: Owner */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Relationship: Commerce Order: Referenced customer profile */
$handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
$handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
$handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
/* Relationship: Commerce Order: Referenced line items */
$handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
$handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
$handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
/* Relationship: Commerce Line item: Referenced products */
$handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
$handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
$handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
$handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
/* Field: Commerce Order: Order number */
$handler->display->display_options['fields']['order_number']['id'] = 'order_number';
$handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_number']['field'] = 'order_number';
$handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
/* Field: Commerce Order: Placed date */
$handler->display->display_options['fields']['placed']['id'] = 'placed';
$handler->display->display_options['fields']['placed']['table'] = 'commerce_order';
$handler->display->display_options['fields']['placed']['field'] = 'placed';
$handler->display->display_options['fields']['placed']['label'] = 'Placed';
$handler->display->display_options['fields']['placed']['empty'] = '-';
$handler->display->display_options['fields']['placed']['date_format'] = 'medium';
/* Field: Commerce Order: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Updated';
$handler->display->display_options['fields']['changed']['date_format'] = 'medium';
/* Field: Commerce Customer profile: Address */
$handler->display->display_options['fields']['commerce_customer_address']['id'] = 'commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['table'] = 'field_data_commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['field'] = 'commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['relationship'] = 'commerce_customer_billing_profile_id';
$handler->display->display_options['fields']['commerce_customer_address']['label'] = 'Name';
$handler->display->display_options['fields']['commerce_customer_address']['empty'] = '-';
$handler->display->display_options['fields']['commerce_customer_address']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['commerce_customer_address']['click_sort_column'] = 'country';
$handler->display->display_options['fields']['commerce_customer_address']['settings'] = array(
  'use_widget_handlers' => 0,
  'format_handlers' => array(
    'name-oneline' => 'name-oneline',
  ),
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'User';
/* Field: Commerce Order: Order total */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
  'calculation' => FALSE,
);
/* Field: Commerce Order: Order status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_order';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: Commerce Order: Operations links */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'commerce_order';
$handler->display->display_options['fields']['operations']['field'] = 'operations';
$handler->display->display_options['fields']['operations']['label'] = 'Operations';
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['operator'] = 'not in';
$handler->display->display_options['filters']['state']['value'] = array(
  'cart' => 'cart',
  'checkout' => 'checkout',
);
$handler->display->display_options['filters']['state']['group'] = 1;
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order state';
$handler->display->display_options['filters']['state']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
/* Filter criterion: Commerce Product: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['filters']['type']['value'] = array(
  'evergreen' => 'evergreen',
  'pop_item' => 'pop_item',
);

/* Display: Admin page */
$handler = $view->new_display('page', 'Admin page', 'admin_page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'View POP Orders';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'pop-catalog/admin/orders/list';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'View POP Orders';
$handler->display->display_options['menu']['weight'] = '-10';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'All Orders';
$handler->display->display_options['tab_options']['description'] = 'Manage orders in the store.';
$handler->display->display_options['tab_options']['weight'] = '';
$handler->display->display_options['tab_options']['name'] = 'menu-pop-catalog';

/* Display: Shopping carts */
$handler = $view->new_display('page', 'Shopping carts', 'shopping_carts');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Shopping carts';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['text']['id'] = 'text';
$handler->display->display_options['empty']['text']['table'] = 'views';
$handler->display->display_options['empty']['text']['field'] = 'area';
$handler->display->display_options['empty']['text']['content'] = 'There are currently no shopping cart orders.';
$handler->display->display_options['empty']['text']['format'] = 'plain_text';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Order: Order number */
$handler->display->display_options['fields']['order_number']['id'] = 'order_number';
$handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_number']['field'] = 'order_number';
$handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
/* Field: Commerce Order: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Updated';
$handler->display->display_options['fields']['changed']['date_format'] = 'medium';
/* Field: Commerce Customer profile: Address */
$handler->display->display_options['fields']['commerce_customer_address']['id'] = 'commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['table'] = 'field_data_commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['field'] = 'commerce_customer_address';
$handler->display->display_options['fields']['commerce_customer_address']['relationship'] = 'commerce_customer_billing_profile_id';
$handler->display->display_options['fields']['commerce_customer_address']['label'] = 'Name';
$handler->display->display_options['fields']['commerce_customer_address']['empty'] = '-';
$handler->display->display_options['fields']['commerce_customer_address']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['commerce_customer_address']['click_sort_column'] = 'country';
$handler->display->display_options['fields']['commerce_customer_address']['settings'] = array(
  'use_widget_handlers' => 0,
  'format_handlers' => array(
    'name-oneline' => 'name-oneline',
  ),
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'User';
/* Field: Commerce Order: Order total */
$handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
$handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
$handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
  'calculation' => FALSE,
);
/* Field: Commerce Order: Order status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_order';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: Commerce Order: Operations links */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'commerce_order';
$handler->display->display_options['fields']['operations']['field'] = 'operations';
$handler->display->display_options['fields']['operations']['label'] = 'Operations';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'cart' => 'cart',
  'checkout' => 'checkout',
);
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order state';
$handler->display->display_options['filters']['state']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
/* Filter criterion: Commerce Product: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['filters']['type']['value'] = array(
  'evergreen' => 'evergreen',
  'pop_item' => 'pop_item',
);
$handler->display->display_options['path'] = 'pop-catalog/admin/orders/carts';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Shopping carts';
$handler->display->display_options['menu']['description'] = 'View Open Carts';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: POP My Orders */
$handler = $view->new_display('page', 'POP My Orders', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'My POP Orders';
$handler->display->display_options['display_description'] = 'My POP orders page for current user';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  18 => '18',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Commerce Order: Order state */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'commerce_order';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'pending' => 'pending',
  'completed' => 'completed',
);
$handler->display->display_options['filters']['state']['group'] = 1;
$handler->display->display_options['filters']['state']['expose']['label'] = 'Order state';
$handler->display->display_options['filters']['state']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
/* Filter criterion: Commerce Product: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'commerce_product';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'commerce_product_product_id';
$handler->display->display_options['filters']['type']['value'] = array(
  'evergreen' => 'evergreen',
  'pop_item' => 'pop_item',
);
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
$handler->display->display_options['filters']['uid_current']['value'] = '1';
$handler->display->display_options['path'] = 'pop-catalog/my-orders/list';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'POP Order History';
$handler->display->display_options['menu']['description'] = 'My POP Orders for Current User';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'POP Catalog';
$handler->display->display_options['tab_options']['weight'] = '0';
$handler->display->display_options['tab_options']['name'] = 'menu-pop-catalog';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'commerce_order',
  2 => 'addressfield',
  3 => 'commerce_price',
);
