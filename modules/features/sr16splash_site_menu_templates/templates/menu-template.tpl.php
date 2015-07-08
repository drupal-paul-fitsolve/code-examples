<?php

/**
 * If a menu template is defined in the Bean UI but the corresponding template file
 * doesn't exist or is incorrectly name, you will see this message in the message 
 * area of the page.
 *
 * We also need this template file so the 'parent' theme function for rendering menu
 * templates can be safely registered. See sr16splash_site_menu_templates_theme
 * in sr16splash_site_menu_templates.module
 */

?>

<?php drupal_set_message(t('Unable to locate a template file in the default theme for this templated menu. Edit this block to see the correct template file name to use.'), 'error'); ?>