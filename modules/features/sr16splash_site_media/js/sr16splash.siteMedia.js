(function ($) {

  /**
   * Behaviour for the sr16splash Site Media Element
   *
   * @author J.Pitt
   * @date 27 Oct 2014
   * 
   * Contributors: -
   * 
   * Description & additional notes:
   * - Integrates the media.js jquery plugin with sr16splash site
   * - It simply initiates the mediaVideo on every video element
   * - For more info, please check out the media.js file
   * - Video instances stored in Drupal.settings.sr16splashsiteMedia
   */
  Drupal.behaviors.sr16splashsiteMedia = {

    defaults : {
      triggerElements : {
        startFrames: '.media-video',
        playInRowLinks: '.media-video--play-in-row'
      },
      instances : []
    },

    attach: function (context, settings) {
      var _base = Drupal.behaviors.sr16splashsiteMedia;
      
      Drupal.settings.sr16splashsiteMedia = Drupal.settings.sr16splashsiteMedia || {};

      /**
       * Setup all inline videos
       */
      $('body', context).once('media-video', this.setupMedia);
    },
    setupMedia: function(context) {
      var _base = Drupal.behaviors.sr16splashsiteMedia;

      // Check if we even have the mediaVideo Loaded
      if(!$.fn.mediaVideo) {
        return;
      }

      /**
       * Extend the settings with the defaults.
       */
      Drupal.settings.sr16splashsiteMedia = $.extend({}, _base.defaults);

      /**
       * Cache Elements that trigger a video player in some shape or form
       * Videos & Play in Row links
       */
      var $videos = $(Drupal.settings.sr16splashsiteMedia.triggerElements.startFrames, context);
      var $links = $(Drupal.settings.sr16splashsiteMedia.triggerElements.playInRowLinks, context);

      /**
       * Initiate inline videos
       */
      var videos = $videos
        .once('mediaVideo')
        .mediaVideo();

      /**
       * Initiate inline row video links
       */
      var links = $links
        .once('mediaVideo')
        .mediaVideo({type:'row'});

      /**
       * Store Instances
       */
      var storeInstance = function(index, videoElement) {
        Drupal.settings.sr16splashsiteMedia.instances.push(videoElement);
      };
      
      /**
       * Store Videos and Links
       */
      $.merge(videos, links);
      $.each(videos, storeInstance);
    }

  };
})(jQuery);