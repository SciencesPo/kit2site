<?php

/**
 * Implementation of hook_taxonomy_tree_select_term_element_alter().
 */
function i18ntaxonomy_taxonomy_tree_select_term_element_alter(&$element, $term) {
  if (function_exists('i18ntaxonomy_translate_term_name')) {
    $element['#title'] = i18ntaxonomy_translate_term_name($term);
  }
}
