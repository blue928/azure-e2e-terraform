<?php

/**
 * @file
 * Contains the StihlOrdersExcludeUnpublishedProducts class.
 */

/**
 * Class StihlOrdersExcludeUnpublishedProducts.
 */
class StihlOrdersExcludeUnpublishedProducts extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function supportsIndex(SearchApiIndex $index) {
    return $index->getEntityType() == 'commerce_product';
  }

  /**
   * Prevent unpublished Commerce Products from being indexed by Search API.
   */
  public function alterItems(array &$items) {
    $items = array_filter($items, function ($item) {
      return $item->status == 1;
    }, ARRAY_FILTER_USE_BOTH);
  }

}
