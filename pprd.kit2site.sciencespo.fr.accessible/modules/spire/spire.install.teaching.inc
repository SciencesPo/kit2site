$content['type']  = array (
  'name' => 'Spire Teaching',
  'type' => 'spire_teaching_type',
  'description' => 'Enseignement de chercheur importé de Spire',
  'title_label' => 'Titre',
  'body_label' => 'Description',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => true,
    'promote' => true,
    'sticky' => false,
    'revision' => false,
  ),
  'language_content_type' => '2',
  'upload' => '1',
  'old_type' => 'spire_teaching_type',
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
  'i18n_node' => 1,
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
    'field_spte_univ' => false,
    'field_spte_date' => false,
    'field_spte_level' => false,
  ),
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Etablissement',
    'field_name' => 'field_spte_univ',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Modifier les informations de base',
    'weight' => '-3',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_spte_univ][0][value',
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
    'label' => 'Date début',
    'field_name' => 'field_spte_date',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Modifier les informations de base',
    'weight' => '-2',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_spte_date][0][value',
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
  2 => 
  array (
    'label' => 'Niveau',
    'field_name' => 'field_spte_level',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Modifier les informations de base',
    'weight' => '-1',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_spte_level][0][value',
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
  'body_field' => '-4',
  'revision_information' => '5',
  'author' => '4',
  'options' => '6',
  'language' => '1',
  'translation' => '8',
  'menu' => '0',
  'path' => '10',
  'attachments' => '9',
  'print' => '7',
  'workflow' => '3',
  'nodewords' => '2',
);