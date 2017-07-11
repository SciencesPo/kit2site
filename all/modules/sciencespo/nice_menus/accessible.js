$.fn.accessibleDropDown = function ()
{
    var el = $(this);

    /* Setup dropdown menus for IE 6 */

    $("li", el).mouseover(function() {
        $(this).addClass("hover");
    }).mouseout(function() {
        $(this).removeClass("hover");
    });

    /* Make dropdown menus keyboard accessible */

    $("a", el).focus(function() {
        $(this).parents("li").addClass("hover");
    }).blur(function() {
        $(this).parents("li").removeClass("hover");
    });


}
$(document).ready(function()
{

   /*Ajoute une class 'hasjs' quand javascript est activé*/
   $("body").addClass("hasjs");

    $("#block-nice_menus-1").accessibleDropDown();

    $("#accessibilitylinks").css("left", "-5000px");

    $("#accessibilitylinks a").focus(function() {
       $("#accessibilitylinks").css("left", "50%");
    });

});
