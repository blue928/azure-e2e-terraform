<?php
/**
 * @file
 * template.php
 */

/**
 * Get color variables from stihl theme settings and write css.
 *
 * Implements hook_preprocess_html().
 */
function stihl_preprocess_html(&$vars) {
  // If current path is stihl settings & user has admin permission.
  $thispage = request_path();
  if ($thispage == 'admin/appearance/settings/stihl' && $vars['is_admin']) {
    drupal_add_library('system', 'farbtastic');
  }
}

/**
 * Get color variables from stihl theme settings and write css.
 *
 * Implements hook_preprocess_page().
 */
function stihl_preprocess_page(&$vars) {
  // Add information about the number of sidebars.
  if (empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-9"';
  }
  else {
    $variables['content_column_class'] = ' class="col-sm-12"';
  }

  if (bootstrap_setting('fluid_container') == 1) {
    $variables['container_class'] = 'container-fluid';
  }
  else {
    $variables['container_class'] = 'container';
  }

  $i18n = module_exists('i18n_menu');

  // Primary nav.
  $variables['primary_nav'] = FALSE;
  if (isset($variables['main_menu'])) {
    // Load the tree.
    $tree = menu_tree_page_data(variable_get('menu_main_links_source', 'main-menu'));

    // Localize the tree.
    if ($i18n) {
      $tree = i18n_menu_localize_tree($tree);
    }

    // Build links.
    $variables['primary_nav'] = menu_tree_output($tree);

    // Provide default theme wrapper function.
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav.
  $variables['secondary_nav'] = FALSE;
  if (isset($variables['secondary_menu'])) {
    // Load the tree.
    $tree = menu_tree_page_data(variable_get('menu_secondary_links_source', 'user-menu'));

    // Localize the tree.
    if ($i18n) {
      $tree = i18n_menu_localize_tree($tree);
    }

    // Build links.
    $variables['secondary_nav'] = menu_tree_output($tree);

    // Provide default theme wrapper function.
    $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }

  $variables['navbar_classes_array'] = array('navbar');

  if (bootstrap_setting('navbar_position') !== '') {
    $variables['navbar_classes_array'][] = 'navbar-' . bootstrap_setting('navbar_position');
  }
  elseif (bootstrap_setting('fluid_container') == 1) {
    $variables['navbar_classes_array'][] = 'container-fluid';
  }
  else {
    $variables['navbar_classes_array'][] = 'container';
  }
  if (bootstrap_setting('navbar_inverse')) {
    $variables['navbar_classes_array'][] = 'navbar-inverse';
  }
  else {
    $variables['navbar_classes_array'][] = 'navbar-default';
  }

  if (isset($vars["secondary_nav"]) && is_array($vars["secondary_nav"])) {
    foreach($vars["secondary_nav"] as $index => $item) {
      if (isset($vars["secondary_nav"][$index]['#href']) && $vars["secondary_nav"][$index]['#href'] == "cart") {
        $vars["secondary_nav"][$index]['#localized_options']['attributes']['class'][] = 'cart-toggle';
        $vars["secondary_nav"][$index]['#localized_options']['attributes']['data-toggle'] = 'collapse';
        $vars["secondary_nav"][$index]['#localized_options']['attributes']['data-target'] = '.cart-popout';
      }
    }
  }

  if (theme_get_setting('logo_bgcolor')) {
    // Get colors from theme settings.
    $vars['logo_bgcolor'] = theme_get_setting('logo_bgcolor');
    $vars['navbar_bgcolor'] = theme_get_setting('navbar_bgcolor');
    $vars['links_color'] = theme_get_setting('links_color');
    // Add colors to the colors.css.php file vars.
    extract($vars, EXTR_SKIP);
    ob_start();
    include path_to_theme() . '/css/colors.css.php';
    $dcss = ob_get_contents();
    ob_end_clean();
    // Adds inline css after style.css
    drupal_add_css($dcss, array(
      'group' => CSS_THEME,
      'type' => 'inline',
      'preprocess' => FALSE,
      'weight' => '9999',
    ));
  }
}

/**
 * Implements hook_preprocess_entity().
 */
function stihl_preprocess_entity(&$vars) {
  if ($vars['entity_type'] == "commerce_product") {
    // Only do this for evergreen and pop_items.
    if ($vars['commerce_product']->type == "pop_item" || $vars['commerce_product']->type == "evergreen") {
      $vars['content']['product_preview'] = [
        '#theme' => 'image_formatter',
        '#item' => $vars['commerce_product']->field_preview[LANGUAGE_NONE][0],
      ];

      if ($vars['commerce_product']->field_attach_pdf) {
        $vars['content']['product_preview']['#path'] = [
          'path' => file_create_url($vars['commerce_product']->field_attach_pdf[LANGUAGE_NONE][0]['uri']),
          'options' => ['html' => TRUE, 'title' => 'link', attributes => ['target' => '_blank']],
        ];

        $vars['content']['product_preview_button'] = [
          '#theme' => 'link',
          '#text' => "Download PDF",
          '#path' => file_create_url($vars['commerce_product']->field_attach_pdf[LANGUAGE_NONE][0]['uri']),
          '#options' => [
            'attributes' => ['target' => '_blank', 'class' => ['btn', 'btn-info', 'btn-block']],
            'html' => TRUE,
          ],
        ];
      }

      $total_units_sold_to_date = $vars['commerce_product']->commerce_stock[LANGUAGE_NONE][0]['value'];
      $vars['content']['next_price_break'] = array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#attributes' => array('class' => ''),
      );
      foreach ($vars['commerce_product']->field_price_table[LANGUAGE_NONE] as $index => $price_table) {
        if ($total_units_sold_to_date == 0 && $index == 0 && count($vars['commerce_product']->field_price_table[LANGUAGE_NONE]) > 1) {
          $next_price_break = $price_table['max_qty'] + 1;
          $vars['content']['next_price_break']['#value'] = "$next_price_break units to next price break";
          $vars['content']['next_price_break']['#attributes']['class'] = "text-danger";
        } else {
          if ($total_units_sold_to_date > 0 && $total_units_sold_to_date < $price_table['min_qty']) {
            $next_price_break = $price_table['min_qty'] - $total_units_sold_to_date;
            $vars['content']['next_price_break']['#value'] = "$next_price_break units to next price break";
            $vars['content']['next_price_break']['#attributes']['class'] = "text-danger";
            break;
          } else if ($total_units_sold_to_date > $price_table['min_qty'] && $index + 1 == count($vars['commerce_product']->field_price_table[LANGUAGE_NONE])) {
            $vars['content']['next_price_break']['#value'] = "Lowest price reached";
            $vars['content']['next_price_break']['#attributes']['class'] = "text-success";
          }
        }
      }

      $form_id = commerce_cart_add_to_cart_form_id([$vars['commerce_product']->product_id]);
      $line_item = commerce_product_line_item_new($vars['commerce_product'], 1);
      $line_item->data['context']['product_ids'] = [$vars['commerce_product']->product_id];
      $add_to_cart = drupal_get_form($form_id, $line_item, true);
      $add_to_cart['#title_display'] = 'invisible';
      // Setup add to cart form variable render array.
      $vars['content']['add_to_cart'] = $add_to_cart;
    }
  }
}

function stihl_preprocess_field(&$variables) {
  $field_name = $variables['element']['#field_name'];
  if ($field_name == 'field_price_table') {
    $table = array(
      'header' => [['data' => 'Quantity'], ['data' => 'Price']],
      'rows' => [],
      'attributes' => array('class' => array('price-table', 'table', 'table-hover', 'table-striped'))
    );

    $total_units_sold = $variables['element']['#object']->commerce_stock[LANGUAGE_NONE][0]['value'];
    foreach($variables['element']['#items'] as $index => $item) {
      if ($item['max_qty'] == -1) {
        $quantity = $item['min_qty'] . "+";
      } else {
        $quantity = $item['min_qty'] . " - " . $item['max_qty'];
      }

      $price = commerce_currency_format($item['amount'], $item['currency_code'], $variables['element']['#object']);
      $table['rows'][$index] = [
        'data' => [$quantity, $price],
      ];

      if ($total_units_sold >= $item['min_qty'] && ($total_units_sold <= $item['max_qty'] || $item['max_qty'] == -1)) {
        $table['rows'][$index]['class'] = ['active'];
      }
    }

    if ($total_units_sold == 0) {
      $table['rows'][0]['class'] = ['active'];
    }

    $variables['items'][0]["#markup"] = theme('table', $table);
  }
}

function stihl_preprocess_commerce_product_sku(&$variables) {
  if ($variables['product']->type == 'pop_item' || $variables['product']->type == 'evergreen') {
    $variables['label'] = 'Item Code:';
  }
}

/**
 * Returns HTML for a marker for required form elements.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *
 * @return string
 *   The HTML string that creates the span tag.
 *
 * @SuppressWarnings(PHPMD.UnusedFormalParameter)
 */
function stihl_form_required_marker($variables) {

  $attributes = [
    'class' => 'form-required',
    'title' => t('This field is required.'),
  ];
  return '<span' . drupal_attributes($attributes) . '>' . t('(Required Field)') . '</span>';
}

function stihl_menu_tree__menu_pop_catalog(array &$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

function stihl_menu_tree__menu_hangtags(array &$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Hide menu items depending on context.
 *
 * Implements hook_menu_link().
 */
function stihl_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  $options = !empty($element['#localized_options']) ? $element['#localized_options'] : array();

  // Check plain title if "html" is not set, otherwise, filter for XSS attacks.
  $title = empty($options['html']) ? check_plain($element['#title']) : filter_xss_admin($element['#title']);

  // Ensure "html" is now enabled so l() doesn't double encode. This is now
  // safe to do since both check_plain() and filter_xss_admin() encode HTML
  // entities. See: https://www.drupal.org/node/2854978
  $options['html'] = TRUE;

  $href = $element['#href'];
  $attributes = !empty($element['#attributes']) ? $element['#attributes'] : array();

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

      // Generate as standard dropdown.
      $title .= ' <span class="caret"></span>';
      $attributes['class'][] = 'dropdown';

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $options['attributes']['data-target'] = '#';
      $options['attributes']['class'][] = 'dropdown-toggle';
      $options['attributes']['data-toggle'] = 'dropdown';
    }
  }

  if ($element['#href'] == 'node/add/article') {
    $contexts = context_active_contexts();
    if (array_key_exists('hangtag_layout', $contexts) || array_key_exists('pop_layout', $contexts)) {
      $attributes['class'][] = 'hidden';
    }
  }

  if ($element['#href'] == 'hangtags') {
    $contexts = context_active_contexts();
    if (array_key_exists('hangtag_layout', $contexts)) {
      $attributes['class'][] = 'hidden';
    }
  }

  if ($element['#href'] == 'pop') {
    $contexts = context_active_contexts();
    if (array_key_exists('pop_layout', $contexts)) {
      $attributes['class'][] = 'hidden';
    }
  }
  return '<li' . drupal_attributes($attributes) . '>' . l($title, $href, $options) . $sub_menu . "</li>\n";
}
