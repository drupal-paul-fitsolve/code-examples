(function ($) {

/**
 * JS related to the tabs in the Panels tabs.
 */
Drupal.behaviors.panelsContentMediaPlayer = {
	slider: null,
  attach: function (context) {
  	var _base = Drupal.behaviors.panelsContentMediaPlayer;
    var contentMediaPlayer = $('.pod--content-media-player');

    _base.slider = contentMediaPlayer.parent().flexslider({
    	selector: '.pod--content-media-player > div',
    	directionNav: true,
    	animationLoop: true,
    	slideshowSpeed: 10000,
    	animationSpeed: 1000,
    	controlNav: false,
	    pausePlay: true,
      start: function(slider) {
        $('.total-slides').text(slider.count);
      },
      after: function(slider) {
        $('.current-slide').text(slider.currentSlide + 1);
      }
    }).flexslider("pause");

    $('.pod--content-media-player ~ .flex-direction-nav').once().prepend('<li class="direction-text"><p class="current-slide">1</p><p>of</p><p class="total-slides"></p></li>');

    var mediaController = $('.pod--content-media-player ~ .flex-pauseplay');

    // Add the additonal controls to the media controller - Music and Quotes
    mediaController.once().append('<a class="flex-music">Play</a><a class="flex-quote">Play</a><span>Click to toggle tool on/off</span>');

    
    //Play/Pause Music
    if ($('.pod--content-media-player').hasClass('primary--needs-pod')) {
        //the primary needs pod is on this page so load audiojs and its audio file
        $('.footer-zone-wrapper').append('<audio src="/sites/sportrelief.com/files/files/downloadables/schools-primary-needs-pod.mp3" preload="none"></audio>');
    }else if ($('.pod--content-media-player').hasClass('secondary--needs-pod')) {
      //the secondary needs pod is on this page so load audiojs and its audio file
        $('.footer-zone-wrapper').append('<audio src="/sites/sportrelief.com/files/files/downloadables/schools-secondary-needs-pod.mp3" preload="none"></audio>');
    }
   
    //initalise audio.js
    if($('.pod--content-media-player').hasClass('primary--needs-pod') || $('.pod--content-media-player').hasClass('secondary--needs-pod')) {
      audiojs.events.ready(function() {
        audiojs.createAll();
      });
      mediaController.children('.flex-music').on('click', null, function(){
        $(this).toggleClass('active');
        $( ".audiojs .play" ).trigger( "click" );
      });
    }
  

    //Show/Hide Quotes
    mediaController.children('.flex-quote').on('click', null, function(){
      $(this).toggleClass('active');
      contentMediaPlayer.toggleClass('quote-is-active');
    });



  }
};


})(jQuery);
