 /**
  * @file
  * Grid expander, allows google images style expanding via AJAX loading
  * This would be a lot simpler if it was easy to wrap the partner entity in a link containing the uuid.
  */

(function ($) {

  $.fn.gridExpander = function(options) {

    var settings = $.extend({
      url : '',
      appendElement : this,
      wrapperClasses : 'grid-expander',
      groupSelect : '.grid-expander',
      closeButton: false,
    }, options );

    $(this).on('click', function(event) {
      event.preventDefault();
      event.stopPropagation();
      if( !$(this).hasClass("is-loaded") && !$(this).hasClass("is-loading") ) { // If this has not been clicked on before
        settings.target = this;
        $(this).gridExpander.load(settings);
      }
      else if( $(this).hasClass("is-loaded") && $(this).hasClass("is-active") ) { // If loaded and open then close it.
        var attribute =  '[data-url="' + settings.url +'"]';
        $('.grid-expander' + attribute).slideUp();
        $(this).removeClass("is-active");
      }
      else { // If loaded and closed then open it.
        var attribute =  '[data-url="' + settings.url +'"]';
        $(settings.groupSelect).not(settings.groupSelect + attribute).slideUp();
        $(settings.groupSelect + '.is-active').removeClass('is-active');
        $(settings.groupSelect + attribute).slideDown();
        $(this).addClass("is-active");
      }
    });

  };

  $.fn.gridExpander.load = function(settings) {
    $(settings.target).addClass('is-loading');
      $.ajax({
        url: settings.url,
        cache: true,
        context: this
      }).done(function( html ) {
        // Issue, missing settings variable from Drupal
        html = $(html).find('#block-system-main').html();
        var output = '<div data-url="' + settings.url + '" class="' + settings.wrapperClasses + '">' + html + '</div>';
        $(settings.groupSelect).slideUp();
        Drupal.attachBehaviors($(output).appendTo(settings.appendElement).hide().slideDown());
        $(settings.appendElement).find('.is-active').removeClass('is-active');
        $(settings.target).addClass("is-active");
        $(settings.target).addClass("is-loaded");
        $(settings.target).removeClass('is-loading');
      });
  };

})(jQuery);
