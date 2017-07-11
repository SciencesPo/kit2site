<?php
$n = 0;
$nn = 0;
$nnn = 0;
$firstrezosocio = false;
global $language;
$lg = $language->language;
global $base_url;

// print "\n<pre>\n";
// print '\$menu_data = ';
// //var_dump(`);
// print_r($menu_data);
// print "\n</pre>\n";
// exit;

?>


<ul id="<?php print $menu_name; ?>">
	
<?php foreach ($menu_data as $key => $menu) { ?>

	<?php if($menu_name == "navcorporate" && strstr($menu['title'], '<img')): ?>
		<li class="rezosocial" id="li-<?php print $n; ?>">
	<?php elseif($menu_name == "navcorporate" && $menu['title'] == "langue"): ?>
		<li class="langue-li" id="li-<?php print $n; ?>">
	<?php elseif($menu_name == "navmain" && substr($menu['title'], 0, 4) == "<img"): ?>
		<li class="search" id="li-<?php print $n; ?>">
	<?php else: ?>
		<li class="normal" id="li-<?php print $n; ?>">
	<?php endif; ?>
          <?php 
			// print "<pre>\n";
			// print "title_tag.' '.menu_title = ";
			// //var_dump($title_tag.' '.menu_title);
			// print_r($title_tag.' '.$menu_title);
			// print "\n</pre>";
			// exit;
			$class = "level1 ";
			if($menu_name == "navmain"){
				$class .= "police-sans-condensed ";
			}else{
				$class .= "police-sans ";
			}
			if($menu_name == "navcorporate" && strstr($menu['title'], '<img')) {
				if(!$firstrezosocio){
					$class .= " rezosoc firstrezo";
					$firstrezosocio = true;
				}else{
					$class .= " rezosoc ";
				}
			}
			if(strstr($menu['title'], '<img') && !strstr($menu['title'], '<img src="http')) {
        $menu['title'] = str_replace('src="', 'src="http://www.sciencespo.fr', $menu['title']);
        $p = '/alt=".*?"\s/';
        $menu['title'] = preg_replace($p, '', $menu['title']);
			}
      if(strstr($menu['title'], '<img') && strstr($menu['title'], 'rss.png')) {
        //print '<pre>';
        //print_r($menu);
        //print '</pre>';

				$menu['title'] = str_replace('rss.png', 'scpo.png', $menu['title']);
				$menu['path'] = 'http://www.sciencespo.fr';
				if($language->language == 'fr'){
					$menu['desc'] = 'Portail Sciences Po';
				}else{
					$menu['desc'] = 'Sciences Po portal';
				}
        //print '<pre>';
        //print_r($menu);
        //print '</pre>';

			}
			
            if($menu['desc'] != $menu['title']){
              $title_tag = $menu['desc'];
            }else{
              $title_tag = '';
            }
	    $menu_title = $menu['title'];
			if($menu_name == "navcorporate" && $n == 0) {
				$class .= " vous-etes ";
			}
			if($menu_name == "navmain" && $n == count($menu_data) - 1) {
				$menu['title'] = $menu['title'];
			}else {
				if($menu['below']){
					$menu['title'] .= '<img alt="" class="fleche-deroulant" src="http://www.sciencespo.fr/sites/all/themes/SPresponsive/images/fleche-menu-deroulant-corp-black.png"/>';
				}
			}
			$id = "level1-$n";

			// if($menu['path'] == "<front>" || $menu['path'] == "/"){
			// 	$menu['path'] == "javascript:void(0)";
			// }
			
			if($menu_name == "navcorporate" && $menu['title'] == "langue"){
				$l = locale_language_list($field = 'name', $all = FALSE);
				if(count($l) == 1){
					$menu['title'] = "";
					$menu['path'] = $base_url;
					$lang = '';

				}else if(count($l) == 2){
						if($lg == 'fr'){
							$menu['title'] = "English";
							$menu['path'] = $base_url."/en";
							$title_tag = "English version of the website";
							// $menu['path'] = "javascript:void(0);";
							$lang = 'en';
						}
						if($lg == 'en'){
							$menu['title'] = "Français";
							$menu['path'] = $base_url."/fr";
							$title_tag = "Version française du site";
							// $menu['path'] = "javascript:void(0);";
							$lang = 'fr';
						}
						$class .= " langue ";

				}else if(count($l) > 2){
					$nom = array('fr' => "Français", 'en' => 'English', 'de' => 'Deutsch');
					$desc = array('fr' => "Version française du site", 'en' => 'English version of the website', 'de' => 'Deutsch Version der Website');
					$menu['title'] = t('Language');
					$menu['path'] = 'lllangues';

					$menu['langues'] = array();
					foreach ($l as $lcode => $lname) {
						$menu['langues'][$lcode]['title'] = $nom[$lcode];
						$menu['langues'][$lcode]['path'] = $base_url."/".$lcode;
						$menu['langues'][$lcode]['lang'] = $lcode;
						$menu['langues'][$lcode]['desc'] = $desc[$lcode];
					}


				}
			}


			$ariahaspopup = 'false';
			$ariaselected = 'false';
			if($menu['current'] == 1){ $ariaselected = 'true'; $tabindex = "0"; }
			if($n == 0){ $class .= "first"; }
			if($n == count($menu_data) - 1){ $class .= "last"; }
			if($menu['below']){ $ariahaspopup = 'true'; $class .= " haschildren"; }
			
			$a = array('html' => true, 'attributes' => array('id' => $id, 'class' => $class, 'aria-haspopup' => $ariahaspopup ));
			if($lang){
				$a['attributes']['lang'] = $lang;
                        }
//print '$menu_title = '.$menu_title.'<br>';
//print '$title_tag = '.$title_tag;


                          $a['attributes']['title'] = $title_tag;
			
                        if($menu['path'] == 'javascript:void(0)'){

			  print '<a href="'.$menu['path'].'" id="'.$id.'"';
                          if($title_tag != ''){
                            print ' title="'.$title_tag.'"';
                          }
			if($menu['below']){ print 'ariahaspopup = true';}

			  print ' class="'.$class.'" role="button">'.$menu['title'].'</a>';

			}else if($menu['path'] == 'lllangues'){
				$div = '<a href="#" title="'.t('Change language of the website').'" class="level1 police-sans langue haschildren last" role="button">'.t('Language').'</a>';
				$div .= '<ul aria-labelledby="'.$id.'">';
				foreach($menu['langues'] as $code => $item){
					$div .= '<li><a href="'.$item['path'].'" title="'.$item['title'].'" class="level2">'.$item['title'].'</a></li>';
				}
				$div .= '</ul>';
				
				print $div;

                        }else{
				print l($menu['title'], $menu['path'], $a); 
			}
		?>
	
		<?php if($menu['below']): ?>

		<ul aria-labelledby="<?php print $id; ?>">
			<?php 
			 $nn = 0;
			 foreach ($menu['below'] as $key_key => $menu_menu) { ?>

				<li>
					<?php 
						$id = "level2-$nn";
						$class = "level2 ";
						$ariahaspopup = 'false';
						$ariaselected = 'false';
						if($menu_menu['current'] == 1){ $ariaselected = 'true'; $tabindex = "0"; }
						if($nn == 0){ $class .= "first"; }
						if($nn == count($menu['below']) - 1){ $class .= "last"; }
						if($menu_menu['below']){ $ariahaspopup = 'true'; }  
						if($menu_menu['desc'] != $menu_menu['title'] && !empty($menu_menu['desc'])){
							print l($menu_menu['title'], $menu_menu['path'], array('html' => true, 'attributes' => array('id' => $id, 'title'=> $menu_menu['desc'], 'class' => $class)));
						}else{
							print l($menu_menu['title'], $menu_menu['path'], array('html' => true, 'attributes' => array('id' => $id, 'class' => $class)));
						}
					?>

				<?php if($menu_menu['below']): ?>

					<ul aria-labelledby="<?php print $id; ?>">

						<?php 
						 $nnn = 0;
						 foreach ($menu_menu['below'] as $key_key_key => $menu_menu_menu) { ?>

							<li>
								<?php
									$id = "level3-$nnn";
									$class = "level3 ";
									$ariaselected = 'false';
									if($menu_menu_menu['current'] == 1){ $ariaselected = 'true'; }
									if($nnn == 0){ $class .= "first"; }
									if($nnn == count($menu_menu['below']) - 1){ $class .= "last"; } 
									print l($menu_menu_menu['title'], $menu_menu_menu['path'], array('html' => true, 'attributes' => array('id' => $id, 'title'=> $menu_menu_menu['desc'], 'class' => $class)));
								?>
							</li>

							<?php $nnn++; ?>
						<?php }//end foreach ?>

					</ul>
				<?php endif; ?>

			</li>

				<?php $nn++; ?>
			<?php }//end foreach ?>

		</ul>
	<?php endif; ?>
	</li>

	<?php $n++; ?>
<?php }//end foreach ?>

</ul>
