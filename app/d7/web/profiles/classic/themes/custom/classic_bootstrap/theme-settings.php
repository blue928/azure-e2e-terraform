<?php

/**
 * @file
 * Provides theme settings for Bootstrap based themes when admin theme is not.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function classic_bootstrap_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // General.
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
    '#group' => 'bootstrap',
  );

  // Buttons.
  $form['general']['buttons'] = array(
    '#type' => 'fieldset',
    '#title' => t('Buttons'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['buttons']['bootstrap_button_size'] = array(
    '#type' => 'select',
    '#title' => t('Default button size'),
    '#default_value' => theme_get_setting('bootstrap_button_size'),
    '#empty_option' => t('Normal'),
    '#options' => array(
      'btn-xs' => t('Extra Small'),
      'btn-sm' => t('Small'),
      'btn-lg' => t('Large'),
    ),
  );
  $form['general']['buttons']['bootstrap_button_colorize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Colorize Buttons'),
    '#default_value' => theme_get_setting('bootstrap_button_colorize'),
    '#description' => t('Adds classes to buttons based on their text value. See: <a href="!bootstrap_url" target="_blank">Buttons</a> and <a href="!api_url" target="_blank">hook_bootstrap_colorize_text_alter()</a>', array(
      '!bootstrap_url' => 'http://getbootstrap.com/css/#buttons',
      '!api_url' => 'http://drupalcode.org/project/bootstrap.git/blob/refs/heads/7.x-3.x:/bootstrap.api.php#l13',
    )),
  );
  $form['general']['buttons']['bootstrap_button_iconize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Iconize Buttons'),
    '#default_value' => theme_get_setting('bootstrap_button_iconize'),
    '#description' => t('Adds icons to buttons based on the text value. See: <a href="!api_url" target="_blank">hook_bootstrap_iconize_text_alter()</a>', array(
      '!api_url' => 'http://drupalcode.org/project/bootstrap.git/blob/refs/heads/7.x-3.x:/bootstrap.api.php#l37',
    )),
  );

  // Colors.
  $form['general']['colors'] = array(
    '#type' => 'fieldset',
    '#title' => t('Colors'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Farbtastic color picker.
  $form['general']['colors']['picker'] = array(
    '#type' => 'markup',
    '#markup' => '<div id="picker"></div>',
  );
  // Logo background.
  $form['general']['colors']['logo_bgcolor'] = array(
    '#type' => 'textfield',
    '#title' => t('Logo background color'),
    '#default_value' => theme_get_setting('logo_bgcolor'),
    '#description' => t('Enter a hexcode color for logo background.'),
  );
  // Nav and footer backgrounds.
  $form['general']['colors']['navbar']['navbar_bgcolor'] = array(
    '#type' => 'textfield',
    '#title' => t('Navbar & Footer background color'),
    '#default_value' => theme_get_setting('navbar_bgcolor'),
    '#description' => t('Enter a hexcode color for the navbar and footer background.'),
  );
  // Link and primary buttons color.
  $form['general']['colors']['links']['links_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Links color'),
    '#default_value' => theme_get_setting('links_color'),
    '#description' => t('Enter a hexcode color for the links.'),
  );

  // Forms.
  $form['general']['forms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Forms'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['forms']['bootstrap_forms_required_has_error'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make required elements display as an error'),
    '#default_value' => theme_get_setting('bootstrap_forms_required_has_error'),
    '#description' => t('If an element in a form is required, enabling this will always display the element with a <code>.has-error</code> class. This turns the element red and helps in usability for determining which form elements are required to submit the form.  This feature compliments the "JavaScript > Forms > Automatically remove error classes when values have been entered" feature.'),
  );

  // Images.
  $form['general']['images'] = array(
    '#type' => 'fieldset',
    '#title' => t('Images'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['images']['bootstrap_image_shape'] = array(
    '#type' => 'select',
    '#title' => t('Default image shape'),
    '#description' => t('Add classes to an <code>&lt;img&gt;</code> element to easily style images in any project. Note: Internet Explorer 8 lacks support for rounded corners. See: <a href="!bootstrap_url" target="_blank">Image Shapes</a>', array(
      '!bootstrap_url' => 'http://getbootstrap.com/css/#images-shapes',
    )),
    '#default_value' => theme_get_setting('bootstrap_image_shape'),
    '#empty_option' => t('None'),
    '#options' => array(
      'img-rounded' => t('Rounded'),
      'img-circle' => t('Circle'),
      'img-thumbnail' => t('Thumbnail'),
    ),
  );
  $form['general']['images']['bootstrap_image_responsive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Responsive Images'),
    '#default_value' => theme_get_setting('bootstrap_image_responsive'),
    '#description' => t('Images in Bootstrap 3 can be made responsive-friendly via the addition of the <code>.img-responsive</code> class. This applies <code>max-width: 100%;</code> and <code>height: auto;</code> to the image so that it scales nicely to the parent element.'),
  );

  // Tables.
  $form['general']['tables'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tables'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['tables']['bootstrap_table_bordered'] = array(
    '#type' => 'checkbox',
    '#title' => t('Bordered table'),
    '#default_value' => theme_get_setting('bootstrap_table_bordered'),
    '#description' => t('Add borders on all sides of the table and cells.'),
  );
  $form['general']['tables']['bootstrap_table_condensed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Condensed table'),
    '#default_value' => theme_get_setting('bootstrap_table_condensed'),
    '#description' => t('Make tables more compact by cutting cell padding in half.'),
  );
  $form['general']['tables']['bootstrap_table_hover'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hover rows'),
    '#default_value' => theme_get_setting('bootstrap_table_hover'),
    '#description' => t('Enable a hover state on table rows.'),
  );
  $form['general']['tables']['bootstrap_table_striped'] = array(
    '#type' => 'checkbox',
    '#title' => t('Striped rows'),
    '#default_value' => theme_get_setting('bootstrap_table_striped'),
    '#description' => t('Add zebra-striping to any table row within the <code>&lt;tbody&gt;</code>. <strong>Note:</strong> Striped tables are styled via the <code>:nth-child</code> CSS selector, which is not available in Internet Explorer 8.'),
  );
  $form['general']['tables']['bootstrap_table_responsive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Responsive tables'),
    '#default_value' => theme_get_setting('bootstrap_table_responsive'),
    '#description' => t('Makes tables responsive by wrapping them in <code>.table-responsive</code> to make them scroll horizontally up to small devices (under 768px). When viewing on anything larger than 768px wide, you will not see any difference in these tables.'),
  );

  // JavaScript settings.
  $form['javascript'] = array(
    '#type' => 'fieldset',
    '#title' => t('JavaScript'),
    '#group' => 'bootstrap',
  );

  // Anchors.
  $form['javascript']['anchors'] = array(
    '#type' => 'fieldset',
    '#title' => t('Anchors'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('This plugin is not able to be configured from the UI as it is severely broken. In an effort to balance not break backwards compatibility and to prevent new users from running into unforeseen issues, you must manually opt-in/out inside your theme .info file. Please see the following issue for more details: <a href="!url" target="_blank">Replace custom JS with the bootstrap-anchor plugin</a>', array(
      '!url' => 'https://www.drupal.org/node/2462645',
    )),
  );
  $form['javascript']['anchors']['bootstrap_anchors_fix'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fix anchor positions'),
    '#default_value' => bootstrap_setting('anchors_fix', $theme),
    '#description' => t('Ensures anchors are correctly positioned only when there is margin or padding detected on the BODY element. This is useful when fixed navbar or administration menus are used.'),
    // Prevent UI edits, see description above.
    '#disabled' => TRUE,
  );
  $form['javascript']['anchors']['bootstrap_anchors_smooth_scrolling'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable smooth scrolling'),
    '#default_value' => bootstrap_setting('anchors_smooth_scrolling', $theme),
    '#description' => t('Animates page by scrolling to an anchor link target smoothly when clicked.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="bootstrap_anchors_fix"]' => array('checked' => FALSE),
      ),
    ),
    // Prevent UI edits, see description above.
    '#disabled' => TRUE,
  );

  // Forms.
  $form['javascript']['forms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Forms'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['javascript']['forms']['bootstrap_forms_has_error_value_toggle'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically remove error classes when values have been entered'),
    '#default_value' => bootstrap_setting('forms_has_error_value_toggle', $theme),
    '#description' => t('If an element has a <code>.has-error</code> class attached to it, enabling this will automatically remove that class when a value is entered. This feature compliments the "General > Forms > Make required elements display as an error" feature.'),
  );

  // Popovers.
  $form['javascript']['popovers'] = array(
    '#type' => 'fieldset',
    '#title' => t('Popovers'),
    '#description' => t('Add small overlays of content, like those on the iPad, to any element for housing secondary information.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['javascript']['popovers']['bootstrap_popover_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable popovers.'),
    '#description' => t('Elements that have the <code>data-toggle="popover"</code> attribute set will automatically initialize the popover upon page load. <strong class="error text-error">WARNING: This feature can sometimes impact performance. Disable if pages appear to "hang" after initial load.</strong>'),
    '#default_value' => bootstrap_setting('popover_enabled', $theme),
  );
  $form['javascript']['popovers']['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#description' => t('These are global options. Each popover can independently override desired settings by appending the option name to <code>data-</code>. Example: <code>data-animation="false"</code>.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="bootstrap_popover_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_animation'] = array(
    '#type' => 'checkbox',
    '#title' => t('animate'),
    '#description' => t('Apply a CSS fade transition to the popover.'),
    '#default_value' => bootstrap_setting('popover_animation', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_html'] = array(
    '#type' => 'checkbox',
    '#title' => t('HTML'),
    '#description' => t("Insert HTML into the popover. If false, jQuery's text method will be used to insert content into the DOM. Use text if you're worried about XSS attacks."),
    '#default_value' => bootstrap_setting('popover_html', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_placement'] = array(
    '#type' => 'select',
    '#title' => t('placement'),
    '#description' => t('Where to position the popover. When "auto" is specified, it will dynamically reorient the popover. For example, if placement is "auto left", the popover will display to the left when possible, otherwise it will display right.'),
    '#default_value' => bootstrap_setting('popover_placement', $theme),
    '#options' => drupal_map_assoc(array(
      'top',
      'bottom',
      'left',
      'right',
      'auto',
      'auto top',
      'auto bottom',
      'auto left',
      'auto right',
    )),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_selector'] = array(
    '#type' => 'textfield',
    '#title' => t('selector'),
    '#description' => t('If a selector is provided, tooltip objects will be delegated to the specified targets. In practice, this is used to enable dynamic HTML content to have popovers added. See <a href="!this" target="_blank">this</a> and <a href="!example" target="_blank">an informative example</a>.', array(
      '!this' => 'https://github.com/twbs/bootstrap/issues/4215',
      '!example' => 'http://jsfiddle.net/fScua/',
    )),
    '#default_value' => bootstrap_setting('popover_selector', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_trigger'] = array(
    '#type' => 'checkboxes',
    '#title' => t('trigger'),
    '#description' => t('How a popover is triggered.'),
    '#default_value' => bootstrap_setting('popover_trigger', $theme),
    '#options' => drupal_map_assoc(array(
      'click',
      'hover',
      'focus',
      'manual',
    )),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_trigger_autoclose'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto-close on document click'),
    '#description' => t('Will automatically close the current popover if a click occurs anywhere else other than the popover element.'),
    '#default_value' => bootstrap_setting('popover_trigger_autoclose', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#description' => t("Default title value if \"title\" attribute isn't present."),
    '#default_value' => bootstrap_setting('popover_title', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_content'] = array(
    '#type' => 'textfield',
    '#title' => t('content'),
    '#description' => t('Default content value if "data-content" or "data-target" attributes are not present.'),
    '#default_value' => bootstrap_setting('popover_content', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('delay'),
    '#description' => t('The amount of time to delay showing and hiding the popover (in milliseconds). Does not apply to manual trigger type.'),
    '#default_value' => bootstrap_setting('popover_delay', $theme),
  );
  $form['javascript']['popovers']['options']['bootstrap_popover_container'] = array(
    '#type' => 'textfield',
    '#title' => t('container'),
    '#description' => t('Appends the popover to a specific element. Example: "body". This option is particularly useful in that it allows you to position the popover in the flow of the document near the triggering element - which will prevent the popover from floating away from the triggering element during a window resize.'),
    '#default_value' => bootstrap_setting('popover_container', $theme),
  );

  // Tooltips.
  $form['javascript']['tooltips'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tooltips'),
    '#description' => t('Inspired by the excellent jQuery.tipsy plugin written by Jason Frame; Tooltips are an updated version, which don\'t rely on images, use CSS3 for animations, and data-attributes for local title storage. See <a href="!url" target="_blank">Bootstrap tooltips</a> for more documentation.', array(
      '!url' => 'http://getbootstrap.com/javascript/#tooltips',
    )),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['javascript']['tooltips']['bootstrap_tooltip_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable tooltips'),
    '#description' => t('Elements that have the <code>data-toggle="tooltip"</code> attribute set will automatically initialize the tooltip upon page load. <strong class="error text-error">WARNING: This feature can sometimes impact performance. Disable if pages appear to "hang" after initial load.</strong>'),
    '#default_value' => bootstrap_setting('tooltip_enabled', $theme),
  );
  $form['javascript']['tooltips']['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#description' => t('These are global options. Each tooltip can independently override desired settings by appending the option name to <code>data-</code>. Example: <code>data-animation="false"</code>.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="bootstrap_tooltip_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_animation'] = array(
    '#type' => 'checkbox',
    '#title' => t('animate'),
    '#description' => t('Apply a CSS fade transition to the tooltip.'),
    '#default_value' => bootstrap_setting('tooltip_animation', $theme),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_html'] = array(
    '#type' => 'checkbox',
    '#title' => t('HTML'),
    '#description' => t("Insert HTML into the tooltip. If false, jQuery's text method will be used to insert content into the DOM. Use text if you're worried about XSS attacks."),
    '#default_value' => bootstrap_setting('tooltip_html', $theme),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_placement'] = array(
    '#type' => 'select',
    '#title' => t('placement'),
    '#description' => t('Where to position the tooltip. When "auto" is specified, it will dynamically reorient the tooltip. For example, if placement is "auto left", the tooltip will display to the left when possible, otherwise it will display right.'),
    '#default_value' => bootstrap_setting('tooltip_placement', $theme),
    '#options' => drupal_map_assoc(array(
      'top',
      'bottom',
      'left',
      'right',
      'auto',
      'auto top',
      'auto bottom',
      'auto left',
      'auto right',
    )),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_selector'] = array(
    '#type' => 'textfield',
    '#title' => t('selector'),
    '#description' => t('If a selector is provided, tooltip objects will be delegated to the specified targets.'),
    '#default_value' => bootstrap_setting('tooltip_selector', $theme),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_trigger'] = array(
    '#type' => 'checkboxes',
    '#title' => t('trigger'),
    '#description' => t('How a tooltip is triggered.'),
    '#default_value' => bootstrap_setting('tooltip_trigger', $theme),
    '#options' => drupal_map_assoc(array(
      'click',
      'hover',
      'focus',
      'manual',
    )),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_delay'] = array(
    '#type' => 'textfield',
    '#title' => t('delay'),
    '#description' => t('The amount of time to delay showing and hiding the tooltip (in milliseconds). Does not apply to manual trigger type.'),
    '#default_value' => bootstrap_setting('tooltip_delay', $theme),
  );
  $form['javascript']['tooltips']['options']['bootstrap_tooltip_container'] = array(
    '#type' => 'textfield',
    '#title' => t('container'),
    '#description' => t('Appends the tooltip to a specific element. Example: "body"'),
    '#default_value' => bootstrap_setting('tooltip_container', $theme),
  );

  // Dropdowns.
  $form['javascript']['dropdowns'] = array(
    '#type' => 'fieldset',
    '#title' => t('Dropdown Menus'),
    '#description' => t('Bootstrap\'s default dropdown.js settings only allow one collapsible submenu. This is an intentional decision due to Bootstrap being a "mobile-first" framework and collapsible menus don\'t play exceptionally well on mobile devices. If your theme\'s navigation requires nested accordian-style collapsible submenus and it will primarily be used on desktop screens, enable Nested Dropdowns. A custom dropdown.js file is already written in the site theme and will allow grandchildren submenus.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['javascript']['dropdowns']['bootstrap_dropdown_options'] = array(
    '#type' => 'select',
    '#title' => t('Dropdown Menu Options'),
    '#default_value' => theme_get_setting('bootstrap_dropdown_options', $theme),
    '#options' => array(
      'default' => t('Bootstrap Default Dropdowns'),
      'nested' => t('Nested Dropdowns'),
    ),
  );
}
