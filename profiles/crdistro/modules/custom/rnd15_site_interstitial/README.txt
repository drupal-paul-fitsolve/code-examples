JP: 03/10/14
-----------

http://wiki.comicrelief.com/wiki/RND15_Interstitial

http://confluence.comicrelief.com/display/rnd15EditorDocumentation/How+to+add+a+Age+Check+on+a+link

An interstitial is a message modal/overlay that is provided to a user when clicking on a link. They will receive set message via a data attribute and will be redirected to the URL of the link within the set delay.

SASS Components:
* <code>components/_interstitial.scss</code>
* <code>variables/components/_interstitial.scss</code>

JS Library Used:
* sites/all/libraries/interstitial/interstitial.jquery.js

Dependencies:
* Menu Attributes

===== Inline Links =====
To make a content link provide an interstitital simply set the link up with the relevant data attributes. Please note that the i.seconds only needs applying if you want the seconds to count down.

<a href="http://www.comicrelief.com" data-interstitial="My message here. &lt;i class='seconds'&gt;6&lt;/i&gt;" data-interstitial-delay="6000">Interstitial link</a>

===== Menu Links =====
Adding an interstitial message to a menu link is simple. This module works in conjunction with the menu attributes module which allows you to add the data interstitial and delay attributes to trigger the modal.

To add the interstitial message simply follow these steps:

# Login to the RND15 site
# Edit the menu you wish to update here: /admin/structure/menu
# Edit the link
# Under "Attributes", add a message to Interstitial and set the delay in milliseconds
Optional: If you wish to provide a countdown timer, simply add the following wrapper around the seconds. The script will automatically count down the number as long as it matches up with the delay. Example:
<pre>"My message here redirecting to <a href="#">site</a> in <i class="seconds">6</i> seconds."</pre>

=====  Custom Interstitial =====
Simply use a new selector and pass in a new options object to override the settings. For more information simply check out the interstitial.js file located in the JS module folder.

=====  Age Check Interstitial =====
To check the age of a user we have an age check interstitial that prompts the user to enter their age. Based on the outcome, users can be redirected to different URLs.

To add an age check to a link simply ensure it has the data-age-check-interstitial attribute applied. Further options can be overriden via the -options attribute as in the example below:
<a href="/who-nose/competition" class="btn btn-red" data-age-check-interstitial data-age-check-interstitial-options='{"promptRedirectUrl": "/who-nose/competition?age=under16"}'>Enter Competition</a>

More details can be found on the confluence page or in the interstitial.ageCheck.jquery.js file located in sites/all/libraries/interstitial.
