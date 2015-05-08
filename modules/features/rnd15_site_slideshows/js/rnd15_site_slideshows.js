/**
 * Slideshow
 * - this javascript provide custom function to work with flexslider
 * - preload images function rely on /themes/custom/rnd15/js/overrides/rnd15.picturefill.js
 */

(function($) {

  Drupal.behaviors.rnd15_sites_slideshows = {
    attach: function (context) {
      $('.slideshow:not(.slideshow--preload-images)', context).addClass('slideshow--preload-images').each(function() { 
        picturefill();  
      });
    }
  }; /* - end behaviors - */

})(jQuery);