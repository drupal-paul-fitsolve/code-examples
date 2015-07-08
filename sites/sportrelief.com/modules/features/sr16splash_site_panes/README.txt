JP: 01/12/14
JW: 27/08/14
-----------

This feature provides the basic panes for sr16splash.

Further information on the wiki:
http://wiki.comicrelief.com/wiki/sr16splash_Technical_Documentation#sr16splash_Technical_Documentation

Process:
--------
Open the IPE or Panel Content editor and add one of the following panes to a panels region:

"Image Pane"
"Video Pane"
"Text Pane"
"SVG Pane"

Save and ensure you select the panel style to "Pane".

Image panes automatically inherit the correct picture group based on the panel column settings OR region picture settings set in the layout plugin inc file.

Text Pane:
--------
Title + Text (Full HTML, Filtered, WYSIWYG or Plain)

This is a generic text pane that will be used for most content. 

Image Pane:
--------
Title + Image

The image pane is only used for images and titles. If you wish to add more content please create new fieldabled panel entity in sr16splash Site Panes and document it here accordingly.

Video Pane:
--------
Title + Video Start Frame + Video YouTube URL

This is a simple pane to display a start frame and play a video on click. Additional information and functionality is provided via the sr16splash_site_media feature.

SVG Pane:
--------
Title + SVG file

The SVG pane is used to add SVG files to panes.

The SVG field itself is provided by crl2_svg_field in sites/all/modules/custom/cr_layout_v2/crl2_svg_field

An SVG pane defines in code a fieldable panel pane that uses this field.

Templating:
--------
There are two templates you need to bear in mind here.

Panels Pane
This is what the grid style plugin uses to output the fieldable panel pane within.

Fieldable Panel Pane
This is what renders the fields/content of the custom panel. 

There are five templates in CR Layout 2 that you can use.
- fieldable-panels-pane--image.tpl.php
- fieldable-panels-pane--text.tpl.php
- fieldable-panels-pane--video.tpl.php
- fieldable-panels-pane.tpl.php
- panels-pane.tpl.php

You can also override the panels-pane specific fieldable panel panes by bundle as such:
panels-pane--fieldable-panels-pane--<ENTITY BUNDLE>.tpl.php

For example:
- panels-pane--fieldable-panels-pane--media-wall.tpl.php

These are basic templates that you can copy paste and modify to your liking.

If you want to override a template based on the view mode, simple use:
fieldable-panels-pane--<TYPE>--<VIEW MODE MACHINE NAME>.tpl.php

For example:
- fieldable-panels-pane--image--full.tpl.php

Define Picture Groups for Regions:
--------
Picture groups set in the panels layout inc files are treated in favor over the pane settings for images. This comes in handy for fixed layouts such as the media wall. To set these, simply specify the picture groups as below. Please ensure the array key of the region matches the one you specified under "regions":

// Plugin definition.
$plugin = array(
  'title' => t('CR WALL'),
  'icon' => 'preview.png',
  'category' => t('CR Content Layouts'),
  'theme' => 'cr_wall_panel',
  'regions' => array(
    'first' => t('First'),
  ),
  'region_picture_groups' => array(
    'first' => array(
      'breakpoints.theme.cr_layout_v2.xs' => array(
        '1x' => 'col_4_xs',
        '2x' => 'col_4_xs_2x',
      ),
      'breakpoints.theme.cr_layout_v2.sm' => array(
        '1x' => 'col_12_sm',
        '2x' => 'col_12_sm_2x',
      ),
      'breakpoints.theme.cr_layout_v2.md' => array(
        '1x' => 'col_12_md',
        '2x' => 'col_12_md_2x',
      ),
      'breakpoints.theme.cr_layout_v2.lg' => array(
        '1x' => 'col_12_lg',
        '2x' => 'col_12_lg_2x',
      ),
    ),
  ),
);