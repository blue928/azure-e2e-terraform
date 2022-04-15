; Drush Make stub file for the Guardr distribution
;
; Use this file to build a full distribution including Drupal core and the
; Guardr install profile using the following command:
;
; drush make build-guardr.make <target directory>

api = 2
core = 7.x

; Drupal core
; -----------
includes[] = drupal-org-core.make

; Install profiles
; ----------------
projects[guardr][type] = profile
projects[guardr][download][type] = git
projects[guardr][download][url] = https://git.drupal.org/project/guardr.git
projects[guardr][download][tag] = 7.x-2.49
