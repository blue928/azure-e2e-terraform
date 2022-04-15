<?php
/**
 * @file
 * variable.ldap_authentication_conf.inc
 */

$api = '2.0.0';

$data = array(
  'name' => 'ldap_authentication_conf',
  'content' => array(
    'sids' => array(
      'CG' => 'CG',
    ),
    'authenticationMode' => 1,
    'loginUIUsernameTxt' => NULL,
    'loginUIPasswordTxt' => NULL,
    'ldapUserHelpLinkUrl' => NULL,
    'ldapUserHelpLinkText' => 'Logon Help',
    'emailOption' => 3,
    'emailUpdate' => 2,
    'allowOnlyIfTextInDn' => array(),
    'excludeIfTextInDn' => array(),
    'allowTestPhp' => '',
    'excludeIfNoAuthorizations' => NULL,
    'ssoRemoteUserStripDomainName' => NULL,
    'seamlessLogin' => NULL,
    'ldapImplementation' => NULL,
    'cookieExpire' => NULL,
  ),
);

$dependencies = array();

$optional = array();

$modules = array();
