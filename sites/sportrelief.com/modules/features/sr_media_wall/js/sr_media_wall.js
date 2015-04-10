/*
 * @file
 * JavaScript for sr_media_bar js.
 * Resize colourbox content on event cbox_complete
 */

(function($) {

  Drupal.behaviors.srMediaWallFlexslider = {
    attach: function(context, settings) {

      $.each(Drupal.settings.panelsSlider, function(i, panelsSlider){

        var flexslider = panelsSlider.extraClasses;
        var flexsliderIdentifier = panelsSlider.flexsliderIdentifier;
        var flexsliderMobile = false;

        // Only run this once, not on every DOM element added
        $("." + flexsliderIdentifier).once('sr_media_wall_slider', function(){

        // Media Wall Flexslider config
        if (flexslider.toLowerCase().indexOf("media-wall") >= 0){
          
          // If paged news title set, fetch here
          var pagedNewsTitle = $(".media-wall-paged-news").text();
          
          if (typeof pagedNewsTitle === "undefined" ||  pagedNewsTitle == "") {
            pagedNewsTitle = "What's Happening";
          }
          

          //If mobile, change 1st slide and add a second slide
          if ($(window).width() <= 740) {

            // MediaWall
            var mediaWall = $('.media-wall', context);
            var mediaWallParent = mediaWall.parent();

            mediaWallParent.prepend("<a id='media-wall-top' href='#'></a>");
            // The DOM is slow, detaching to manipulate then attach later
            mediaWall.detach();

            //Remove Twitter element, this is because JS will still run when attachBehaviors is called. Remove here for performance
            mediaWall.find('.media-bar.media-bar--type-twitter').remove();

            var mobileFirstSlide = mediaWall.find('.slider-content:first-child .bean-media-wall > div:first-child');

            // Create second slide be removing items here
            var nodequeueDiv = mobileFirstSlide.find('.view-id-media_wall').detach();
            var instagramDiv = mobileFirstSlide.find('.media-wall_instagram').detach();
            var fundraisingDiv = mobileFirstSlide.find('.media-wall__fundraising-kit').detach();

            var mobileDiv = $('<div id="mobile-div1" class="slider-content dynamic-slide bean-media-wall sr-media-wall clearfix"><h2 class="pane-title">' + pagedNewsTitle + '</h2></div>');
            $(mobileDiv).append(nodequeueDiv, instagramDiv, fundraisingDiv );

            // Insert second div
            mediaWall.find('.slider-content:first-child').after(mobileDiv);

            // Re-attach MediaWall
            mediaWallParent.append(mediaWall);

            //Let everyone know its mobile
            flexsliderMobile = true;
          }

          var srSlidingDiv = $('<div class="slider-content dynamic-slide bean-media-wall sr-media-wall equal-height-container clearfix" data-mediawall="get"><div id="my-media-wall"><div class="cr-loader"><div class=" loader loader__black_on_blue"></div></div></div></div>');
          var srSlidingDiv2 = $('<div class="slider-content dynamic-slide bean-media-wall sr-media-wall equal-height-container clearfix" data-mediawall="get"><div id="my-media-wall-2"><div class="cr-loader"><div class=" loader loader__black_on_blue"></div></div></div></div>');


          //var srSlidingDiv = $('<div class="slider-content dynamic-slide bean-media-wall sr-media-wall  clearfix" data-mediawall="get"><div id="my-media-wall"><div class="cr-loader"><div class=" loader loader__black_on_blue"></div></div></div></div>');
          //var srSlidingDiv2 = $('<div class="slider-content dynamic-slide bean-media-wall sr-media-wall  clearfix" data-mediawall="get"><div id="my-media-wall-2"><div class="cr-loader"><div class=" loader loader__black_on_blue"></div></div></div></div>');


          if(typeof panelsSlider !== 'undefined' && typeof panelsSlider.flexsliderSlideClass !== 'undefined'){

            try{
              var sliderItemClass = ".media-wall  ." + panelsSlider.flexsliderSlideClass;
              // Add divs to slider
              $(sliderItemClass + " .slider-content:last-child", context).before(srSlidingDiv, srSlidingDiv2);

              // Pass additional options to send to cr_panels_slider here
              var moreOptions = {
                // Pass ajax behavior here. Because 'before' is used, currentSlide needs to be incremented by 1
                before: function(slider){
                  // Current slide
                  var slide = $(slider.slides[slider.currentSlide+1]);
                  var slideSelector = $(slider.slides[slider.currentSlide+1]).find("div:first-child").attr('id');
                  // If slide is a dynamic slider then run ajax
                  if($(slide).data('mediawall') == "get"){
                    // Run AJAX (GET)

                    // If mobile then delay by 1 second until scrolling is complete. Perfromance reasons
                    if(flexsliderMobile == true && slider.playing == false){
                        setTimeout(function(){
                          __getViewsAjax(context, flexsliderIdentifier, pagedNewsTitle, (slider.currentSlide+1), slideSelector);
                        }, 1000);
                    }else{
                      __getViewsAjax(context, flexsliderIdentifier, pagedNewsTitle, (slider.currentSlide+1), slideSelector);
                    }

                    // Set data attribute to stop further ajax requests. This is internally stored by JQuery
                    // and is not displayed in HTML source
                    $(slide).data('mediawall','processed');
                  }
                },
                after: function(slider){
                  //Add scroller for phones. This should only behave like this if autoplay is off
                  if(flexsliderMobile == true && slider.playing == false){
                    var scrollRef = $(context).find('a#media-wall-top');
                    if (typeof scrollRef === "undefined") {
                      return;
                    }

                    var target = $(scrollRef);
                    var position = target.offset().top;
                    $('html,body').animate({
                      scrollTop:position
                      }, 1000);
                  }
                }
              }

              // Create object for panels slider (cr_panels_slider.js)
              var extendedOptions = {};
              extendedOptions[flexsliderIdentifier] = moreOptions;
              // Add to Drupal.settings
              $.extend(Drupal.settings, {"panelsSliderExtend" : extendedOptions});

            }
            catch(e){
              alert('An error has occurred: (SR Media Wall) '+e.message)
            }
          }
        } //eof Media Wall Flexslider config
        });
      });

   }
  }

  // Ajax get function
  function __getViewsAjax(context, flexsliderIdentifier, pagedNewsTitle, page, slideSelector, term, type) {

    if(page == null && slideSelector !== undefined){
      page == 0;
    }
    // Assign correct path prefix
    if (typeof type === "undefined" || type === null) {
      var nthChild = "4";
      if(isTouchDevice(context)){

        //if phone
        if(isMobileDevice(context)){
          type = "phone_touch";
        }else{
          type = "touch";
        }

        var nthChild = "2";
      }
      else{
        type = "normal";
      }
    }
    // Full path for AJAX request
    var ajax_path = Drupal.settings.sr_media_wall.path + '/' + type + '/' + page;

    $.ajax({
      url: ajax_path,
      type: 'GET',
      //Set headers
      beforeSend: function(xhr) {
        //Cache for 1 week
        xhr.setRequestHeader('Cache-Control', 'public, max-age=604800');
        //xhr.setRequestHeader('Pragma', '');
      },
      success: function(response) {
        $.each( response, function( key, object ) {
          //console.log(object);
          // Fetch method from drupal ajax framework
          if(typeof object.method != 'undefined'){
            var method = object.method;
            parent = $("#" + slideSelector,context).parent();
            // Apply method eg "replaceWith", "appendTo" etc
            $("#" + slideSelector)[method]("<div>" + object.data + "</div>");
            // Assign omega on every 4th div
            if(type !== "phone_touch"){
              $("." + flexsliderIdentifier + " div.media-wall__small-tile:nth-child(" + nthChild + "n+1)", context).addClass('alpha');
              $("." + flexsliderIdentifier + " div.media-wall__small-tile:nth-child(" + nthChild + "n)", context).addClass('omega');
            }
            //Update H2 header
            $(parent).find("h2.mw-latest-news").text(pagedNewsTitle);
            // New content for DOM, run attach behaviors and apply Drupals methods here
            Drupal.attachBehaviors("." + flexsliderIdentifier);
          }


        });
      },
      error: function(xhr) {
        //console.log('error');
        console.log(xhr);
      },
      dataType: 'json',
    });
  }

  function isTouchDevice(context) {
    var bodyClass = $('body',context).attr('class');
    var regex = /(responsive-layout-mobile|responsive-layout-narrow)/i;
    return touchDevice = regex.test(bodyClass);
  }

  function isMobileDevice(context) {
    var bodyClass = $('body',context).attr('class');
    var regex = /(responsive-layout-mobile)/i;
    return touchDevice = regex.test(bodyClass);
  }

})(jQuery);
