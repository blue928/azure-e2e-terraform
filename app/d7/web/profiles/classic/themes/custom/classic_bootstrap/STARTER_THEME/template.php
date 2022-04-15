<?php
/**
 * @file
 * template.php
 */

/**
 * Add Farbtastic library to theme settings page. Change 'starter_theme' to your theme name.
 *
 * Implements hook_preprocess_html().
 */
function starter_theme_preprocess_html(&$vars) {
  // If current path is classic_bootstrap settings & user has admin permission.
  $thispage = request_path();
  if ($thispage == 'admin/appearance/settings/starter_theme' && $vars['is_admin']) {
    drupal_add_library('system', 'farbtastic');
  }
}

/**
 * Change 'starter_theme' to your theme name. Change 'menu_name' to your menu name.
 *
 * Implements hook_menu_link().
 */
function starter_theme_menu_link__menu_menu_name($variables) {
  // Bootstrap requires this function (per menu) to enable nested submenus,
  // since Boostrap is primarily a mobile-first theme and submenus don't
  // typically work well on mobile devices.
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && $element['#original_link']['depth'] > 1) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#attributes']['class'][] = 'dropdown-submenu';
      $element['#localized_options']['html'] = TRUE;
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
    else {
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
