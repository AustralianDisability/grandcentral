<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _mn_topics_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-news';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'topic' => 'topic',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
    'views' => array(
      'values' => array(
        'mn_topic_news:page_1' => 'mn_topic_news:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mn_core-print' => array(
          'module' => 'mn_core',
          'delta' => 'print',
          'region' => 'palette',
          'weight' => 0,
        ),
        'views_modes-modes' => array(
          'module' => 'views_modes',
          'delta' => 'modes',
          'region' => 'page_tools',
          'weight' => 0,
        ),
        'mn_core-formats' => array(
          'module' => 'mn_core',
          'delta' => 'formats',
          'region' => 'page_tools',
          'weight' => 1,
        ),
        'views-mn_topics-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_topics-block_1',
          'region' => 'left',
          'weight' => 0,
        ),
      ),
    ),
    'menu' => 'topics',
  );
  $context->condition_mode = 0;

  $translatables['mn-section-news'] = array(
  );

  $export['mn-section-news'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-topics-notrash';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'mn_topic_news:page_1' => 'mn_topic_news:page_1',
      ),
    ),
    'views_modes' => array(
      'values' => array(
        'default' => 'default',
        'views-mode-list' => 'views-mode-list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-mn_topic_news-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_topic_news-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-mn_topic_news-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_topic_news-block_2',
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  $translatables['mn-section-topics-notrash'] = array(
  );

  $export['mn-section-topics-notrash'] = $context;
  return $export;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _mn_topics_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  else if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_feeds_importer_default().
 */
function _mn_topics_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'topics';
  $feeds_importer->config = array(
    'name' => 'Topics',
    'description' => 'Topic importer to create multiple feeds based on pre-defined sources.',
    'fetcher' => array(
      'plugin_key' => 'FeedsNullFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsTopicParser',
      'config' => array(
        'title_pattern' => '',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFeedNodeProcessor',
      'config' => array(
        'content_type' => 'feed',
        'update_existing' => 0,
        'expire' => -1,
        'mappings' => array(
          '0' => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          '1' => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => 'topic',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['topics'] = $feeds_importer;
  return $export;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _mn_topics_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Topics',
    'path' => 'topics',
    'weight' => '-49',
  );
  // Translatables
  (
    t('Topics')
  );


  return $items;
}

/**
 * Helper to implementation of hook_rules_defaults().
 */
function _mn_topics_rules_defaults() {
  return array(
    'rules' => array(
      'mn_topics_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Import feeds when topic is created',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'mn',
          'mn_topics' => 'mn_topics',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'topic' => 'topic',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Content is a topic',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'module' => 'Node',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Import a topic',
              'base' => 'rules_core_action_execute',
              'action_name' => 'feeds_import_topic_action',
              'configurable' => NULL,
            ),
            '#name' => 'rules_core_feeds_import_topic_action',
            '#settings' => array(
              'auto_save' => 1,
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}
