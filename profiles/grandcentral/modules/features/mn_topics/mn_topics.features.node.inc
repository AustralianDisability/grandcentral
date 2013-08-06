<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _mn_topics_node_info() {
  $items = array(
    'topic' => array(
      'name' => t('Topic'),
      'module' => 'features',
      'description' => t('A topic is a list of keyword phrases that should be monitored from a list of known feed sources.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
