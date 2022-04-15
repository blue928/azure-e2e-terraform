<?php

/**
 * @file
 * Code for determining if hang tag preview images exist.
 */

/**
 * Generates a page display.
 */
function stihl_product_views_preview_image_status_page() {

  $products_array = stihl_product_views_get_product_data_array();

  $vertical_products = array_filter($products_array, function ($product) {
    return stihl_product_views_preview_image_not_available($product->sku);
  });

  $horizontal_products = array_filter($products_array, function ($product) {
    if ($product->horizontal) {
      return stihl_product_views_preview_image_not_available($product->sku, FALSE);
    }
  });

  $render['vertical_fieldset'] = array(
    '#title' => t('Vertical Hang Tags'),
    '#type' => 'fieldset',
    '#description' => t('@count missing preview images', array('@count' => count($vertical_products))),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
    'container' => array(
      '#type' => 'markup',
      '#prefix' => '<div class="container-fluid">',
      '#suffix' => '</div>',
    ),
  );
  $render['vertical_fieldset']['container']['vertical_table'] = array(
    '#prefix' => '<div class="row">',
    '#markup' => stihl_product_views_products_table($vertical_products),
    '#suffix' => '</div>',
  );

  $render['horizontal_fieldset'] = array(
    '#title' => t('Horizontal Hang Tags'),
    '#type' => 'fieldset',
    '#description' => t('@count missing preview images', array('@count' => count($horizontal_products))),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
    'container' => array(
      '#type' => 'markup',
      '#prefix' => '<div class="container-fluid">',
      '#suffix' => '</div>',
    ),
  );
  $render['horizontal_fieldset']['container']['horizontal_table'] = array(
    '#prefix' => '<div class="row">',
    '#markup' => stihl_product_views_products_table($horizontal_products),
    '#suffix' => '</div>',
  );

  return $render;
}

/**
 * Generates an array of all products with a sub-set of data.
 *
 * Each object contains:
 *   SKU, title, product ID, status, and horizontal option field.
 *
 * @return array
 *   An array of objects containing product data.
 */
function stihl_product_views_get_product_data_array() {

  $cache_id = 'stihl_product_views:product_data_array';

  if ($cached = cache_get($cache_id)) {
    return $cached->data;
  }

  $sql = 'SELECT cp.sku,cp.title,cp.product_id,cp.status,hf.field_horizontal_hangtag_value AS horizontal
          FROM commerce_product cp
          INNER JOIN field_data_field_horizontal_hangtag hf
          ON cp.product_id = hf.entity_id';

  $query = db_query($sql);
  $result = $query->fetchAll();

  if (!empty($result)) {
    cache_set($cache_id, $result, 'cache', strtotime('+7 days'));
  }
  return $result;
}

/**
 * Callback to determine if a hang tag preview image is not available.
 *
 * @param string $sku
 *   The product SKU number.
 * @param boolean $vertical
 *   (optional) Requesting vertical or horizontal.
 *
 * @return boolean
 *   Return true if file not available.
 */
function stihl_product_views_preview_image_not_available($sku, $vertical = TRUE) {

  $alignment = ($vertical) ? 'V' : 'H';
  $file_path = 'public://product-images/' . $alignment . '/' . $sku . '_' . $alignment . '.jpg';

  // This is negated because we are checking if the file is not available.
  return !stihl_orders_attempt_file_resource($file_path, 'r', FALSE);
}

/**
 * Generates a table of product data.
 *
 * @param array $products_array
 *   An array of objects containing product data.
 */
function stihl_product_views_products_table($products_array) {

  $headers = array(
    array('data' => 'Drupal ID', 'class' => 'text-center'),
    array('data' => 'Product Enabled', 'class' => 'text-center'),
    array('data' => 'Horizontal Option', 'class' => 'text-center'),
    array('data' => 'SKU'),
  );

  $rows = array();

  array_walk($products_array, function ($product) use (&$rows) {
    $rows[] = array(
      array('data' => l($product->product_id, '/product/' . $product->product_id), 'align' => 'center'),
      array('data' => ($product->status ? "Yes" : "No"), 'align' => 'center'),
      array('data' => ($product->horizontal ? "Yes" : "No"), 'align' => 'center'),
      array('data' => $product->sku),
    );
  });

  return theme('table', array(
    'header' => $headers,
    'rows' => $rows,
    'empty' => t('No products to display'),
  ));
}
