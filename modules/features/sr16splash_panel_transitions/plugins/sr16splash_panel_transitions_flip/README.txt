PB 9/9/14:
----------

Panel Transitions: Flip
-----------------------

This module is an implementation of a Transition plugin.


Background:
-----------

Provides a Mini-Panel layout with two regions - Front and Back.

Any type or amount of panes an be added to both regions. 

Once the Mini-Panel is embedded into a region on a page, Front will display upon a user arriving at a page. Back will display on hover or touch.

See mixin sass/mixins/_flip.scss for mixin options - $speed, $direction and $perspective etc.
See also:
 - sass/components/transition-flip.scss        (General styles for the flip effects)
 - sass/components/transition-flip--tool.scss  (Additional styling for tools)


Process to add Transition Flip to the site:
-------------------------------------------

  Create the Mini-Panel
  ---------------------

  - Go to Admin > Structure > Mini-Panels > Add
  - Name the Mini-Panel. Place it in a sensibly-named category
  - On the Context screen, click Continue
  - On the Layout screen, select 'Transitions' from the category dropdown
  - Select 'Transition: Flip' and click Next


  Add the Mini-Panel Content
  --------------------------

  The 'Front' region is what users will see on arriving at the page. The 'Back' regions is what they see on hover or touch.

  - Add any type of pane/s and multiple panes to the 'Front' region.
  - Add any type of pane/s and multiple panes to the 'Back' region.
  - Ensure the Style of each pane is set to pane but Columns are disabled. *
  - Ensure the Style of each region is set to 'No style' *
    *  This may change going forward.

  Set this Mini-Panel fo 'Flip'
  -----------------------------

  - Set the 'Default style' of this Mini-Panel to Transition: Flip
  - Check 'Use flip?'
  - Set the direction of flip
  - Add a class to this Mini-Panel. The styling should be provided by the SASS component of your plugin.
  - Add a CTA link, if required
    Note: The 'Back' region will be wrapped in the CTA if you sepcify it here

  Save the Mini-Panel

  Go to a page either in the Page Manager UI or in the IPE and add this Mini-Panel you created to a region.

