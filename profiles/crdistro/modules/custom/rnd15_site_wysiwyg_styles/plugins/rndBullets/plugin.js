/*
 CKEditor Plugin - provides bespoke html injection into the ckeditor textarea.
 @author Carl Hinton for Comic Relief.
 */
CKEDITOR.plugins.add( 'rndBullets',
    {
        init: function( editor )
        {
            editor.addCommand( 'rndBulletsDialog', new CKEDITOR.dialogCommand( 'rndBulletsDialog' ) );

            editor.ui.addButton( 'rndBullets',
                {
                    label: 'Insert an unordered list',
                    command: 'rndBulletsDialog',
                    icon : this.path + '/rndBullets.png'
                } );

            CKEDITOR.dialog.add( 'rndBulletsDialog', function( editor )
            {
                return {
                    title : 'RND Bullet Properties',
                    minWidth : 200,
                    minHeight : 100,
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
                                            'Adds a styled bullet list. For more information please refer to the  ' +
                                            '<a target="_blank" href="' +
                                            Drupal.settings.rnd15_site_wysiwyg_styles.docs + '">' +
                                            'editor documentation</a>.'
                                        },
                                        {
                                            type : 'select',
                                            id : 'style',
                                            label : 'Style',
                                            items :
                                                [
                                                    [ 'Default',   '' ],
                                                    [ 'Plain',     'list--plain' ]
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
                        // Insert the code.
                        var dialog = this,
                            element,
                            data = {};
                        this.commitContent( data );
                        var bullet = editor.document.createElement( 'ul' );
                        bullet.setAttribute( 'class', 'list ' + data.style);
                        bullet.setHtml('<li>&nbsp;</li>');
                        editor.insertElement( bullet );

                        // Move the cursor to the correct spot.
                        var range = new CKEDITOR.dom.range(editor.document);
                        range.moveToElementEditablePosition(bullet, true);
                        editor.getSelection().selectRanges([range]);

                    }
                };
            });
        }
    });