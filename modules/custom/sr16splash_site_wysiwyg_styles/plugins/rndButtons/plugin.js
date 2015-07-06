/*
 CKEditor Plugin - provides bespoke html injection into the ckeditor textarea.
 @author Carl Hinton for Comic Relief.
 */
CKEDITOR.plugins.add( 'rndButtons',
    {
        init: function( editor )
        {
            editor.addCommand( 'rndButtonsDialog', new CKEDITOR.dialogCommand( 'rndButtonsDialog' ) );

            editor.ui.addButton( 'rndButtons',
                {
                    label: 'Insert a RND button',
                    command: 'rndButtonsDialog',
                    icon : this.path + '/rndButtons.png'
                } );

            CKEDITOR.dialog.add( 'rndButtonsDialog', function( editor )
            {
                return {
                    title : 'RND Button Properties',
                    minWidth : 400,
                    minHeight : 200,
                    contents :
                        [
                            {
                                id : 'general',
                                label : 'Settings',
                                elements :
                                    [
                                        {
                                            type : 'html',
                                            html :
                                                'This lets you create RND button links see ' +
                                                '<a target="_blank" href="' +
                                                Drupal.settings.sr16splash_site_wysiwyg_styles.docs + '">' +
                                                'editor documentation</a>.'
                                            },
                                        {
                                            type : 'text',
                                            id : 'id',
                                            label : 'Identifier',
                                            validate : CKEDITOR.dialog.validate.notEmpty( 'You must have an identifier.' ),
                                            required : true,
                                            default : '{page slug}_{row number}_{number, if applicable}',
                                            commit : function( data )
                                            {
                                                data.id = this.getValue();
                                            }
                                        },
                                        {
                                            type : 'html',
                                            html :
                                            '<sed>Please supply an ID for tracking for example: ' +
                                            '"schools-resources_1_2"</sed>'
                                        },
                                        {
                                            type : 'text',
                                            id : 'url',
                                            label : 'URL',
                                            validate : CKEDITOR.dialog.validate.notEmpty( 'The link must have a URL.' ),
                                            required : true,
                                            commit : function( data )
                                            {
                                                data.url = this.getValue();
                                            }
                                        },
                                        {
                                            type : 'text',
                                            id : 'text',
                                            label : 'Link text',
                                            validate : CKEDITOR.dialog.validate.notEmpty( 'The link text cannot be empty.' ),
                                            required : true,
                                            commit : function( data )
                                            {
                                                data.text = this.getValue();
                                            }
                                        },
                                        {
                                            type : 'select',
                                            id : 'style',
                                            label : 'Style',
                                            items :
                                                [
                                                    [ 'Pink',       'btn-pink' ],
                                                    [ 'Orange',     'btn-orange' ],
                                                    [ 'Red',        'btn-red' ],
                                                    [ 'Purple',     'btn-purple' ],
                                                    [ 'Blue',       'btn-blue'],
                                                    [ 'Aqua',       'btn-aqua'],
                                                    [ 'Green',      'btn-green'],
                                                    [ 'Yellow',     'btn-yellow'],
                                                    [ 'Light grey', 'btn-light-grey'],
                                                    [ 'Grey',       'btn-grey'],
                                                    [ 'Black',      'btn-black'],

                                                ],
                                            commit : function( data )
                                            {
                                                data.style = this.getValue();
                                            }
                                        }

                                    ]
                            }
                        ],
                    onOk : function()
                    {
                        var dialog = this,
                            data = {},
                            link = editor.document.createElement( 'a');
                        this.commitContent( data );
                        link.setAttribute( 'href', data.url);
                        link.setAttribute( 'class', 'btn ' + data.style);
                        link.setAttribute( 'id', data.id );
                        link.setText(data.text);
                        editor.insertElement( link );
                    }
                };
            });
        }
    });