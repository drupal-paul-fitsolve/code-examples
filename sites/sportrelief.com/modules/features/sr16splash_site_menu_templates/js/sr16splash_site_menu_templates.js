/**
 * This Javascript provides the template file autocomplete functionality
 * when creating a new menu template Bean at /block/add/menu-template
 *
 * Author Peter B.
 */

(function ($) {

Drupal.behaviors.sr16splash_site_menu_templates = {

    // adds an element .menu-template-name-suffix after the form label to hold the 
    // autocomplete.
    // on typing into the label field, take typed value, replace spaces and 
    // non-alphanumeric // characters with dashes, add .tpl.php to the end and i
    // nsert into .menu-template-name-suffix as the exact name of the tpl file 
    // to use for this menu
    // 
    attach: function (context, settings) {

        // Cache the label
        var $label = $('#edit-label');

        // Add the element to contain the menu template name
        $label.addClass('processed').after('<div class="description menu-template-name-suffix">&nbsp;</div>');

        // Cache the suffix element
        var $suffix = $label.next('.menu-template-name-suffix');

        // Bind to input key events and complete the template name
        // as we type our menu template name

        // Change this to use on once >= jQuery 1.7 is installed
        $label.bind('keyup change', function () {

          // Replace spaces and non-alphanumeric characters with dashes
          var name = $(this).val().toLowerCase().replace(/[^a-z0-9]+/g, '-').replace(/_+/g, '-');
          if (name !== '_' && name !== '') {

            // Insert the menu template filename to use
            $suffix.empty().append('Template file: <strong>menu-template--' + name + '.tpl.php</strong>');
          
          } else { // if the menu template name is empty remove the template file suggestion
          
            $('.menu-template-name-suffix').text('');
          
          }

        });

    }
  };

})(jQuery);