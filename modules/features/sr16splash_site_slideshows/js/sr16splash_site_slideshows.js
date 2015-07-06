/**
 * Slideshow
 * - this javascript provide custom function to work with flexslider
 * - preload images function rely on /themes/custom/sr16splash/js/overrides/sr16splash.picturefill.js
 */

(function($) {

  Drupal.behaviors.sr16splash_sites_slideshows = {
    attach: function (context) {
      $('.slideshow:not(.slideshow--preload-images)', context).addClass('slideshow--preload-images').each(function() { 
        picturefill();  
      });
    }
  }; /* - end behaviors - */

})(jQuery);