/**
  * Fires off the dropkick JS to replace native dropdowns
  */

(function ($) {
  Drupal.behaviors.sr16splashDropKick = {
    attach: function (context, settings) {
      // Only run dropkick on touch devices where IPE is disabled.
      if($('html.touch body.panels-ipe', context).length) {
        return;
      }

      var $dropkick_element = $('select:not(.no-dropkick)', context);
      // Skip if dropkick is in modal
      if($dropkick_element.parents('.ctools-modal-content').length) {
        return;
      }

      //Need to check for ctools-modal as well, otherwise it does not fire at all when on a page with ipe
      $dropkick_element.attr('tabindex', 0).once('sr16splashDropKick').dropkick({
        startSpeed: 0, /* We dont actually want a delay here */
        change: function () {
  
          // Trigger change: new Dropkick update changes hidden native select when its Dropkick stand-in
          // is changed, but it doesn't register as changed. This is required by some code on the donate
          // page to show extra content, so we're having to do this for the time being.. -AP
          $('#' + this.data.select.id).trigger("change");

        }
      }).after('<span class="select__icon"></span>');
    }
  };
})(jQuery);

