<?php

/**
 * @file
 * Stihl profiles entity UI controller.
 */

/**
 * Custom controller for the administrator UI.
 */
class StihlProfilesUIController extends EntityDefaultUIController {

  /**
   * Override the menu hook to alter title and description.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['title'] = 'Stihl Distributor Profiles';
    $items[$this->path]['description'] = t('Manage branch/distributor profiles');
    return $items;
  }

  /**
   * Add column to overview table.
   */
  protected function overviewTableHeaders($conditions, $rows, $additional_header = array()) {
    $additional_header = array('Updated');
    $header = parent::overviewTableHeaders($conditions, $rows, $additional_header);
    return $header;
  }

  /**
   * Add column to overview table.
   */
  protected function overviewTableRow($conditions, $id, $entity, $additional_cols = array()) {
    $additional_cols[] = array(
      'data' => array(
        '#theme' => 'entity_ui_overview_item',
        '#label' => format_date($entity->changed, 'short'),
        '#entity_type' => $this->entityType,
      ),
    );
    return parent::overviewTableRow($conditions, $id, $entity, $additional_cols);
  }

}
