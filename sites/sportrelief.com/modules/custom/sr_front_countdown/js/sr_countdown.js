// FlipClock unnecessarily repaints the page even if you turn seconds off.
// In future, its probably better to just turn seconds back on.

(function ($) {

  $(document).ready(function () {

    // Grab the current date
    var currentDate = new Date();

    // Find future date from data-future-timestamp from target div.
    var futureDate = $('.countdown').data('future-timestamp');

    // Calculate the difference in seconds between the future and current date
    var countdownTimeDiff = futureDate - currentDate.getTime() / 1000;

    // Sport Relief is here!
    // Display the graphic instead of initialising the FlipClock.
    if(countdownTimeDiff <= 0) {
      $('.countdown').html('<div class="front--sport_relief_is_here">Sport Relief is here!</div>');

      // Remove rendered/non-JS PHP countdown timer
      $('.countdown-offline').remove();

      // Return so that we do not load FlipClock etc.
      return;
    }

    // Decide if we should show seconds to the user.
    var showSeconds = false;

    // Only run countdown FlipClock on tablet/desktop and above
    if($(window).width() >= 768) {

      // Hide mobile/non-JS widget if we are showing the JS flip one.
      $('.countdown-offline').hide();

      // Initiate a countdown FlipClock
      clock = $('.countdown').FlipClock(countdownTimeDiff, {
        clockFace: 'DailyCounter',
        countdown: true,
        showSeconds: showSeconds
      });

      // Add Countdown to Sport Relief header to explain what this widget.
      $('<h3/>', {text: 'Countdown to Sport Relief', class: 'countdown-explanation'}).insertBefore(".countdown");

      // Add explanation next to days/hours/minutes
      $('<div/>', {text: 'days', class: 'clock-divider-explanation days'}).insertBefore(".flip-clock-divider.hours");
      $('<div/>', {text: 'hours', class: 'clock-divider-explanation hours'}).insertBefore(".flip-clock-divider.minutes");
      $('<div/>', {text: 'minutes', class: 'clock-divider-explanation minutes'}).insertBefore(".flip-clock-divider.seconds");

      // This is a hack to extend FlipClock to do things it shouldn't do.
      if(showSeconds) {
        $('<span/>', {text: 'seconds', class: 'clock-divider-explanation last'}).insertAfter(".flip:last");
      }else{
        $('<span/>', {text: 'minutes', class: 'clock-divider-explanation last'}).insertAfter(".flip:last");
      }

    }

  });

  // This function updates the display based upon the width of the browser.
  function countdownResize(e) {

    if($(window).width() > 768) {
      $('.countdown-offline').hide();
      $('.countdown, .countdown-explanation').show();
    }else{
      $('.countdown, .countdown-explanation').hide();
      $('.countdown-offline').show();
    }

  }

  if(!Modernizr.touch) {
    $(window).on("resize", countdownResize);
  }

}(jQuery));
