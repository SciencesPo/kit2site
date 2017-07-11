
/**
 * Toggle the visibility of a div using smooth animations
 */
Drupal.toggleFieldset = function(div) {
  if ($(div).is('.collapsed')) {
    // Action div containers are processed separately because of a IE bug
    // that alters the default submit button behavior.
    var content = $('> div:not(.action)', div);
    $(div).removeClass('collapsed');
    content.hide();
    content.slideDown( {
      duration: 'fast',
      easing: 'linear',
      complete: function() {
        Drupal.collapseScrollIntoView(this.parentNode);
        this.parentNode.animating = false;
        $('div.action', div).show();
        var titre = $('a', div).attr('title');
        $('a.switch', div).attr('title', titre.replace(ferme, ouvert));
      },
      step: function() {
        // Scroll the div into view
        Drupal.collapseScrollIntoView(this.parentNode);
      }
    });
  }
  else {
    $('div.action', div).hide();
    var content = $('> div:not(.action)', div).slideUp('fast', function() {
      $(this.parentNode).addClass('collapsed');
      
      this.parentNode.animating = false;
    });
  }
};

/**
 * Scroll a given div into view as much as possible.
 */
Drupal.collapseScrollIntoView = function (node) {
  var h = self.innerHeight || document.documentElement.clientHeight || $('body')[0].clientHeight || 0;
  var offset = self.pageYOffset || document.documentElement.scrollTop || $('body')[0].scrollTop || 0;
  var posY = $(node).offset().top;
  var fudge = 55;
  if (posY + node.offsetHeight + fudge > h + offset) {
    if (node.offsetHeight > h) {
      window.scrollTo(0, posY);
    } else {
      window.scrollTo(0, posY + node.offsetHeight - h + fudge);
    }
  }
};

Drupal.behaviors.collapse = function (context) {
  $('div.collapsible > h2:not(.collapse-processed)', context).each(function() {
    var div = $(this.parentNode);
    // Expand if there are errors inside
    if ($('input.error, textarea.error, select.error', div).size() > 0) {
      div.removeClass('collapsed');
    }

    // Turn the h2 into a clickable link and wrap the contents of the div
    // in a div for easier animation
    var text = this.innerHTML;
      $(this).empty().append($('<a href="#" title="'+text+' - ' +ferme+'" class="switch">'+ text +'</a>').click(function() {
        var div = $(this).parents('div:first')[0];
        // Don't animate multiple times
        if (!div.animating) {
          div.animating = true;
          Drupal.toggleFieldset(div);
        }
        return false;
      }))
      .after($('<div class="div-wrapper"></div>')
      .append(div.children(':not(h2):not(.action)')))
      .addClass('collapse-processed');
  });
  $('div.collapsible > h3:not(.collapse-processed)', context).each(function() {
    var div = $(this.parentNode);
    // Expand if there are errors inside
    if ($('input.error, textarea.error, select.error', div).size() > 0) {
      div.removeClass('collapsed');
    }

    // Turn the h2 into a clickable link and wrap the contents of the div
    // in a div for easier animation
    var text = this.innerHTML;
      $(this).empty().append($('<a href="#" title="'+text+' - '+ferme+'" class="switch">'+ text +'</a>').click(function() {
        var div = $(this).parents('div:first')[0];
        // Don't animate multiple times
        if (!div.animating) {
          div.animating = true;
          Drupal.toggleFieldset(div);
        }
        return false;
      }))
      .after($('<div class="div-wrapper"></div>')
      .append(div.children(':not(h3):not(.action)')))
      .addClass('collapse-processed');
  });
  $('div.collapsible > h4:not(.collapse-processed)', context).each(function() {
    var div = $(this.parentNode);
    // Expand if there are errors inside
    if ($('input.error, textarea.error, select.error', div).size() > 0) {
      div.removeClass('collapsed');
    }

    // Turn the h2 into a clickable link and wrap the contents of the div
    // in a div for easier animation
    var text = this.innerHTML;
      $(this).empty().append($('<a href="#" title="'+text+' - '+ferme+'" class="switch">'+ text +'</a>').click(function() {
        var div = $(this).parents('div:first')[0];
        // Don't animate multiple times
        if (!div.animating) {
          div.animating = true;
          Drupal.toggleFieldset(div);
        }
        return false;
      }))
      .after($('<div class="div-wrapper"></div>')
      .append(div.children(':not(h4):not(.action)')))
      .addClass('collapse-processed');
  });
};
