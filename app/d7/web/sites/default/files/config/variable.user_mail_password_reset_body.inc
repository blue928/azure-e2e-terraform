<?php
/**
 * @file
 * variable.user_mail_password_reset_body.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'user_mail_password_reset_body',
  'content' => 'A request to reset the password for your account has been made at [site:name].

You may now log in by clicking this link or copying and pasting it to your browser:

[user:one-time-login-url]

This link can only be used once to log in and will lead you to a page where you can set your password. It expires after one day and nothing will happen if it\'s not used.

--  [site:name] team',
);

$dependencies = array();

$optional = array();

$modules = array();
