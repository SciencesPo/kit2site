$content['type']  = array (
  'name' => 'Spire Publication',
  'type' => 'spire_publication_type',
  'description' => 'Publication importée de Spire',
  'title_label' => 'Titre',
  'body_label' => 'Chicago',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => true,
    'promote' => false,
    'sticky' => false,
    'revision' => false,
  ),
  'language_content_type' => '2',
  'upload' => '0',
  'old_type' => 'spire_publication_type',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'nodewords_edit_metatags' => 1,
  'nodewords_metatags_generation_method' => '0',
  'nodewords_metatags_generation_source' => '2',
  'nodewords_use_alt_attribute' => 1,
  'nodewords_filter_modules_output' => 
  array (
    'imagebrowser' => false,
    'img_assist' => false,
  ),
  'nodewords_filter_regexp' => '',
  'content_profile_use' => 0,
  'links_related_types' => '0',
  'print_display' => 1,
  'print_display_comment' => 0,
  'print_display_urllist' => 1,
  'print_mail_display' => 1,
  'print_mail_display_comment' => 0,
  'print_mail_display_urllist' => 1,
  'print_pdf_display' => 1,
  'print_pdf_display_comment' => 0,
  'print_pdf_display_urllist' => 1,
  'i18n_newnode_current' => 0,
  'i18n_required_node' => 0,
  'i18n_lock_node' => 0,
  'i18n_node' => '1',
  'i18nsync_nodeapi' => 
  array (
    'name' => false,
    'status' => false,
    'promote' => false,
    'moderate' => false,
    'sticky' => false,
    'revision' => false,
    'parent' => false,
    'taxonomy' => false,
    'files' => false,
    'field_sppu_date_issued' => false,
    'field_sppu_rec_type' => false,
    'field_sppu_desc' => false,
    'field_sppu_auteurs' => false,
    'field_sppu_rec_id' => false,
  ),
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Date parution',
    'field_name' => 'field_sppu_date_issued',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Modifier les informations de base',
    'weight' => '-4',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_sppu_date_issued][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Enregistrer les paramètres du champ',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      5 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'Type',
    'field_name' => 'field_sppu_rec_type',
    'type' => 'text',
    'widget_type' => 'optionwidgets_select',
    'change' => 'Modifier les informations de base',
    'weight' => '-3',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'ConferencePoster|Affiche de conférence
JournalArticle|Article
MagazineArticle|Article
NewspaperArticle|Article
AnnotationArticle|Article annoté
Map|Carte
ConferenceProceedings|Délibération de conférence
ConferencePaper|Discours de conférence
Document|Document
WorkingPaper|Document de travail
Event|Evènement
BookPart|Extrait de livre
ReportPart|Extrait de rapport
ConferenceContribution|Intervention en conférence
InterviewArticle|Interview
Book|Ouvrage
PeriodicalIssue|Périodique
Preprint|Prépresse
Report|Rapport
Website|Site web
BookReview|Synopsys
DoctoralThesis|Thèse de doctorat
MasterThesis|Thèse de master
ProfessoralThesis|Thèse professorale
VideoRecording|Video
websiteContribution: WebPage|Page web',
    'allowed_values_php' => '',
    'op' => 'Enregistrer les paramètres du champ',
    'module' => 'text',
    'widget_module' => 'optionwidgets',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      5 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  2 => 
  array (
    'label' => 'Description',
    'field_name' => 'field_sppu_desc',
    'type' => 'text',
    'widget_type' => 'text_textarea',
    'change' => 'Modifier les informations de base',
    'weight' => '-2',
    'rows' => '5',
    'size' => 60,
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_sppu_desc][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Enregistrer les paramètres du champ',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      5 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  3 => 
  array (
    'label' => 'Auteurs',
    'field_name' => 'field_sppu_auteurs',
    'type' => 'nodereference',
    'widget_type' => 'nodereference_select',
    'change' => 'Modifier les informations de base',
    'weight' => 0,
    'autocomplete_match' => 'contains',
    'size' => 60,
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'nid' => '',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '1',
    'referenceable_types' => 
    array (
      'spire_auteur_type' => 'spire_auteur_type',
      'accessibilite' => 0,
      'actualite' => 0,
      'page_interne' => 0,
      'auteur' => 0,
      'image_de_fond' => 0,
      'map' => 0,
      'communique' => 0,
      'contact' => 0,
      'dernieres_publications' => 0,
      'faq' => 0,
      'feed' => 0,
      'logo_adresse' => 0,
      'mentions_legales' => 0,
      'node_from_feed' => 0,
      'pdf' => 0,
      'aide' => 0,
      'partenaires' => 0,
      'profile' => 0,
      'rechercheur' => 0,
      'reseaux_sociaux' => 0,
      'scpo_on_the_web' => 0,
      'scpocarousel' => 0,
      'scpocarousel_content' => 0,
      'outil_numerique' => 0,
      'spire_chercheur_type' => 0,
      'spire_degree_type' => 0,
      'spire_orgunit_type' => 0,
      'spire_publication_type' => 0,
      'spire_relationship_type' => 0,
      'spire_teaching_type' => 0,
      'temp_exp' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'op' => 'Enregistrer les paramètres du champ',
    'module' => 'nodereference',
    'widget_module' => 'nodereference',
    'columns' => 
    array (
      'nid' => 
      array (
        'type' => 'int',
        'unsigned' => true,
        'not null' => false,
        'index' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      5 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  4 => 
  array (
    'label' => 'Rec id',
    'field_name' => 'field_sppu_rec_id',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Modifier les informations de base',
    'weight' => '1',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_sppu_rec_id][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Enregistrer les paramètres du champ',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      2 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      3 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      5 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'body_field' => '-1',
  'revision_information' => '7',
  'author' => '6',
  'options' => '8',
  'language' => '2',
  'translation' => '11',
  'menu' => '3',
  'path' => '10',
  'print' => '9',
  'workflow' => '5',
  'nodewords' => '4',
);
