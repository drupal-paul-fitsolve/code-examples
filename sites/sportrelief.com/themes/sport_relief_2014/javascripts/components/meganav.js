/**
 * @file
 * Functinality for the Mega menu
 */

(function ($) {

	var mobileLoaded = false;
	var desktopLoaded = false;

  $.fn.megaMenu = function( context, deviceGroup, menuElement) {
  	$.fn.megaMenu.context = context;
  	$.fn.megaMenu.deviceGroup = deviceGroup;
		if(typeof this.each == 'function') {
	    return this.each(function() {
				$.fn.megaMenu.init(this, context, menuElement, function() {

					//This callback decides whether to apply mobile or desktop functionality (pageload only).
					if(deviceGroup == 'desktop') {
						$.fn.megaMenu.desktop( context);
					}
					else {
						$.fn.megaMenu.mobile(this, context);
					}
				});
	    });
	  }
  };

	// Define our init function.
	$.fn.megaMenu.init = function( megaMenuWrapper, context, menuElement, callback ) {
	  $.fn.megaMenu.megaMenu = $(megaMenuWrapper),

		graceTime = 1000, // How long they have to move to the mega menu
		hoverTicker = null;

	  $.fn.megaMenu.menu = $(menuElement);

		$.fn.megaMenu.lastMenuItem = {
			parentItem: null,
			childMenu: null,
			childMenuHovered: false
		};

		if(typeof callback == 'function') {
			callback();
		}
	};

	// Remove hover events
	$.fn.megaMenu.pause = function() {

		if($.fn.megaMenu.deviceGroup == 'desktop') {

			$('a', $.fn.megaMenu.menu).off('mouseenter mouseleave');
		}
	}
	// Add back hover events
	$.fn.megaMenu.unpause = function() {

		if($.fn.megaMenu.deviceGroup == 'desktop') {

			$.fn.megaMenu.desktop($.fn.megaMenu.context);
		}
	}




	$.fn.megaMenu.desktop = function( context ) {


		if (!$('.menu-toggle').hasClass('is-collapsed')) {
			$('.menu-toggle').addClass('is-collapsed');
			$('.zone-menu-wrapper').addClass('is-collapsed');
			$('.menu li.has-children').addClass('is-collapsed');
		}

			$('.menu-toggle', context).off('click');


			$('a', $.fn.megaMenu.menu).hover(function () {

				// Hide the previous active menu
				$.fn.megaMenu.hideMenu();
				// Reveal the new one if it exists
				var childMenuId = $(this).attr('data-minipanel-target');
				if (childMenuId) $.fn.megaMenu.revealMenu($(this).parent(), childMenuId, context);
			}, function () {
				// Clear any existing tickers
				clearTimeout(hoverTicker);
				// If the parent menu item is left and the user didn't move to the mega
				// menu then hide/remove classes.
				if ($.fn.megaMenu.lastMenuItem.childMenu && !$.fn.megaMenu.lastMenuItem.childMenuHovered) {
					// Don't hover out immediately as they may be finding their way to
					// the mega menu.
					hoverTicker = setTimeout($.fn.megaMenu.hideMenu, graceTime);
				}
			});
			$('a', $.fn.megaMenu.menu).click(function (e) {
				if (('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch) {
					if($(this).parent().hasClass('expanded')) e.preventDefault();
				}
			});
			if (('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch) {
				$(document).click(function (e) {
			    if (!$.fn.megaMenu.menu.is(e.target) // if the target of the click isn't the container...
			        && $.fn.megaMenu.menu.has(e.target).length === 0) // ... nor a descendant of the container
			    {
		        clearTimeout(hoverTicker);
						$.fn.megaMenu.hideMenu();
			    }
				});
			}
	}


	$.fn.megaMenu.mobile = function( thisElement, context ) {
		//Sort Menu toggle button - hide/show

			$('a', $.fn.megaMenu.menu).unbind('mouseenter mouseleave');

			var menu = $.fn.megaMenu.menu;
			menu.addClass('is-collapsed');
			$('.menu-toggle', context).addClass('is-collapsed');
			$('.menu li.expanded .menu', context).each(function(){
				$(this).parent().removeClass('expanded').addClass('is-collapsed has-children');
			});

			$('.zone-menu-wrapper .menu .menu .menu', context).each(function(){
				$(this).addClass("tertiary-menu").parent().addClass('tertiary-parent');
			});

			$('.menu-toggle', context).on('click', null, function (e) {
				$(this).toggleClass('is-collapsed');
				menu.toggleClass('is-collapsed');

				$('.cr-mediaelement-video iframe').toggleClass('navhide');

				//Collapse all child menus that are open if the menu is toggled off
				if(menu.hasClass('is-collapsed')) {
					$('.menu li.has-children').addClass('is-collapsed');
				}
			});


			//Sort Children Menu - show/hide
			$('.menu li.has-children', context).on('click', 'a:not(li li a)', function (e) {
				var parentList =  $(this).parent();
				e.stopPropagation();

				if(parentList.hasClass('is-collapsed')) {
					$('.menu li.has-children').addClass('is-collapsed');
					parentList.removeClass('is-collapsed');
				} else {
					parentList.addClass('is-collapsed');
				}

				e.preventDefault();
			});


			$('.tertiary-parent', context).on('click', 'a', function (e) {
				
				e.stopPropagation();

				if ( $(this).parent().hasClass('is-collapsed') ) {
					$(this).parent().removeClass('is-collapsed');
					} else {
						$(this).parent().addClass('is-collapsed');
					}

				e.preventDefault();
			});
	}

	$.fn.megaMenu.revealMenu = function(parentItem, childMenuId, context) {


		// Get mega menu and set classes
		$.fn.megaMenu.megaMenu.addClass('is-active');
		$.fn.megaMenu.lastMenuItem.parentItem = parentItem.addClass('has-dropdown');
		$.fn.megaMenu.lastMenuItem.childMenu = $.fn.megaMenu.megaMenu.find('#block-panels-' + childMenuId, context).addClass('is-active');

		// Listen for mega menu hover and set a flag to true
		$.fn.megaMenu.lastMenuItem.childMenu.on('mouseenter.crdesktop', null, function () {
			$(this).off('mouseenter.crdesktop');
			$.fn.megaMenu.lastMenuItem.childMenuHovered = true;

			// Remove any existing hover tickers to stop the menu
			// being hidden
			clearTimeout(hoverTicker);
		});

		// Hide mega menu if it is left
		$.fn.megaMenu.lastMenuItem.childMenu.on('mouseleave.crdesktop', null, function () {

			$(this).off('mouseleave.crdesktop');
			clearTimeout(hoverTicker);
			hoverTicker = setTimeout($.fn.megaMenu.hideMenu, graceTime);
		});
	}

	$.fn.megaMenu.hideMenu = function() {
	if ($.fn.megaMenu.lastMenuItem.childMenu) {

		// Remove classes and reset the $.fn.megaMenu.lastMenuItem object
		$.fn.megaMenu.megaMenu.removeClass('is-active');
		$.fn.megaMenu.lastMenuItem.parentItem.removeClass('has-dropdown');
		$.fn.megaMenu.lastMenuItem.childMenu.removeClass('is-active');

		$.fn.megaMenu.lastMenuItem.parentItem = null;
		$.fn.megaMenu.lastMenuItem.childMenu = null;
		$.fn.megaMenu.lastMenuItem.childMenuHovered = false;
	}

	// Remove any existing hover ticker
	clearTimeout(hoverTicker);
	}

})(jQuery);
