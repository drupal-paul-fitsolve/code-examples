/*!
 * jquery.tzineClock.js - Tutorialzine Colorful Clock Plugin
 *
 * Copyright (c) 2009 Martin Angelov
 * http://tutorialzine.com/
 *
 * Licensed under MIT
 * http://www.opensource.org/licenses/mit-license.php
 *
 * Launch  : December 2009
 * Version : 1.0
 * Released: Monday 28th December, 2009 - 00:00
 */

(function($){
	
	// A global array used by the functions of the plug-in:
	var gVars = {};
	var intID = 0;
		var counter = 1;
	var goal = 450;
	var currentPercentage = 0;
	var percentageLimit = 75;
	var triggered = false;

	// Extending the jQuery core:
	$.fn.givingwheelAnim = function(opts){
	
		// "this" contains the elements that were selected when calling the plugin: $('elements').tzineClock();
		// If the selector returned more than one element, use the first one:		
		var container = this.eq(0);
	
		if(!container)
		{
			try{
				//console.log("Invalid selector!");
			} catch(e){}
			
			return false;
		}
	

		// Calling the setUp function and passing the container,
		// will be available to the setUp function as "this":
		setUp.call(container);
		
		return this;
	}
	
	function setUp()
	{
		// The colors of the dials:
		var colors = ['givingwheel'];
		
		var clock = $('.givingwheel.clock');
		
		// Markup now hardcoded for non-JS mobile usage
/*			clock = $('<div>').attr('class',colors[0]+' clock').html(
				'<div class="display"></div>'+

				'<div class="percentage"></div>'+
				
				'<div class="front left"></div>'+
				
				'<div class="rotate left">'+
					'<div class="bg left"></div>'+
				'</div>'+
				
				'<div class="rotate right">'+
					'<div class="bg right"></div>'+
				'</div>'
			);*/
			
			// Appending to the container:
		//$(this).append(clock);

		// Assigning some of the elements as variables for speed:
		clock.rotateLeft = clock.find('.rotate.left');
		clock.rotateRight = clock.find('.rotate.right');
		clock.display = clock.find('.display');
		clock.percentage = clock.find('.percentage');

		gVars[colors[0]] = clock;
	
		clock.percentage.html("0% of goal");

		$(window).scroll(function(){

			if (($(window).scrollTop() + $(window).height() - $('.givingwheel--wrapper').height()) > $('.givingwheel--wrapper').offset().top
			&& triggered==false) {
				triggered=true;

				intID = setInterval(function(){
					animation(gVars.givingwheel, counter, goal + 1);
					counter++;
				},5);
			}
		});

	}
	
	function animation(clock, current, total) {

		if (triggered && (currentPercentage < percentageLimit))  {

			var angle = (360/total)*(current+1);
			percentage = Math.floor(current / goal * 100);
		
			var element;

			if(current==0) {
				clock.rotateRight.hide();
				rotateElement(clock.rotateLeft,0);
			}
			
			if(angle<=180) {
				element = clock.rotateLeft;
			} else {
				clock.rotateRight.show();
				clock.rotateLeft.show();
				rotateElement(clock.rotateLeft,180);
				element = clock.rotateRight;
				angle = angle-180;
			}

			rotateElement(element,angle);
			
			// Setting the text inside of the display element, inserting a leading zero if needed:
			//clock.display.html("£" + (current<10?'0'+current:current));
			clock.percentage.html("Raised (" + percentage + "%)");
		}
	}
	
	function rotateElement(element,angle) {

		if (percentage >= percentageLimit ) {
			clearInterval(intID);
		}

		// Rotating the element, depending on the browser:
		var rotate = 'rotate('+angle+'deg)';
		
		if(element.css('MozTransform')!=undefined)
			element.css('MozTransform',rotate);
			
		else if(element.css('WebkitTransform')!=undefined)
			element.css('WebkitTransform',rotate);

	
		// A version for internet explorer using filters, works but is a bit buggy (no surprise here):
		else if(element.css("filter")!=undefined) {
			var cos = Math.cos(Math.PI * 2 / 360 * angle);
			var sin = Math.sin(Math.PI * 2 / 360 * angle);
			
			element.css("filter","progid:DXImageTransform.Microsoft.Matrix(M11="+cos+",M12=-"+sin+",M21="+sin+",M22="+cos+",SizingMethod='auto expand',FilterType='nearest neighbor')");
			element.css("left",-Math.floor((element.width()-160)/2));
			element.css("top",-Math.floor((element.height()-160)/2));
		}

		else {
			element.css("transform",rotate);
		}
	}
		
})(jQuery)