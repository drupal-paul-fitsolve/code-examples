// This check is duplicated across CR13, SR14 and now sr16splash themes
// PO asserted that this method of checking size onload provides
// more accurate assessment of platform than tracking resized breakpoints

(function ($) {
  Drupal.behaviors.emailSignupPlatformCheck = {
    attach: function (context) {
      // Ensure ESU and donate "platform" flags are set for "mobile" users.
      if ($(window).width() <= 740) {
        $('input[name="platform"]', context).val('mobile');
      }
    }
  };
})(jQuery);