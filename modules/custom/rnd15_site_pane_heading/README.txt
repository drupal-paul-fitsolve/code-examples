rnd15 Fieldable Panels Pane Header Styles module.
=================================================

This module provides form elements that allow selection of the header tag
and custom css classes for the header element of a text fieldable_panels_pane.

The controls are optional and hidden by a CTools dependency rather than a
collapsible fieldset for consistency with pre-existing form elements.

The pane type is detected via its bundle and has two modes of operation.
In both cases the styles are saved as part of the pane style settings.

1) Panel context pane edit form.
--------------------------------
This method describes creation of a pane during while editing a panel.
The panes persistence is dependent on the panel as if the panel is not saved
modifications to its constituent panes should also not be saved.

When the container panel is saved, the pane style settings will be saved.

2) Entity form.
---------------
This method describes the creation of a pane via the fieldable_panels_pane
enitity form, creating a standalone fieldable_panels_pane entity.

The pane styles are saved by directly updating or creating pane style settings
when the pane entity is saved.

Removing header styles
----------------------
Unchecking the checkbox to change the headers appearance will hide the pane
header styles form fields and remove the header modifications on save by
setting the header style values to their defaults.

The custom classes field allows up to 120 characters and will refuse invalid
css classes - see rnd15_site_pane_heading_validate() for details.

Custom CSS class rules
------------------------
The custom classes field allows up to 120 characters and will refuse characters
outside the following criteria:

* the hyphen (U+002D)
* a-z (U+0030 - U+0039)
* A-Z (U+0041 - U+005A)
* the underscore (U+005F)
* 0-9 (U+0061 - U+007A)
* ISO 10646 characters U+00A1 and higher