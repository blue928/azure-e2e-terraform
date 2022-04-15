<?php

/**
 * @file
 * Stihl pricing years entity UI controller.
 */

/**
 * Custom controller for the administrator UI.
 */
class StihlPricingYearsUIController extends EntityDefaultUIController {

  /**
   * Override the menu hook to alter title and description.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['title'] = 'Stihl Order Pricing Years';
    $items[$this->path]['description'] = t('Manage pricing years');
    return $items;
  }

  /**
   * Do not show 'delete' link when only one pricing year is available.
   */
  public function overviewTable($conditions = array()) {
    $table = parent::overviewTable($conditions);
    // If there's only one row in the table, remove the 'delete' link.
    if (count($table['#rows']) == 1) {
      // Create a reference to the row for readability.
      $row =& $table['#rows'][0];
      // For the sake of scalability, walk each of the columns in the row
      // to find the delete link rather than 'popping' it from the array.
      array_walk($row, function ($column, $pos) use (&$row) {
        if (gettype($column) == 'string' && strip_tags($column) == 'delete') {
          unset($row[$pos]);
        }
      });
    }
    return $table;
  }

  /**
   * Add column headers to overview table.
   */
  protected function overviewTableHeaders($conditions, $rows, $additional_header = array()) {
    $additional_header = array('Updated', 'Status');
    $header = parent::overviewTableHeaders($conditions, $rows, $additional_header);
    $header[0] = 'Pricing Years';
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

    $additional_cols[] = array(
      'data' => array(
        '#theme' => 'entity_ui_overview_item',
        '#label' => $entity->enabled ? 'Enabled' : 'Disabled',
        '#entity_type' => $this->entityType,
      ),
    );
    return parent::overviewTableRow($conditions, $id, $entity, $additional_cols);
  }

  /**
   * Add button to create new Pricing Years to overview form.
   */
  public function overviewForm($form, &$form_state) {
    $form = parent::overviewForm($form, $form_state);
    $form[] = array(
      '#type' => 'markup',
      '#markup' => l(t('Add @label', array('@label' => $this->entityInfo['label'])),
        STIHL_PRICING_YEARS_MANAGE_URI . '/add',
        array('attributes' => array('class' => 'btn btn-success'))
      ),
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    );
    return $form;
  }

  /**
   * Prevent referenced pricing years from being deleted.
   *
   * If the user is attempting to delete a pricing year that is being referenced
   * by an existing order, prevent them from doing so and display an error.
   */
  public function operationForm($form, &$form_state, $entity, $op) {
    if ($op == 'delete') {
      // SQL Query to find existing orders that reference the pricing year's ID.
      $sql = 'SELECT o.order_id FROM {commerce_order} o
        INNER JOIN {field_data_field_pricing_year_reference} yr ON o.order_id = yr.entity_id
        WHERE yr.field_pricing_year_reference_target_id = :id';
      $query = db_query($sql, array(':id' => $entity->id));

      switch (TRUE) {
        case ($order_ids = $query->fetchCol()):
          $message = t('It is referenced by order(s): @order_ids', array('@order_ids' => implode(', ', $order_ids)));
          break;

        case (count(entity_load($this->entityType, FALSE)) == 1):
          $message = t('A minimum of one pricing year is required for Stihl Order creation.');
          break;

        default:
          $message = NULL;
      }

      // If the $message is not null, the entity should not be deleted.
      if (is_null($message) == FALSE) {
        // Format the error message.
        $message = t('Unable to delete the @entity @label. @message', array(
          '@entity' => $this->entityInfo['label'],
          '@label' => entity_label($this->entityType, $entity),
          '@message' => $message,
        ));

        drupal_set_message($message, 'error');
        return drupal_goto($this->path);
      }
    }
    return parent::operationForm($form, $form_state, $entity, $op);
  }

}
