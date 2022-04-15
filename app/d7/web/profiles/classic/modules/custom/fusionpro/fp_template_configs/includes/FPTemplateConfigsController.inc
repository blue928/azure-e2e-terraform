<?php

/**
 * @file
 * FP Template Configs entity controller.
 */

/**
 * Custom controller for FP Template Configs entity.
 */
class FPTemplateConfigsController extends EntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    $build['name'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->name),
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
    );
    $build['description'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->description),
      '#prefix' => '<div>Description: ',
      '#suffix' => '</div>',
    );
    $build['cache'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->cache) ? 'Yes' : 'No',
      '#prefix' => '<div>Enable caching: ',
      '#suffix' => '</div>',
    );

    // Template Config fieldset.
    $build['template_config'] = array(
      '#type' => 'fieldset',
      '#title' => t('Template Configuration'),
    );
    $build['template_config']['template'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->template),
      '#prefix' => '<div>Template name: ',
      '#suffix' => '</div>',
    );
    $build['template_config']['file_type'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->file_type),
      '#prefix' => '<div>Output file type: ',
      '#suffix' => '</div>',
    );
    $build['template_config']['data_format'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->data_format),
      '#prefix' => '<div>Template data format: ',
      '#suffix' => '</div>',
    );
    $build['template_config']['cfg_file'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->cfg_file),
      '#prefix' => '<div>CFG file: ',
      '#suffix' => '</div>',
    );

    // Dates fieldset.
    $build['dates'] = array(
      '#type' => 'fieldset',
      '#title' => t('Date information'),
    );
    $build['dates']['created'] = array(
      '#type' => 'markup',
      '#markup' => format_date($entity->created, 'long'),
      '#prefix' => '<p>Created: ',
      '#suffix' => '</p>',
    );
    $build['dates']['changed'] = array(
      '#type' => 'markup',
      '#markup' => format_date($entity->changed, 'long'),
      '#prefix' => '<p>Updated: ',
      '#suffix' => '</p>',
    );

    // Navigation actions.
    $build['actions']['edit_link'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Edit Profile'),
        FP_TEMPLATE_CONFIGS_MANAGE_URI . '/manage/' . $entity->id,
        array('attributes' => array('class' => 'button'))
      ),
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    );
    $build['actions']['back_link'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Back to list'), FP_TEMPLATE_CONFIGS_MANAGE_URI),
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
