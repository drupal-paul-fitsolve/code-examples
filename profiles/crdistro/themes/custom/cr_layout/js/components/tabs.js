(function ($) {

/**
 * JS related to the tabs in the Panels tabs.
 */
Drupal.behaviors.panelsTabs = {
  attach: function (context) {
    if (Drupal.settings.panelsTabs.style === "side") {
      var direction = "vertical";
    }
    else {
      var direction = "horizontal";
    }
    $('.js-tabs').flexslider({
      namespace: "tabs-",
      selector: ".tab-contents > .tab-content",
      directionNav: false,
      manualControls: ".js-tabs .tab-link",
      animation: Drupal.settings.panelsTabs.transition,
      animationSpeed: 400,
      useCSS: true,
      direction: direction,
      slideshow: false,
      animationLoop: false,
      startAt: parseInt(Drupal.settings.panelsTabs.open_tab),
    });
  }
};

})(jQuery);
