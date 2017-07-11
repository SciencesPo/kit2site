$(document).ready(function() {
	rollOverMenu();
	new_window_title();
  $(".rezosoc img").mouseover(function(event) {
    var src = $(this).attr('src').split('.');
    src[src.length - 2] = src[src.length - 2] + "_on";
    $(this).attr("src", src.join('.'));
  });
  $(".rezosoc img").mouseout(function(event) {
    var src = $(this).attr('src').replace('_on', '');
    $(this).attr("src", src);
  });
});


function rollOverMenu() {
	$("#block-barre_corp-menu_corporate ul ul").css('left', '-20000px');
	// $("#block-barre_corp-menu_corporate ul ul").css('height', '0');

	
//CLICK MOBILES
	$("#block-barre_corp-menu_corporate ul li a").click(function(event) {
		if($(this).parent().children("ul").css('left') == '-20000px'){
			$(this).parent().children("ul").css('left', '0');
		//	$(this).parent().children("ul").attr('aria-expanded', 'true');
		//	$(this).parent().children("ul").attr('aria-hidden', 'false');
		}else{
			$(this).parent().children("ul").css('left', '-20000px');
		//	$(this).parent().children("ul").attr('aria-expanded', 'false');
		//	$(this).parent().children("ul").attr('aria-hidden', 'true');
		}
	});
//MOUSEOVER
	$("#block-barre_corp-menu_corporate ul li a").mouseover(function(event) {
		$(this).children('.fleche-deroulant').attr('src', 'http://www.sciencespo.fr/sites/all/themes/SPresponsive/images/fleche-menu-deroulant-corp-white.png');
		$(this).parent().children("ul").css('left', '0');
		//$(this).parent().children("ul").attr('aria-expanded', 'true');
		//$(this).parent().children("ul").attr('aria-hidden', 'false');
                //$(this).parent().children("ul").children("li").children("a").attr('aria-hidden', 'false');
	});
	$("#block-barre_corp-menu_corporate ul li ul").mouseover(function(event) {
		$(this).css('left', '0');
		//$(this).attr('aria-expanded', 'true');
		//$(this).attr('aria-hidden', 'false');
	});
//MOUSEOUT
	$("#block-barre_corp-menu_corporate ul li a").mouseout(function(event) {
		$(this).children('.fleche-deroulant').attr('src', 'http://www.sciencespo.fr/sites/all/themes/SPresponsive/images/fleche-menu-deroulant-corp-black.png');
		$(this).parent().children("ul").css('left', '-20000px');
		//$(this).parent().children("ul").attr('aria-expanded', 'false');
		//$(this).parent().children("ul").attr('aria-hidden', 'true');
                //$(this).parent().children("ul").children("li").children("a").attr('aria-hidden', 'true');
	});
	$("#block-barre_corp-menu_corporate ul li ul").mouseout(function(event) {
		$(this).css('left', '-20000px');
		//$(this).attr('aria-expanded', 'false');
		//$(this).attr('aria-hidden', 'true');
	});
//FOCUS
	$("#block-barre_corp-menu_corporate ul li a").focus(function(event) {
		$(this).parent().children("ul").css('left', '0');
		//$(this).parent().children("ul").attr('aria-expanded', 'true');
		//$(this).parent().children("ul").attr('aria-hidden', 'false');
	});
	$("#block-barre_corp-menu_corporate ul li ul li a").focus(function(event) {
		$(this).parent().parent().css('left', '0');
		//$(this).parent().parent().attr('aria-expanded', 'false');
		//$(this).parent().parent().attr('aria-hidden', 'true');
	});
//BLUR	
	$("#block-barre_corp-menu_corporate ul li a").blur(function(event) {
		$(this).parent().children("ul").css('left', '-20000px');
		//$(this).parent().parent().attr('aria-expanded', 'false');
		//$(this).parent().parent().attr('aria-hidden', 'true');
	});
	$("#block-barre_corp-menu_corporate ul li ul li a").blur(function(event) {//a de niveau 2
		$(this).parent().parent().css('left', '-20000px');//ul de niveau 2
		//$(this).parent().parent().attr('aria-expanded', 'false');
		//$(this).parent().parent().attr('aria-hidden', 'true');
		//$(this).children("li").children("a").attr('aria-hidden', 'false');//a de niveau 2
	});
	
}



function new_window_title() {

  $("#block-barre_corp-menu_corporate h2.title").html("Menu global Sciences Po");

	$("#block-barre_corp-menu_corporate a").each(function(index) {
		
		if(this.href.indexOf(BaseUrl) == -1 && this.href.indexOf("javascript") == -1){
			this.target = "_blank";
		}

		//ouverture dans une nouvelle fenetre des autres sites du meme domaine (ex : sciencespo.fr/recherche)
		var exceptions = ['avenir', 'recherche', 'enseignants', 'vie-etudiante', 'formation-continue', 'ressources-numeriques'];
		for (var i = 0; i < exceptions.length; i++) {
			if(this.href.indexOf(BaseUrl+'/'+exceptions[i]) != -1 && this.href.indexOf("javascript") == -1){
				this.target = "_blank";
			}
		}

	/*	if(!this.title || this.title == ''){
			var html = this.innerHTML.trim();
			html = html.replace(/<img.*>/, '');
			this.title = html.trim();
		}
    */


		if(this.target == '_blank') {
                  var exp = /^<img.*?>$/;
			if((!lang || lang == 'fr')&& this.title.indexOf('ouvelle fen') == -1) {
                          if(this.innerHTML.match(exp)){
                            var t = this.getAttribute("title");
                                  this.removeAttribute("title");
                                  var img = this.getElementsByTagName("img");
                                  var alt = img[0].getAttribute("alt");
                                  if(!alt){ alt = t }
                                  alt = alt + ' - Nouvelle fenêtre';
                                  img[0].setAttribute("alt", alt);
                          }else{
                                  if(!this.title || this.title == ''){
                                    this.title = this.innerHTML + ' - Nouvelle fenêtre';
                                  }else{
                                    this.title = this.title + ' - Nouvelle fenêtre';
                                  }
                                }
			  }
			if((lang == 'en')&& this.title.indexOf('ew window') == -1) {
				if(this.innerHTML.match(exp)){
                                  this.removeAttribute("title");
                                  var img = this.getElementsByTagName("img");
                                  var alt = img[0].getAttribute("alt");
                                  alt = alt + ' - New window';
                                  img[0].setAttribute("alt", alt);
                                }else{
                                  if(!this.title || this.title == ''){
                                    this.title = this.innerHTML + ' - New window';
                                  }else{
				    this.title = this.title + ' - New window';
                                  }
                                }
			}
		}
                if(this.title == this.innerHTML) {
                  this.removeAttribute("title");
                }
	});

}


