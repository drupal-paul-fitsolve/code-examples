 /**
  * @file
  * Flip cards, AJAX load in content and spin them around.
  */

(function ($) {

  $.fn.flipCards = function(options) {

    var settings = $.extend({
      url : '',
      appendElement : this,
      wrapperClasses : 'flip-cards',
      groupSelect : '.flip-cards',
      closeButton: false,
      nav: '.people-helped',
    }, options );

    $(this).on('click', function(event) {
      event.preventDefault();
      event.stopPropagation();
      if($(this).hasClass("is-loading")) {
        return;
      }
      if( !$(this).hasClass("is-loaded") ) { // If this has not been clicked on before
        settings.target = this;
        $(this).flipCards.load(settings);
      }
      else if( $(this).hasClass("is-loaded") && $(this).hasClass("is-active") ) { // If loaded and open then close it.
        var attribute =  '[data-url="' + settings.url +'"]';
        $('.flip-cards' + attribute).fadeIn();
        $(this).removeClass("is-active");
      }
      else { // If loaded and closed then open it.
        var attribute =  '[data-url="' + settings.url +'"]';
        $(settings.groupSelect + attribute).fadeIn();
        $(this).addClass("is-active");
      }
    });

  };

  $.fn.flipCards.load = function(settings) {
    $(settings.target).addClass('is-loading');
    var $nav = $(settings.nav);
      $.ajax({
        url: settings.url,
        cache: true,
        context: this,
      }).done(function( html ) {
        // This is a bit of a hack to get the correct flexslider settings to apply.
        Drupal.settings.flexslider.optionsets.grid_12.animation = 'fade';
        html = $(html).find('#block-system-main').html();
        var output = '<div data-url="' + settings.url + '" class="' + settings.wrapperClasses + '"><button class="icon icon-close flip-cards__close">Close</button>' + html + '</div>';
        $(settings.groupSelect).fadeOut();
        Drupal.attachBehaviors($(output).appendTo(settings.appendElement).hide().fadeIn());
        $nav.removeClass('is-active is-loading');
        $(settings.target).addClass("is-active");
        $(settings.target).addClass("is-loaded");
        $(settings.nav).css('visibility', 'hidden');
        $(settings.appendElement).find('.flip-cards__close').on('click', function() {
          $(settings.groupSelect).fadeOut();
          $(settings.appendElement).find('.is-active').removeClass('is-active');
          $(settings.nav).css('visibility', 'visible');
        })
      });
  };

})(jQuery);
