<?php

$file = drupal_get_path('module', 'extractor') . '/extractor.feeds.inc';
require_once DRUPAL_ROOT . '/' . $file;

/**
 * Extend common syndication parser and add term extraction.
 */
class ExtractorSyndicationParser extends FeedsSyndicationParser {

  /**
   * Add additional mapping sources.
   */
  public function getMappingSources() {
    return parent::getMappingSources() + extractor_feeds_get_mapping_sources();
  }

  /**
   * If extracted_terms or extracted_tids was selected, extract terms and attach
   * them to item.
   * FeedsParser::getSourceElement(FeedsSource $source, FeedsParserResult $result, $element_key)
   * was:   getSourceElement(FeedsImportBatch $batch, $element_key) {
   */
  public function getSourceElement(FeedsSource $source, FeedsParserResult $result, $element_key) {
    print_r('TODO');
    var_dump($source, $result, $element_key);
    /*if ($result = extractor_feeds_get_source_element($batch->currentItem(), $element_key, $this->config)) {
      return $result;
    }*/
    return parent::getSourceElement($source, $element_key);
  }

  /**
   * Config Form Defaults
   */
  public function configDefaults() {
    return extractor_feeds_defaults();
  }

  /**
   * Config Form
   */
  public function configForm(&$form_state) {
    return extractor_feeds_form($this->config);
  }
}
