<?php
/**
 * @file
 * variable.user_registrationpassword_register_body.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'user_registrationpassword_register_body',
  'content' => '[user:name],

Thank you for registering at [site:name]. You may now log in and verify your account by clicking this link or copying and pasting it to your browser:

[user:registrationpassword-url]

This link can only be used once. You will be able to log in at [site:login-url] in the future using:

username: [user:name]
password: Your password

--  [site:name] team',
);

$dependencies = array();

$optional = array();

$modules = array();
