(function ($) {

  /**
   * Behaviour for the rnd15 Site Media Wall
   *
   * Author: J.Pitt
   * Contributors: -
   * 
   * Last update: 4th February 2015
   * 
   * Description & additional notes:
   * Simply adds negative bottom to captions based on paragraph height
   * 
   */
  Drupal.behaviors.rnd15siteMediaWall = {

    defaults : {
      baseClass : '.media-wall',
      captionElementClass: '.pane-media-wall__caption-content',
      paragraphElementClass: '.pane-media-wall__paragraph:visible',
      linkElementClass: '.pane-media-wall--link',
      $captions: null
    },

    attach: function (context, settings) {
      var _base = Drupal.behaviors.rnd15siteMediaWall;

      // Setup the panes media wall, passing in the relevant context
      $(_base.defaults.baseClass, context).once('rnd15siteMediaWall', function() {
        // Extend the current behaviour with default values
        Drupal.settings.rnd15siteMediaWall = $.extend({}, Drupal.settings.rnd15siteMediaWall, _base.defaults);

        // Setup the menu
        _base.setupPanesMediaWall(context);
      });
    },

    /**
     * Sets up the media wall panes
     */
    setupPanesMediaWall : function(context) {
      var _base = Drupal.behaviors.rnd15siteMediaWall;
      var _settings = Drupal.settings.rnd15siteMediaWall;

      // Skip lower than ie9 browsers
      _base.isLtIe9 = $('html', context).hasClass('lt-ie9');
      if(_base.isLtIe9) return;

      /**
       * Cache JS & jQuery Objects we require
       */
      _settings.$paragraphs = $(_settings.paragraphElementClass, context);
      _settings.$captions = $(_settings.captionElementClass, context);

      // Let's run the responsive captions which will take care of stuff for us
      _base.responsiveCaptions();

      // Setup Touch Captions
      _base.touchCaptions();
    },

    /*
     * Responsive Captions
     * Uses enquire js to trigger the responsive captions
     */
    responsiveCaptions : function() {
      var _base = Drupal.behaviors.rnd15siteMediaWall;
      var _settings = Drupal.settings.rnd15siteMediaWall;
    
      // We use the exception handler in case enquire.js is not available
      try {
        // Attach enquire JS events
        enquire
          .register(Drupal.settings.crl2.breakpoints.sm, {
            // Remove positions in case we go from SM to XS
            unmatch : _base.removeCaptionPositions,
            match : _base.updateCaptions
          })
          .register(Drupal.settings.crl2.breakpoints.md, {
            unmatch : _base.updateCaptions,
            match : _base.updateCaptions
          }, true)
          .register(Drupal.settings.crl2.breakpoints.lg, {
            unmatch : _base.updateCaptions,
            match : _base.updateCaptions
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
     * Touch Captions
     * Uses the rnd15_site_menu isTouchDevice check
     */
    touchCaptions : function() {
      var _base = Drupal.behaviors.rnd15siteMediaWall;
      var _settings = Drupal.settings.rnd15siteMediaWall;

      // If on touch, add a special click handler that shows the caption first
      if(typeof Drupal.settings.rnd15touchMenu !== 'undefined' && Drupal.settings.rnd15touchMenu.isTouchDevice) {
        
        // Skip if we are on the XS breakpoint
        if(typeof Drupal.settings.crl2.breakpointActive !== 'undefined' && Drupal.settings.crl2.breakpointActive === 'xs') return;

        _settings.$paragraphs
          .parents(_settings.linkElementClass)
          .once('touchCaptions')
          .on('click', _base.touchOnPane);
      }
    },

    /**
     * Click event handler for panes
     * Simply skips the first click :)
     */
    touchOnPane : function(e) {
      if(typeof this.clicked == 'undefined') {
        this.clicked = 1;
        e.preventDefault();
      }
    },

    /**
     * Loop through each caption and paragraph
     */
    updateCaptions : function() {
      var _settings = Drupal.settings.rnd15siteMediaWall;
      var _base = Drupal.behaviors.rnd15siteMediaWall;
      $.each(_settings.$paragraphs, _base.setCaptionPosition);
    },

    /**
     * Set each caption bottom negative to the paragraph height
     */
    setCaptionPosition : function(index, value) {
      var _settings = Drupal.settings.rnd15siteMediaWall;
      var paragraphHeight = this.offsetHeight;
      if(typeof paragraphHeight !== 'undefined') {
        this.parentNode.style.bottom = -paragraphHeight.toString() + 'px';
      }
    },

    /**
     * Loop through each caption and paragraph
     */
    removeCaptionPositions : function() {
      var _settings = Drupal.settings.rnd15siteMediaWall;
      var _base = Drupal.behaviors.rnd15siteMediaWall;
      $.each(_settings.$captions, _base.resetCaptionPosition);
    },

    /**
     * Set each caption bottom negative to the paragraph height
     */
    resetCaptionPosition : function(index, value) {
      this.style.bottom = '0px';
    }
  };
})(jQuery);