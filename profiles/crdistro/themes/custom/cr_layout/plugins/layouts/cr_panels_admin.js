(function ($) {
  Drupal.behaviors.cr_panels_admin = {
    attach: function (context, settings) {
      console.log("test1");
      // Trigger drupal behaviour here so it's redone whenever Dom is changed
    	$('.panels-ipe-editing #panels-rows .row').each(function(){
    		console.log("test2");
    	});
    }
  };
}(jQuery));