<?php

/**
 * Implements hook_context_default_contexts().
 */
function mn_topics_context_default_contexts() {
  module_load_include('inc', 'mn_topics', 'mn_topics.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_topics_context_default_contexts', $args);
}

/**
 * Implements hook_ctools_plugin_api().
 */
function mn_topics_ctools_plugin_api() {
  module_load_include('inc', 'mn_topics', 'mn_topics.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_topics_ctools_plugin_api', $args);
}

/**
 * Implements hook_feeds_importer_default().
 */
function mn_topics_feeds_importer_default() {
  module_load_include('inc', 'mn_topics', 'mn_topics.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_topics_feeds_importer_default', $args);
}

/**
 * Implements hook_menu_default_items().
 */
function mn_topics_menu_default_items() {
  module_load_include('inc', 'mn_topics', 'mn_topics.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_topics_menu_default_items', $args);
}

/**
 * Implements hook_node_info().
 */
function mn_topics_node_info() {
  // TODO The array elements in this hook function need to be changed.
  module_load_include('inc', 'mn_topics', 'mn_topics.features.node');
  $args = func_get_args();
  return call_user_func_array('_mn_topics_node_info', $args);
}

/**
 * Implements hook_rules_defaults().
 */
function mn_topics_rules_defaults() {
  module_load_include('inc', 'mn_topics', 'mn_topics.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_topics_rules_defaults', $args);
}

/**
 * Implements hook_views_default_views().
 */
function mn_topics_views_default_views() {
  module_load_include('inc', 'mn_topics', 'mn_topics.features.views');
  $args = func_get_args();
  return call_user_func_array('_mn_topics_views_default_views', $args);
}
