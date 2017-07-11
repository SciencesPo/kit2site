(function($){	
	$.fn.scpoeditocarousel = function(defaults) {
		
		/* Options par défaut */
		defaults = $.extend({
			content : null,
			contentBloc: null,
			navigation: null,
			curindex: 0,
			maxindex: null,
			duration: 500,
			timer: 7000,
			THIS: $(this),
			slider: null,
			nbelement: null,
			containerWidth: null,
			containerHeight: null
		}, defaults || {});
		
		return this.each(function() {
		
			defaults.slider = $(this).find('ul');
			defaults.nbelement = $(this).find('li').length;
			defaults.maxindex = defaults.nbelement - 1;
			defaults.containerWidth = $(this).width();
			defaults.containerHeight = $(this).height();
			stopped = false,
			
			defaults.slider.wrap('<div class="scpoeditocarousel" />');
					
			/* On n'insère pas les éléments de navigation si il y a qu'une seule image */
			if (defaults.nbelement > 1) {
				/* Mise en place de la navigation */
				$(this).find('.scpoeditocarousel').append(' \
				<div class="nav-arrow"> \
					<a class="prev" title="' + prev + '"><img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/fleche_G.png" alt="' + prev + '" /></a> \
					<a id="pause" class="paspause" title="' + pause + '"><img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/fleche_P.png" alt="' + pause + '" /></a> \
					<a class="next" title="' + next + '"><img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/fleche_D.png" alt="' + next + '" /></a> \
				</div> \
					<div class="nav-item"> \
					</div> \
				');

				/* Gestionnaire de clic sur les boutons suivant, précédent */
				$(this).find(".prev").click(function(){
               stopped = false;
					swap(defaults.curindex, defaults.curindex - 1, 'prev');
               // defaults.THIS.bind('mouseout', start_time_handler);
               $("#pause").removeClass('pause');
               $("#pause").addClass('paspause');
				});

				$(this).find(".next").click(function(){
					swap(defaults.curindex, defaults.curindex + 1, 'next');
               // defaults.THIS.bind('mouseout', start_time_handler);
               stopped = false;
               $("#pause").removeClass('pause');
               $("#pause").addClass('paspause');
				});
				$(this).find("#pause").click(function(){
               // alert(stopped)
				   if(stopped == true) {
                  stopped = false;
                  $("#pause").removeClass('pause');
                  $("#pause").addClass('paspause');
 				      start_time_handler();
				   }else{
                  $("#pause").removeClass('paspause');
                  $("#pause").addClass('pause');
                  stopped = true;
   					stop_time_handler();
 				   }
				});
			}
			
			/* Mise en place du tableau content et ajout de la navigation par items */
			/* Si on détecte iframe ou object, on redimensionne correctement */
			defaults.content = new Array();
			defaults.contentBloc = new Array();
			
			$(this).find('li').each(function(i){

            // $(this).bind('mouseover', stop_time_handler);
            //  $(this).bind('mouseout', start_time_handler);
			
				//Il y a plusieurs média dans chaque Li, d'ou la boucle
				$(this).find('object').each(function(){
					$(this).attr('width', $(this).parent().width());
					$(this).attr('height', $(this).parent().height());
					embed = $(this).parent().find('embed');
					embed.attr('width', $(this).parent().width());
					embed.attr('height', $(this).parent().height());
				});
				
				$(this).find('iframe').each(function(i){
					$(this).attr('width', $(this).parent().width());
					$(this).attr('height', $(this).parent().height());
				});
				
				defaults.content[i] = $(this);
				defaults.contentBloc[i] = new Array();
				
				if (i != 0) {
					$(this).hide();
				}
				
				defaults.THIS.find('.nav-item').prepend('<a title="'+ item +'"><img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/cercle_puce_new.png" alt="' + item + '" /></a>');
				$(this).find('.bloc').each(function(j){
					defaults.contentBloc[i][j] = $(this);
				});
				
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
                 swap(defaults.curindex, i, 'goto');
                // defaults.THIS.bind('mouseout', start_time_handler);
             });
 			});
			
			/* Mise en place des calques pour obtenir l'effet désiré */
			$(this).find('.bloc').each(function(){
				$(this).append('<div class="calque"></div>');
			});
			
			/* Gestionnaire du défilement automatique */
			start_time_handler = function() {
				$(document).everyTime(defaults.timer, 'timer', function(){
					swap(defaults.curindex, defaults.curindex + 1, 'next');
				});
			}
			
			stop_time_handler = function() {
				$(document).stopTime('timer');
			}
			
         // $(this).bind('mouseover', stop_time_handler);
         // $(this).bind('mouseout', start_time_handler);

												
			start_time_handler();
			
			
			/* Gestionnaire de clic pour afficher les vidéo */
         // $(this).find('.bloc .voirVideo').click(function(){
         //    $(this).parent().find('.video').show();
         //    defaults.THIS.unbind('mouseout', start_time_handler);
         // });

			/* Gestion du swap */
			function swap(prevIndex, index, todo) {
				/* On vérifie que l'index n'est pas hors limite */
				if (index < 0) { index = defaults.maxindex; }
				if (index > defaults.maxindex) { index = 0; }
				if (index == defaults.curindex) { return; }
				
				defaults.content[prevIndex].hide();
				defaults.content[index].show();
				
				count = defaults.content[index].find('.calque').length;
				defaults.content[index].find('.calque').show();
				
				/* On effectue l'action choisie */
				if (todo == 'next') { slide('left', index, count, count - 1); }
				
				if (todo == 'prev') { slide('right', index, count, 0); }
				
				if (todo == 'goto') {
					if (prevIndex < index) {
						slide('left', index, count, count - 1);
					} else {
						slide('right', index, count, 0);
					}
				}

				/* Changement du statut 'active' de la navigation */
				/* Changement du statut 'active' de la navigation */
				defaults.THIS.find('.nav-item a.active').html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/cercle_puce_new.png" alt="' + item + '" />');
				defaults.THIS.find('.nav-item a.active').removeClass('active');
				defaults.navigation[index].addClass('active');
				defaults.navigation[index].html('<img src="' + BaseUrl + '/sites/all/themes/sciencespo/images/cercle_puce.png" alt="' + itemactif + '" />');

				/* On actualise curindex */
				defaults.curindex = index;
				
				/* On cache les vidéos */
				defaults.content[index].find('.video').hide();
				
				return false;
			};
			
			/* Gestion du slide */
			function slide(direction, index, count, current) {
				// alert(direction+', '+index+', '+count+', '+current)
					defaults.contentBloc[index][current].find('.calque').toggle('slide', {direction: direction, easing: "easeOutCirc"}, defaults.duration, function() {
				
						//On effectue la fonction "stats_display" a chaque fois qu'une actualités apparait
	               // if (defaults.isDevl == 0) {
	               //    stats_display(defaults.contentBloc[index][current]);
	               // }
				
						/* Left */
						if (direction == 'left' && current == 0) { return; }
						if (direction == 'left') { current = current - 1; }
						/* Right */
						if (direction == 'right' && current == count - 1) { return; }
						if (direction == 'right') { current = current + 1; }
					
						slide(direction, index, count, current);
					
					});

			}
			
			
			
			//Si on est en "devl", on n'effectue pas les requêtes ajax pour les statistiques.
         if (defaults.isDevl == 0) {
         
            /*Statistiques "click url" */
            // $(".gabarit .bloc a").click(function(event){
            //    //event.preventDefault();
            //          
            //    info_stat = $(this).parents('.bloc').find("input[name='info']").val();
            //    url_actu = $(this).attr('href');
            //    
            //    //tab_info_stat[0] - nid
            //    //tab_info_stat[1] - priorité
            //    //tab_info_stat[2] - section
            //    tab_info_stat = info_stat.split(';');
            //          
            //    // alert(url_actu);
            //    // return;
            //    
            //    //On vérifie que le nid est bien défini, sinon c'est qu'il n'y a pas d'actualité dans le bloc
            //    if (tab_info_stat[0] != '') { 
            //       $.ajax({
            //          async:false,
            //          url: "ze_reporting_click/" + tab_info_stat[0] + "/" + tab_info_stat[1] + "/" + tab_info_stat[2],
            //          type: "GET"
            //       });
            //    }
            // });
            
            /*Statistiques "click video" */
            // $(".gabarit .bloc .voirVideo span").click(function(){
            //    info_stat = $(this).parents('.bloc').find("input[name='info']").val();
            //    
            //    //tab_info_stat[0] - nid
            //    //tab_info_stat[1] - priorité
            //    //tab_info_stat[2] - section
            //    tab_info_stat = info_stat.split(';');
            //    
            //    //On vérifie que le nid est bien défini, sinon c'est qu'il n'y a pas d'actualité dans le bloc
            //    if (tab_info_stat[0] != '') { 
            //       $.ajax({
            //          url: "ze_reporting_click/" + tab_info_stat[0] + "/" + tab_info_stat[1] + "/" + tab_info_stat[2] + "/1",
            //          type: "GET"
            //       });
            //    }
            // });
            
				//On effectue la fonction "stats_display" pour les actualités aparaissant dès l'affichage de la page d'accueil
            // $(".gabarit1 .bloc").each(function(){
            //    stats_display($(this));
            // });
				
			}
			
			/*Statistiques "affichage" */
         // function stats_display(bloc) {
         //    info_stat = bloc.find("input[name='info']").val();
         //    
         //    //tab_info_stat[0] - nid
         //    //tab_info_stat[1] - priorité
         //    //tab_info_stat[2] - section
         //    tab_info_stat = info_stat.split(';');
         //    
         //    if (tab_info_stat[0] != '') {
         //       $.ajax({
         //          url: "ze_reporting_affichage/" + tab_info_stat[0] + "/" + tab_info_stat[1] + "/" + tab_info_stat[2],
         //          type: "GET"
         //       });   
         //    }
         // }
						
		});
		
	};
})(jQuery);