var sliding = false;

(function($){	
	$.fn.scpocarousel = function(defaults) {

		/* Options par défaut */
		defaults = $.extend({
			content : null,
			navigation: null,
			curindex: 0,
			maxindex: null,
			duration: 700,
			THIS: $(this),
			slider: null,
			nbelement: null,
			containerWidth: null,
			containerHeight: null
		}, defaults || {});
		
		return this.each(function() {
			defaults.slider = $(this).find('ul.ul-scpocarousel');
			defaults.nbelement = $(this).find('li.li-scpocarousel').length;
			defaults.maxindex = defaults.nbelement - 1;
			defaults.containerWidth = $(this).width();
			defaults.containerHeight = $(this).height();
			
			defaults.slider.wrap('<div class="scpocarousel" />');
			
			/* On ajoute les styles nécessaires */
			//defaults.slider.css({'width': (defaults.nbelement * defaults.containerWidth), 'height': defaults.containerHeight})
			//$(this).find('li').css({'width': defaults.containerWidth, 'height': defaults.containerHeight});
                        defaults.slider.css({'width': (defaults.nbelement * (defaults.containerWidth + 2))});
                        $(this).find('li.li-scpocarousel').css({'width': defaults.containerWidth, 'marginRight': 2});
						
			/* On n'insère pas les éléments de navigation si il y a qu'une seule image */
			if (defaults.nbelement > 1) {
				/* Mise en place de la navigation */
				$(this).find('div.scpocarousel').append(' \
					<div class="nav-arrow"> \
					<a class="prev" title="' + prev + '"><img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/fleche_G.png" alt="' + prev + '" /></a> \
					<a class="next" title="' + next + '"><img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/fleche_D.png" alt="' + next + '" /></a> \
					</div> \
					<div class="nav-item"> \
					</div> \
				');
				/* Gestionnaire de clic sur les boutons suivant, précédent */
				$(this).find(".prev").click(function(){
					if(sliding == false){
						sliding = true;	
						slide(defaults.curindex, defaults.curindex - 1, 'prev');
						var t = setTimeout("sliding = false", 1000);
					}
				});

				$(this).find(".next").click(function(){
					if(sliding == false){
						sliding = true;	
						slide(defaults.curindex, defaults.curindex + 1, 'next');
						var t = setTimeout("sliding = false", 1000);
					}
				});
			}
			
			/* Mise en place du tableau content et ajout de la navigation par items */
			/* Si on détecte iframe ou object, on redimensionne correctement */
			defaults.content = new Array();
			$(this).find('li.li-scpocarousel').each(function(i){
			
				//Le ratio  672 * 400 = taille maximale fixé par Djeff
				if (defaults.ratio) {
					ratioD = 672 / 400;
					fixHeight = defaults.containerWidth / ratioD;
					$(this).find('img[class!="alt-display"]').css({'height': fixHeight, 'width': 'auto'});
					//$(this).css('textAlign', 'center');
				}
			
				if ($(this).find('object').css('height') != undefined) {
					if (defaults.ratio) {
						$(this).find('object').attr('width', defaults.containerWidth);
						$(this).find('object').attr('height', fixHeight);
						$(this).find('embed').attr('width', defaults.containerWidth);
						$(this).find('embed').attr('height', fixHeight);
					} else {
						objectHeight = $(this).find('object').attr('height');
						objectWidth = $(this).find('object').attr('width');
						
						ratio = objectWidth / objectHeight;
						
						myHeight = defaults.containerWidth / ratio;
						
						$(this).find('object').attr('width', defaults.containerWidth);
						$(this).find('object').attr('height', myHeight);
						$(this).find('embed').attr('width', defaults.containerWidth);
						$(this).find('embed').attr('height', myHeight);
					}
				}
				
				if ($(this).find('iframe').css('height') != undefined) {
					if (defaults.ratio) {
						$(this).find('iframe').attr('width', defaults.containerWidth);
						$(this).find('iframe').attr('height', fixHeight);
					} else {
						iframeHeight = $(this).find('iframe').attr('height');			
						iframeWidth = $(this).find('iframe').attr('width');
						
						ratio = iframeWidth / iframeHeight;
						
						myHeight = defaults.containerWidth / ratio;
						
						$(this).find('iframe').attr('width', defaults.containerWidth);
						$(this).find('iframe').attr('height', myHeight);
					}
				}
			
				defaults.content[i] = $(this);
				defaults.THIS.find('.nav-item').prepend('<a title="' + item + '"><img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/cercle_puce_new.png" alt="' + item + '" /></a>');
			});

			/* Gestionnaire de clic sur la navigation et mise en place du tableau correspondant */
			defaults.navigation = new Array();
			$(this).find('.nav-item a').each(function(i){
				defaults.navigation[i] = $(this);
				if (i == 0) {
					$(this).addClass('active');
					$(this).html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/cercle_puce.png" alt="' + itemactif + '" />');
				}
				$(this).click(function(){
				   slide(defaults.curindex, i, 'goto');
				});
			});

         /*si l'url indique une description textuelle, afficher directement l'item concerné*/
         var pathname = window.location.pathname;
         if(pathname.indexOf('description-textuelle') != -1){
            urls = pathname.split('description-textuelle/');
            src = urls[1];
   			$(this).find('.ul-scpocarousel li').each(function(i){
               if($(this).html().indexOf(src) != -1) {
                  slide(defaults.curindex, i, 'goto');
               }
   			});
         }

			/* Gestion du slide */
			function slide(prevIndex, index, todo) {
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
				
				/* On effectue l'action choisie */
				if (todo == 'next') {
					defaults.slider.animate({
						left: "-=" + defaults.containerWidth + "px"
					}, defaults.duration, function() {
						defaults.slider.append(defaults.content[prevIndex]);
						defaults.slider.css('left', '0px');
					});
				}
				
				if (todo == 'prev') {
					defaults.slider.prepend(defaults.content[index]);
					defaults.slider.css('left', '-' + defaults.containerWidth + 'px');
					defaults.slider.animate({
						left: "+=" + defaults.containerWidth + "px"
					});
				}
				
				if (todo == 'goto') {
					if (prevIndex < index) {
						defaults.slider.animate({
							left: "-=" +  (index - prevIndex) * defaults.containerWidth + "px"
						}, defaults.duration, function() {
							for (i = prevIndex; i < index; i++) {
								defaults.slider.append(defaults.content[i]);
							}
							defaults.slider.css('left', '0px');
						});
					} else {
						for (i = (prevIndex - 1); i >= index; i--) {
							defaults.slider.prepend(defaults.content[i]);
						}
						defaults.slider.css('left', '-' + (prevIndex - index) * defaults.containerWidth + 'px');
						defaults.slider.animate({
							left: "+=" + (prevIndex - index) * defaults.containerWidth + "px"
						});
					}
				}

				/* Changement du statut 'active' de la navigation */
				defaults.THIS.find('.nav-item a.active').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/cercle_puce_new.png" alt="' + item + '" />');
				defaults.THIS.find('.nav-item a.active').removeClass('active');
				defaults.navigation[index].addClass('active');
				defaults.navigation[index].html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/cercle_puce.png" alt="' + itemactif + '" />');
				
				return false;
			};
			
		});
		
	};
})(jQuery);
