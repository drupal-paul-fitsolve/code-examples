<?php

/**
 * Custom override of the summary field behaviour.
 * 
 * Author P.Brady
 * Date 14 Jan 2015
 *
 * - Always show the summary field.
 * - Hide the toggle link for showing and hiding the summary.
 */

/**
 * Implementation of hook_form_FORM_ID_alter.
 *
 * We really need to expose the body summary and also make
 * it required, as the summary is used for meta, share links etc.
 */
function sr16splash_site_news_article_form_news_article_node_form_alter(&$form, &$form_state, $form_id) {

  // Make the body summary required.
  $form['body'][LANGUAGE_NONE][0]['summary']['#required'] = TRUE;

  // Remove the description for the summary as it's a little misleading.
  unset($form['body'][LANGUAGE_NONE][0]['summary']['#description']);

  // Provide our custom CSS to override the core behaviour of the Summary field.
  // It's hidden by default.
  $form['#attached']['css'][] = drupal_get_path('module', 'sr16splash_site_news_article') . '/css/sr16splash.site-news-article.css';

}