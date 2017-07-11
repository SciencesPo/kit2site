(function($){	
	$.fn.scpofeed = function(defaults) {

		/* Options par défaut */
		defaults = $.extend({
			content : null,
			curindex: 0,
			maxindex: null,
			nbelement: null,
			timer: 3500
		}, defaults || {});
		
		return this.each(function() {
		
			defaults.nbelement = $(this).find('li').length;
			defaults.maxindex = defaults.nbelement - 1;
			defaults.content = new Array();
			
			$(this).find('li').each(function(i){
				defaults.content[i] = $(this);
				if (i != 0) {
					$(this).hide();
				}
			});
			
			/* Gestionnaire du défilement automatique */
			function _timer() {
				$(document).everyTime(defaults.timer, 'timer_feed', function(){
					swap(defaults.curindex, defaults.curindex + 1);
				});
			}
			
			$(this).hover(
				function(){
					$(document).stopTime('timer_feed');
				},
				function(){
					_timer();
				}
			);
			
			_timer();

			/* Gestionnaire du SWAP */
			function swap(prevIndex, index) {
				/* On vérifie que l'index n'est pas hors limite */
				if (index < 0) {
					index = defaults.maxindex;
				}
				
				if(index > defaults.maxindex) {
					index = 0;
				}

				if(index == defaults.curindex) {
					return;
				}
				
				/* On actualise curindex */
				defaults.curindex = index;
				
				/* On effectue le SWAP */
				defaults.content[prevIndex].fadeOut(250, function(){
                   defaults.content[index].fadeIn();
                });
				
				return false;
			};
			
		});
		
	};
})(jQuery);

