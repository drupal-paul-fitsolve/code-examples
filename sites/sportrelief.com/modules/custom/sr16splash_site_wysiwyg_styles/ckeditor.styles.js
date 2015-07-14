/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet( 'drupal',
    [

            //Header styles.
            { name : 'Heading 1 XLarge', element : 'h1', attributes : { 'class' : 'type--xl'}},
            { name : 'Heading 1 Large',  element : 'h1', attributes : { 'class' : 'type--lg'}},
            { name : 'Heading 1',        element : 'h1', attributes : { 'class' : 'type--def'}},
            { name : 'Heading 2',        element : 'h2', attributes : { 'class' : ''}},
            { name : 'Heading 3',        element : 'h3', attributes : { 'class' : ''}},


            // Paragraph styles.
            { name : 'White paragraph'	, element : 'p', attributes : { 'class' : 'type--white' } },
            { name : 'Pink paragraph'	, element : 'p', attributes : { 'class' : 'type--pink' } },
            { name : 'Orange paragraph'	, element : 'p', attributes : { 'class' : 'type--orange' } },
            { name : 'Red paragraph'	, element : 'p', attributes : { 'class' : 'type--red' } },
            { name : 'Purple paragraph'	, element : 'p', attributes : { 'class' : 'type--purple' } },
            { name : 'Blue paragraph'	, element : 'p', attributes : { 'class' : 'type--blue' } },
            { name : 'Aqua paragraph'	, element : 'p', attributes : { 'class' : 'type--aqua' } },
            { name : 'Green paragraph'	, element : 'p', attributes : { 'class' : 'type--green' } },
            { name : 'Yellow paragraph'	, element : 'p', attributes : { 'class' : 'type--yellow' } },
            { name : 'Grey paragraph'	, element : 'p', attributes : { 'class' : 'type--grey' } },
            { name : 'Black paragraph'	, element : 'p', attributes : { 'class' : 'type--black' } },
            { name : 'XLarge paragraph'	, element : 'p', attributes : { 'class' : 'type--xl' } },
            { name : 'Large paragraph'	, element : 'p', attributes : { 'class' : 'type--lg' } },
            { name : 'Body paragraph'	, element : 'p', attributes : { 'class' : '' } },
            { name : 'Small paragraph'	, element : 'p', attributes : { 'class' : 'type--sm' } },

            // Span styles.
            { name : 'XLarge span'  	, element : 'span', attributes : { 'class' : 'type--xl' } },
            { name : 'Large span'    	, element : 'span', attributes : { 'class' : 'type--lg' } },
            { name : 'Body span'    	, element : 'span', attributes : { 'class' : '' } },
            { name : 'Small span'    	, element : 'span', attributes : { 'class' : 'type--sm' } },
            { name : 'Light type'    	, element : 'span', attributes : { 'class' : 'type--light' } },
            { name : 'Semibold type'   	, element : 'span', attributes : { 'class' : 'type--semibold' } },
            { name : 'UPPERCASE type'  	, element : 'span', attributes : { 'class' : 'type--upper' } },
            { name : 'Not uppercase'  	, element : 'span', attributes : { 'class' : 'type--non-upper' } },
            { name : 'Italic type'  	, element : 'span', attributes : { 'class' : 'type--italic' } },
            { name : 'Left Aligned'  	, element : 'span', attributes : { 'class' : 'type--left' } },
            { name : 'Center Aligned'  	, element : 'span', attributes : { 'class' : 'type--centred' } },
            { name : 'Right Aligned'  	, element : 'span', attributes : { 'class' : 'type--right' } }

    ]);
}