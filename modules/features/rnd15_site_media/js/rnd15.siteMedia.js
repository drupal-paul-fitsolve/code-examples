(function ($) {

  /**
   * Behaviour for the rnd15 Site Media Element
   *
   * @author J.Pitt
   * @date 27 Oct 2014
   * 
   * Contributors: -
   * 
   * Description & additional notes:
   * - Integrates the media.js jquery plugin with rnd15 site
   * - It simply initiates the mediaVideo on every video element
   * - For more info, please check out the media.js file
   * - Video instances stored in Drupal.settings.rnd15siteMedia
   */
  Drupal.behaviors.rnd15siteMedia = {

    defaults : {
      triggerElements : {
        startFrames: '.media-video',
        playInRowLinks: '.media-video--play-in-row'
      },
      instances : []
    },

    attach: function (context, settings) {
      var _base = Drupal.behaviors.rnd15siteMedia;
      
      Drupal.settings.rnd15siteMedia = Drupal.settings.rnd15siteMedia || {};

      /**
       * Setup all inline videos
       */
      $('body', context).once('media-video', this.setupMedia);
    },
    setupMedia: function(context) {
      var _base = Drupal.behaviors.rnd15siteMedia;

      // Check if we even have the mediaVideo Loaded
      if(!$.fn.mediaVideo) {
        return;
      }

      /**
       * Extend the settings with the defaults.
       */
      Drupal.settings.rnd15siteMedia = $.extend({}, _base.defaults);

      /**
       * Cache Elements that trigger a video player in some shape or form
       * Videos & Play in Row links
       */
      var $videos = $(Drupal.settings.rnd15siteMedia.triggerElements.startFrames, context);
      var $links = $(Drupal.settings.rnd15siteMedia.triggerElements.playInRowLinks, context);

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
        Drupal.settings.rnd15siteMedia.instances.push(videoElement);
      };
      
      /**
       * Store Videos and Links
       */
      $.merge(videos, links);
      $.each(videos, storeInstance);
    }

  };
})(jQuery);