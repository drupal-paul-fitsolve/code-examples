
JW: 17/7/14
-----------

This feature provides panel slideshow style/layout plugin for rnd15. (Integration with Flexslider)

Further information on the wiki:
http://wiki.comicrelief.com/wiki/rnd15_Technical_Documentation#Slideshows

Process:
--------
Go to mini panel admin page /admin/structure/mini-panels 

Add a mini panel, select "Slideshow Layouts" from Category dropdown

"Multiple"
"Single"

Click "Continue" 

Add panes to each region

Find "Display settings" -> "Style" -> "Slidshows" -> "Next" to configuration page, choose FlexSlider Option Set, View Modes of Panes, and add extra class if needed

Click "Save" to save settings and submit changes


Style Plugin
----------------
Provide FlexSlider Optionset, includes Transition, default slide, navigation, play/pause button, auto play, and many more
You can create a new optionset here: /admin/config/media/flexslider/add

Layout Single  
----------------
Single region: one pane per slide 


Layout Multiple 
----------------
Multiple regions: allow to add mulitiple panes per slide


Templating:
----------------

Currently we have two templates but will extend and increase when required.


There are two templates you can use.
- rnd15-site-slideshows-layout-multiple.tpl.php
- rnd15-site-slideshows-layout-single.tpl.php

These are basic templates that you can copy paste and modify to your liking.
