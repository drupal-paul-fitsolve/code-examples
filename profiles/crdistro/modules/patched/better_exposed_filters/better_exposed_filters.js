/**
 * @file better_exposed_filters.js
 *
 * Provides some client-side functionality for the Better Exposed Filters module
 */
(function ($) {
  Drupal.behaviors.better_exposed_filters = {
    attach: function(context) {

      /*
       * Add Select all/none links to specified checkboxes
       */
      var selected = $('.form-checkboxes.bef-select-all-none:not(.bef-processed)');
      if (selected.length) {
        var selAll = Drupal.t('Select All');
        var selNone = Drupal.t('Select None');

        // Set up a prototype link and event handlers
        var link = $('<a class="bef-toggle" href="#">'+ selAll +'</a>')
        link.click(function(event) {
          // Don't actually follow the link...
          event.preventDefault();
          event.stopPropagation();

          if (selAll == $(this).text()) {
            // Select all the checkboxes
            $(this)
              .html(selNone)
              .siblings('.bef-checkboxes, .bef-tree')
                .find('.form-item input:checkbox').each(function() {
                  $(this).attr('checked', 'checked');
                  _bef_highlight(this, context);
                })
              .end()

              // attr() doesn't trigger a change event, so we do it ourselves. But just on
              // one checkbox otherwise we have many spinning cursors
              .find('input[type=checkbox]:first').change()
            ;
          }
          else {
            // Unselect all the checkboxes
            $(this)
              .html(selAll)
              .siblings('.bef-checkboxes, .bef-tree')
                .find('.form-item input:checkbox').each(function() {
                  $(this).attr('checked', '');
                  _bef_highlight(this, context);
                })
              .end()

              // attr() doesn't trigger a change event, so we do it ourselves. But just on
              // one checkbox otherwise we have many spinning cursors
              .find('input[type=checkbox]:first').change()
            ;
          }
        });

        // Add link to the page for each set of checkboxes.
        selected
          .addClass('bef-processed')
          .each(function(index) {
            // Clone the link prototype and insert into the DOM
            var newLink = link.clone(true);

            newLink.insertBefore($('.bef-checkboxes, .bef-tree', this));

            // If all checkboxes are already checked by default then switch to Select None
            if ($('input:checkbox:checked', this).length == $('input:checkbox', this).length) {
              newLink.click();
            }
          })
        ;
      }

      // Add highlight class to checked checkboxes for better theming
      $('.bef-tree input[type="checkbox"], .bef-checkboxes input[type="checkbox"]')
        // Highlight newly selected checkboxes
        .change(function() {
          _bef_highlight(this, context);
        })
        .filter(':checked').closest('.form-item', context).addClass('highlight')
      ;

      // Check for and initialize datepickers
      if (Drupal.settings.better_exposed_filters.bef_datepicker && $.fn.datepicker) {
        // Note: JavaScript does not treat "" as null
        if (Drupal.settings.better_exposed_filters.bef_dateformat) {
          $('.bef-datepicker').datepicker({
            dateFormat: Drupal.settings.better_exposed_filters.bef_dateformat
          });
        }
        else {
          $('.bef-datepicker').datepicker();
        }
      }

    }                   // attach: function() {
  };                    // Drupal.behaviors.better_exposed_filters = {

  Drupal.behaviors.better_exposed_filters_select_as_links = {
    attach: function(context) {
      $('.bef-select-as-links', context)
        .once('bef-select-as-links')
        .find('.form-type-bef-link a').click(function (event) {
          event.preventDefault();
          event.stopPropagation();

          var $link = $(this);
          var $linkWrapper = $link.closest('.form-type-bef-link');

          var $setWrapper = $linkWrapper.closest('.bef-select-as-links');
          var $hiddenElement = null;
          if ($setWrapper.hasClass('bef-select-as-links-multiple')) {
            // Toggle state of the individual hidden element for the clicked link.
            $hiddenElement = $('#' + ($linkWrapper.attr('id'))  + '-hidden');

            if ($hiddenElement.attr('disabled')) {
              $hiddenElement.attr('disabled', false);
              $linkWrapper.addClass('selected');
            }
            else {
              $hiddenElement.attr('disabled', true);
              $linkWrapper.removeClass('selected');
            }
          }
          else {
            // Set state and value of the single hidden element for the filter.
            $hiddenElement = $('#' + ($setWrapper.closest('.views-exposed-widget').attr('id').replace('-wrapper', '')) + '-hidden');

            if ($setWrapper.hasClass('bef-select-as-links-toggle')) {
              if (!$linkWrapper.hasClass('selected')) {
                $setWrapper.find('.form-type-bef-link').removeClass('selected');
                $linkWrapper.addClass('selected');
              }
              var sort_key = $link.data('bef-select-as-links-toggle-key');
              var sort_dir = $link.data('bef-select-as-links-toggle-dir');
              $hiddenElement.attr('value', sort_key + ' ' + sort_dir);

              // Update the link's text, href, and direction data attribute.
              var new_sort_dir = (sort_dir == 'ASC') ? 'DESC' : 'ASC';
              $link.html(
                  Drupal.settings.better_exposed_filters['select-as-links-toggle'][sort_key]['label'] +
                  ' ' +
                  Drupal.settings.better_exposed_filters['select-as-links-toggle'][sort_key][new_sort_dir]
                );
              $link.attr('href', $link.attr('href').replace(sort_key + '%20' + sort_dir, sort_key + '%20' + new_sort_dir));
              $link.data('bef-select-as-links-toggle-dir', new_sort_dir);
            }
            else {
              if ($linkWrapper.hasClass('selected')) {
                $setWrapper.find('.form-type-bef-link').removeClass('selected');
                $hiddenElement.attr('value', '');
                $hiddenElement.attr('disabled', true);
              }
              else {
                $setWrapper.find('.form-type-bef-link').removeClass('selected');
                $hiddenElement.attr('value', $link.data('bef-select-as-links-value'));
                $hiddenElement.attr('disabled', false);
                $linkWrapper.addClass('selected');
              }
            }
          }

          var $form = $hiddenElement.closest('form');
          // @see ctools/js/auto-submit.js
          if ($form.hasClass('ctools-auto-submit-full-form')) {
            $form.find('.ctools-auto-submit-click').click();
          }
        });
    }
  };

  /*
   * Helper functions
   */

  /**
   * Adds/Removes the highlight class from the form-item div as appropriate
   */
  function _bef_highlight(elem, context) {
    $elem = $(elem, context);
    $elem.attr('checked')
      ? $elem.closest('.form-item', context).addClass('highlight')
      : $elem.closest('.form-item', context).removeClass('highlight');
  }

}) (jQuery);
