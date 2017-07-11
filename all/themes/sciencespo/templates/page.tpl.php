<?php
global $base_url;
global $language;
$v = variable_get('new-custom-block-title', array());
$titredublock = $v[$language->language];
if(!$titredublock) {
	$titredublock = 'Pas de titre';
}
$site_title = variable_get('site_title', array());
if(!empty($site_title)){
  $site_name = $site_title['title_'.$language->language];  
}


$h1 = variable_get('h1', array());
$h1colonnedroite = str_replace('%titre-site', $site_name, $h1['h1colonnedroite_'.$language->language]);
$h1footer = str_replace('%titre-site', $site_name, $h1['h1footer_'.$language->language]);
$pat = '/<div id="block-.*?" class=".*?">.*?<\/div>.*?<!-- \/\.block -->/si';
preg_match_all( $pat, $header, $matches);
$mymatches = $matches;
$newterm = 0;
sort($matches[0]);
$newterm = 0;
$newblocks = array();
foreach( $matches[0] as $i => $m){
	if(strstr($m, 'SPlogin') ){
        $m = str_replace('<!-- /.block -->', '', $m);
		    $m = str_replace( '<a lang="en" href="#">Login</a>', '<a href="#">'.$titredublock.'</a>', $m);
        $m = str_replace('</ul>', '', $m);
        $m = str_replace('</div>', '', $m);
        $m = preg_replace('/<div id="block-.*?" class=".*?">.*?<div class="content">.*?<ul class="mainlist">/si', '', $m);
		    $newterm = 1;
        $newblocks['SPlogin'] = $m;
	}else if(strstr($m, 'custom')){
        $m = str_replace('<!-- /.block -->', '', $m);
		if($newterm == 0){
            $m = preg_replace('/<li.*class="first"><a.*href=".*?".*target="_blank".*title=".*?">.*?<\/a><span.*id="custom_fleche".*class="menu-fleche"><img.*src="\/sites\/all\/themes\/sciencespo\/images\/icon_flechedroite.png".*alt="".*\/><\/span><\/li>/msi', '<li class="first" ><a href="#">'.$titredublock.'</a><span id="custom_fleche" class="menu-fleche"><img src="/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""></span></li>', $m);
		    $newterm = 0;
        }else{
            $m = str_replace('class="first"', 'class="ouvert hiddenlist"', $m);  
            $m = str_replace('<span id="custom_fleche" class="menu-fleche"><img src="/sites/all/themes/sciencespo/images/icon_flechedroite.png" alt=""/></span>', '', $m);
		}
        $m = str_replace('</ul>', '', $m);
        $m = str_replace('</div>', '', $m);
        $m = preg_replace('/<div id="block-.*?" class=".*?">.*?<div class="content">.*?<ul class="mainlist">/si', '', $m);
        $newblocks['custom'] = $m;
	}else if( strstr($m, 'block-search')){ 
        $newblocks['search'] = $m;
	}else if(strstr($m, 'langues')){
        $newblocks['langues'] = $m;
	}else if(strstr($m, 'corporate')){
        $newblocks['corporate'] = $m;
	}
}
$s = $newblocks['SPlogin'].$newblocks['custom'];
if(!empty($s)){
	$newblock = '<div id="block-topboxes-custom" class="block block-topboxes"><div class="content"><ul class="mainlist" >';
	if($newblocks['SPlogin']){
	    $newblock .= $newblocks['SPlogin'];
	}
	if($newblocks['custom']){
	    $newblock .= $newblocks['custom'];
	}
	$newblock .= '</ul></div></div>';
}else{
	$newblock = null;
}

$d = explode('/', $base_url);
$path = '/store/www/kit2site02/sites/'.str_replace('www.', '', $d[count($d)-2]).    '.'.$d[count($d) - 1].'/themes/sciencespo';
$logo = null;
$withlogo = 0;
$withENlogo = 0;
if($dossier = opendir($path)){
    while(false !== ($fichier = readdir($dossier))){
		if(strstr($fichier, '_en')){
			$withENlogo = 1;
		}
	}
}
if($dossier = opendir($path)){
    while(false !== ($fichier = readdir($dossier))){
        if(strstr($fichier, $d[count($d) - 1]) && !strstr($fichier, '_en')){
            $logo = '/'.$d[count($d)-1].'/sites/'.str_replace('www.', '', $d[count($d)-2]).    '.'.$d[count($d)-1].'/themes/sciencespo/'.$fichier;
			if($language->language == 'en' && $withENlogo == 1){
				$logo = str_replace('.png', '_en.png', $logo);
			}
            $withlogo = 1;
        }
    }
}
if(!$logo){
    $logo = $base_url.'/sites/all/themes/sciencespo/logo-new.png';
}
$acc = array();
$acc['content']['fr'] = 'Aller au contenu';
$acc['content']['en'] = 'Go to content';
$acc['content']['de'] = 'Direkt zum Inhalt';
$acc['corp']['fr'] = 'Navigation corporate';
$acc['corp']['en'] = 'Corporate navigation';
$acc['corp']['de'] = 'Zur Firmen-navigation';
$acc['navig']['fr'] = 'Navigation principale';
$acc['navig']['en'] = 'Main navigation';
$acc['navig']['de'] = 'Zur Hauptnavigation';
$acc['search']['fr'] = 'Recherche';
$acc['search']['en'] = 'Search form';
$acc['search']['de'] = 'Suche';
$althome = "Retour à l'accueil de $site_name";
if($language->language == 'en'){ $althome = "Back to $site_name home";}
if($language->language == 'de'){ $althome = "Zurück zum $site_name Startseite";}
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"	"http://www.w3.org/TR/html4/loose.dtd">
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>

<!-- Google Tag Manager -->
<script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
'https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
})(window,document,'script','dataLayer','GTM-WFBGG7');</script>
<!-- End Google Tag Manager --> 


  <title><?php print preg_replace('/(.*)\|(.*)/', '$1| Sciences Po '.$site_name, $head_title); ?></title>
  <meta name="kit2site-version" content="2.4.0.0 du 27 janvier 2012">
  <?php print str_replace(array('/>', '/ >'), '>', $head); ?>
  <?php print str_replace('/>', '>', $styles); ?>
  <?php print str_replace('/>', '>', $scripts); ?>
</head>
<body class="<?php print $classes; ?>">

<!-- Google Tag Manager (noscript) -->
<noscript><iframe src="https://www.googletagmanager.com/ns.html?id=GTM-WFBGG7"
height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
<!-- End Google Tag Manager (noscript) -->

	<ul id="accessibilitylinks">
		<li><a href="#content"><?php print $acc['content'][$language->language]; ?></a>/</li>
		<li><a href="#block-barre_corp-menu_corporate"><?php print $acc['corp'][$language->language]; ?></a>/</li>
		<li><a href="#navigation"><?php print $acc['navig'][$language->language]; ?></a>/</li>
		<li><a href="#edit-search-block-form-1"><?php print $acc['search'][$language->language]; ?></a></li>
	</ul>

	  <div id="page-wrapper"><div id="page">
        <?php if($withlogo == 0): ?>
			<div id="header">
        <?php else: ?>
			<div id="header" class="dedie">
		<?php endif; ?>


<!--//******************************************************************************************-->
        <div id="topbarlarge">
            <?php print $newblocks['corporate']; ?>
        </div>
        <?php if($withlogo == 0): ?>
			<div class="logo" style="float:left">
        <?php else: ?>
			<div class="logo dedie" style="float:left">
		<?php endif; ?>
<a href="<?php print $front_page; ?>" title="<?php print $althome; ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print $althome; ?>" /></a>            
        </div>

		<?php if($newblock): ?>
	        <div class="custom-block" style="float:right;position:relative">
	            <?php print $newblock; ?>
	        </div>
		<?php endif; ?>
        <div class="search" style="float:right">
            <?php print $newblocks['search']; ?>
        </div>
            
        <?php if($withlogo == 0): ?>
        <div class="title" style="float:none;clear:both;">
            <?php print $site_name; ?>
        <?php else: ?>
        	<div class="filet" style="float:none;clear:both;">
				&nbsp;
		<?php endif; ?>
		</div>
		

<!--//*****************************************************************************************-->

	    </div> <!-- /.section, /#header -->



	    <div id="main-wrapper"><div id="main" class="clearfix<?php if ($primary_links || $navigation) { print ' with-navigation'; } ?>">

	      <?php if ($primary_links || $navigation): ?>
	        <div id="navigation">
				<div class="section clearfix">

				  <?php print theme(array('links__system_main_menu', 'links'), str_replace('/>', '>', $primary_links),
					array(
					  'id' => 'main-menu',
					  'class' => 'links clearfix',
					),
					array(
					  'text' => t('Main menu'),
					  'level' => 'h2',
					  'class' => 'element-invisible',
					));
				  ?>

	          <?php print str_replace('/>', '>', $navigation); ?>
					<div id="degrade"></div>
				</div>
			</div> <!-- /.section, /#navigation -->
	      <?php endif; ?>
<!--//***********************************************************************************************-->

			<?php print str_replace('/>', '>', $edito); ?>
		    <?php print str_replace('/>', '>', $breadcrumb); ?>

	      <div id="content" class="column"><div class="section">

	        <?php if ($mission): ?>
	          <div id="mission"><?php print str_replace('/>', '>', $mission); ?></div>
	        <?php endif; ?>

	        <?php //print $edito; ?>

	        <?php 
			if ($title　&& ($node->type != "page_interne") || $node->type == NULL): ?>
	          <h1 class="title"><?php print $title; ?></h1>
	        <?php endif; ?>
	        <?php print $messages; ?>
	        <?php if ($tabs): ?>
	          <div class="tabs"><?php print $tabs; ?></div>
	        <?php endif; ?>
	        <?php print $help; ?>

	        <?php print $content_top; ?>
			<!--dela-->
	        <div id="content-area">

	          <?php print str_replace('/>', '>', $content); ?>
	        </div>
			<!--ala-->

	        <?php print str_replace('/>', '>', $content_bottom); ?>


	      </div></div> <!-- /.section, /#content -->


	<!-- navigation avant !!! -->
			<?php print str_replace('/>', '>', $sidebar_first); ?>


			<?php
			//permet d'afficher le <h1 class="outscreen"> uniquement si des blocs sont présents dans la colonne de droite.
			$sidebar_second_vide = '<div class="content">&nbsp;</div>';
			$test_vide = str_replace(array(' ', "\n", "\r", "\n\r", "\t"), '', $sidebar_second_vide);
			$atester_vide = str_replace(array(' ', "\n", "\r", "\n\r", "\t"), '', $sidebar_second);
			if(!strstr($atester_vide, $test_vide)){
				$pat = '/<div(.*?)>/';
				preg_match($pat, $sidebar_second, $matches);
				$sidebar_second = str_replace($matches[0], $matches[0].'<h1 class="outscreen">'.$h1colonnedroite.'</h1>', $sidebar_second);
			}
				print str_replace('/>', '>', $sidebar_second);
			?>

	    </div></div> <!-- /#main, /#main-wrapper -->


		<div id="back_top">
			<a href="#header"><?php print t('Back to top'); ?></a>
		</div>

	    <?php if ($footer || $footer_message || $secondary_links): ?>
	      <div id="footer"><div class="section clearfix">
			  <h1 class="outscreen"><?php print $h1footer; ?></h1>

	        <?php print theme(array('links__system_secondary_menu', 'links'), str_replace('/>', '>', $secondary_links),
	          array(
	            'id' => 'secondary-menu',
	            'class' => 'links clearfix',
	          ),
	          array(
	            'text' => t('Secondary menu'),
	            'level' => 'h2',
	            'class' => 'element-invisible',
	          ));
	        ?>


	        <?php if ($footer_message): ?>
	          <div id="footer-message"><?php print $footer_message; ?></div>
	        <?php endif; ?>

	        <?php print str_replace('/>', '>', $footer); ?>

	      </div></div> <!-- /.section, /#footer -->
	    <?php endif; ?>

	  </div></div> <!-- /#page, /#page-wrapper -->

	  <?php print str_replace('/>', '>', $page_closure); ?>

	  <?php print str_replace('/>', '>', $closure); ?>
</body>
</html>
