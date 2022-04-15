api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = 7.63

; Patch default.settings.php to support MySQL over SSL connections
; http://drupal.org/node/1824946
projects[drupal][patch][] = https://www.drupal.org/files/issues/guardr-settings-for-mysql-pdo-tls-1824946-11.patch
; Expire cookies when the browser closes and set
; garbage collection on sessions at 12 hrs instead of 2.3 days
; https://www.drupal.org/node/2234751
projects[drupal][patch][] = https://www.drupal.org/files/issues/guardr-expire-sessions-faster-223751-2.patch
