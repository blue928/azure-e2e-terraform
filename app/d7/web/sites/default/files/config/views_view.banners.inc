<?php
/**
 * @file
 * views_view.banners.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'banners';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Banners';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = '<none>';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Banner Image */
$handler->display->display_options['fields']['field_banner_image']['id'] = 'field_banner_image';
$handler->display->display_options['fields']['field_banner_image']['table'] = 'field_data_field_banner_image';
$handler->display->display_options['fields']['field_banner_image']['field'] = 'field_banner_image';
$handler->display->display_options['fields']['field_banner_image']['label'] = '';
$handler->display->display_options['fields']['field_banner_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_banner_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_banner_image']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
/* Field: Content: Banner Description */
$handler->display->display_options['fields']['field_banner_description']['id'] = 'field_banner_description';
$handler->display->display_options['fields']['field_banner_description']['table'] = 'field_data_field_banner_description';
$handler->display->display_options['fields']['field_banner_description']['field'] = 'field_banner_description';
$handler->display->display_options['fields']['field_banner_description']['label'] = '';
$handler->display->display_options['fields']['field_banner_description']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'banner_image' => 'banner_image',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'node',
  2 => 'image',
  3 => 'text',
);
