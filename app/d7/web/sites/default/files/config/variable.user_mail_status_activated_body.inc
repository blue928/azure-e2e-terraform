<?php
/**
 * @file
 * variable.user_mail_status_activated_body.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'user_mail_status_activated_body',
  'content' => 'Your account at [site:name] has been activated.

You may now log in by clicking this link or copying and pasting it into your browser:

[user:one-time-login-url]

This link can only be used once to log in and will lead you to a page where you can set your password.

After setting your password, you will be able to log in at [site:login-url] in the future using:

username: Your username
password: Your password

--  [site:name] team',
);

$dependencies = array();

$optional = array();

$modules = array();
