
Drupal.behaviors.cas = function (context) {
  var $loginElements = $("#edit-name-wrapper, #edit-pass-wrapper, #user-login-form li, #user-login li");
  var $casElements = $("#edit-cas-identifier-wrapper, li.uncas-link");
  $("#edit-cas-identifier").hide();
  $("#edit-cas-identifier-wrapper label").hide();
  if($("#edit-cas-identifier").attr("checked")) {
    $loginElements.hide();
    // Use .css("display", "block") instead of .show() to be Konqueror friendly.
    $casElements.css("display", "block");
  }
  else
  {
    $loginElements.css("display", "block");
    // Use .css("display", "block") instead of .show() to be Konqueror friendly.
    $casElements.hide();
  }

  $("li.cas-link", context)
    .click( function() {
       $loginElements.hide();
       $casElements.css("display", "block");
	   $("#edit-cas-identifier").attr("checked", true);
      // Remove possible error message.
      $("#edit-name, #edit-pass").removeClass("error");
      $("div.messages.error").hide();
      return false;
    });
  $("li.uncas-link", context)
    .click(function() {
       $loginElements.css("display", "block");
       $casElements.hide();
	   $("#edit-cas-identifier").attr("checked", false);
      // Clear cas Identifier field and remove possible error message.
      $("div.messages.error").css("display", "block");
      // Set focus on username field.
      $("#edit-name")[0].focus();
      return false;
    });
};
