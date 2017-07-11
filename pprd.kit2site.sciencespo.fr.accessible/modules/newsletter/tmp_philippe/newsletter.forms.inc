<?php
/**
* Génère le formulaire d'administration pour la gestion des listes à montrer à l'internaute.
*
*/
function newsletter_overview_form(){
	global $sympa_lists;
	

	
	
	$var = newsletter_get_lists();
	$sympa_lists = $var[0];
	$abonnes = $var[1];

	
	$lists_desc = variable_get('lists_desc', array());//variable stockant les descriptions et les images

	
	$form['info'] = array(
		'#value' => '<ul>Les newsletters listées ci-dessus sont disponibles pour ce site<li>Seules celles qui sont activées sont visibles et gérables par l\'internaute</li><li>La newsletter sélectionnée par défaut est celle à laquelle l\'internaute s\'abonne lorqu\'il utilise le bloc d\'abonnement rapide</li><li>Les autres sont gérables par l\'internaute sur la page d\'abonnement</li></ul>',
		'#weight' => -150,
	);
	$sympa_lists_affichable = array();
	$form['#attributes'] = array('enctype' => "multipart/form-data");
	foreach($sympa_lists as $name => $subject) {
		$sympa_lists_affichable[$name] = '';
	    $form['name'][$name] = array(
			'#value' => $subject
			);
		  $form['desc_'.$name] = array(
			'#type' => 'textarea',
			'#title' => 'Description',
		    '#default_value' => $lists_desc[$name]['desc'],
		  );
			if(!empty($lists_desc[$name]['image'])){
				  $form['image'][$name] = array(
					// '#type' => 'checkbox',
					// '#value' => 'retirer',
					// '#default_value' => 'pas retirer',
					// '#size' => 30,
					'#value' => 'Illustration<br />'.theme_image(file_directory_path().'/'.$lists_desc[$name]['image'], '', '', array('width' => '100px'), FALSE),
				  );
				  $form['image_'.$name] = array(
					'#type' => 'checkbox',
					'#title' => 'Retirer',
				  	// '#value' => 'retirer',
					// '#default_value' => null, 
				);
			}else{
			  $form['image'][$name] = array(
				'#type' => 'file',
				'#size' => 30,
				'#title' => 'Illustration',
			  );
			}
		  $form['archive_'.$name] = array(
			'#type' => 'textfield',
			'#title' => 'Url des archives',
	    	'#default_value' => $lists_desc[$name]['archive'],
		  );
	
		if($abonnes[$name]['count'] == 0) {
			$form['abonnes_'.$name] = array(
				'#value' => 'Pas d\'abonné',
			);
		}else{
			$img = theme_image(drupal_get_path('module', 'newsletter').'/icone_excel.png', t('Liste des abonnes'), t('Télécharger la liste des abonnés'));
			$abo = $abonnes[$name]['count'] > 0 && $abonnes[$name]['count'] < 2 ? '1 abonné' : $abonnes[$name]['count'].' abonnés';
			$form['abonnes_'.$name]['liste'] = array(
				'#value' => $abo.'<br /><br />'.l($img, 'newsletter-abonnes/'.$name, array('html' => TRUE)),
			);
		}
	}
//listes retenues par le webmaster
	$lists = variable_get('sympa_lists', array());
	$default_list = variable_get('sympa_default', 0);

	if(!empty($sympa_lists)){
	  $form['enabled'] = array(
		'#type' => 'checkboxes',
	    '#options' => $sympa_lists_affichable,
	    '#default_value' => $lists,
	  );
	  $form['site_default'] = array(
		'#type' => 'radios',
	    '#options' => $sympa_lists_affichable,
	    '#default_value' => $default_list,
	  );

	}
	  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
	  $form['#theme'] = 'newsletter_overview_form';

	
	return $form;

}

function theme_newsletter_overview_form($form) {
  $default = variable_get('sympa_default', NULL);
  foreach ($form['name'] as $key => $element) {
    // Do not take form control structures.
    if (is_array($element) && element_child($key)) {
      // Disable checkbox for the default language, because it cannot be disabled.
      // if ($key == $default) {
      //   $form['enabled'][$key]['#attributes']['disabled'] = 'disabled';
      // }
      $rows[] = array(
        array('data' => drupal_render($form['enabled'][$key]), 'align' => 'center'),
        check_plain($key),
        drupal_render($form['name'][$key]),
        array('data' => drupal_render($form['site_default'][$key]), 'align' => 'center'),
		array('data' => drupal_render($form['abonnes_'.$key]), 'align' => 'center'),
		array('data' => drupal_render($form['desc_'.$key]).'<hr />'.drupal_render($form['image'][$key]).drupal_render($form['image_'.$key]).'<hr/>'.drupal_render($form['archive_'.$key]), 'class' => 'desc'),
      );
    }
  }
  $header = array(array('data' => t('Activée')), array('data' => t('Nom')), array('data' => t('Sujet')), array('data' => t('Par défaut')), array('data' => t('Abonnés')) , array('data' => t('Description, image et URL d\'archives')));
  $output = theme('table', $header, $rows);
  $output .= drupal_render($form);

  return $output;
}
/**
* Submit du formulaire définit dans newsletter_overview_form()
*
*/
function newsletter_overview_form_submit($form, &$form_state){

	
	global $sympa_lists;
	
	$default_list = variable_get('sympa_default', array());
	$values = $form_state['clicked_button']['#post'];
	$values['enabled'][$default_list] = $default_list;
	$lists_desc = variable_get('lists_desc', array());

	
	foreach ($values['enabled'] as $key => $value) {
		if(!empty($value)) {
			if($file = file_save_upload($key, array(), file_directory_path(), FILE_EXISTS_RENAME)){
				$lists_desc[$key]['image'] = $file->filename;
				$lists_desc[$key]['image_id'] = $file->fid;
			}
			if(isset($values['image_'.$value]) && $values['image_'.$value] == 1){
				$lists_desc[$key]['image'] = '';
				$lists_desc[$key]['image_id'] = '';
			}
		}
		
		$lists_desc[$key]['desc'] = $values['desc_'.$key];
		$lists_desc[$key]['archive'] = $values['archive_'.$key];
	}
  foreach ($sympa_lists as $name => $subject) {
    if ($values['site_default'] == $name || $default_list == $name) {
      $values['enabled'][$name] = $name;
    }
  }

	$new_sympa_lists = array();
	$new_sympa_lists[$values['site_default']] = 1;
	foreach ($values['enabled'] as $key => $value) {
		if($value != '0'){
			$new_sympa_lists[$key] = $value;
		}		
	}
	
		
	variable_set('sympa_lists', $new_sympa_lists);
	variable_set('sympa_default', $values['site_default']);
	variable_set('lists_desc', $lists_desc);

	drupal_set_message('Les paramètres de newsletter sont enregistrés.', $type = 'status', $repeat = TRUE);
}

/**
* Formulaire d'abonnement rapide dans le bloc newsletters
*/
function newsletter_block_form(){
	global $language;
	$lg = $language->language;
	$txt = variable_get('textes_newsletter', array());
	$txt = $txt[$lg];	
	
	$default = variable_get('sympa_default', NULL);		
	global $user;
	$email = NULL;
	if($user->uid != 0) {
		$email = $user->email;
	}
	// $form['newsletter'] = array(
	// 	'#type' => 'fieldset',
	// 	'#collapsible' => FALSE,
	// );
	$form['newsletter']['quiet'] = array(
		'#type' => 'hidden',
		'#default_value' => 0,
	);
	$form['newsletter']['email'] = array(
		'#type' => 'textfield',
		'#title' => $txt['intro'],
		'#default_value' => $email,
		'#size' => NULL,
		'#attributes' => array('title' => t('Must be of the form : user@domain.ext')),
	);
	$form['newsletter']['submit'] = array('#type' => 'submit', '#value' => 'Ok', '#attributes' => array('title' => t('Submit newsletter subscription')));
	
	return $form;
}
/**
* Valide le formulaire d'abonnement rapide dans le bloc newsletters
*/
function newsletter_block_form_validate($form, &$form_state) {
	global $language;
	global $textes;
	$lg = $language->language;
	$values = $form_state['values'];
	$mail = '/.+@.+\..+/';
	if(empty($values['email'])){
		form_set_error('email-page', $textes[$lg]['warning-mail-empty']);
	}else if(!preg_match ($mail, $values['email'])){
		form_set_error('', $textes[$lg]['warning-mail-wrong']);
	}
}


/**
* Submit du formulaire d'abonnement rapide dans le bloc newsletters
*/
function newsletter_block_form_submit($form, &$form_state) {
	global $abonnes;
	global $default;

	$var = newsletter_get_lists();
	$sympa_lists = $var[0];
	$abonnes = $var[1];
	
   
	$default_list = variable_get('sympa_default', NULL);
	
	$email = $form_state['values']['email'];
	$quiet = $form_state['values']['quiet'];
	$data = array(str_replace('_', '.', $default_list), $email, '');
	
	
	if($abonnes[$default_list] && !in_array($email, $abonnes[$default_list])){
		$sympa = variable_get('sympa', $default);
		$options	= array('compression'=>false, 'exceptions'=>false, 'wsdl_cache' => 0, 'trace'=>true, 'uri' => $sympa['soapServer'], 'location' => $sympa['soapServer'] );
		$soapclient = new SoapClient(null, $options);
		//listes disponibles dans SYMPA

		try {
			use_soap_error_handler(true);
			$sympaLists = $soapclient->authenticateRemoteAppAndRun($sympa['trusted_application'], $sympa['trusted_application_password'], $sympa['proxy_vars'], 'add', $data);
			drupal_set_message(t('You have been subscribed to the newsletter %newsletter. Thanks for your input.', array('%newsletter' => $default_list)), $type = 'status', $repeat = FALSE);
		}catch (Exception $soapFault) {
			$message = $soapFault.", ".$sympaLists;
			drupal_set_message($message, $type = 'error', $repeat = TRUE);
		}
		
	}else{
		drupal_set_message(t('You already subscribed to this newsletter'), $type = 'status', $repeat = FALSE);
	}

}






/**
* Génère le formulaire de la page d'abonnement aux newsletters
*
*/
function newsletter_list_form($form_id, $email = NULL, $list = NULL){
	global $abonnes;
	global $language;
	global $textes;
	$lg = $language->language;
	$liste = variable_get('sympa_lists', array());
	$lists_desc = variable_get('lists_desc', array());//variable stockant les descriptions et les images



	foreach ($liste as $key => $listname) {
		$form['f'.$key] = array(
			'#type' => 'fieldset',
			'#title' => $key,
		);
		if(!empty($lists_desc[$key]['image'])){
			$form['f'.$key]['image'.$key] = array(
				'#value' => theme_image(file_directory_path().'/'.$lists_desc[$key]['image'], null, null, array('width' => '160px', 'class' => 'image-newsletter'), FALSE),
			);
		}else{
			$form['f'.$key]['image'.$key] = array(
				'#value' => '<div style="width:160px;height:120px" class="image-newsletter"></div>',
			);
		}
		$form['f'.$key]['titre'.$key] = array(
			'#value' => '<div class="bloc-nwsltr">',
		);
		$form['f'.$key]['desc'.$key] = array(
			'#value' => '<p>'.$lists_desc[$key]['desc'].'</p>',
		);
				
		$opt = array('1' => $textes[$lg]['sabonner'], '0' => $textes[$lg]['sedesabonner']);
		$archive = '';
		if(!empty($lists_desc[$key]['archive'])){
			$archive = '<a href="'.$lists_desc[$key]['archive'].'" target="_blank">'.$textes[$lg]['archives'].'</a></div></div>';
		}else{
			$archive = '</div>';
		}
		
		$form['f'.$key]['abonner'.$key] = array(
			'#type' => 'radios',
			'#options' => $opt,
			'#prefix' => '<div class="archive">',
			'#suffix' => $archive,
		);
	}

	$form['email-txt'] = array(
		'#value' => '<p>'.$textes[$lg]['email-txt'].'</p>',
	);

	$form['email-page'] = array(
		'#type' => 'textfield',
		'#title' => $textes[$lg]['email'],
		'#size' => NULL,
		'#attributes' => array('title' => t('Must be of the form : user@domain.ext')),
	);

	$form['submit'] = array('#type' => 'submit', '#value' => 'Ok', '#attributes' => array( 'title' => t('Submit your changes to the newsletter list')));	
	return $form;
}

function newsletter_list_form_validate($form, &$form_state){
	global $language;
	global $textes;
	$lg = $language->language;
	$values = $form_state['values'];
	$mail = '/.+@.+\..+/';
	if(empty($values['email-page'])){
		form_set_error('email-page', $textes[$lg]['warning-mail-empty']);
	}else if(!preg_match ($mail, $values['email-page'])){
		form_set_error('', $textes[$lg]['warning-mail-wrong']);
	}

}



function newsletter_list_form_submit($form, &$form_state){
	global $default;
	global $textes;
	global $language;
	$lg = $language->language;
   
	$values = $form_state['values'];
	$dontget = array('op', 'submit', 'form_build_id', 'form_token', 'form_id', 'email-page');
	$sympa = variable_get('sympa', $default);
	$options	= array('compression'=>false, 'exceptions'=>false, 'wsdl_cache' => 0, 'trace'=>true, 'uri' => $sympa['soapServer'], 'location' => $sympa['soapServer'] );
	$soapclient = new SoapClient(null, $options);
	$result = array('already_subscribed' => array(), 'new_subscribing' => array(), 'unsubscribing' => array(), 'not_subscribed' => array());
	foreach ($values as $key => $value) {
		if(in_array($key, $dontget)){ continue; }
		$list = str_replace('abonner', '', $key);
		$list = str_replace('_', '.', $list);
		$mail = $values['email-page'];

		

		$mails_in_this_list = $soapclient->authenticateRemoteAppAndRun($sympa['trusted_application'], $sympa['trusted_application_password'], $sympa['proxy_vars'], 'review', array($list));
		$data = array($list, $mail, '');
		
		if($value[$key] == '1'){//s'abonner à $list
			if($mails_in_this_list && in_array($mail, $mails_in_this_list)){					
				$result['already_subscribed'][] = $list;
			}else{
				$result['new_subscribing'][] = $list;
			}
			$soapclient->authenticateRemoteAppAndRun($sympa['trusted_application'], $sympa['trusted_application_password'], $sympa['proxy_vars'], 'add', $data);
		}else if($value[$key] == '0'){//se desabonner de $list
			if(in_array($mail, $mails_in_this_list)){
				$result['unsubscribing'][] = $list;
			}else{
				$result['not_subscribed'][] = $list;
			}
			$soapclient->authenticateRemoteAppAndRun($sympa['trusted_application'], $sympa['trusted_application_password'], $sympa['proxy_vars'], 'signoff', $data);
		}
		unset($mails_in_this_list);
	}
	$message_recap = '';
	if(!empty($result['already_subscribed'])){
		$message_recap .= $textes[$lg]['already_subscribed'].'<ul><li>'.implode('</li><li>', $result['already_subscribed']).'</li></ul>';
	}
	if(!empty($result['new_subscribing'])){
		$message_recap .= '<br />';
		$message_recap .= $textes[$lg]['new_subscribing'].'<ul><li>'.implode('</li><li>', $result['new_subscribing']).'</li></ul>';
	}
	if(!empty($result['unsubscribing'])){
		$message_recap .= '<br />';
		$message_recap .= $textes[$lg]['unsubscribing'].'<ul><li>'.implode('</li><li>', $result['unsubscribing']).'</li></ul>';
	}
	if(!empty($result['not_subscribed'])){
		$message_recap .= '<br />';
		$message_recap .= $textes[$lg]['not_subscribed'].'<ul><li>'.implode('</li><li>', $result['not_subscribed']).'</li></ul>';
	}
	$message_recap .= $textes[$lg]['merci'];
	
	drupal_set_message($message_recap, $type = 'status', $repeat = FALSE);
	
}



/**
* Formulaire des settings de connexion au server SOAP de sympa
*
*/
function newsletter_admin_settings(){
   global $default;

	$sympa = variable_get('sympa', $default);

	$form = array();
	$form['soapFileWsdl'] = array(
		'#type' => 'textfield',
		'#title' => 'Uri WSDL',
		'#default_value' => $sympa['soapFileWsdl'],
	);
	$form['soapServer'] = array(
		'#type' => 'textfield',
		'#title' => 'Uri SOAP server',
		'#default_value' => $sympa['soapServer'],
	);
	$form['trusted_application'] = array(
		'#type' => 'textfield',
		'#title' => 'User',
		'#default_value' => $sympa['trusted_application'],
	);
	$form['trusted_application_password'] = array(
		'#type' => 'textfield',
		'#title' => 'Password',
		'#default_value' => $sympa['trusted_application_password'],
	);
	$form['proxy_vars'] = array(
		'#type' => 'textfield',
		'#title' => 'Variables de proxy',
		'#default_value' => $sympa['proxy_vars'],
	);
	$form['#submit'][0] = 'newsletter_submit';
	
	return system_settings_form($form);

}

/**
* Submit du formualire défini dans newsletter_admin_settings()
*/
function newsletter_submit($form, &$form_state) {

	$values = $form_state['values'];
	$var = array();
	foreach($values as $k => $v){
		$var[$k] = $v;
	}
	variable_set('sympa', $var);
	
}


function newsletter_txt_settings() {
	global $textes;
   
	$form = array();
	$form['#tree']=true;
	$n = 0;
	foreach($textes['fr'] as $key => $value) {
	
		$form['fr'][$key.'_fr']['text'] = array(
			'#type' => 'textarea',
			'#title' => 'français',
			'#default_value' => $value,
			'#weight' => $n,
		);
		// $form['fr'][$key.'_fr']['format'] = filter_form(NULL, $n + 1, array('fr', $key.'_fr', 'format'));
		
		$form['en'][$key.'_en']['text'] = array(
			'#type' => 'textarea',
			'#title' => 'anglais',
			'#default_value' => $textes['en'][$key],
			'#weight' => $n + 2,
		);
		// $form['en'][$key.'_en']['format'] = filter_form(NULL, $n + 3, array('en', $key.'_en', 'format'));
	
		$n = $n + 4;
	}
	  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
	  $form['#theme'] = 'newsletter_txt_form';

	return $form;
	
}


function theme_newsletter_txt_form($form) {
	global $textes;
  foreach ($form['en'] as $key => $element) {
	
    // Do not take form control structures.
    if (is_array($element) && element_child($key)) {
       $rows[] = array(
			array('data' => check_plain($textes['etiquettes'][str_replace('_en', '', $key)]), 'colspan' => '2', 'header' => true),

		);
       $rows[] = array(
        array('data' => drupal_render($form['fr'][str_replace('_en', '_fr', $key)]), 'align' => 'center', 'width' => '250px'),
        array('data' => drupal_render($form['en'][$key]), 'align' => 'center', 'width' => '250px'),
      );
	}
  }
  // $header = array(array('data' => 'Français'), array('data' => 'Anglais'));
	$caption = 'blabbla';
  $output = theme_table(NULL, $rows);
  $output .= drupal_render($form);

  return $output;
}

function newsletter_txt_settings_submit($form, &$form_state) {
	global $textes;

	

	$values = $form_state['values'];
	$var = $textes;
	// $dontget = array('op', 'submit', 'form_build_id', 'form_token', 'form_id', 'email-page');
	foreach($values['fr'] as $k => $v){
		// if(in_array($v, $dontget)) { continue; }
			$var['fr'][str_replace('_fr', '', $k)] = $v['text'];
			$var['en'][str_replace('_fr', '', $k)] = $values['en'][str_replace('_fr', '_en', $k)]['text'];
	}
	variable_set('textes_page_newsletter', $var);
	
}

