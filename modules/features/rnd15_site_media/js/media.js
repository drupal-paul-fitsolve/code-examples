/*!
 * jQuery MediaElementJS Wrapper for rnd15
 * 
 * @author Jeremy P.
 * @date 9 Jan 2015
 */
;(function ( $ ) {

  // Create the plugin name and defaults once
  var pluginName = "mediaVideo",
      defaults = {
        played : 0,
        type : 'inline',
        rowSelector : '.cr-content-region',
        mediaElementOptions: {
          // Always show controls even if cursor is not over video
          alwaysShowControls : false,
          // force iPad's native controls
          iPadUseNativeControls: true,
          // force iPhone's native controls
          iPhoneUseNativeControls: true,
          // force Android's native controls
          AndroidUseNativeControls: true,
          plugins : ['youtube'],
          // Prevent the video from looping
          loop: false,
          // These are the youtube player vars, specific vars we can pass into the iframe
          youTubePlayerVars : {autoplay: 1, loop: 0, modestbranding: 1, playsinline: 0, showinfo: 0}
        }
      };

  // The actual plugin constructor
  function Plugin( element, options ) {
    this.$element = $(element);

    /**
     * jQuery has an extend method that merges the
     * contents of two or more objects, storing the
     * result in the first object. The first object
     * is generally empty because we don't want to alter
     * the default options for future instances of the plugin
     */
    this.options = $.extend( {}, defaults, options) ;

    this._defaults = defaults;
    this._name = pluginName;

    this.init();
  }

  Plugin.prototype = {

    /**
     * Initialization logic here
     * We have access to the DOM element and
     * the options via the instance, e.g. this.$element
     * and this.options
     * you can add more functions like the one below and
     * call them like so: this.yourOtherFunction(this.$element, this.options).
     */
    init: function() {

      /**
       * Declare properties
       */
      this.youTubeUrl = this.$element.attr('href');
      this.videoId = this.youTubeUrl ? youtube_parser(this.youTubeUrl) : '';
      this.cssRowId = 'media-video-' + this.videoId + '-' + Math.floor(Math.random() * 10000);

      /**
       * Cache the elements we need to use
       */
      this.$videoElement = $('video', this.$element);

      /**
       * Remove controls from video tag and change height to fix iPad issue that 'steal' our click events
       */
      if(this.$videoElement.length) {
        this.$videoElement.removeAttr('controls').height(0).attr('height','0');
      }

      /**
       * Handle logic for different types of players
       */
      switch (this.options.type) {
        case 'row':
          this.setupPlayerInRow();
        break;
        case 'inline':
          this.$startFrame = $('span[data-picture]', this.$element);
          this.$playButton = $('.media-video__overlay-button', this.$element);
        break;
      }

      /**
       * Add our main click event handler that triggers the player
       */
      this.$element.on('click', {plugin:this}, this.handleElementClick);
    },
    
    /**
     * Initialise the player
     */
    initPlayer: function() {
      var plugin = this;

      /**
       * Add attributes back in case we have removed them
       */
      plugin.$videoElement.attr('controls', 'controls').height('100%').attr('height', '100%');

      /**
       * Suppress any automatic interactions on the site to help performance
       */
      plugin.suppressAutoInteractions();

      /**
       * Handle logic for different types of players
       */
      switch (plugin.options.type) {
        case 'inline':
          plugin.hideStartFrame();
        break;
        case 'row':
          plugin.displayPlayerInRow();
        break;
      }

      /**
       * Make sure we pass in the success handler to the MEJS options
       */
      plugin.options.mediaElementOptions.success = plugin.mediaElementJsSuccess;

      /**
       * Instantiate the mediaelementplayer and assign to plugin.player if it does not exist
       */
      if(typeof plugin.player == 'undefined') {

        plugin.$videoElement.mediaelementplayer(plugin.options.mediaElementOptions);

        plugin.player = plugin.$videoElement[0].player;
      }
    },

    /**
     * MEJS Success Handler
     * Allows us to add custom 'fake' events as per MEJS scripts once player has initialised
     */
    mediaElementJsSuccess: function (mediaElement, domObject) {
      /**
       * Specificlayly Track all the events so we can 
       * pass them to GTM's dataLayer
       */
      mediaElement.addEventListener('loadedmetadata', mediaTrackVideo, false);
      mediaElement.addEventListener('play', mediaTrackVideo, false);
      mediaElement.addEventListener('playing', mediaTrackVideo, false);
      mediaElement.addEventListener('pause', mediaTrackVideo, false);
      mediaElement.addEventListener('ended', mediaTrackVideo, false);
      mediaElement.addEventListener('timeupdate', mediaTrackVideo, false);
    },

    /**
     * Suppress any automatic interactions on the site
     */
    suppressAutoInteractions: function() {
      /**
       * Pauses all Flexslider Slideshows
       */
      if(typeof Drupal.settings.flexslider !== 'undefined' && typeof Drupal.settings.flexslider.instances !== 'undefined') {
        /**
         * Loop through the instances and use the instance name + hash to find the flexslider and pause it
         */
        for(var instanceName in Drupal.settings.flexslider.instances) {
          if (typeof $('#'+instanceName).flexslider == 'undefined') return;
          $('#'+instanceName).flexslider('pause');
        }
      }
    },

    /**
     * Helper functions for the player
     */
    
    /**
     * Hide the start frame and it's play button
     */
    hideStartFrame: function() {
      var plugin = this;

      /**
       * Hide the start frame if it exists
       */
      if(plugin.$startFrame.length) {
        plugin.$startFrame.add(plugin.$playButton).hide();
      }
    },

    /**
     * Hide the start frame and it's play button
     */
    setupPlayerInRow: function() {
      var plugin = this;

      /**
       * Check if we have an existing player, if not create one on the fly
       */
      var $rows = plugin.$element.parents(plugin.options.rowSelector);
      plugin.$row = $($rows[$rows.length - 1]);

      /**
       * Get the YouTube URL
       */
      var youTubeUrl = plugin.$element.attr('href');

      var closeButton = '<button class="media-video-row__btn-close btn icon icon--large icon-close-cross"><span>Close</span></button>';

      /**
       * We dynamically insert the markup to make our video work in the row
       */
      var videoElement = '<div class="media-video">' +
      '<div class="media-video__content mejs-wrapper">' +
        closeButton +
        '<video width="100%" height="100%">' +
          '<source type="video/youtube" src="' + youTubeUrl + '">' +
        '</video>' +
      '</div></div>';

      /**
       * Prepend the markup to the row
       */
      plugin.$row
        .prepend('<div class="media-video-row__wrapper" id="' + plugin.cssRowId + '">' +
          '<div class="container media-video-row__container">' +
          '<div class="row media-video-row media-video-row--vertically-centred"><div class="col-xs-12 media-video-row__pane">' + videoElement + '</div></div>' +
          '</div>' +
          '<div class="media-video-row__bg"></div>' +
        '</div>');

      /**
       * Cache the references so we can apply event handlers and further work with these elements
       */
      plugin.$mediaVideoRowWrapper = $('#' + plugin.cssRowId + '.media-video-row__wrapper', plugin.$row);
      plugin.$videoElement = $('video', plugin.$mediaVideoRowWrapper);
      plugin.$mediaVideoRowBackground = $('.media-video-row__bg', plugin.$mediaVideoRowWrapper);
      plugin.$mediaVideoRowCloseButton = $('.media-video-row__btn-close', plugin.$mediaVideoRowWrapper);
    },

    /**
     * Display the Player In Row
     */
    displayPlayerInRow: function() {
      var plugin = this;

      /**
       * Ensure we suppress any auto playing of slideshows
       */
      plugin.suppressAutoInteractions();

      /**
       * Add class to show the background and video markup
       */
      plugin.$mediaVideoRowWrapper.addClass('media-video-row__wrapper--visible');

      /**
       * Add Event Handlers
       */
      plugin.$mediaVideoRowBackground.on('click', {plugin:plugin}, plugin.handleBackgroundClick);
      plugin.$mediaVideoRowCloseButton.on('click', {plugin:plugin}, plugin.handleCloseButtonClick);
      $(document).on('mediaelementjs.before.enterfullscreen', plugin.handleMeJSEnterFullScreen);
      $(document).on('mediaelementjs.before.exitfullscreen', plugin.handleMeJSExitFullScreen);
    },

    /**
     * Hide the start frame and it's play button
     */
    hidePlayerInRow: function() {
      var plugin = this;

      /**
       * Remove class to show the background and video markup
       */
      plugin.$mediaVideoRowWrapper.removeClass('media-video-row__wrapper--visible');

      /**
       * Remove Event Handlers
       */
      plugin.$mediaVideoRowBackground.off('click', plugin.handleBackgroundClick);
      plugin.$mediaVideoRowCloseButton.off('click', plugin.handleCloseButtonClick);
      $(document).off('mediaelementjs.before.enterfullscreen', plugin.handleMeJSEnterFullScreen);
      $(document).off('mediaelementjs.before.exitfullscreen', plugin.handleMeJSExitFullScreen);

      /**
       * Pause the Player
       */
      plugin.player.pause();
    },

    /**
     * Event handler to respond to the click event on the element (Start frame or link)
     * @param  {object} e [click event object]
     */
    handleElementClick: function(e) {
      e.data.plugin.initPlayer();
      e.preventDefault();
    },

    /**
     * Event handler for row background
     * @param  {object} e [click event object]
     */
    handleBackgroundClick: function(e) {
      e.data.plugin.hidePlayerInRow();
      e.preventDefault();
    },

    /**
     * Event handler for row close button
     * @param  {object} e [click event object]
     */
    handleCloseButtonClick: function(e) {
      e.data.plugin.hidePlayerInRow();
      e.preventDefault();
    },

    /**
     * Handles the MEJS enter fullscreen event
     * Fixes an issue that is caused by vertically centering the video
     * @param  {[type]} e [description]
     */
    handleMeJSEnterFullScreen: function(e) {
      if(typeof e.mejs == 'undefined') return;
      $(e.mejs.container)
        .parents('.media-video-row')
        .removeClass('media-video-row--vertically-centred');
    },

    /**
     * Handles the MEJS exit fullscreen event
     * Fixes an issue that is caused by vertically centering the video
     * @param  {[type]} e [description]
     */
    handleMeJSExitFullScreen: function(e) {
      if(typeof e.mejs == 'undefined') return;
      $(e.mejs.container)
        .parents('.media-video-row')
        .addClass('media-video-row--vertically-centred');
    }
  };

  /*
   * A really lightweight plugin wrapper around the constructor,
   * protecting against multiple instantiations 
   */
  $.fn[pluginName] = function ( options ) {
      return this.each(function () {
        if (typeof options === "string") {
            var args = Array.prototype.slice.call(arguments, 1),
                plugin = $.data(this, 'plugin_' + pluginName);
            plugin[options].apply(plugin, args);
        } else if (!$.data(this, 'plugin_' + pluginName)) {
              $.data(this, "plugin_" + pluginName,
              new Plugin( this, options ));
          }
      });
  };
})( jQuery );

/**
 * Track Video Helper Function
 */
var mediaTrackVideo = function(e) {
  if (!dataLayer) return;

  var YT = e.target.pluginApi; // Youtube Object
  var video_data = YT["getVideoData"]();
  var label = video_data.video_id+':'+video_data.title;
  var action = e.type;

  switch(e.type) {
    /**
     * Track the play event
     */
    case 'play':
      // Increment the playCount
      e.target.playCount = typeof e.target.playCount === 'undefined' ? 0 : e.target.playCount + 1;
      // Track the first time play was triggered
      if(e.target.playCount === 0) {
        action = 'playfirst';
      }
    break;
    /**
     * Track when certain playtimes have been met
     * e.g. 0%, 25%, 50%, 75% and 100%
     */
    case 'timeupdate':
      var t = YT["getDuration"]() - YT["getCurrentTime"]() <= 1.5 ? 1 : (Math.floor(YT["getCurrentTime"]() / YT["getDuration"]() * 4) / 4).toFixed(2);
      if (!YT["lastP"] || t > YT["lastP"]) {
        YT["lastP"] = t;
        action = t * 100 + "%";
      } else {
        // Skip, if we have not met a major milestone
        return;
      }
    break;
  }

  var videoEvent = {
    event: "rnd15.video",
    label: label,
    action: action,
    mejs: e.target,
    youtubeObject: YT
  };

  // Push the event object to the dataLayer
  dataLayer.push(videoEvent);
};

/**
 * Helper function to get the YouTube Video ID
 * http://stackoverflow.com/questions/3452546/javascript-regex-how-to-get-youtube-video-id-from-url
 */
function youtube_parser(url){
  var regExp = /^.*((youtu.be\/)|(v\/)|(\/u\/\w\/)|(embed\/)|(watch\?))\??v?=?([^#\&\?]*).*/;
  var match = url.match(regExp);
  if (match&&match[7].length==11){
      return match[7];
  }else{
      if(typeof console.log !== 'undefined') {
        console.log('Could not retrieve Video ID from YouTube URL');
      }
  }
}