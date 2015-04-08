(function ($) {

/**
 * Wysiwyg plugin button implementation for NodeEmbed plugin.
 */
Drupal.wysiwyg.plugins.node_embed = {
  /**
   * Return whether the passed node belongs to this plugin.
   *
   * @param node
   *   The currently focused DOM element in the editor content.
   */
  isNode: function(node) {
    return ($(node).is('img.wysiwyg-node_embed'));
  },

  /**
   * Execute the button.
   *
   * @param data
   *   An object containing data about the current selection:
   *   - format: 'html' when the passed data is HTML content, 'text' when the
   *     passed data is plain-text content.
   *   - node: When 'format' is 'html', the focused DOM element in the editor.
   *   - content: The textual representation of the focused/selected editor
   *     content.
   * @param settings
   *   The plugin settings, as provided in the plugin's PHP include file.
   * @param instanceId
   *   The ID of the current editor instance.
   */
  invoke: function(data, settings, instanceId) {

    var pictureGroups = Drupal.settings['picture']['groups'];
    if(pictureGroups.length > 0) {
      var pictureSelectBox = '<label>Picture Group:</label><select id="EmbedPictureGroup">';
        for(var i = 0; i < pictureGroups.length; i++ ) {
          var selected = '';
          if(i == 0) {
            selected = 'selected';
          }
          var picture = pictureGroups[i];
          pictureSelectBox += '<option ' + selected + ' value="' + picture[0] + '">' + picture[0] + '</option>';
        }
      pictureSelectBox += '</select>';
    }

    //Show the node selection Dialog
    var iframeSrc = Drupal.settings.basePath + 'cr-ckeditor-node-embed';
    var dialogMarkup = '<div id="nodeEmbedDialog" title="Embed a Node" style="width:100%; height:100%">' +
      '<iframe frameborder="no" style="width:700px; height:400px; border:0" src="'+iframeSrc+'"></iframe>' +
      '<div class="node-embed-picture-group">' + pictureSelectBox + '</div>' +
      '<div class="nodeEmbedButtons"><button id="buttonEmbedFromDialog">Embed</button><button id="buttonCancelDialog">Cancel</button></div>' +
      '</div>';

    var dialog = $(dialogMarkup).dialog(
      {
        autoOpen: false,
        height: 520,
        width: 730,
        modal: true,
        dialogClass: 'node_embed_dialog'
      }
    );

    $(dialog).bind( "dialogclose", function(event, ui) {
      $(this).remove();
    });

    $('#buttonEmbedFromDialog').click(function(e) {
      var picture_group = $('#EmbedPictureGroup option:selected').val();
      picture_group = picture_group.replace(/ /g,"_").toLowerCase();
      console.log(picture_group);
      var node_id = window.currentActiveNid; //set or updated whenever a node is selected
      if( node_id != null && node_id != "" ) {
        dialog.editor_content = '[video:id:' + node_id + ':' + picture_group + ']';
      }

      if(window.currentActiveNid && window.currentActiveNid != ""){
        var edit_content = '[video:id:' + node_id + ':' + picture_group + ']';
        if (data.format == 'html') {
          var content = edit_content;
        }
        else {
          var content = edit_content;
        }
        //write the content to the editor
        if (typeof content != 'undefined') {
          Drupal.wysiwyg.instances[instanceId].insert(content);
        }
      }

      $(dialog).dialog('close');
    });

    $('#buttonCancelDialog').click(function(e) {
      $(dialog).dialog('close');
    });

    $(dialog).dialog('open');
    // Generate HTML markup.

  },
};
})(jQuery);
