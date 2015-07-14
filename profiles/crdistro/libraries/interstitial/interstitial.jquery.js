(function ($) {
/**
 * Interstitial jQuery Plugin
 * Author: Jeremy P.
 * 
 * Usage:
 * HTML: <a href="" data-interstitial="My message here." data-interstitial-delay="2000">Interstitial link</a>
 * JS: $('[data-interstitial]').interstitial(options);
 *
 * Options can be override by passing them into the function
 *
 * Example:
 * var options = { backgroundAttributes:{id:'foo', class:'bar'}, cancelButtonText: 'STOP!'}
 * $('.my-link').interstitial(options);
 * 
 */
jQuery.fn.interstitial = function(options) {
  var $overlay,
      $overlayContent,
      $background,
      $cancelButton,
      $text,
      $number;

  // Default Options
  var settings = $.extend({
      default_delay: 5000,
      default_message: "You will be redirected shortly.",
      cancelButtonText: "Cancel",
      overlayAttributes : {
        id: 'interstitial'
      },
      backgroundAttributes : {
        id: 'interstitial__background'
      },
      cancelButtonAttributes : {
        'class': 'interstitital__btn-cancel ',
        href: '#close'
      },
      textAttributes : {
        'class': 'interstitial__message'
      }
  }, options );

  // Set the timing which can differ from link to link
  var delay = settings.default_delay;

  // Declare the timer so we can remove it if we can cancel
  var delayTimer = null;

  // Setup Overlay
  function setupOverlay(message) {
    var $body = $('body');

    // Setup the cancel button
    $cancelButton = $('<a/>')
      .attr( settings.cancelButtonAttributes )
      .text(settings.cancelButtonText)
      .on('click', handleCancelClick);

    // Setup the text area
    $text = $('<p/>')
      .attr( settings.textAttributes )
      .html(message);

    // Setup the background div
    $background = $('<div/>')
      .attr( settings.backgroundAttributes )
      .appendTo( $body )
      .on('click', handleCancelClick);

    // Setup the overlay div
    $overlay = $('<div/>')
      .attr( settings.overlayAttributes )
      .wrapInner( '<div class="interstitial__content"><div class="interstitial__content-inner"></div></div>')
      .appendTo( $body );

    // Assign overlay content and add text + button
    $overlayContent = $('.interstitial__content-inner', $overlay)
      // Add text and cancel button
      .append( $text )
      .append( $cancelButton );
    
    // We can only wrap once appending it to the dom
    $cancelButton
      .wrap('<p class="interstitital__btn type--centred"></p>');
  }

  // Open Overlay
  function toggleOverlay() {
    var $link = $(this);
    var textMessage = $link.attr('data-interstitial') ? $link.attr('data-interstitial') : settings.default_message;
    delay = $link.attr('data-interstitial-delay') ? $link.attr('data-interstitial-delay') : settings.default_delay;

    // Setup the overlay if it's not existent
    if(!$overlay) {
      setupOverlay(textMessage);
    } else {
      // Just update the text
      $text.html(textMessage);
    }

    // Save the number if we have one so we can count it down
    $number = $('i.seconds', $text);

    // Toggle the overlay (hide or show)
    $background.toggle();
    $overlay.toggle();

    // Check if the overlay is visible or not using jQuery's "is" function
    var overlayIsVisible = $overlay.is(":visible");

    return overlayIsVisible;
  }

  // Close the Overlay
  function closeOverlay(e) {
    $background.hide();
    $overlay.hide();
  }

  // Handle the cancel button click
  function handleCancelClick(e) {
    // Prevent redirect in progress
    window.clearTimeout(delayTimer);

    // Close the overlay
    closeOverlay();
    e.preventDefault();
  }

  // Handle Interstitial Link Click
  function handleClick(e) {
    e.preventDefault();

    var overlayIsOpen = toggleOverlay.apply(this);

    if(overlayIsOpen) {
      var href = $(this).attr('href');
      var secondsPassed = 1; // When timedRedirect is triggered first time, a second has already passed
      var seconds = delay/1000;
      var timedRedirect = function() {
        if(secondsPassed == seconds) {
          window.clearTimeout(delayTimer);
          window.location.href = href;
        }
        if($number) {
          $number.text(seconds - secondsPassed);
        }
        secondsPassed++;
      };
      delayTimer = window.setInterval(timedRedirect, 1000);// By default every second
    }
  }

  // Setup Link
  function setupLink() {
    var $link = $(this);
    // Do something to each element here.
    $link.on('click', handleClick);
  }

  // This is so we can chain the interstitial :)
  return this.each(setupLink);
};
})(jQuery);