<?php

/**
 * @file
 * Pricing entity metadata controller.
 */

/**
 * Class StihlPricingMetadataController.
 *
 * Set specific properties for pricing entities.
 */
class StihlPricingMetadataController extends EntityDefaultMetadataController {

  /**
   * {@inheritdoc}
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    // Define getter/setter method for entity reference.
    $properties['bd_reference'] = array(
      'label' => t('Distributor profile reference'),
      'type' => 'integer',
      'description' => t('The ID of the distributor.'),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'schema field' => 'bd_reference',
    );
    // Define date property types.
    $properties['created'] = array(
      'label' => t('Date created'),
      'type' => 'date',
      'description' => t('The date the entity was created.'),
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t('Date changed'),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t('The date the entity was updated.'),
    );

    return $info;
  }

}
