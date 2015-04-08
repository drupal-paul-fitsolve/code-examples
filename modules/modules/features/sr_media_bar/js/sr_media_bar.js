/*
 * @file
 * JavaScript for sr_media_bar js.
 * Resize colourbox content on event cbox_complete
 */

(function($) {

  Drupal.behaviors.srMediaBarColourBox = {
    attach: function(context, settings) {
      // Only fire on media bar
      var $found = $(context).find('.colorbox-container, .view-mode-colorbox');
      if($found.length == 1){

        // Delay resize due to DOM calculating height before image loaded
        // Cannot use cbox_complete event because colorbox node fires another ajax request
        // through Drupal.ajax, meaning none of the colorbox api methods are useful to us.
        // Extremely frustrating!
        setTimeout(function() {

          // if media-images
          if($(context).find('.node-media-images').length == 1){
            // Get the dimensions of the images
            imgHeight = $(context).find('.colorbox--top img').attr('height');
            imgWidth = $(context).find('.colorbox--top img').attr('width');

            // Calculate the orientation of the image, and also calulate the image ratio for later
            if(imgHeight > imgWidth){
              imgType = 'portrait';
              imgRatio = new Array(imgWidth/imgHeight, 1);
            }else{
              imgType = 'landscape';
              imgRatio = new Array(1, imgHeight/imgWidth);
            }

            // Get the max dimensions we want to display (using grid system as a base)
            // Remember that text will appear below the image
            maxWidth = $('.grid-16').width()/1.3;
            maxHeight = maxWidth;

            // Based on orientation, calculate the newDimensions for the image
            if(imgType === 'landscape'){
              newDimensions = new Array(Math.round(maxWidth), Math.round(maxWidth*imgRatio[1]));
            }else{
              newDimensions = new Array(Math.round(maxHeight*imgRatio[0]), Math.round(maxHeight));
            }
            // Set the width of the colorbox and the width/height if the actual img
            $.colorbox.resize(options = {innerWidth: newDimensions[0]});
            $('.colorbox--top img').attr('height',newDimensions[1]).attr('width',newDimensions[0]).height(newDimensions[1]).width(newDimensions[0]);
          }
          // if video
          else{
            var gW = $('.grid-16').width();
            $.colorbox.resize(options = {innerWidth: gW});
          }
        } ,500);

        setTimeout(function() {
          $.colorbox.element().show();
        } ,2000);

      }
    }
  }

})(jQuery);
