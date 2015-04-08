(function($) {

  $(document).ready(function() {

    // ------ Touch devices only ----------- //
    if ((('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch) || $(window).width() < 719) {
      // ------ All devices exclude touch devices ----------- //  
    } else {
    
        $('.views-fluidgrid-item').live('mouseenter', function() {
             $(this).find('.total-circle').fadeIn('slow');
        }).live('mouseleave', function() {
            $(this).find('.total-circle').fadeOut('slow');
        });
        setTotal();
    }
  }); /* end - document ready */

  Drupal.behaviors.sr14_fundraiser_showcases = {
      attach: function (context, settings) {

        var width_responsive = 280,   
            setColumnWidth = function() { width_responsive = $(window).innerWidth() > 1200 ? 280 : $(window).innerWidth() > 400 ? 220 : 145; };
        setColumnWidth();
        var gutter_responsive = 20,   
            setGutterWidth = function() { gutter_responsive = $(window).innerWidth() > 1200 ? 20 : $(window).innerWidth() > 400 ? 20 : 10; };
        setGutterWidth();
        
        $(window).resize(setColumnWidth);

        // Auto pager
        var $container = $('div.fr-showcase');

        $('div.fr-showcase').infinitescroll({
            navSelector  : 'div.fr-showcase .pager-next',    // selector for the paged navigation
            nextSelector : 'div.fr-showcase .pager-next a',  // selector for the NEXT link (to page 2)
            itemSelector : 'div.fr-showcase .views-row',     // selector for all items you'll retrieve
            loading: {
              finishedMsg: 'No more pages to load.',
              img: Drupal.settings.basePath + 'sites/sportrelief.com/themes/sport_relief_2014/images/loading.gif'
            }
          }, 
            // trigger Masonry as a callback
            function( newElements ) {
              // hide new items while they are loading
              var $newElems = $( newElements ).css({ opacity: 0 });
              // ensure that images load before adding to masonry layout
              $newElems.imagesLoaded(function(){
                // show elems now they're ready
                // ------ Touch devices only ----------- //
    if ((('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch) || $(window).width() < 719) {
      // ------ All devices exclude touch devices ----------- //  
    } else {
        setTotal();
    }  
                $newElems.animate({ opacity: 1 });
                $container.masonry().masonry( 'appended', $newElems, true );
                /*$("html, body").animate({
                  scrollTop: $('#infscr-loading').next().offset().top + $('#infscr-loading').next().height()
                }, 3000);
                */
                $container.find('.item-list').appendTo($container);
                $('.pager-next').show();               
                Drupal.behaviors.colorboxNode.attach($container, Drupal.settings);      
          });
        });

        //if($.browser.msie && $.browser.version=="9.0") { {
          $(window).unbind('.infscr');
        //} 

        $container.imagesLoaded(function(){
          $container.masonry({
            itemSelector: '.views-row',
            columnWidth: width_responsive,
            gutterWidth: gutter_responsive,
            isAnimated: true,
            animationOptions: {
                            duration: 750,
                            easing: 'linear',
                            queue: false
                        }
          });
        });

          $('div.fr-showcase .pager-next a').live('click', function() {          
            $('div.fr-showcase').infinitescroll('retrieve').masonry();
            return false;    
          });

        $(document).ajaxError(function(e,xhr,opt){
          if(xhr.status==404) $('.pager-next').remove();
        });
    

      // ------ Colorbox  ----------- //
      $('#colorbox', context).ajaxStart(function(){ 
        $(this).removeClass('cbox-loaded');
        $(this).addClass('cbox-loading');
      });  

      // resize after colorbox-node load
      $('#colorbox', context).ajaxSuccess(function(){
        $(this).addClass('cbox-loaded');
        $(this).removeClass('cbox-loading');
      if($('.flexslider ul li:first img').length > 0 ) {
      
        $('.flexslider ul li:first img').load(function(){
            // natural width & height
            var
            props = ['Width', 'Height'],
            prop;
        
            while (prop = props.pop()) {
              (function (natural, prop) {
                $.fn[natural] = (natural in new Image()) ? 
                function () {
                return this[0][natural];
                } : 
                function () {
                var 
                node = this[0],
                img,
                value;
          
                if (node.tagName.toLowerCase() === 'img') {
                  img = new Image();
                  img.src = node.src,
                  value = img[prop];
                }
                return value;
                };
              }('natural' + prop, prop.toLowerCase()));
            }
            $.colorbox.resize({width: $(this).naturalWidth() + 320, height: 688});   
        });
        
        $('.flexslider').flexslider();
        // Add this because flexslider > li is default to display:none for some reason
        $('.flexslider ul li:first').show();
      
      } else {
        // video     
        $.colorbox.resize({width: 960, height: 688}); 
      }
            // resize once clicked
            $('.flex-control-paging li').click(function(event) {
                var slide_num = parseInt($(this).text()) - 1;
                $.colorbox.resize({width: $('ul.slides li:eq(' + slide_num +') img').naturalWidth() + 320, height: 688 }); 
            });
            
            $('.flex-direction-nav li').click(function(event) {
              $.colorbox.resize({width: $('li.flex-active-slide img').naturalWidth() + 320 }); 
            });
        
          $('.frsc-prev-next').fadeIn('2000');


      }); /* end - ajaxSuccess */      

    } /* end - attach */
  }; /* end - behaviors */

       
  function setTotal() {
        var amount;
        $('.total-circle .total').each(function() {
           amount = $(this).parents().parents().parents().siblings('.views-field-nid').find('.field-content').text();
           $(this).html(amount);
        });
  }   

})(jQuery);