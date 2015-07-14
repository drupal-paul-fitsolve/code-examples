(function ($) {

// Behavior to load FlexSlider
Drupal.behaviors.flexslider = {
  attach: function(context, settings) {
    var sliders = [];
    //Skip if we do not have flexslider instances
    if(!settings.flexslider) return;

    for (id in settings.flexslider.instances) {

      //Get current layout isnt called in time
      var wW = $(window).width();
      if(settings.flexslider.optionsets[settings.flexslider.instances[id]] !== undefined && 
         settings.flexslider.optionsets[settings.flexslider.instances[id]].disableMobile && wW <= 740) {
        return;
      }

      if (settings.flexslider.optionsets[settings.flexslider.instances[id]] !== undefined) {
        if (settings.flexslider.optionsets[settings.flexslider.instances[id]].asNavFor !== '') {
          // We have to initialize all the sliders which are "asNavFor" first.
          _flexslider_init(id, settings.flexslider.optionsets[settings.flexslider.instances[id]], context);
        }
        else {
          // Everyone else is second
          sliders[id] = settings.flexslider.optionsets[settings.flexslider.instances[id]];
        }
      }
    }
    // Slider set
    for (id in sliders) {
      _flexslider_init(id, settings.flexslider.optionsets[settings.flexslider.instances[id]], context);
    }
  }
};

/**
 * Initialize the flexslider instance
 */
function _flexslider_init(id, optionset, context) {
  $('#' + id, context).once('flexslider', function() {
    // Remove width/height attributes
    // @todo load the css path from the settings
    $(this).find('ul.slides > li > img').removeAttr('height');
    $(this).find('ul.slides > li > img').removeAttr('width');
    
    if (optionset) {
      $(this).flexslider(optionset);
    }
    else {
      $(this).flexslider();
    }
  });
}

}(jQuery));
