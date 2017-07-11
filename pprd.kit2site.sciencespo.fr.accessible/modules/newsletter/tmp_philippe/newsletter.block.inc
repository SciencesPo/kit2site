<?php
/*
* implementation of hook_block
* Créé et affiche le block d'inscription aux newsletters
*/

function newsletter_block($op = 'list', $delta = 0, $edit = array()) {

    switch ($op) {
		case 'list':
			$blocks['newsletter'] = array(
				'title' => t('Newsletters subscription'),
				'info' => 'Block d\'inscription aux newsletters',
				'status' => 1,
				'region' => 'sidebar_second',
			);
			return $blocks;
		break;

		case 'configure':
			$txt_defaut = array(
				'fr' => array(
					'titre' => 'Newsletter',
					'intro'=> 'Entrez votre adresse email pour ête informé de l\'actualité de Sciences po',
					'sabonner' => 'S\'abonner',
					'toutes' => 'Toutes les neswletters',
				),
				'en' => array(
					'titre' => 'Newsletter',
					'intro'=> 'Enter your email to keep updated about Sciences Po news',
					'sabonner' => 'Subscribe',
					'toutes' => 'All newsletters',
				),
			);
			$txt = variable_get('textes_newsletter', $txt_defaut);
			$form['fr_titre'] = array(
				'#type' => 'textfield',
				'#title' => 'Titre du bloc en français',
				'#default_value' => $txt['fr']['titre'],
			);
			$form['en_titre'] = array(
				'#type' => 'textfield',
				'#title' => 'Titre du bloc en anglais',
				'#default_value' => $txt['en']['titre'],
			);
			$form['fr_intro'] = array(
				'#type' => 'textfield',
				'#title' => 'Texte d\'intro du bloc en français',
				'#default_value' => $txt['fr']['intro'],
			);
			$form['en_intro'] = array(
				'#type' => 'textfield',
				'#title' => 'Texte d\'intro du bloc en anglais',
				'#default_value' => $txt['en']['intro'],
			);
			$form['fr_sabonner'] = array(
				'#type' => 'textfield',
				'#title' => 'Texte du bouton d\'envoi en français',
				'#default_value' => $txt['fr']['sabonner'],
			);
			$form['en_sabonner'] = array(
				'#type' => 'textfield',
				'#title' => 'Texte du bouton d\'envoi en anglais',
				'#default_value' => $txt['en']['sabonner'],
			);
			$form['fr_toutes'] = array(
				'#type' => 'textfield',
				'#title' => 'Lien vers toutes les newsletters en français',
				'#default_value' => $txt['fr']['toutes'],
			);
			$form['en_toutes'] = array(
				'#type' => 'textfield',
				'#title' => 'Lien vers toutes les newsletters en anglais',
				'#default_value' => $txt['en']['toutes'],
			);
			return $form;
			
		break;
		
		case 'save':
			$txt = array();
			foreach($edit as $key => $v){
				if(strstr($key, 'fr_')){
					$k = str_replace('fr_', '', $key);
					$txt['fr'][$k] = $v;
				}
				if(strstr($key, 'en_')){
					$k = str_replace('en_', '', $key);
					$txt['en'][$k] = $v;
				}
			}
			variable_set('textes_newsletter', $txt);
		break;

		case 'view':
			switch ($delta) {
				//contenu du bloc
				case 'newsletter':
					global $language;
					$lg = $language->language;
					$txt = variable_get('textes_newsletter', array());
					$txt = $txt[$lg];		
					$block['subject'] = $txt['titre'];
					// $block['content'] = $txt['intro'];
					//afficher formulaire pour adresse mail et bouton OK pour s'inscrire en un click a newsletter par defaut
					$block['content'] = drupal_get_form('newsletter_block_form');
					$block['content'] .= '<p>'.l($txt['toutes'], 'newsletter-inscription', array('html' => true)).'</p>';	
				break;
			}
			return $block;
		
		break;		
	}
}


























