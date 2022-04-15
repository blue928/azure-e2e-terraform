<?php
/**
 * @file
 * views_view.tracker.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'tracker';
$view->description = 'Shows all new activity on system.';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Tracker';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Recent posts';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'type' => 'type',
  'title' => 'title',
  'name' => 'name',
  'comment_count' => 'comment_count',
  'last_comment_timestamp' => 'last_comment_timestamp',
  'timestamp' => 'title',
  'new_comments' => 'comment_count',
);
$handler->display->display_options['style_options']['default'] = 'last_comment_timestamp';
$handler->display->display_options['style_options']['info'] = array(
  'type' => array(
    'sortable' => 1,
    'separator' => '',
  ),
  'title' => array(
    'sortable' => 1,
    'separator' => '&nbsp;',
  ),
  'name' => array(
    'sortable' => 1,
    'separator' => '',
  ),
  'comment_count' => array(
    'sortable' => 1,
    'separator' => '<br />',
  ),
  'last_comment_timestamp' => array(
    'sortable' => 1,
    'separator' => '&nbsp;',
  ),
  'timestamp' => array(
    'separator' => '',
  ),
  'new_comments' => array(
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['order'] = 'desc';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Author';
/* Field: Content: Comment count */
$handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
$handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
$handler->display->display_options['fields']['comment_count']['label'] = 'Replies';
/* Field: Content: Last comment time */
$handler->display->display_options['fields']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
$handler->display->display_options['fields']['last_comment_timestamp']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
$handler->display->display_options['fields']['last_comment_timestamp']['label'] = 'Last Post';
/* Field: Content: Has new content */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'history';
$handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['comments'] = TRUE;
/* Field: Content: New comments */
$handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
$handler->display->display_options['fields']['new_comments']['table'] = 'node';
$handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
$handler->display->display_options['fields']['new_comments']['label'] = '';
$handler->display->display_options['fields']['new_comments']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['new_comments']['suffix'] = ' new';
/* Sort criterion: Content: Last comment time */
$handler->display->display_options['sorts']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
$handler->display->display_options['sorts']['last_comment_timestamp']['table'] = 'node_comment_statistics';
$handler->display->display_options['sorts']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
/* Contextual filter: Content: User posted or commented */
$handler->display->display_options['arguments']['uid_touch']['id'] = 'uid_touch';
$handler->display->display_options['arguments']['uid_touch']['table'] = 'node';
$handler->display->display_options['arguments']['uid_touch']['field'] = 'uid_touch';
$handler->display->display_options['arguments']['uid_touch']['exception']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['uid_touch']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['uid_touch']['title'] = 'Recent posts for %1';
$handler->display->display_options['arguments']['uid_touch']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['uid_touch']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid_touch']['specify_validation'] = TRUE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'tracker';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Recent posts';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'node',
);
