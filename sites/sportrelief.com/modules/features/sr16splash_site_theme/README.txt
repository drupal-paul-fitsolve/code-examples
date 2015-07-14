PB: 29/7/14
-----------

This feature provides the theme settings for the sr16splash theme - sr16splash.

Our initial thought was to provide all theme settings in the sr16splash.info file in the theme.
However, after much testing, the CSS/JS exclude functionality in Omega is a bit buggy.
The JS excludes seem to overwrite the CSS excludes intermittently.
So, I decided to store all theme settings in this feature.
Obviously, the sr16splash theme still complains that theme settings are being served form a variable.

Further information on the wiki:
http://wiki.comicrelief.com/wiki/sr16splash_Technical_Documentation#sr16splash_Theme