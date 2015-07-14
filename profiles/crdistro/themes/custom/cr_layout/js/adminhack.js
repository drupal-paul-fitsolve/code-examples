
/* The In Place Editor is rubbish so have to force
   resize on the browser to recalculate the equal heights - TG*/

(function($) {

    Drupal.behaviors.crEqualHeightsSidebar = {
      attach: function (context) {
        $('body', context).once('cr-equalheights', function () {

			// On click of customise this page, this allows the pods to resize
          $('#panels-ipe-customize-page', context).click(function(){
				$(document).ajaxStop(function() {
				   $(window).trigger("resize");
				});
		  });
        });
      }
    };
})(jQuery);