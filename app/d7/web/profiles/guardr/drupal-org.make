; Drush Make file for the Guardr distribution
api = 2
core = 7.x

; Modules
; -------
projects[autologout][subdir] = contrib
projects[autologout][version] = 4.5

projects[clear_password_field][subdir] = contrib
projects[clear_password_field][version] = 1.2

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.14

projects[diff][subdir] = contrib
projects[diff][version] = 3.3

projects[diskfree][subdir] = contrib
projects[diskfree][version] = 1.3

projects[duo][subdir] = contrib
projects[duo][version] = 1.11

projects[ejectorseat][subdir] = contrib
projects[ejectorseat][version] = 1.0
projects[ejectorseat][patch][] = https://www.drupal.org/files/issues/ejectorseat-register-autologout-2226873-2.patch

projects[email_confirm][subdir] = contrib
projects[email_confirm][version] = 1.3

projects[encrypt][subdir] = contrib
projects[encrypt][version] = 2.3

projects[entitycache][subdir] = contrib
projects[entitycache][version] = 1.5

projects[field_permissions][subdir] = contrib
projects[field_permissions][version] = 1.0

projects[flood_control][subdir] = contrib
projects[flood_control][version] = 1.0

projects[guardr_core][subdir] = contrib
projects[guardr_core][version] = 1.1

projects[hacked][subdir] = contrib
projects[hacked][version] = 2.0-beta6

projects[hide_php_fatal_error][subdir] = contrib
projects[hide_php_fatal_error][version] = 1.0

projects[libraries][subdir] = contrib
projects[libraries][version] = 2.3
; Patch libraries.module to support PHP 7.
; http://www.drupal.org/node/2779591.
projects[libraries][patch][] = http://www.drupal.org/files/issues/libraries-version-callback-reference-parameter-fix-2779591-3.patch

projects[login_history][subdir] = contrib
projects[login_history][version] = 1.1

projects[login_security][subdir] = contrib
projects[login_security][version] = 1.9

projects[logging_alerts][subdir] = contrib
projects[logging_alerts][version] = 2.2

projects[mass_pwreset][subdir] = contrib
projects[mass_pwreset][version] = 1.1

projects[memcache][subdir] = contrib
projects[memcache][version] = 1.6

projects[no_autocomplete][subdir] = contrib
projects[no_autocomplete][version] = 1.3

projects[paranoia][subdir] = contrib
projects[paranoia][version] = 1.7

projects[password_policy][subdir] = contrib
projects[password_policy][version] = 1.16

projects[permission_watchdog][subdir] = contrib
projects[permission_watchdog][version] = 1.1

projects[r4032login][subdir] = contrib
projects[r4032login][version] = 1.8

projects[realname][subdir] = contrib
projects[realname][type] = module
projects[realname][download][type] = git
projects[realname][download][url] = https://git.drupal.org/project/realname.git
projects[realname][download][branch] = 7.x-1.x
projects[realname][download][revision] = 425d6307eba622f9e7886d600805103aace09360
projects[realname][patch][] = https://www.drupal.org/files/issues/realname_autocomplete_views-2261665-9.patch

projects[remove_generator][subdir] = contrib
projects[remove_generator][version] = 1.4

projects[revision_all][subdir] = contrib
projects[revision_all][version] = 2.1

projects[role_watchdog][subdir] = contrib
projects[role_watchdog][version] = 2.x-dev
projects[role_watchdog][download][branch] = 7.x-2.x

projects[seckit][subdir] = contrib
projects[seckit][version] = 1.9

projects[security_review][subdir] = contrib
projects[security_review][version] = 1.3

projects[semiclean][subdir] = contrib
projects[semiclean][version] = 1.0

projects[session_expire][type] = module
projects[session_expire][subdir] = contrib
projects[session_expire][download][type] = git
projects[session_expire][download][url] = https://git.drupal.org/project/session_expire.git
projects[session_expire][download][branch] = 7.x-1.x
projects[session_expire][download][revision] = 384f0fb2521f23b8e66a89e62af643f2c57ff931
projects[session_expire][patch][] = https://drupal.org/files/deleteQuery_range_not_supported-1832200-3.patch

projects[session_limit][subdir] = contrib
projects[session_limit][version] = 2.3

projects[settings_audit_log][subdir] = contrib
projects[settings_audit_log][version] = 1.2

projects[tfa][subdir] = contrib
projects[tfa][version] = 2.0

projects[tfa_basic][subdir] = contrib
projects[tfa_basic][version] = 1.1

projects[token][subdir] = contrib
projects[token][version] = 1.7

projects[user_registrationpassword][subdir] = contrib
projects[user_registrationpassword][version] = 1.5

projects[username_enumeration_prevention][subdir] = contrib
projects[username_enumeration_prevention][version] = 1.2

projects[view_profiles_perms][subdir] = contrib
projects[view_profiles_perms][version] = 1.0

projects[x_originating_ip][subdir] = contrib
projects[x_originating_ip][version] = 1.2

; Libraries
; ---------
libraries[profiler][download][type] = "get"
libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-7.x-2.0-beta1.tar.gz"
