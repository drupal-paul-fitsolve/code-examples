(function($, Drupal, undefined){
  /**
   * When set to enable mediaelement for all audio/video files add it to the page.
   */
  Drupal.behaviors.cr_video = {
    attach: function(context, settings) {

      if (settings.cr_video_mediaelement !== undefined) {
        // @todo Remove anonymous function.
        $.each(settings.cr_video_mediaelement, function(selector, options) {
          var opts;
          $('.cr-mediaelement-video').on("click", function () {

            // Show Videoplayer markup
            $(selector, this).once('mediaelement', function () {

              var containerWidth = $(context).find('.cr-mediaelement-video').width();
              var containerHeight = $(context).find('.cr-mediaelement-video').height();

              if (options.controls) {

                options.videoWidth = containerWidth;
                options.videoHeight = containerHeight;

                // Hide startframe
                $(this).parent().find('.cr_video_layer').hide();

                // Setup success callback. Hide image when video success event fires
                options.success = function (mediaElement, domNode) {

                  // If colorbox, resize
                  $(context).find("#colorbox").colorbox.resize();
                  /*
                    This is a bug in MediaElementJS, autoplay works for native and silverlight, but needs a little help with Flash.
                    You can listen for canPlay event and start playing as soon as the flash player is ready.
                    http://stackoverflow.com/questions/5394109/autoplay-mediaelementplayer
                  */
                  if (mediaElement.pluginType === 'flash') {

                    mediaElement.addEventListener('canplay', function () {
                      // Player is ready
                      mediaElement.play();
                    }, false);

                  }

                };

                // Bind mediaplayer to video tag with matching selector
                $(selector).mediaelementplayer(options);

              } else {
                $(this).mediaelement();
              }

            });

          });

        });
      }
      // The global option is seperate from the other selectors as it should be
      // run after any other selectors.
      if (settings.mediaelementAll !== undefined) {
        $('video,audio', context).once('mediaelement', function() {
          $(this).mediaelementplayer();
        });
      }
    }
  };

})(jQuery, Drupal);
