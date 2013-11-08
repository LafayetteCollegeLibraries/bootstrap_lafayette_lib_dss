<?php

  /**
   * @file
   * Theming for forms
   *
   */

/**
 * griffinj
 * Implements hook_form_alter()
 *
 * Theming for the advanced search form must be implemented using a hook which does not conflict with the actual form implementation within the global context
 *
 */
function bootstrap_dss_islandora_dev_form_alter(&$form, $form_state, $form_id) {

  switch($form_id) {

  case 'islandora_solr_advanced_search_form':

    // Push/append a theming callback on to the array of theming callbacks for the individual form element
    $form['#theme'] = array('bootstrap_dss_islandora_dev_islandora_solr_advanced_search_form');
    break;

  case 'islandora_solr_simple_search_form':

    // Increase the size of the text box
    $form['simple']['islandora_simple_search_query']['#size'] = 21;
    $form['simple']['islandora_simple_search_query']['#value'] = 'Search...';
    $form['simple']['islandora_simple_search_query']['#default_value'] = 'Search...';

    // Insert the glyphicon for searching
    $form['simple']['submit']['#value'] = '<span class="icon-large icon-search"></span>';
    //$form['simple']['submit']['#class'][] = 'icon-search';

    /*
    $form['simple']['#suffix'] = l('Advanced Search', '/', array('attributes' => array('data-toggle' => 'modal'),
								 'class' => array('btn', 'btn-primary', 'btn-lg'),
								 'fragment' => 'advanced-search-modal'));
    */
    $form['simple']['#suffix'] = '<a href="#advanced-search-modal" data-toggle="lafayette-dss-modal">Advanced Search</a>';
    
    break;
  }
}

/**
 * Preprocess variables for 
 *
 * @see islandora-solr-advanced-search-form.tpl.php
 */
function bootstrap_dss_islandora_dev_preprocess_bootstrap_dss_islandora_dev_islandora_solr_advanced_search_form(&$variables) {

  //$form = $variables['form'];

  //foreach($form['terms'] as $key => &$value) {
  foreach($variables['form']['terms'] as $key => &$value) {

    if(is_numeric($key)) {

      $value['add']['#value'] = '<span class="icon-large icon-plus-sign"></span>';
      /*
	$value['add']['#value'] = '<span class="icon-large icon-plus-sign"></span>';
	$value['add']['#ajax']['callback'] = '_bootstrap_dss_islandora_dev_islandora_solr_advanced_search_terms';

	$value['search']['#value'] = '';
	//dpm($value);
	*/
    }
  }

  dpm($variables);
}