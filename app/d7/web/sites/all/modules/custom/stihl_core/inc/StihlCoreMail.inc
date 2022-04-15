<?php

/**
 * @file
 * Contains the StihlCoreMail class.
 */

/**
 * The StihlCoreMail class.
 */
class StihlCoreMail {
  public $bd;
  public $recipients = [];
  public $adminEmails = ['STIHLOrderAdmins@rlci.com', 'stihl-hangtag-orders@knowclassic.com'];

  /**
   * StihlCoreMail constructor.
   *
   * @param int $bd
   *   The BD ID whose users' emails we want to get.
   */
  public function __construct($bd = NULL) {
    $this->bd = $bd;
  }

  /**
   * Returns a list of all the users with the "classic employee" role.
   *
   * We don't want to include any individual Classic employees in the email
   * notifications that get sent when an order changes workflow status. Any
   * users that should get those notices need to be added to the admin
   * stihl-hangtag-orders@knowclassic.com mailing list.
   *
   * @return array
   *   Array containing the UIDs of every user with the "classic employee" role.
   */
  public function classicUids() {
    $classic_role = user_role_load_by_name('classic employee');
    $sql = 'SELECT * FROM {users_roles} WHERE rid = :rid';
    $users = db_query($sql, array(':rid' => $classic_role->rid))->fetchAllKeyed();
    return array_keys($users);
  }

  /**
   * Returns an array of user objects for users associated with the given BD.
   *
   * @param int $bd
   *   The BD ID.
   *
   * @return array
   *   An array of partial user objects.
   */
  public function bdUsers($bd) {
    $query = db_select('users', 'u');
    $query->join('field_data_field_bd_reference', 'b', 'u.uid = b.entity_id');
    $query
      ->fields('u', array('mail'))
      ->condition('u.status', '1')
      ->condition('u.uid', $this->classicUids(), 'NOT IN')
      ->condition('b.field_bd_reference_target_id', $bd);
    return $query->execute()->fetchAll();
  }

  /**
   * Returns just the email property from a user object.
   *
   * @param object $user
   *   A Drupal user object.
   *
   * @return string
   *   The email address for a given user.
   */
  public function userEmail($user) {
    return $user->mail;
  }

  /**
   * Returns an array containing the emails for a BD's users.
   *
   * @param int $bd
   *   The BD ID.
   *
   * @return array
   *   An array of a BD's users emails.
   */
  public function bdUsersEmails($bd) {
    return array_map(array($this, 'userEmail'), $this->bdUsers($bd));
  }

  /**
   * Sets the BD ID on the object if not passed to the constructor.
   *
   * @param int $bd
   *   The BD ID.
   *
   * @return object
   *   This StihlCoreMail object.
   */
  public function bd($bd = NULL) {
    $this->bd = $bd;
    return $this;
  }

  /**
   * Builds an array of the recipients who should receive a notification email.
   *
   * If a BD ID is passed, this will just populate the recipients array the
   * email addresses of every user associated with the BD. If no BD ID is passed
   * it will just populate the recipients list with the admin user emails.
   *
   * @return object
   *   This StihlCoreMail object.
   */
  public function recipients() {
    $recipients = $this->bd ? $this->bdUsersEmails($this->bd) : $this->adminEmails;
    $this->recipients = array_unique($recipients);
    return $this;
  }

  /**
   * Adds the admin users emails to the recipients array.
   *
   * In some cases, like when an order is submitted, the admin recipients should
   * also be included in the list of recipients, but should never be duplicated.
   *
   * @return object
   *   This StihlCoreMail object.
   */
  public function withAdmin() {
    $recipients = array_merge($this->recipients, $this->adminEmails);
    $this->recipients = array_unique($recipients);
    return $this;
  }

  /**
   * Returns the recipients array as a comma-separated list.
   *
   * @return string
   *   A comma-separated list of recipients.
   */
  public function getList() {
    return implode(', ', $this->recipients);
  }

  /**
   * Returns the recipients array.
   *
   * @return array
   *   An array of all recipients for a given message.
   */
  public function getArray() {
    return $this->recipients;
  }

}
