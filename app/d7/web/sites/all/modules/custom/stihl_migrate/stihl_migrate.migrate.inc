<?php

/**
 * @file
 * Migrate api for Stihl migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function stihl_migrate_migrate_api() {

  $api = array(
    'api' => 2,

    'groups' => array(
      'Taxonomy' => array(
        'title' => t('Stihl product categories migrations'),
      ),
      'Products' => array(
        'title' => t('Stihl product migrations'),
      ),
    ),

    'migrations' => array(
      'PricingImport' => array(
        'class_name' => 'StihlMigratePricing',
        'group_name' => 'Products',
      ),
      'ProductImport' => array(
        'class_name' => 'StihlMigrateProducts',
        'group_name' => 'Products',
      ),
      'ParentTermsImport' => array(
        'class_name' => 'StihlMigrateParentTerms',
        'group_name' => 'Taxonomy',
      ),
      'ChildTermsImport' => array(
        'class_name' => 'StihlMigrateChildTerms',
        'group_name' => 'Taxonomy',
      ),
    ),
  );

  return $api;
}
