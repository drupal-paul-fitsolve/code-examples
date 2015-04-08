/**
 * @file
 * Adds an 'is-active' class to the target of the href.
 * Example: call $('element').activateTarget() to attach the click action.
 */

(function ($) {

  $.fn.activateTarget = function(options,callback) {
    // This is the easiest way to have default options.
    var settings = $.extend({
        activeClass: 'is-active',
        targetAttribute: 'href',
    }, options );

    return this.on('click',function(event) {
      event.preventDefault();
      event.stopPropagation();
      var target = $(this).attr(settings.targetAttribute);
      $(target).toggleClass(settings.activeClass);
      if(typeof callback !== "undefiend") {
        callback(target);
      }
    });

  };

})(jQuery);
