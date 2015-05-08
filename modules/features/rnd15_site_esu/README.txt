JP: 16/10/14
-----------

http://wiki.comicrelief.com/wiki/rnd15_Technical_Documentation#ESU_Strip_Pane

==== ESU Strip Pane ====

The ESU Strip pane is only used for the email sign up (DASP). The core functionality is provided by the sites/all/modules/custom/all/cr_marketing_prefs module.

SASS Files:
* <code>components/_esu-strip.scss</code>
* <code>variables/componeents/_esu-strip.scss</code>

Dependencies:
* CR Marketing Prefs

===== Add ESU Strip =====
* Login and visit the page where you want to add the pane
* In the relevant region click on the Plus symbol
* Under "Email Sign Up" select the "Promo Banner"
* Fill out the text as required
* Hit Save
* Ensure the region has the "Section" style applied to it
* Ensure the ESU Pane has the 12 columns applied to it

===== GTM Tracking: Header ESU =====
An event is fired when the user steps through the ESU form and also when an error is triggered. The follow event is fired:

When error or user steps throught the forms.
<code>
{
  event: 'rnd15.esu',
  activeStep : <current step the user is on e.g. step1 - step3>,
  previousStep : <step the user come from e.g. step1 - step3>,
  error : <text error message the user received>
}
</code>