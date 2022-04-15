<?php

/**
 * @file
 * Pricing Years entity controller.
 */

/**
 * Custom controller for Stihl pricing years entity.
 */
class StihlPricingYearsController extends EntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    $build['pricing_year'] = array(
      '#type' => 'fieldset',
      '#title' => check_plain($entity->label()),
    );
    $build['pricing_year']['bulk_one_sided'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->bulk_one_sided),
      '#prefix' => '<p>One-Sided Bulk Tags: ',
      '#suffix' => '</p>',
    );
    $build['pricing_year']['kitted_one_sided'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->kitted_one_sided),
      '#prefix' => '<p>One-Sided Kitted Tags: ',
      '#suffix' => '</p>',
    );
    $build['pricing_year']['bulk_two_sided'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->bulk_two_sided),
      '#prefix' => '<p>One-Two Bulk Tags: ',
      '#suffix' => '</p>',
    );
    $build['pricing_year']['kitted_two_sided'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->kitted_two_sided),
      '#prefix' => '<p>Two-Sided Kitted Tags: ',
      '#suffix' => '</p>',
    );
    $build['pricing_year']['upc_book'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->upc_book),
      '#prefix' => '<p>UPC Books: ',
      '#suffix' => '</p>',
    );
    $build['pricing_year']['enabled'] = array(
      '#type' => 'markup',
      '#markup' => $entity->enabled ? 'Yes' : 'No',
      '#prefix' => '<p>Enabled: ',
      '#suffix' => '</p>',
    );
    $build['pricing_year']['default_pricing'] = array(
      '#type' => 'markup',
      '#markup' => $entity->default_pricing ? 'Yes' : 'No',
      '#prefix' => '<p>Default: ',
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
      '#markup' => l(t('Edit Pricing Year'),
        STIHL_PRICING_YEARS_MANAGE_URI . '/manage/' . $entity->id,
        array('attributes' => array('class' => 'button'))
      ),
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    );
    $build['actions']['back_link'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Back to list'), STIHL_PRICING_YEARS_MANAGE_URI),
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

  /**
   * {@inheritdoc}
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    $sql_query = 'SELECT entity_id FROM {field_data_associated_pricing} WHERE associated_pricing_target_id IN (:ids)';
    $profile_ids = db_query($sql_query, array(':ids' => $ids))->fetchCol();

    foreach (stihl_pricing_years_load_multiple($ids) as $pricing_year) {
      foreach (stihl_profiles_load_multiple($profile_ids) as $profile) {
        stihl_pricing_years_update_associated_profile($profile, $pricing_year);
      }
    }

    parent::delete($ids, $transaction);
  }

}
