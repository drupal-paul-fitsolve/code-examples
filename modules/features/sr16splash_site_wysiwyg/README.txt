@author: Carl Hinton for Comic Relief 20/11/14
-----------

This feature provides the ckeditor settings for sr16splash.

This includes:

The ckeditor profiles - this outlines which widgets appear on the WYSIWYG when used in defined instances.
The ckeditor filters  - filters are used to clean-up html after entering into a textarea, and ensure the site is not
                        broken by what an editor adds. We hope to add htmltidy later to ensure W3C compliance.
User permissions      - users need to be given the permission to use a text format that is associated with a ckeditor
                        profile in order for the user to see a WYSIWYG in textareas

NB. The wysiwyg text format is NOT defined within this feature. This is defined within cross-site features.

Further information on confluence:
http://jira.comicrelief.com:8090/display/sr16splashDocumentation/WYSIWYG+Editor