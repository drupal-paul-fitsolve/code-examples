@author: Carl Hinton for Comic Relief 05/11/14
-----------

http://jira.comicrelief.com:8090/display/rnd15Documentation/WYSIWYG+Editor

Introduction
============
There are four modules that are used to configure the WYSIWYG on the RND site
contrib/ckeditor - this is the actual ckeditor module
custom/rnd15_site_deployment - this ensures that the modules are included in the build
custom/rnd15_site_wysiwyg_styles - this is where we define the selector styles, such that they match the text style
  guide - http://rnd15-dev.rednoseday.com/sites/rednoseday.com/themes/custom/rnd15/styleguide/index.html
features/rnd15_site_wysiwyg - this is where we featurize the majority of the ckeditor settings. N.B. Currently some of the text formats and text profiles are not fully configured within this feature as the place for those settings will be in a global settings / global permission features

Configuring which buttons appear
================================

* As an admin navigate to /admin/config/content/ckeditor/edit/rnd_profile
* Select editor appearance
* Drag and drop buttons as appropriate
* Recreate the feature rnd15_site_wysiwyg and deploy

Configuring styles
==================

The styles available to the editor are defined in JSON found in rnd15_site_wysiwyg_styles/ckeditor.styles.js
To add / delete from this simply amend the JSON as indicated by the file markup
It may be necessary to flush the js cache before this becomes active
hook_ckeditor_settings_alter can be used to alter which version of the JSON is used on a per role / per user basis

Buttons
=======

Buttons are created as ckeditor js plugins
These plugins are made known to Drupal via the function rnd15_site_wysiwyg_styles_plugin_definitions()
Button images are held within the individual plugin directories held within the rnd15_site_wysiwyg_styles directory.


ckeditor documentation
======================

ckeditor is fully documented here http://docs.ckeditor.com/