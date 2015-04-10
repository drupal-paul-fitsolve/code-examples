/**
 * @file
 * Scrolling interaction for the spend areas.
 */

(function ($) {

  Drupal.behaviors.sportrelief_2014.spendareas = function(context) {
    var spendAreas = $(context).find('.spend-area__section');
    if(spendAreas.length === 0 || $(window).width() <= 740) {
      return;
    }
    // @TODO destroy the event listener instead of returning false
    var pause = false;
    var endPoint = Drupal.behaviors.sportrelief_2014.spendareas.getEndPoint();
    var s = skrollr.init({
      beforerender: function(vars) {
        if(pause) {
          return false;
        }
        if(vars.curTop >= endPoint) {
          pause = true;
        }
      }
    });
    var appendElement = $('.spend-areas__header').filter(':visible');
    for (var i = spendAreas.length - 1; i >= 0; i--) {
      spendAreas[i].targetObject = $(spendAreas[i]).find('.spend-area__content');
      spendAreas[i].targetTitle = $(spendAreas[i]).find('.spend-area__section__title').text();
      $(appendElement).append(spendAreas[i].targetObject);
      $(spendAreas[i].targetObject).prepend('<h3>' + spendAreas[i].targetTitle + '</h3>');
      $(spendAreas[i]).on('click', function(event) {
        event.preventDefault();
        $('.spend-area__pound').addClass('is-active');
        $('.spend-area__content').removeClass('is-active');
        $(this.targetObject).addClass('is-active');
      });
    }
  };

  /**
   * Calculate the point when the scrolling animation will be complete, so we can kill it.
   * @return endPoint
   */
  Drupal.behaviors.sportrelief_2014.spendareas.getEndPoint = function() {
    var $lowestElement = $('.spend-area__section--third');
    var position = $lowestElement.offset();
    var positionTop = position.top;
    var viewportHeight = $(window).height();
    var endPoint = positionTop - (viewportHeight / 2) - 100;
    return endPoint;
  };

})(jQuery);
