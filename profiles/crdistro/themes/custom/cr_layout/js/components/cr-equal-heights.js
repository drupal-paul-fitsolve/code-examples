/**
 * @todo
 */

(function($) {
  /**
   * @todo
   */
  Drupal.behaviors.omegaEqualHeights = {
    attach: function (context) {
      $('body', context).once('omega-equalheights', function () {
        $(window).bind('resize.omegaequalheights', function () {
          $($('.equal-height-container').get().reverse()).each(function () {
            var elements = $(this).find('.equal-height-element').css('height', '');
            /* This second class is added to all columns to give them equal height
              it is run second to allow any internal equal height elements to be set - TG */
            var elements2 = $(this).find('.equal-height-element-two').css('height', '');

            if (Drupal.omega.getCurrentLayout() != 'mobile') {
              var tallest = 0;

              elements.each(function () {
                if ($(this).height() > tallest) {
                  tallest = $(this).height();
                }
              }).each(function() {
                $(this).css('height', tallest);
              });
              elements2.each(function () {
                if ($(this).height() > tallest) {
                  tallest = $(this).height();
                }
              }).each(function() {
                $(this).css('height', tallest);
              });
            }
          });
        }).load(function () {
          $(this).trigger('resize.omegaequalheights');
        });
      });
    }
  };

})(jQuery);
