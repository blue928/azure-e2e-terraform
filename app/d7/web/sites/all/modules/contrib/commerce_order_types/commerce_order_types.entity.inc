<?php

/**
 * @file
 * Extends EntityAPIControllerInterface with classes for commerce order types.
 */

/**
 * Provides a class for commerce order types.
 *
 * Use a separate class so we can specify some defaults modules may be alter.
 */
class CommerceOrderType extends Entity {
  public $type;
  public $id;
  public $help;
  public $data;

  public function __construct($values = array()) {
    parent::__construct($values, 'commerce_order_type');
  }

  function isLocked() {
    return !empty($this->id);
  }

}
