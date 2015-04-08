(function ($) {

  /*
  * This is accordion to be run on mobile only
  * - this is for tabs printed with views - TG
  */
  $.fn.viewsAccordion = function( context, deviceGroup) {
    $.fn.viewsAccordion.context = context;
    $.fn.viewsAccordion.deviceGroup = deviceGroup;

    $.fn.viewsAccordion.init(this, context, function() {
      $.fn.viewsAccordion.mobile(context);
    });

  };

  // Define our init function.
  $.fn.viewsAccordion.init = function( accordionContainer, context, callback ) {
    $.fn.viewsAccordion.viewsAccordion = $(accordionContainer);
    $.fn.viewsAccordion.list = $('ul', accordionContainer);
    $.fn.viewsAccordion.listItem = $('li:not(li ul li)', $.fn.viewsAccordion.list);

    if(typeof callback == 'function') {
      callback();
    }
  }

  $.fn.viewsAccordion.mobile = function( context ) {

    // Set up markup for accordion
    var i = 0;
    $.fn.viewsAccordion.listItem.each(function(){
      i++;
      var tabTitle = $('.pod__title', $(this)).text();
      if(i == 1) $(this).addClass('is-open');
      $(this).children('div').wrapAll('<div class="accordion-content"></div>')
      $(this).prepend('<div class="accordion-title"><p>' + tabTitle + '</p></div>')

    });

    // Animate the accordion
    $('.accordion-title').on('click', function (event) {
          var open = $(this).parent('li').hasClass('is-open');
          if(open) {
            $(this).parent('li').removeClass('is-open');
          }
          if(!open) {
            $.fn.viewsAccordion.listItem.each(function(){$(this).removeClass('is-open');});
            $(this).parent('li').addClass('is-open');
          }
        });

  }

})(jQuery);