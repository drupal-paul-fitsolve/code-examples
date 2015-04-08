/* Plugin created by jankoatwarpspeed.com 
 * Customised for SR14
*/

(function($) {
    $.fn.formSteps = function(options) {
        options = $.extend({  
            submitButton: "" 
        }, options); 
        
        var element = this;

        var steps = $(element).find("fieldset.fr-step");
        var count = steps.size();
        var submmitButtonName = "#edit-submit";
        $(submmitButtonName).hide();

        $(element).before("<ul id='steps'></ul>");

        steps.each(function(i) {
            $(this).wrap("<div id='step" + i + "'></div>");
            $(this).append("<p id='step" + i + "commands'></p>");

            var name = $(this).find("legend").html();
            $("#steps").append("<li id='stepDesc" + i + "'><span class='stepName'>" + (i + 1) + "</span><span>" + name + "</span></li>");

            if (i == 0) {
                createNextButton(i);
                selectStep(i);
            }
            else if (i == count - 1) {
                $("#step" + i).hide();
                createPrevButton(i);
            }
            else {
                $("#step" + i).hide();
                createPrevButton(i);
                createNextButton(i);
            }
        });

        function createPrevButton(i) {
            var stepName = "step" + i;
            $("#" + stepName + "commands").append("<a href='#' id='" + stepName + "Prev' class='prev button button--swim'>Back</a>");

            $("#" + stepName + "Prev").bind("click", function(e) {
                $("#" + stepName).hide();
                $("#step" + (i - 1)).show();
                $(submmitButtonName).hide();
                selectStep(i - 1);
            });
        }

        function createNextButton(i) {
            var stepName = "step" + i;
            $("#" + stepName + "commands").append("<a href='#' id='" + stepName + "Next' class='next button button--swim'>Next</a>");
            // temp: add disable button
            if (i > 0) {
                $("#" + stepName + "commands").append("<span class='next button button--disable'>Next</span>");
            }
            
            $("#" + stepName + "Next").bind("click", function(e) {
                $("#" + stepName).hide();
                $("#step" + (i + 1)).show();
                if (i + 2 == count)
                    $(submmitButtonName).show();
                selectStep(i + 1);
            });
        }

        function selectStep(i) {
            $("#steps li").removeClass("current");
            $("#stepDesc" + i).addClass("current");
        }

    }

/* 
 * SR14
 * UGC Image Upload form
 */

  Drupal.behaviors.sr14_fundraiser_showcases_upload = {
      attach: function (context, settings) {

         var steps = $('#steps');
         var form = $('#fundraiser-showcase-node-form');
         var form_overlay = $('#colorbox #fundraiser-showcase-node-form');

         // temp solution for form action redirect, need to fix it properly later
         //form.attr('action', '/fundraiser-showcase-thank-you');

         // only run once
         form.once().formSteps(); 
         $(form, context).once('sr14_fundraiser_showcases_upload_form', function(){  
            form.prepend('<div class="process_bar"></div>');
         }); 

         // Colobox resize: specific height on each step based on design 
         $('#step0Next', form_overlay).bind("click", function(e) { $.colorbox.resize({ height: 1010 }); });
         $('#step2Prev', form_overlay).bind("click", function(e) { $.colorbox.resize({ height: 1010 }); });
         $('#step1Prev', form_overlay).bind("click", function(e) { $.colorbox.resize({ height: 770 }); });
         $('#step1Next', form_overlay).bind("click", function(e) { $.colorbox.resize({ height: 890 }); });
       
        // Disable video upload
        //$('#edit-field-fundrasier-showcase-option-und-1').attr('disabled', 'disabled');
        //$('#edit-field-fundrasier-showcase-option-und .form-type-radio:eq(1)').addClass('option--disable');
        //$('#edit-field-fundrasier-showcase-option-und .form-type-radio:eq(1) label').text('Video upload coming soon');

        // Step 0
        $('.group-step1 input[type=radio]').bind("click", function(e) {
            if ($(this).attr("checked")) {
                var type = $(this).parent();
                if ($('.option:contains("photos")', type).length > 0) {
                    $('.group_photo_upload').show().siblings('.group_video_upload').hide();                    
                } else {
                    $('.group_video_upload').show().siblings('.group_photo_upload').hide();
                }
                $('#step0Next').click();
                return;
            }
            
        });

        // Step 1 & 2       
        /* To do: 
           1) video field check 
        */
        // initilize checkbox value         
        $('#edit-field-terms-und').val($(this).is(':checked'));
        $('#edit-field-terms-und').change(function() {
            $('#edit-field-terms-und').val($(this).is(':checked'));
        });

        // Check field value then enable/disable next/submit button
        $('#step1Next',form).hide();
        $('#edit-submit', form).attr('disabled','disabled').addClass('button--disable').hide(); 
        $("#edit-body-und-0-value, .file-size, #edit-field-terms-und, #edit-title-field-und-0-value, #edit-field-town-und-0-value, #edit-field-email-und-0-email, #edit-field-how-did-you-fundraise-und").bind("change keyup",
            function () {   
                /* step 1 */   
                if ( $("#edit-body-und-0-value").val() != "" 
                     //&& $('.file-size').length > 0
                     && $('#edit-field-terms-und').is(':checked')) {
                    $('#step1Next', form).show();
                    $('.button--disable').hide();
                } else {
                    $('#step1Next', form).hide();
                    $('.button--disable').show();
                }    
                /* step 2*/
                if ( $("#edit-title-field-und-0-value").val() != "" 
                     && $("#edit-field-town-und-0-value").val() != "" 
                     && $("#edit-field-email-und-0-email").val() != ""
                     && /(.+)@(.+){2,}\.(.+){2,}/.test($("#edit-field-email-und-0-email").val())
                     && $("#edit-field-how-did-you-fundraise-und").val() != "_none") {
                    $('#edit-submit', form).removeClass('button--disable').removeAttr('disabled','disabled');   
                    $('#edit-submit', form).show();  
                    $('.button--disable').show();          
                } else {
                    $('#edit-submit', form).addClass('button--disable').attr('disabled','disabled');
                    $('#edit-submit', form).hide();
                }    
        });
        
        // Default text on input field
        var filter = $('.fr-showcase .views-exposed-form #edit-title');
        var video_title = $("#edit-field-video-upload-und-0-video-title");
        var text = 'Enter video title...';
        var text2 = 'Find someone...';
        
        video_title.attr('value', text); 
        video_title.focus(function() {
            if($(this).attr("value") == text) $(this).attr('value', '');
        });     
        video_title.blur(function() {
            if($(this).attr('value') == '') $(this).attr('value', text);
        });

        filter.attr('value', text2); 
        filter.focus(function() {
            if($(this).attr("value") == text2) $(this).attr('value', '');
        });     
        filter.blur(function() {
            if($(this).attr('value') == '') $(this).attr('value', text2);
        });



    } /* end - attach */
  }; /* end - behaviors */

  $(document).ready(function() {   
    var forms = ("#fundraiser-showcase-node-form");
    var terms = $('.field-name-field-terms .description', forms);
    $('.field-name-field-terms label.option').replaceWith(terms);
    $(terms).prepend($('#edit-field-terms-und'));
  }); /* end - document ready */

})(jQuery); 