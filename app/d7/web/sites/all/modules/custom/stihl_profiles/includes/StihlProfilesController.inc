<?php

/**
 * @file
 * Products entity controller.
 */

/**
 * Custom controller for Stihl profiles entity.
 */
class StihlProfilesController extends EntityAPIController {

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
    $build['id'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->id),
      '#prefix' => '<div>Distributor id: ',
      '#suffix' => '</div>',
    );
    $build['phone'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->phone),
      '#prefix' => '<div>Phone: ',
      '#suffix' => '</div>',
    );

    // Options fieldset.
    $build['options'] = array(
      '#type' => 'fieldset',
      '#title' => t('Option information'),
    );
    $build['options']['number_on_tag'] = array(
      '#type' => 'markup',
      '#markup' => $entity->number_on_tag ? 'Yes' : 'No',
      '#prefix' => '<div>Display part numbers on hangtags: ',
      '#suffix' => '</div>',
    );
    $build['options']['only_vertical_tag'] = array(
      '#type' => 'markup',
      '#markup' => $entity->only_vertical_tag ? 'Yes' : 'No',
      '#prefix' => '<div>Vertical tag: ',
      '#suffix' => '</div>',
    );
    $build['options']['hangtag_without_pricing'] = array(
      '#type' => 'markup',
      '#markup' => $entity->hangtag_without_pricing ? 'Yes' : 'No',
      '#prefix' => '<div>Hangtag without pricing: ',
      '#suffix' => '</div>',
    );

    // Address fieldset.
    $build['address'] = array(
      '#type' => 'fieldset',
      '#title' => t('Address information'),
    );
    $build['address']['address_1'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->address_1),
      '#prefix' => '<div>Address 1: ',
      '#suffix' => '</div>',
    );
    $build['address']['address_2'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->address_2),
      '#prefix' => '<div>Address 2: ',
      '#suffix' => '</div>',
    );
    $build['address']['city'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->city),
      '#prefix' => '<div>City: ',
      '#suffix' => '</div>',
    );
    $build['address']['state'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->state),
      '#prefix' => '<div>State: ',
      '#suffix' => '</div>',
    );
    $build['address']['zip'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->zip),
      '#prefix' => '<div>Zip: ',
      '#suffix' => '</div>',
    );

    // Shipping fieldset.
    $build['shipping'] = array(
      '#type' => 'fieldset',
      '#title' => t('Shipping information'),
    );
    $build['shipping']['shipping_address_1'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->shipping_address_1),
      '#prefix' => '<div>Shipping Address 1: ',
      '#suffix' => '</div>',
    );
    $build['shipping']['shipping_address_2'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->shipping_address_2),
      '#prefix' => '<div>Shipping Address 2: ',
      '#suffix' => '</div>',
    );
    $build['shipping']['shipping_city'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->shipping_city),
      '#prefix' => '<div>Shipping City: ',
      '#suffix' => '</div>',
    );
    $build['shipping']['shipping_state'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->shipping_state),
      '#prefix' => '<div>Shipping State: ',
      '#suffix' => '</div>',
    );
    $build['shipping']['shipping_zip'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->shipping_zip),
      '#prefix' => '<div>Shipping Zip: ',
      '#suffix' => '</div>',
    );
    $build['shipping']['shipping_phone'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->shipping_phone),
      '#prefix' => '<p>Shipping Phone: ',
      '#suffix' => '</p>',
    );
    $build['shipping']['shipping_method_details'] = array(
      '#type' => 'markup',
      '#markup' => check_plain($entity->shipping_method_details),
      '#prefix' => '<p>Shipping Method Details: ',
      '#suffix' => '</p>',
    );

    // Freight fieldset.
    $build['freight'] = array(
      '#type' => 'fieldset',
      '#title' => t('Freight carrier information'),
    );
    $build['freight']['shipping_provider_1'] = array(
      '#type' => 'container',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
      'name_1' => array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->shipping_provider_name_1),
        '#prefix' => '<div>Shipping provider name 1: ',
        '#suffix' => '</div>',
      ),
      'account_1' => array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->shipping_provider_account_1),
        '#prefix' => '<div>Shipping provider account 1: ',
        '#suffix' => '</div>',
      ),
    );
    $build['freight']['shipping_provider_2'] = array(
      '#type' => 'container',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
      'name_2' => array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->shipping_provider_name_2),
        '#prefix' => '<div>Shipping provider name 2: ',
        '#suffix' => '</div>',
      ),
      'account_2' => array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->shipping_provider_account_2),
        '#prefix' => '<div>Shipping provider account 2: ',
        '#suffix' => '</div>',
      ),
    );
    $build['freight']['shipping_provider_3'] = array(
      '#type' => 'container',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
      'name_3' => array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->shipping_provider_name_3),
        '#prefix' => '<div>Shipping provider name 3: ',
        '#suffix' => '</div>',
      ),
      'account_3' => array(
        '#type' => 'markup',
        '#markup' => check_plain($entity->shipping_provider_account_3),
        '#prefix' => '<div>Shipping provider account 3: ',
        '#suffix' => '</div>',
      ),
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
      '#markup' => l(t('Edit Profile'),
        STIHL_PROFILES_MANAGE_URI . '/manage/' . $entity->id,
        array('attributes' => array('class' => 'button'))
      ),
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    );
    $build['actions']['back_link'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Back to list'), STIHL_PROFILES_MANAGE_URI),
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
