
/**
 * Sport Relief SR Media Bar Script
 */
(function ($) {
Drupal.behaviors.sr_media_bar = {
  name_space: 'sr_media_bar',
  selector : '.media-bar__list.auto-height__resizable',
  mediabarScrollbars : [],
  config : {
    pagerItemIncrement: {
      'mobile' : 1,
      'narrow' : 2
    }
  },

  defaultPageTo: 0,

  scrollBarsResized: false,
  scrollId: 0,

  attach: function (context, settings) {
    var _base = Drupal.behaviors.sr_media_bar;

    // Extends our default config with custom settings
    _base.config = $.extend(_base.config, Drupal.settings[_base.name_space]);

    // Initialize only running it once
    var handleResponsiveLayout = function (e) {
      $(_base.selector, context).once(_base.name_space,_base.run);
    };

    $(document).on('responsivelayout', handleResponsiveLayout);
  },

  /*
   * Core Initaliser
   */
  run: function (event) {
    var _base = Drupal.behaviors.sr_media_bar;

    try {
        breakpoint = Drupal.omega.getCurrentLayout();
    }
    catch (err) {
        console.log('Error: Cant get current layout! Defaulting to normal.');
        breakpoint = 'normal';
    }


    // Exception to not calculate height if breakpoint is mobile
    if (!breakpoint || (breakpoint == 'wide' || breakpoint == 'normal')) {
      // Desktop
      _base.implementNormalWideScroller.call(this, breakpoint);
    } else {
      // Mobile & narrow
      // Set the page to element based on breakpoint
      _base.defaultPageTo = _base.config.pagerItemIncrement[breakpoint];
      _base.implementNarrowMobileScroller.call(this, breakpoint);
    }

    // Convert twitter data image into html images
    if ( !breakpoint || (breakpoint == 'wide' || breakpoint == 'normal' || breakpoint == 'narrow')) {
      _base.convertToImage.call(this, 5);
    }
  },
  /*
   * Normal and Wide Scrollbar
   */
  implementNormalWideScroller: function (breakpoint) {
    var _base = Drupal.behaviors.sr_media_bar;

    var $mediaList = $(this);
    // TODO
    // We could implement a desktop scroll here. For styling for instance.
  },

  /*
   * Narrow and Mobile Scrollbar
   * Uses iscroll
   */
  implementNarrowMobileScroller: function (breakpoint) {
    var _base = Drupal.behaviors.sr_media_bar;
    var $mediaList = $(this);

    // Setup iScroll
    var id = $mediaList.attr('id');
    if (!id) {
      var newId = 'scroller-'+ _base.scrollId;
      $mediaList.attr('id', newId);
      id = newId;
    }
    var scroller = new iScroll(id, {
        momentum: true,
        hScroll: false,
        vScroll: true,
        bounce: true,
        vScrollbar: true,
        hideScrollbar:false,
        scrollbarClass: 'media-bar__scrollbar',
        onScrollMove: function () {
          $(this.wrapper).pagedTo = _base.defaultPageTo;
          this.scrolled = true;
        }
      }
    );
    _base.mediabarScrollbars.push(scroller);
    _base.scrollId++;

    // Mobile Breakpoint Specific
    if (breakpoint !== 'mobile') {
      return;
    }

    // Now we are done, we can setup the mobile pager
    _base.setupMobilePager.call(this, scroller);
  },

  setupMobilePager: function (iscroll) {
    var _base = Drupal.behaviors.sr_media_bar;
    var $mediaList = $(this);
    var $mediaFooter = $mediaList.siblings('.media-bar__footer');

    // Sets up the mobile pager
    $mediaList.pagedTo = _base.defaultPageTo;
    iscroll.scrolled = false;
    $mediaList.iscroll = iscroll;
    $mediaListItems = $mediaList.find('li.item');

    // Remove elements and append a button with an event handler.
    $mediaFooter
      .empty()
      .addClass('media-bar__footer--pager')
      .append(
        $('<button class="media-bar_footer--pager-button">load more</button>')
          .on('click', {items: $mediaListItems, list: $mediaList}, _base.eh_media_page_click)
      );

    setTimeout(_base.resizeMobileScrollbars, 400);
  },

  eh_media_page_click: function (e) {
    e.preventDefault();

    var _base = Drupal.behaviors.sr_media_bar;
    var $elements = e.data;
    var scrollElement = null;

    // We scrolled before, so we need to fix something!
    if ($elements.list.iscroll.scrolled) {
      var pos, $el;
      for(var i = 0; i < $elements.items.length; i++) {
        $el = $elements.items.eq(i);
        pos = $el.position();
        if (pos.top > 0) {
          break;
        }
      }
      $elements.list.iscroll.scrolled = false;
      $elements.list.pagedTo = $el.index() + _base.defaultPageTo;
    }

    // Figure out what we want to do
    if ($elements.list.pagedTo >= $elements.items.length) {
      var maxScrollOffset = ($elements.list.iscroll.maxScrollY + 20);
      if ( $elements.list.iscroll.y >= maxScrollOffset) {
        // If we are close to the bottom, just animate the rest.
        $elements.list.iscroll.scrollTo(0, $elements.list.iscroll.maxScrollY, 150);
      } else {
        // Otherwise we know we're at the bottom so let's scroll to the top
        $elements.list.iscroll.scrollTo(0, 0, 500);
        $elements.list.pagedTo = _base.defaultPageTo;
      }
    } else {
      // Scroll to next element
      var $scrollToItem = $elements.items.eq($elements.list.pagedTo);
      $elements.list.iscroll.scrollToElement($scrollToItem[0],300);

      // set pageTo
      $elements.list.pagedTo += _base.defaultPageTo;
    }

    return false;
  },

  resizeMobileScrollbars: function (e) {
    var _base = Drupal.behaviors.sr_media_bar;

    if (_base.scrollBarsResized) {
      return; // Only run once
    }

    // Loop through scrollbars and refresh them
    for(var i = 0; i < _base.mediabarScrollbars.length; i++) {
      _base.mediabarScrollbars[i].refresh();
    }

    _base.scrollBarsResized = true;
  },

  convertToImage: function (amount) {

    var parent,
        pics,
        mediaBar,
        count,
        noOfTweetImages;

    // if parameter amount if defined, use it otherwise look in Drupal.settings.
    if( typeof Drupal.settings.sr_media_bar !== "undefined"){
      noOfTweetImages = Drupal.settings.sr_media_bar.number_tweet_images;
    }else{
      noOfTweetImages = amount;
    }

    mediaBar = $(this);

    parent = $(mediaBar).parent();

    // The DOM is slow; you want to avoid manipulating it as much as possible
    mediaBar.detach();

    pics = $(mediaBar).find('.sr-media-bar-image');

    // Set default count
    count = pics.length;

    // Set the loop limit
    if (noOfTweetImages > 0 && pics.length > 0) {
      count = noOfTweetImages;
    } else if (noOfTweetImages === 'all' && pics.length > 0) {
      count = pics.length;
    }

    // Loop the pictures
    for (var i = 0, il = count; i < il; i++ ) {
      //Make sure image index exists before processing
      if(typeof pics[i] !== undefined) {

        // Create image to attach onto current image span
        var img = $('<img />').attr({
          'src': pics[i].getAttribute('data-image-src') || '',
          'width': pics[i].getAttribute('data-image-width') || '',
          'height': pics[i].getAttribute('data-image-height') || '',
          'alt': pics[i].getAttribute('data-image-alt') || '',
          }
        ).appendTo(pics[i]);

      }

    }
    // Re-attach after making DOM additions
    parent.prepend(mediaBar);

  }

}; // End Drupal.behaviors.sr_media_bar

})(jQuery);
