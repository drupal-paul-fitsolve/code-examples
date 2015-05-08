JP: 28/11/14
-----------
Developer Documentation:
http://confluence.comicrelief.com/display/rnd15Documentation/rnd15+Site+Media

Video Panes Editor Documentation:
http://confluence.comicrelief.com/display/rnd15EditorDocumentation/How+to+add+a+Video+Pane

Video Pages Editor Documentation:
http://confluence.comicrelief.com/display/rnd15EditorDocumentation/How+to+add+a+Video+Page

Inline Video Row Editor Documentation:
http://confluence.comicrelief.com/display/rnd15EditorDocumentation/How+to+add+an+Inline+Video+Row

GTM Tracking for Videos documented here:
http://confluence.comicrelief.com/display/rnd15EditorDocumentation/GTM+Event+Tracking

SASS Components:
* <code>components/_media.scss</code>
* <code>components/_media-video.scss</code>

Template Files:
* templates/field/field--field_site_video_url.tpl.php
* templates/field/field--field_site_image--video.tpl.php

##############
This module provides the basic Video Implementation on the Red Nose Day 2015 website.

Please refer to the Video Pane﻿ or Video Page﻿ Editor Documentation﻿ on how to add the relevant video content.

The Video Panes are handled via the rnd15 Site Panes feature and the pages are handled separately in the rnd15 Site Media Video feature.

===== GTM Tracking =====
Several events are fired and pushed to the dataLayer listed below. For further information, please refer to the media.js file or the confluence documentation here: http://confluence.comicrelief.com/display/rnd15EditorDocumentation/GTM+Event+Tracking

loadedmetadata
Initial load of the meta data by Google JS API. Now this can happen several times which is confirmed on IOS devices. The problem is, on autoplay/loop, this is also triggered once the video has finished.

play
Play is triggered EVERYTIME a play is initiated. Either on autoplay, via the controls play button or the big play button over the video itself

playfirst
Play first is triggerd on the first occurence of play. This can be via autoplay or user interaction. It's the only reliable way of knowing that a video play has been triggered.

playing
Once play has initiated and the video has buffered, this event is triggered to notify that the video is actually playing.

pause
When the video was paused by the user.

ended
Once the video has ended, this event has been fired.

% played
There are four points at which the playback points will be reported. These are 0%, 25%, 50% and 100%