README for CRL_v2 - http://wiki.comicrelief.com/wiki/CR_Layout_V2

CR Layout V2
CRL2 is the predecessor to CR Layout 1 used for SR14 and CR13. It is a base theme for Comic Relief websites to be used for RND15.

Omega4 Info
The documentation is a little thin on the ground but you can find it here - https://www.drupal.org/node/1768686 There is also a screencast by the creators here - http://youtu.be/CmTuvzbPduI along with a tutorial series here - https://www.youtube.com/playlist?list=PLLnpHn493BHH5nnK2dKE_42l1oXA6Tq6H

Running Omega-Guard
To automatically compile CSS you need to run omega guard. When working on CRL2, run the following command:

drush --uri=http://layout.comicrelief.com omega-guard

Theme File Structure
Locations for particular files are outlined below:

Templates - sites/all/themes/custom/cr_layout_v2/templates
JS - sites/all/themes/custom/cr_layout_v2/js
SASS - sites/all/themes/custom/cr_layout_v2/sass
CSS - sites/all/themes/custom/cr_layout_v2/css
Layouts - sites/all/themes/custom/cr_layout_v2/layouts
Libraries - sites/all/themes/custom/cr_layout_v2/libraries
Images - sites/all/themes/custom/cr_layout_v2/images
Panels - sites/all/themes/custom/cr_layout_v2/panels
Omega Template Files
The main template file for CRL2 is the "CR Responsive Layout" template. It's an omega layout template consisting of a header, content and footer region. This essentially replaces the page.tpl file in a vanilla Drupal installation.

You can find it here: sites/all/themes/custom/cr_layout_v2/layouts/cr-responsive

Omega templates can be contextually switched. This may be helpful if we want a template that for example, is more simple, without the main navigation.

The panel content template files are used in conjunction with he panel style plugin, providing the markup for panes along with the variables needed.

About Bootstrap
Bootstrap has been integrated into CRL2. To get more information on Bootstrap, the documentation is here http://getbootstrap.com/css/#grid-media-queries.

CRL2 does not use all of the Bootstrap functionality, only the grid and functions related to it as follows:

Columns - http://getbootstrap.com/css/#grid-options
Push/Pull - http://getbootstrap.com/css/#grid-column-ordering
Offset - http://getbootstrap.com/css/#grid-offsetting
Create a new Omega Layout Template
Replicate the cr-responsive folder and rename as you wish. Make sure file names and references in layout.inc are updated accordingly.

Panel Templates
The "CR Content" template is an eight row panel template file. It is only used for panel content. It gives us the flexibility to exactly define how the content will look. It does not have the same overrides as CR Layout V1, where excessive classes including equal heights are added programmatically. This is all controlled via the Panel Style plugin including, setting Grid Classes, Equal Heights Container/Element classes and more.

How the Panels Style Plugin Works with Columns
The plugin adds classes to the panel and the panes within them based on how you want to display the content.

Columns are laid out in the next section 'Breakpoints and SASS Usage'.

To summarise, in the pane style settings you can select the column width (1-12 or inherit) for extra small, small, medium and large screen sizes. Along with being able to reorder content using push and pull in the same fashion.

Breakpoints and SASS Usage
We have the following breakpoints:

           Extra small devices
           Phones (<768px)
           Small devices
           Tablets (≥768px)
           Medium devices
           Desktops (≥992px)
           Large devices
           Desktops (≥1200px)
Grid behavior	Horizontal at all times	Collapsed to start, horizontal above breakpoints
Container width	None (auto)	720px	950px	1200px
Class prefix	.col-xs-	.col-sm-	.col-md-	.col-lg-
# of columns	12
Column width	Auto	[TBC]px	[TBC]px	[TBC]px
Gutter width	30px (15px on each side of a column)
Nestable	Yes
Offsets	Yes
Column ordering	Yes
SASS Breakpoint Examples
SASS Variables in: sites/all/themes/custom/cr_layout_v2/sass/variables/_breakpoints.scss

$screen-xs
$screen-sm
$screen-md
$screen-lg
$highres

You can pass in one parameter as below to target a specific breakpoint:

// Everything above the tablet breakpoint of 720px;
@include breakpoint($screen-sm) {
// Your CSS/SASS
}

To combine multiple queries, use parentheses to wrap the two variables. For example, to target the small breakpoint high resolution, use the following:

@include breakpoint(($screen-sm $highres)) {
// Your CSS/SASS
}

How to use Equal Heights
In the pane settings you can select the 'Match Heights' tick box and pick a group from the dropdown menu to apply it to, or create one.

How to Override Theme Functions
Omega 4 lays out process and preprocess functions differently to default by separating each function into it's own group of files instead of clogging up template.php so do not use template.php. If you wish to override a theme function, do the following:

Preprocess
Go to sites/all/themes/custom/cr_layout_v2/preprocess
Create an .inc file for your function. the file should be named in accordance with the function, if your function is theme_preprocess_block your file should be name block.preprocess.inc
Process
Go to sites/all/themes/custom/cr_layout_v2/process
Create an .inc file for your function. the file should be named in accordance with the function, if your function is theme_process_comment_wrapper your file should be name comment-wrapper.process.inc