; REQUIRED ATTRIBUTES

; The Drush Make API version. This should always be 2.
api = 2

; The version of Drupal the profile is built for.
core = 7.x
projects[drupal][version] = 7.34

;Patches applied to core
projects[drupal][patch][] = https://www.drupal.org/files/drupal-remove_double_underscore_from_css_filter-2009584-16.patch
projects[drupal][patch][] = https://www.drupal.org/files/issues/menu_alter_callback-1079628-3.patch

;Link to contributed modules that are specific to this site
;There are no specific contributed modules for Sport Relief

;Link to contributed themes that are specific to this site
;Added omega to repo as it has been customised
projects[omega][type] = theme
projects[omega][subdir] = contrib
projects[omega][version] = "3.1"
