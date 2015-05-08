JP: 11/09/14
-----------

http://wiki.comicrelief.com/wiki/rnd15_Technical_Documentation#Site_Header

This feature provides the default functionality for the ESU block in the header.

It relies on the rnd15 site menu and hooks into the menu script to show and hide the ESU.

SASS Files:
* <code>components/_esu-header.scss</code>
* <code>variables/componeents/_esu-header.scss</code>

Dependencies:
* rnd15 Site Menu
* CR Marketing Prefs feature
* *CRL2 Breakpoints* & Enquire JS
* jQuery Update and Version 1.7
* jQuery Update and Version 1.7


===== Update ESU Text =====
To update the ESU text simply follow these steps:

* Login and visit this page: /admin/config/services/cr/cr_marketing_prefs
* Edit the text as required
* Save

===== GTM Tracking: Header ESU =====
An event is fired when the user steps through the ESU form and also when an error is triggered. The follow event is fired:

When error or user steps throught the forms.
<code>
{
  event: 'rnd15.esuHeader',
  activeStep : <current step the user is on e.g. step1 - step3>,
  previousStep : <step the user come from e.g. step1 - step3>,
  error : <text error message the user received>
}
</code>
