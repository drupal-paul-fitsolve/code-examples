(function ($) {

  /**
   * Author: Andy E. Phipps
   * Last update: 30th September 2014
   *
   * Simple function to prevent the clickable '#' anchor
   * on the front of the flipcard from scrolling to the top
   * of the page on touch devices.
   *
   * This anchor isn't clickable on desktop devices
   * due to hover state animation it uses, so this bug
   * doesn't exist on this breakpoint.
   *
   * - This script relies on:
   * -- Modernizr
   */

  Drupal.behaviors.panelTransitionsFlip = {

    defaults : {
      flipClass: '.transition-flip--tool',
      isTouch : false
    },

    attach: function (context, settings) {

      var _base = Drupal.behaviors.panelTransitionsFlip;

      var default_settings = Drupal.settings.panelTransitionsFlip ? Drupal.settings.panelTransitionsFlip : {};
      Drupal.settings.panelTransitionsFlip = $.extend(default_settings, _base.defaults);

      _base.setupSupressClick(context);
    },

    /* Sets-up the page for the surpressClick functionality, ensuring that the device is
     * touch-enabled and that the fliptools are present. */
    setupSupressClick  : function (context) {

      var _base = Drupal.behaviors.panelTransitionsFlip;
      var _settings = Drupal.settings.panelTransitionsFlip;

      // Determine if we're using a touch device or not
      _settings.isTouch = (typeof Modernizr !== 'undefined') && Modernizr.touch;

      // Check that the device is touch-enabled.. if not, exit the function
      if (!_settings.isTouch) return;

      // Runs supressClick function *only* on the anchor element on the .front of fliptools
      $(_settings.flipClass + ' .front a', context).once('suppressClick').on('click', _base.suppressClick);
    },


    /* Just runs a preventDefault when the user 'clicks' the front of the flipcard to stop
    * the undesirable 'scroll-to-top' but still maintaining the fliptool functionality and animation */
    suppressClick : function (e) {
      e.preventDefault();
    }
  };
})(jQuery);