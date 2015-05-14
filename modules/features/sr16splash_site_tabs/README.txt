
AP: 10/09/14
-----------

This feature provides the layout and plugins to create tabbed content on the sr16splash site.

Further information on the wiki:

http://wiki.comicrelief.com/wiki/sr16splash_Technical_Documentation#Tabs

SASS Components and Variables:
* <code>components/_tabs.scss</code>
* <code>variables/components/_tabs.scss</code>


=====  Creating tabbed content =====

Create a new minipanel, maybe using the category 'Tabs' to keep things ordered.
Accept default Context setting
Choose 'Tab Layouts' from Layout category dropdown (currently just one layout)

Now add your content panes to each tab region (First tab, Second tab etc), setting the column widths and so on using the Pane style plug-in as usual.

Add one more pane to each region which will act as the 'Title Pane', and fill in this pane's title field, leaving the body or any other fields
empty. This pane isn't rendered on the page, but the title value is used to label the button that represents this region. This functionality
will be extended in the future to pull-in images, SVGs etc, to act as button labels.

For each region, apply the 'Tabs Title' style plug-in, and choose your title pane's title from the dropdown.

Finally, go to Display Settings, and select the 'Tab' style plug-in. Here you can apply a H3 heading above the tab buttons, choose which of your tab regions
the page opens on by default, and add another other extra classes you may need.


=====  Javascript =====

This features uses the History javascript plugin (https://github.com/browserstate/history.js/) for href and URL-based
switching between different 'states', allowing specific tab content to be shared and bookmarked.

The tab region name supplied by the title pane (shown in the tab button) is what is used by the module to produce
the required hrefs and IDs to switch between content:
pagetitle#/your-pane-title-and-now-tab-name

The custom Javascript also adds in additional functionality to allow smooth jQuery-based scrolling to a named anchor
sitting in that particular region:
pagetitle#/your-pane-title-and-now-tab-name/your-anchor

=====  Templating =====

There's currently just one template available, which provides up to 10 tab regions: sr16splash-site-tabs.tpl
