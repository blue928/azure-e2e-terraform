<?php

/**
 * @file
 * Provides Fusion Pro templating node admin configurations.
 */

/**
 * Menu callback, admin form.
 */
function _fp_template_admin_settings() {
  // List each node type.
  $types = node_type_get_types();
  $output = '';
  foreach ($types as $type_name => $type) {
    $node_header = array($type->name, '', '', '', '');
    // For each node type, list current configurations,
    // with links to clone, export, delete, edit.
    $config_table = array();
    $configs = _fp_template_get_configurations($type_name);
    foreach ($configs as $config) {
      $config_active = 'disable';
      if ($config->active == 0) {
        $config_active = 'enable';
      }
      $config_table[] = array(
        l(t('@config_label', array('@config_label' => $config->label)), 'admin/config/services/fp_template/edit/' . $config->cid),
        l(t('clone'), 'admin/config/services/fp_template/clone/' . $config->cid),
        l(t('export'), 'admin/config/services/fp_template/export/' . $config->cid),
        l(t('@toggle', array('@toggle' => $config_active)), 'admin/config/services/fp_template/toggle/' . $config->cid),
        l(t('edit'), 'admin/config/services/fp_template/edit/' . $config->cid),
      );
    }
    // For each node type, provide links to add a new configuration.
    $config_table[] = array(
      l(t('Add new configuration for this content type'), 'admin/config/services/fp_template/add/' . $type_name),
      '', '', '',
    );
    // Prepare output.
    $output .= theme('table', array('header' => $node_header, 'rows' => $config_table));
  }
  return $output;
}

/**
 * Menu callback, add a configuration to a type, forwards to config edit form.
 */
function _fp_template_add_configuration($type_name) {
  // Given node type id, create an initial configuration.
  // Save the configuration and pass through to _fp_template_edit_configuration
  $config->content_type = $type_name;
  $config->active = 1;
  $config->keywords = array();
  $config->label = '';
  $config->template = '';
  $config->rename_pattern = '';
  _fp_template_save_configuration($config);
  drupal_goto('admin/config/services/fp_template/edit/' . $config->cid);
}

/**
 * Menu callback, clone a configuration on a type, forwards to config edit form.
 */
function _fp_template_clone_configuration($cid) {
  // Given a configuration id, create a new configuration matching the old.
  // Save the configuration and pass through to _fp_template_edit_configuration
  $config = _fp_template_get_configuration($cid);
  unset($config->cid);
  foreach ($config->keywords as $delta => $map_set) {
    unset($config->keywords[$delta]->cid);
    unset($config->keywords[$delta]->kid);
  }
  $config->active = 1;
  _fp_template_save_configuration($config);
  drupal_goto('admin/config/services/fp_template/edit/' . $config->cid);
}

/**
 * Menu callback, form. Ask if you want to delete the config before allowing.
 */
function _fp_template_remove_configuration(&$form_state, $cid) {
  $config = _fp_template_get_configuration($cid);
  $form['cid'] = array(
    '#type' => 'value',
    '#value' => $cid,
  );
  $form['config_label'] = array(
    '#type' => 'value',
    '#value' => $config->label,
  );
  return confirm_form(
    $form,
    t('Are you sure you want to delete the configuration %config_label?', array('%config_label' => $config->label)),
    'admin/config/services/fp_template',
    NULL,
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Menu callback, toggle a configuration on a type.
 */
function _fp_template_toggle_configuration($cid) {
  // Given a configuration id, create a new configuration matching the old.
  // Save the configuration and pass through to _fp_template_edit_configuration
  $config = _fp_template_get_configuration($cid);
  if ($config->active == 1) {
    $config->active = 0;
  }
  else {
    $config->active = 1;
  }
  _fp_template_save_configuration($config);
  drupal_goto('admin/config/services/fp_template');
}

/**
 * Form submit for deleting a configuration.
 */
function _fp_template_remove_configuration_submit($form, &$form_state) {
  _fp_template_delete_configuration($form_state['values']['cid']);
  drupal_set_message(t('Deleted %config_label.', array('%config_label' => $form_state['values']['config_label'])));
  drupal_goto('admin/config/services/fp_template');
}

/**
 * Menu callback for editing a configuration.
 */
function _fp_template_edit_configuration($form, &$form_state, $cid) {
  // Given a cid, check the given type.
  $config = _fp_template_get_configuration($cid);
  // If no type is set, error and return.
  if (!isset($config->cid) || !isset($config->content_type)) {
    // Error, bailout.
    drupal_set_message(t('An error was encountered while editing this configuration: no configuration set or no type set.'));
    drupal_goto('admin/config/services/fp_template');
  }
  $form['cid'] = array(
    '#type' => 'hidden',
    '#default_value' => $config->cid,
    '#value' => $config->cid,
    '#disabled' => TRUE,
  );
  $form['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('A human readable label for your configurations. This label will be used on preview buttons for this content type.'),
    '#default_value' => $config->label,
    '#required' => TRUE,
  );
  $form['content_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Type'),
    '#description' => t('Associated content type for this configuration.'),
    '#default_value' => $config->content_type,
    '#value' => $config->content_type,
    '#disabled' => TRUE,
  );
  $display_options = array('No display', 'Preview iframe', 'Download link');
  $form['display'] = array(
    '#type' => 'select',
    '#title' => t('Display'),
    '#description' => t('Display format to use when viewing the node.'),
    '#options' => $display_options,
    '#default_value' => $config->display,
  );
  $display_options = array('No display', 'Preview iframe', 'Download link');
  $form['preview_display'] = array(
    '#type' => 'select',
    '#title' => t('Preview display'),
    '#description' => t('Display format to use when editing the node.'),
    '#options' => $display_options,
    '#default_value' => $config->preview_display,
  );
  /* Return file options. */
  $file_type_options = array(
    'pdf' => 'PDF',
    'jpg' => 'JPG',
  );
  $form['file_type'] = array(
    '#type' => 'select',
    '#title' => t('Return file type'),
    '#options' => $file_type_options,
    '#default_value' => $config->file_type,
    '#required' => TRUE,
  );
  $form['template'] = array(
    '#type' => 'textfield',
    '#title' => t('Template file'),
    '#description' => t('The template file on the Fusion Pro server to use.'),
    '#default_value' => $config->template,
    '#required' => TRUE,
  );
  $form['rename_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Rename pattern'),
    '#description' => t('Using the tokens available below, enter the pattern should the filename take.'),
    '#default_value' => $config->rename_pattern,
    '#required' => TRUE,
  );
  $form['keyword_map'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
    '#title' => t('Keyword mapping'),
    '#description' => t('Map strings for the Fusion Pro templates to use to values from the content.') . ' ' .
    t('To remove a keyword mapping, leave the keyword field empty.'),
    '#prefix' => '<div id="keyword-map-wrapper">',
    '#suffix' => '</div>',
  );
  $form['keyword_map']['maps'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div id="keyword-maps">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#theme' => 'fp_template_config_display',
  );
  // Figure out how many *additional* configuration slots to show,
  // if we have none - default 5.
  if (!isset($config->keywords)) {
    $config_new_count = 5;
  }
  else {
    $config_new_count = count($config->keywords);
  }
  $config_new_php = 0;
  if (isset($form_state['values']['op']) && $form_state['values']['op'] == 'Add keyword map') {
    $config_new_count = count($form_state['values']['maps']) + 1;
    $config_new_php = 0;
  }
  if (user_access('use PHP for FusionPro templates')) {
    if (isset($form_state['values']['op']) && $form_state['values']['op'] == 'Add PHP map') {
      $config_new_count = count($form_state['values']['maps']) + 1;
      $config_new_php = 1;
    }
  }
  $type_tokens = _fp_template_edit_configuration_get_type_tokens($config->content_type);
  for ($delta = 0; $delta < $config_new_count; $delta++) {
    if (isset($form_state['values']['maps'][$delta])) {
      $keyword = $form_state['values']['maps'][$delta]['keyword'];
      $value = array(
        'php_type' => $form_state['values']['maps'][$delta]['php_type'],
        'mapped_value' => $form_state['values']['maps'][$delta]['mapped_value'],
      );
    }
    elseif (isset($config->keywords[$delta])) {
      $keyword = $config->keywords[$delta]->keyword;
      $value = array(
        'php_type' => $config->keywords[$delta]->php_type,
        'mapped_value' => $config->keywords[$delta]->mapped_value,
      );
    }
    else {
      $keyword = '';
      $value = array(
        'php_type' => $config_new_php,
        'mapped_value' => '',
      );
    }
    $form['keyword_map']['maps'][$delta]['keyword'] = array(
      '#type' => 'textfield',
      '#default_value' => $keyword,
    );
    $form['keyword_map']['maps'][$delta]['php_type'] = array(
      '#type' => 'hidden',
      '#value' => $value['php_type'],
    );
    if ($value['php_type'] == 0) {
      $form['keyword_map']['maps'][$delta]['mapped_value'] = array(
        '#type' => 'select',
        '#description' => t('Select token value to map. Consult "Token help" below for more information.'),
        '#options' => $type_tokens,
        '#default_value' => $value['mapped_value'],
      );
    }
    else {
      $form['keyword_map']['maps'][$delta]['mapped_value'] = array(
        '#type' => 'textarea',
        '#description' => t('You may use $node here. Return the value to map to the keyword. Do not use <?php or ?> in your script.'),
        '#default_value' => $value['mapped_value'],
      );
    }
  }
  $form['keyword_map']['add_map'] = array(
    '#type' => 'button',
    '#value' => t('Add keyword map'),
    '#description' => t('Click here to add more keyword fields.'),
    '#ajax' => array(
      'callback' => '_fp_template_edit_configuration_more_maps',
      'wrapper' => 'keyword-maps',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );
  if (user_access('use PHP for FusionPro templates')) {
    $form['keyword_map']['add_php'] = array(
      '#type' => 'button',
      '#value' => t('Add PHP map'),
      '#description' => t('Click here to add more PHP based keyword fields.'),
      '#ajax' => array(
        'callback' => '_fp_template_edit_configuration_more_maps',
        'wrapper' => 'keyword-maps',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
  }
  $form['keyword_map']['token_help'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
    '#title' => t('Token help'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['keyword_map']['token_help']['help'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save this configuration'),
  );
  return $form;
}

/**
 * Theme callback, for use on admin page keyword map displays.
 */
function theme_fp_template_config_display($keyword_maps) {
  $rows = array();
  if (is_array($keyword_maps['keyword_maps'])) {
    $header = array(t('Keywords'), '', t('Mapped value (Token or PHP value)'));
    foreach (element_children($keyword_maps['keyword_maps']) as $delta) {
      $new_fields['data'][0] = drupal_render($keyword_maps['keyword_maps'][$delta]['keyword']);
      $new_fields['data'][1] = ' >> ';
      $new_fields['data'][2] = drupal_render($keyword_maps['keyword_maps'][$delta]['mapped_value']);
      $rows[] = $new_fields;
    }
    $form['keyword_map']['maps'] = array(
      '#value' => theme('table', array('header' => $header, 'rows' => $rows)),
    );
  }
  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Form AHAH submit handler.
 */
function _fp_template_edit_configuration_more_maps($form, &$form_state) {
  return $form['keyword_map']['maps'];
}

/**
 * Form submit function, save a configuration and return to main page.
 */
function _fp_template_edit_configuration_submit($form, &$form_state) {
  $values = $form_state['values'];
  // Loop through values and construct a config.
  $keywords = $values['maps'];
  unset($values['maps']);
  $config = (object) $values;
  foreach ($keywords as $delta => $map_set) {
    $php_type = FALSE;
    if ($map_set['php_type'] == 1) {
      $php_type = TRUE;
    }
    if (!empty($map_set['keyword'])) {
      if ($php_type == FALSE || ($php_type == TRUE && user_access('use PHP for FusionPro templates'))) {
        $config->keywords[$delta]->keyword = $map_set['keyword'];
        $config->keywords[$delta]->php_type = $map_set['php_type'];
        $config->keywords[$delta]->mapped_value = $map_set['mapped_value'];
      }
    }
  }
  // Save it.
  _fp_template_save_configuration($config);
  drupal_set_message(t('Updated configuration %config_label.', array('%config_label' => $config->label)));
  drupal_goto('admin/config/services/fp_template');
}

/**
 * Helper function, given type name, get the options for the type keywords.
 */
function _fp_template_edit_configuration_get_type_tokens($type_name) {
  // Use the token module to gather all our tokens that we can use.
  $type_tokens = array();
  $all_tokens = token_get_info();
  ksort($all_tokens['tokens']);
  foreach ($all_tokens['tokens'] as $type => $tokens) {
    ksort($tokens);
    foreach ($tokens as $token => $token_data) {
      $type_tokens[$type . ':' . $token] = drupal_ucfirst($type) . ': [' . $token . ']';
    }
  }
  return $type_tokens;
}
