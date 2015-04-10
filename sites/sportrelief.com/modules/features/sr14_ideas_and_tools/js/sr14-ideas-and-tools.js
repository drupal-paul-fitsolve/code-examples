(function($) {
  
    $(document).ready(function() {

    
    var pane = $('.pane-ideas-tips');
    var itemsView = $('.ideas-tips');
    var toolsView = $('.pane-tools');
    var items = $('.item-column', itemsView)
    var itemIdeas = $('.item-column.ideas');
    var itemTips = $('.item-column.tips');
    var itemIdeasLevel1only = $('.item-column.2, .item-column.3, .item-column.4');
    var itemIdeasHeader = $('.css-bootstrap-header');

      // ------ Custom scale slider ----------- //    
      var data = { '1': '1', '2': '2', '3': '3', '4': '4'}
      var s = $('<select id="scale"/>');
        for(var val in data) {
          $('<option />', {value: val, text: data[val]}).appendTo(s);
        }
      s.insertAfter(itemIdeasHeader);
      s.hide();
          s.selectToUISlider({
            sliderOptions: {
              change: function(e,ui) {
                  var currentValue =  parseInt(s.val());
                  items.removeClass('new-col').addClass('filtered');
                  items.each(function() {
                      var level = $(this).attr('class').split(' ')[3];
                      if(level.length && level == currentValue) {
                        $(this).removeClass('filtered').addClass('new-col');
                      }
                  });
                  resetDiv();
                  pagination.rebuild();
                    $('.item-column').removeAttr('col');
                    $('.new-col').each(function(i){
                      $(this).attr('col', (i+1));
                    });                  
              }
            }
          });          

      // place marker 
      var showall = '<div class="slider-reset" accesskey="ideas"><div class="show_all form-item-wrapper">Show all ideas</div></div>';
      var shortcut = '<div id="shortcuts"><div class="shortcut"><a href="#" id="ideas">Find an idea</a></div> <div class="shortcut button--swim"><a href="#" id="tips">Get a tip</a></div><div class="shortcut tools"><a href="#" id="tools">Get tools</a></div></div>';   
      $('.ui-slider').wrap('<div class="slider" />');
      $('.slider').attr('accesskey', 'ideas');
      $('.slider').append('<div class="slider-desc">Use the scale to filter fundraising ideas</div>');
      $('.ui-slider-scale li').text('|');
      $('.ui-slider-scale li:nth-child(1)').text('Quick & Easy').addClass('label-first');
      $('.ui-slider-scale li:nth-child(4)').text('Prove yourself').addClass('label-last');    
      $(showall).insertBefore($('.slider'));
      $(shortcut).insertBefore(itemsView);
      hideAll();      
      
      $("img[title*='arrive']").addClass('clicked'); 

    var shortcut = $('#shortcuts').offset().top;  
    var point_top = $('.pointer_desktop').offset().top;
    var topPadding = 123;   

      // ------ Touch devices only ----------- //
      if ((('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch) || $(window).width() < 719) {
      // ------ All devices exclude touch devices ----------- //  
      } else {
        // hover state
        $('.box .button, .shortcut a').on({        
          mouseover: function(e) {
            $('img[title=' + $(this).attr('id') +']').addClass('hover');
          },
          mouseout: function(e) {
            $('img[title=' + $(this).attr('id') +']').removeClass('hover');
          }
        });
        
        // float shortcut behaviour 
        $(window).scroll(function () {
          if ($(window).scrollTop() > point_top - topPadding ) {        
              if(itemsView.is(':visible') || toolsView.is(':visible')) {
                $('#shortcuts').addClass('stick');
                /*
                $('#shortcuts').stop().animate({            
                    marginTop: $(window).scrollTop() - point_top         
                }).show();
                */        
              }   
            } else {   
              $('#shortcuts').removeClass('stick');   
            /*  
                $('#shortcuts').stop().animate({            
                    marginTop: 0            
                }).hide();
            */
            }
        }); /* end - window scroll */           
        
      }

      // ------ Mobile only ----------- //
      if( $(window).width() < 719 ) {
        $('#shortcuts').insertBefore($('.content-row-5-wrapper'));
        $('#shortcuts').show();        
      }

      // ------ All devices ----------- //
      $('.box .button, .shortcut a').on({               
        click: function(e) {           
            e.preventDefault();
            resetDiv(); 
            hideAll();
            items.removeClass('filtered');            

            // ideas & tips share same div so need to amend accesskey accordingly      
            if ( $(this).attr('id')  == "tips") { 
              pane.attr('accesskey', 'tips'); 
              itemIdeas.addClass('filtered');              
              pagination.rebuild();  
              setItemCol(itemTips);    

                if (typeof(_gaq) !== 'undefined') {
                _gaq.push(['_trackPageview', '/fundraise/ideas-and-tools/get-a-tip']); 
              }
            }
            if ( $(this).attr('id')  == "ideas") { 
              pane.attr('accesskey', 'ideas'); 
              itemIdeasLevel1only.addClass('filtered'); // only level 1
              itemTips.addClass('filtered');
              pagination.rebuild();
              setItemCol(itemIdeas);

                if (typeof(_gaq) !== 'undefined') {
                  _gaq.push(['_trackPageview', '/fundraise/ideas-and-tools/find-an-idea']); 
                }              
            } 
            if ( $(this).attr('id')  == "tools") { 
                if (typeof(_gaq) !== 'undefined') {
                  _gaq.push(['_trackPageview', '/fundraise/ideas-and-tools/get-tools']); 
                }       
            }
            $('img[title=' + $(this).attr('id') +']').addClass('clicked');
            $('div[accesskey='+ $(this).attr('id') +']').removeClass('in-active');
            $('html, body').animate({
              scrollTop: $('div[accesskey='+ $(this).attr('id') +']').offset().top - 65
            }, 2000);
        }
      }); /* end - on */
     
      // ------ Showall to trigger ajax form ----------- //
      $('.slider-reset .show_all').click(function(){
        if($(this).hasClass('clicks')) { 
          $(this).removeClass('clicks');
          $('.ui-slider').slider('enable');
          pane.removeClass('all');   

            var currentValue =  parseInt(s.val());
            items.addClass('filtered');
            items.each(function() {
              var level = $(this).attr('class').split(' ')[3];
              if(level.length && level == currentValue) {
                $(this).removeClass('filtered');
              }
            });
        } else if (!$(this).hasClass('clicks')) {     
          $(this).addClass('clicks');
          $('.ui-slider').slider('disable');
          pane.addClass('all');
          items.removeClass('filtered');
          itemTips.addClass('filtered');
        }
        resetDiv();
        pagination.rebuild();
        setItemCol(itemIdeas);        
      });  

      // ------ pager behaviour ----------- // 
      $('.pager a').live("click",function(e){               
        resetDiv();        
      }); 

      // ------ URL hashtag detection to trigger ----------- //
      var url = window.location.hash;
      var hash = document.URL.substr(document.URL.indexOf('#')+1);
      if( hash == 'sponsorship_tips') { 
        $('.box__tips .button').click();
      } else if ( hash == 'fundraising_ideas') {
        $('.box__ideas .button').click();
      } else if ( hash == 'fundraising_tools') {
        $('.box__tools .button').click();
      }


  }); /* - end document ready - */

  function hideAll() {
      $("div[accesskey*='ideas']").addClass('in-active');
      $("div[accesskey*='tips']").addClass('in-active');
      $("div[accesskey*='tools']").addClass('in-active');
      $(".pointer_desktop img").removeClass('clicked');
  }
  
  function setItemCol(arg) {
      $('.item-column').removeAttr('col');
      $('.item-column').removeClass('new-col');
      $(arg).each(function(i){
         $(this).attr('col', (i+1));
      });  
  }

  function resetDiv() {
      var associatedToolDiv = $('.associated-tools-wrapper');
      // values depends on layout
      var layouts = Drupal.omega.getCurrentLayout();
      var move_box, move_icon, move_title, move_body;
              switch (layouts) { 
                case 'wide': 
                  move_box = 69;
                  move_icon = 25;
                  move_title = 25;
                  move_body = 35;
                break; 
                case 'normal': 
                  move_box = 84;
                  move_icon = 35;
                  move_title = 43;
                  move_body = 35;
                break;
                case 'narrow': 
                  move_box = 62;
                  move_icon = 25;
                  move_title = 25;
                  move_body = 25;
                break;
            }

      if($('.item-column').hasClass('collapse')) {
                $(associatedToolDiv).slideUp("slow")
                   .siblings('.item-column')
                   .animate({"min-height": "+=" + move_box +"px"}, "slow", function() {
                    $('.item-column').removeClass('active-item');
                 }).find(".fr-icons")
                   .animate({"top": "+=" + move_icon +"px"}, "slow")
                   .end()
                   .find(".views-field-title")
                   .animate({"top": "+=" + move_title +"px"}, "slow")
                   .end()
                   .find(".views-field-body")
                   .animate({"top": "+=" + move_body +"px"}, "slow")
                   .end()
                   .removeClass('collapse');
                //$(associatedToolDiv).appendTo($('.ideas-tips'));   
      }           
  }

  Drupal.behaviors.sr14_ideas_and_tools = {
      attach: function (context, settings) {

      var share_text;
      var share = '<ul id="share-link"><li><a href="#" onclick="window.open(\'http://www.facebook.com/sharer.php?s=100&p[url]=http://www.sportrelief.com/fundraise/ideas-and-tools&p[images][0]=http://www.sportrelief.com/sites/all/modules/features/sr14_ideas_and_tools/css/images/fb_thumbnail_fitt.png&p[title]=Fundraise ideas, tips and tools&p[summary]=**\',\'facebook-share-dialog\',\'width=626,height=436\');return false;"><img src="/sites/sportrelief.com/themes/sport_relief_2014/images/components/social-widget/fb.png"></a></li><li><a href="#" onclick="window.open(\'https://plus.google.com/share?url=http://www.sportrelief.com/fundraise/ideas-and-tools\',\'google-share-dialog\',\'width=626,height=436\');return false;"><img src="/sites/sportrelief.com/themes/sport_relief_2014/images/components/social-widget/google.png"></a></li></ul>';

      // ------ Jquery once ----------- //  
      $('.ideas-tips', context).once('sr14_ideas_and_tools', function(){  
        $('.fr-share-widget').prepend(share);  
      }); /* end - once */

      // ------ Share text replace with clicked ideas/tips ----------- // 
      $('.ideas-tips .item-column').on({
        click: function(event) {

          if( $(this).hasClass('ideas')) { $('.associated-tools-wrapper').removeAttr('id').attr('id', 'cat-ideas').find('h3').text('for this idea'); }
          if( $(this).hasClass('tips')) { $('.associated-tools-wrapper').removeAttr('id').attr('id', 'cat-tips'); $('.associated-tools-wrapper').find('h3').text('for this tip'); }

          share_text = $(this).find('.views-field-body').children().children().text();
          $('#share-link').remove();
          $('.fr-share-widget').prepend(share);  
          $('.fr-share-widget').html($('.fr-share-widget').html().replace(/\*\*/g, '**' + share_text));
        }  
      }); /* end - on */     

      // ------ Sponsortship form overlay responsive ----------- //
      /*
      var colorbox_inline_width = '1180';
      var colorbox_inline_width_half = '590';
      if(Drupal.omega.getCurrentLayout() == "wide") { colorbox_inline_width = '1180'; colorbox_inline_width_half = '590'; }
      if(Drupal.omega.getCurrentLayout() == "normal") {  colorbox_inline_width = '940'; colorbox_inline_width_half = '470'; }
      if(Drupal.omega.getCurrentLayout() == "narrow") {  colorbox_inline_width = '700'; colorbox_inline_width_half = '350'; }

      $('.dl-overlay').each(function() {
          var path = $(this).find('h2.title').text().toLowerCase().replace(/\s/g, '-');
          $(this).find('a').attr({ class: 'colorbox-node', href: '/' + path + '/all?width=' + colorbox_inline_width + '&height=490'});            
      });
      */
      }/* end - attach*/
    }/* end - behaviour*/   


})(jQuery);