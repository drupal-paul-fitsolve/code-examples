; REQUIRED ATTRIBUTES

; The Drush Make API version. This should always be 2.
api = 2

; The version of Drupal the profile is built for.
core = 7.x
projects[drupal][version] = 7.34

;Patches applied to core
projects[drupal][patch][] = https://www.drupal.org/files/drupal-remove_double_underscore_from_css_filter-2009584-16.patch
projects[drupal][patch][] = https://www.drupal.org/files/issues/menu_alter_callback-1079628-3.patch

;Link to Comic Relief's Distro
projects[crdistro][type] = profile
projects[crdistro][download][type] = git
projects[crdistro][download][url] = git@github.com:paul-at-fitsolve/crdistro.git



