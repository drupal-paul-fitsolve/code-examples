 /**
  * @file
  * An example file for a jQuery plugin
  * This file contains the functionality, where and when it gets run can be defined by main.js
  */

(function ($) {

  $.fn.examplePlugin = function(options) {
    // This is the easiest way to have default options.
    var settings = $.extend({
        // These are the defaults.
        color: "#556b2f",
        backgroundColor: "white"
    }, options );

    return this.each(function() {
        // Do something to each element here.
        $( this ).css('color': settings.color, 'background-color:': settings.backgroundColor);
    });

  };

})(jQuery);
