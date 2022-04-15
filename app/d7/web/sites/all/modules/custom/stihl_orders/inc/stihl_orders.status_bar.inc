<?php

/**
 * @file
 * Contains the StihlOrdersStatusBar class.
 */

/**
 * Class StihlOrdersStatusBar().
 */
class StihlOrdersStatusBar {

  /**
   * Relevant metadata about each status in the ordering process.
   *
   * @var array
   */
  public static $statusData = [
    'order' => [
      'step' => 'order',
      'name' => 'create order',
      'sub_path' => 'new',
      'links' => [],
      'title' => 'Edit kit quantities',
    ],
    'tags' => [
      'step' => 'tags',
      'name' => 'select hang tags',
      'sub_path' => 'edit',
      'links' => ['order'],
      'title' => 'Edit orders',
    ],
    'qty' => [
      'step' => 'qty',
      'name' => 'pricing/qty',
      'sub_path' => 'configure',
      'links' => ['tags', 'order'],
      'title' => 'Configure order',
    ],
    'subt' => [
      'step' => 'subt',
      'name' => 'submit order',
      'sub_path' => 'submit',
      'links' => ['qty', 'tags', 'order'],
      'title' => 'Submit order',
    ],
    'conf' => [
      'step' => 'conf',
      'name' => 'confirmation',
      'sub_path' => 'confirmation',
      'links' => ['subt', 'qty', 'tags', 'order'],
    ],
  ];

  /**
   * Returns the step name for the current URL sub-path.
   *
   * @return mixed
   *   The step name for the current URL sub-path.
   */
  protected static function currentStep() {
    $current_sub_path = explode('/', $_GET['q'])[1];
    $steps = array_column(self::$statusData, 'sub_path', 'step');
    return array_search($current_sub_path, $steps);
  }

  /**
   * Returns whether or not a menu item should be linked.
   *
   * In order for a status to be linked, it needs to have an established order
   * object (can't be a new order), must not be in a "submitted" workflow state
   * and must be a step prior to the current step in the process.
   *
   * @param mixed $order
   *   An order object, if set, NULL, if not.
   * @param string $step
   *   The name of the step whose menu item we are rendering.
   *
   * @return bool
   *   Whether or not the current step should be linked.
   */
  protected static function isLinked($order, $step) {
    return isset($order)
      && stihl_orders_get_states_by_workflow()['submitted'] != $order->field_order_status->value()
      && in_array($step, self::$statusData[self::currentStep()]['links']);
  }

  /**
   * Renders the opening anchor tag for steps that should be linked.
   *
   * @param mixed $order
   *   An order object, if set, NULL, if not.
   * @param string $step
   *   The name of the step whose menu item we are rendering.
   *
   * @return null|string
   *   The opening anchor tag for steps that should be linked, otherwise NULL.
   */
  protected static function prefix($order, $step) {
    if (self::isLinked($order, $step)) {
      $sub_path = self::$statusData[$step]['sub_path'];
      $title = self::$statusData[$step]['title'];
      return '<a href="/orders/' . $sub_path . '/' . $order->getIdentifier() . '" title="' . $title . '">';
    }
    return NULL;
  }

  /**
   * Renders the closing anchor tag for steps that should be linked.
   *
   * @param mixed $order
   *   An order object, if set, NULL, if not.
   * @param string $step
   *   The name of the step whose menu item we are rendering.
   *
   * @return null|string
   *   The closing anchor tag for steps that should be linked, otherwise NULL.
   */
  protected static function suffix($order, $step) {
    if (self::isLinked($order, $step)) {
      return '</a>';
    }
    return NULL;
  }

  /**
   * Builds the render array for the Order Status bar.
   *
   * @param int $order_id
   *   The ID for the current order.
   *
   * @return array
   *   The render array for the Order Status bar.
   */
  public static function build($order_id) {
    $order_status = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => array('order-status'),
      ),
    );
    $order = $order_id ? entity_metadata_wrapper('commerce_order', $order_id) : NULL;
    foreach (array_keys(self::$statusData) as $step) {
      $name = strtoupper(self::$statusData[$step]['name']);
      $order_status[$step] = array(
        '#prefix' => self::prefix($order, $step),
        '#markup' => "<div id=$step>" . $name . "</div>",
        '#suffix' => self::suffix($order, $step),
      );
    }
    // We do not want to return a status bar for 'submitted' orders.
    if (!is_null($order) && $order->field_order_status->value() == stihl_orders_get_states_by_workflow()['submitted']) {
      return [];
    }
    return $order_status;
  }

}
