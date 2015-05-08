(function ($) {
  /**
   * JS for rnd15 Google Tag Manager
   *
   * Author: J.Pitt
   * Contributors: -
   * 
   * Last update: 31st August 2014
   * 
   * Description & additional notes:
   * - Tracks breakpoint
   * - Tracks touch or non touch
   *
   */

  Drupal.behaviors.rnd15gtm = {

    attach: function (context, settings) {
      var _base = Drupal.behaviors.rnd15gtm;

      if(settings.ajaxPageState && settings.ajaxPageState.theme == 'rnd15'){
        // Setup the menu, passing in the relevant context
        $('html').once('rnd15GTM', _base.setupDataLayer);
      }
    },

    /**
     * Sets up the touch menu
     *
     * - Declares the menu wide objects required and caches them
     * - Enables responsive touch so the menu works from non-touch to touch and vice versa
     * - Provides a debug mode (append ?touch=true/false to test the menu)
     * - Checks if we are on a touch device OR on XS/SM breakpoint
     * - Sets up the menu with some data attributes so we can nicely animate it
     * - 
     * @param  {[type]} context [description]
     * @return {[type]}         [description]
     */
    setupDataLayer : function() {
      var _base = Drupal.behaviors.rnd15gtm;

      // Track the current breakpoint
      _base.trackBreakpoints();

      // Track the Touch devices
      _base.trackTouch();
    },
    /**
     * Handle the Breakpoints
     * 
     * Register relevant JS media query handles
     */
    trackTouch: function() {
      var _base = Drupal.behaviors.rnd15gtm;
      if(typeof Modernizr == 'undefined') return;

      var touchString = String(Modernizr.touch);
      dataLayer.push({event: 'rnd15.touch', hasTouch:touchString});
    },

    /**
     * Handle the Breakpoints
     * 
     * Register relevant JS media query handles
     */
    trackBreakpoints: function() {
      var _base = Drupal.behaviors.rnd15gtm;

      // Skip if we do not have enquire loaded
      if(typeof enquire == 'undefined') return;

      // We use the exception handler in case enquire.js is not available
      try {
        // Attach enquire JS events
        enquire
          .register(Drupal.settings.crl2.breakpoints.xs, {
            match : _base.trackActiveBreakpoint
          })
          .register(Drupal.settings.crl2.breakpoints.sm, {
            match : _base.trackActiveBreakpoint
          })
          .register(Drupal.settings.crl2.breakpoints.md, {
            match : _base.trackActiveBreakpoint
          }, true)
          .register(Drupal.settings.crl2.breakpoints.lg, {
            match : _base.trackActiveBreakpoint
          });
      }
      catch(err) {
        // Output the error
        if (window.console) {
          console.log(err);
        }
      }
    },

    /*
     * Helper function to track the current breakpoint
     */
    trackActiveBreakpoint: function() {
      var _base = Drupal.behaviors.rnd15gtm;
      var breakpointEvent = {};
      var activeBreakpointString = String(Drupal.settings.crl2.breakpointActive);

      if(Drupal.settings.crl2.breakpointFrom === null) {
        breakpointEvent.event = 'rnd15.breakpoint';
        breakpointEvent.breakpoint = activeBreakpointString;
      } else {
        var fromBreakpointString = String(Drupal.settings.crl2.breakpointFrom);
        breakpointEvent.event = 'rnd15.breakpointSwitch';
        breakpointEvent.breakpointFrom = fromBreakpointString;
        breakpointEvent.breakpointTo = activeBreakpointString;
      }
      
      dataLayer.push(breakpointEvent);
    }

  };
})(jQuery);