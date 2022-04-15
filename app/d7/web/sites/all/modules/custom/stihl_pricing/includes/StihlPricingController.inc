<?php

/**
 * @file
 * Pricing entity controller.
 */

/**
 * Custom controller for Stihl pricing entity.
 */
class StihlPricingController extends EntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    // Information fieldset.
    $build['information'] = array(
      '#type' => 'fieldset',
      '#title' => t('Product information'),
    );
    $build['information']['product_name'] = array(
      '#type' => 'markup',
      '#markup' => isset($entity->product_name) ? check_plain($entity->product_name) : '',
      '#prefix' => '<p>Product name: ',
      '#suffix' => '</p>',
    );
    $build['information']['hangtag_code'] = array(
      '#type' => 'markup',
      '#markup' => isset($entity->hangtag_code) ? check_plain($entity->hangtag_code) : '',
      '#prefix' => '<p>RLC SKU hangtag code: ',
      '#suffix' => '</p>',
    );
    $build['information']['display_product'] = array(
      '#type' => 'markup',
      '#markup' => $entity->display_product ? 'Yes' : 'No',
      '#prefix' => '<p>Display product: ',
      '#suffix' => '</p>',
    );
    $build['information']['display_price'] = array(
      '#type' => 'markup',
      '#markup' => $entity->display_price ? 'Yes' : 'No',
      '#prefix' => '<p>Display price: ',
      '#suffix' => '</p>',
    );

    // Pricing fieldset.
    $build['pricing'] = array(
      '#type' => 'fieldset',
      '#title' => t('Pricing information'),
    );
    $build['pricing']['current_year_price'] = array(
      '#type' => 'markup',
      '#markup' => isset($entity->current_year_price) ? check_plain($entity->current_year_price) : '',
      '#prefix' => '<p>Current year price: ',
      '#suffix' => '</p>',
    );
    $build['pricing']['next_year_price'] = array(
      '#type' => 'markup',
      '#markup' => isset($entity->next_year_price) ? check_plain($entity->next_year_price) : '',
      '#prefix' => '<p>Next year price: ',
      '#suffix' => '</p>',
    );
    $build['pricing']['msrp'] = array(
      '#type' => 'markup',
      '#markup' => isset($entity->msrp) ? check_plain($entity->msrp) : '',
      '#prefix' => '<p>Product MSRP: ',
      '#suffix' => '</p>',
    );

    // Reference fieldset.
    $build['reference'] = array(
      '#type' => 'fieldset',
      '#title' => t('Reference information'),
    );
    $build['reference']['bd_reference'] = array(
      '#type' => 'markup',
      '#markup' => isset($entity->bd_reference) ? check_plain($entity->bd_reference) : '',
      '#prefix' => '<p>BD Reference: ',
      '#suffix' => '</p>',
    );

    // Dates fieldset.
    $build['dates'] = array(
      '#type' => 'fieldset',
      '#title' => t('Date information'),
      'created' => array(
        '#type' => 'markup',
        '#markup' => format_date($entity->created, 'long'),
        '#prefix' => '<p>Created: ',
        '#suffix' => '</p>',
      ),
      'changed' => array(
        '#type' => 'markup',
        '#markup' => format_date($entity->changed, 'long'),
        '#prefix' => '<p>Updated: ',
        '#suffix' => '</p>',
      ),
    );

    // Navigation actions.
    $build['actions']['edit_link'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Edit Pricing'),
        STIHL_PRICING_MANAGE_URI . '/manage/' . $entity->id,
        array('attributes' => array('class' => 'button'))
      ),
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    );
    $build['actions']['back_link'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Back to list'), STIHL_PRICING_MANAGE_URI),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    return $build;
  }

  /**
   * {@inheritdoc}
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    if (isset($entity->is_new)) {
      $entity->created = REQUEST_TIME;
    }

    $entity->changed = REQUEST_TIME;
    return parent::save($entity, $transaction);
  }

}
