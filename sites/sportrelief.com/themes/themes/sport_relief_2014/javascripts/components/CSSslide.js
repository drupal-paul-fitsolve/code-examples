 /**
  * @file
  * CSS Slide, slide up and down with CSS transitions
  * See: http://jsfiddle.net/adambiggs/MAbD3/
  *
  */

(function ($) {

  $.fn.CSSslide = function(options) {
    // This is the easiest way to have default options.
    var settings = $.extend({
        innerElement: $(this).find('.inner'),
        openClass: 'is-open',
        closedClass: 'is-closed'
    }, options );

    return this.each(function() {
        var content = $(this);

          content.toggleClass(settings.openClass + ' ' + settings.closedClass);
          content.contentHeight = content.outerHeight();

          if(content.hasClass(settings.closedClass)){

              // disable transitions & set max-height to content height
              content.removeClass('js-transitions').css('max-height', content.contentHeight);
              setTimeout(function(){

                  // enable & start transition
                  content.addClass('js-transitions').css({
                      'max-height': 0,
                      'opacity': 0
                  });

              }, 10); // 10ms timeout is the secret ingredient for disabling/enabling transitions
              // chrome only needs 1ms but FF needs ~10ms or it chokes on the first animation for some reason

          }else if(content.hasClass(settings.openClass)){

              content.contentHeight += settings.innerElement.outerHeight(); // if closed, add inner height to content height
              content.css({
                  'max-height': content.contentHeight,
                  'opacity': 1
              });

          }

         // css transition callback
        content.on('transitionEnd webkitTransitionEnd transitionend oTransitionEnd msTransitionEnd', function(e){
            if(content.hasClass(settings.openClass)){
                content.css('max-height', 9999); // try setting this to 'none'... I dare you!
            }
        });

    });

  };

})(jQuery);
