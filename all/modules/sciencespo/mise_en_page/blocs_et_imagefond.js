// gestion de la position des blocs supérieurs en fonction de leur nombre
// $(document).ready(function(){
//    var c = 0;
//    $(".region-header").children().each(function(){
//       if($(this).attr('id') != 'block-search-0'){
//          c++;
//       }
//    });
//    if(c == 2 || c == 3) {
//       var d = 0;
//       $(".region-header").children().each(function(){
//          if($(this).attr('id') != 'block-search-0'){
//             d++;
//             switch (d) {
//                case 1:
//                   $(this).css('margin-left', '337px');
//                break;
//                case 2:
//                   $(this).css('margin-left', '350px');
//                break;
//             }
//          }
//       });
//    }else if(c == 4 || c == 5) {
//       var d = 0;
//       $(".region-header").children().each(function(){
//          if($(this).attr('id') != 'block-search-0'){
//             d++;
//             switch (d) {
//                case 1:
//                   $(this).css('margin-left', '212px');
//                break;
//                case 2:
//                   $(this).css('margin-left', '225px');
//                break;
//                case 3:
//                   $(this).css('margin-left', '337px');
//                break;
//                case 4:
//                   $(this).css('margin-left', '350px');
//                break;
//             }
//          }
//       });
//    }else if(c == 6 || c == 7) {
//       var d = 0;
//       $(".region-header").children().each(function(){
//          if($(this).attr('id') != 'block-search-0'){
//             d++;
//             switch (d) {
//                case 1:
//                   $(this).css('margin-left', '87px');
//                break;
//                case 2:
//                   $(this).css('margin-left', '100px');
//                break;
//                case 3:
//                   $(this).css('margin-left', '212px');
//                break;
//                case 4:
//                   $(this).css('margin-left', '225px');
//                break;
//                case 5:
//                   $(this).css('margin-left', '337px');
//                break;
//                case 6:
//                   $(this).css('margin-left', '350px');
//                break;
//             }
//          }
//       });
//             
//    }
// 
// });
//gestion de la dimension de l'image de fond
var win_w;
var win_h;
var img_w;
var img_h;

$(document).ready(function(){
	$('#fond').load(function() {
		img_w = $(this).width();
		img_h = $(this).height();
		win_w = $(window).width();
		win_h = $(window).height();
		
		doresize();
	});
});
$(window).resize(function(){
	win_w = $(window).width();
	win_h = $(window).height();
	doresize();
});

function doresize(){
	//si l'image est plus grande que la fenetre, la placer au centre horizontalement et verticalement
	if(img_w > win_w && img_h > win_h) {
		$('#fond').css('top', win_h/2 + 'px');
		$('#fond').css('margin-top', '-' + img_h/2 + 'px');
		$('#fond').css('left', win_w/2 + 'px');
		$('#fond').css('margin-left', '-' + img_w/2 + 'px');
	}
	//si l'image est plus petite en largeur uniquement
	if(img_w < win_w && img_h >= win_h) {
		$('#fond').width(win_w);//mettre l'image à la largeur de la fenetre
		$('#fond').height(img_h * win_w/img_w);//ajuster la hauteur de l'image en fonction de son ratio
		$('#fond').css('top', win_h/2 + 'px');//centrer l'image verticalement
		$('#fond').css('margin-top', '-' + img_h/2 + 'px');
	}
	//si l'image est plus petite en hauteur uniquement
	if(img_h < win_h && img_w >= win_w) {
		$('#fond').height(win_h);//mettre l'image à la hauteur de la fenetre
		$('#fond').width(img_w * win_h/img_h);//ajuster la largeur de l'image en fonction de son ratio
		$('#fond').css('left', win_w/2 + 'px');//centrer l'image horizontalement
		$('#fond').css('margin-left', '-' + img_w/2 + 'px');
	}
	//si l'image est plus petite en largeur et hauteur uniquement
	if(img_h < win_h && img_w < win_w) {
		//determiner si il faut se baser sur la largeur ou la hauteur
		var ratio_w = win_w/img_w; 
		var ratio_h = win_h/img_h;
		if(ratio_w > ratio_h) {
			$('#fond').width(win_w);//mettre l'image à la largeur de la fenetre
			$('#fond').height(img_h * win_w/img_w);//ajuster la hauteur de l'image en fonction de son ratio
			$('#fond').css('top', win_h/2 + 'px');//centrer l'image verticalement
			$('#fond').css('margin-top', '-' + (img_h * win_w/img_w)/2 + 'px');
		}else{
			$('#fond').height(win_h);//mettre l'image à la hauteur de la fenetre
			$('#fond').width(img_w * win_h/img_h);//ajuster la largeur de l'image en fonction de son ratio
			$('#fond').css('left', win_w/2 + 'px');//centrer l'image horizontalement
			$('#fond').css('margin-left', '-' + (img_w * win_h/img_h)/2 + 'px');
		}
	}
	
}
