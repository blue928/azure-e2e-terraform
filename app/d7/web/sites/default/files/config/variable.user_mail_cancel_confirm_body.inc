<?php
/**
 * @file
 * variable.user_mail_cancel_confirm_body.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'user_mail_cancel_confirm_body',
  'content' => 'A request to cancel your account has been made at [site:name].

You may now cancel your account on [site:url-brief] by clicking this link or copying and pasting it into your browser:

[user:cancel-url]

NOTE: The cancellation of your account is not reversible.

This link expires in one day and nothing will happen if it is not used.

--  [site:name] team',
);

$dependencies = array();

$optional = array();

$modules = array();
