JP: 03/09/14
-----------

http://wiki.comicrelief.com/wiki/sr16splash_Technical_Documentation#Site_Navigation

The main navigation and touch functionality is provided by the *sr16splash_site_menu* feature.

The sr16splash site menu is a light weight feature that provides a touch menu via JS using Drupal's "Main Menu". 

SASS Components:
* <code>components/_nav-normal.scss</code>
* <code>components/_nav-touch.scss</code>
* <code>components/_button-nav.scss</code>

Dependencies:
* *CRL2 Breakpoints* & Enquire JS
* jQuery Update and Version 1.7

===== Touch Menu =====
The touch navigation is triggered if the user is on a touch device OR if the user is on the XS or SM breakpoint.

The touch navigation specifically switches from SM to MD when turning from portrait to landscape - and vice versa.

===== Debugging Touch Menu on non-touch device =====
The JS script has a debug mode. To control this follow these steps:

# Enable by appending your URL with "?touch=true".
Note: A cookie is set to show the touch menu styling and also trigger the scripts to run.
# To turn off the touch menu simply append "?touch=false" to the URL. The cookie is deleted and menu reverted back to the normal version.

=====  Navigation Link IDs =====
For tracking and QA testing all menu links in the header are provided with a menu ID:

<code>#menu-<menu title></code>

=====  Navigation Link IDs - Touch only parent link =====
Every nested level has a copy of the parent level menu item to provide a link to go to that landing page e.g.:

* First Level (Opens the child menu)
** First Level Link Page for touch
** Second Level Link

The "First Level Link Page" has an ID appended with '-touch' e.g.:

<code>#menu-<menu title>-touch</code>

=====  Navigation Buttons (Button Nav) =====
Navigation buttons are provided for touch and the normal navigation.

These are handled and should only be provided by the sr16splash_site_menu feature and javascript to keep them consistent. All style are located in:

<code>sass/components/_button-nav.scss</code>

=====  Creating a New Nav Button =====
# Add the button markup to:
<code>rednoseday.com/themes/custom/sr16splash/templates/block/block--nav.tpl.php</code>

# Leave the relevant styling or add the styling to:
<code>sass/components/_button-nav.scss</code>

# Duplicate the "sr16splash.emailSignup.js" located here:
<code>rednoseday.com/modules/features/sr16splash_site_menu/js/sr16splash.emailSignup.js</code>

# Create the correct namespace convention for the new JS and provide your own logic to show/hide the resulting element.

===== Turning on the simple nav =====

# Go to the sr16splash_site_header_simple context and add the path of the page to add the simple nav

# Go to the sr16splash_site_header context and add the path of the page to remove the main site header

This will result in a simple nav being displayed on the desired page.

===== Turning on the Kids Nav =====

# Go to the page manager page and add the class 'kids__page-wrapper'

# Edit the menu, via /admin/structure/menu/manage/main-menu

# Edit the link you wish to hide for kids and add the "kids__item-hide" class

For more info please go to http://confluence.comicrelief.com/display/sr16splashDocumentation/Kids+Nav