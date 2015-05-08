JP: 01/10/14
-----------

http://wiki.comicrelief.com/wiki/rnd15_Tracking

The rnd15 GTM feature provides the global dataLayer JS object.

Each piece of JS functionality on the site that needs to provide additional tracking information to Google Tag Manager simply needs to push an event object to this global array.

Dependencies:
* Modernizr
* Enquire.js

===== Tracking with the Data Layer =====
Tracking is easily done by creating an event object and pushing it to the global dataLayer array.

Here is an example you can use:
<pre>
/*
 * Helper function to track the current breakpoint
 */
trackActiveBreakpoint: function() {
  var _base = Drupal.behaviors.rnd15gtm;
  var breakpointEvent = {};
  var activeBreakpointString = String(Drupal.settings.crl2.breakpointActive);

  if(Drupal.settings.crl2.breakpointFrom === null) {
    breakpointEvent.event = 'rnd15.breakpoint';
    breakpointEvent.breakpoint = activeBreakpointString;
  } else {
    var fromBreakpointString = String(Drupal.settings.crl2.breakpointFrom);
    breakpointEvent.event = 'rnd15.breakpointSwitch';
    breakpointEvent.breakpointFrom = fromBreakpointString;
    breakpointEvent.breakpointTo = activeBreakpointString;
  }
  
  dataLayer.push(breakpointEvent);
},
</pre>

===== Debugging =====
Debugging is easy. The easiest way is to simply open the console in Chrome or Firefox and check the dataLayer object by typing it into the console and pressing enter.

The other option is to log into Google Tag Manager, click on the version you wish to use and use the debug mode. Then visit the site you are working on and checkout the debug frame at the bottom of your browser with real time events coming through the data layer.

===== GTM Tracking: Breakpoint =====
An event is fired on initial load and also when resizes/switching from landscape to portrait. Below is a breakdown of the event objects fired and naming conventions.

Initial page load:
<code>
{
  event: 'rnd15.breakpoint',
  breakpoint: <the breakpoint e.g. xs, sm, md or lg>,
}
</code>

On resize or portrait/landscape switching e.g. tablet:
<code>
{
  event: 'rnd15.breakpointSwitch',
  breakpointFrom: <the breakpoint e.g. xs, sm, md or lg>,
  breakpointTo: <the breakpoint e.g. xs, sm, md or lg>,
}
</code>

 ===== GTM Tracking: Touch =====
An event is fired on initial load to track if the user is on a touch or non-touch device. Below is a breakdown of the event objects fired and naming conventions.

Initial page load:
<code>
{
  event: 'rnd15.touch',
  hasTouch: <false/true>,
}
</code>
