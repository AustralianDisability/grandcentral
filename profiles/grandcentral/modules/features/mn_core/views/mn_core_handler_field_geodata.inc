<?php
class mn_core_handler_field_geodata extends views_handler_field {
  function query() { }

  function render($values) {
    if ($this->real_field == 'feature') {
      $result = db_query("SELECT td.name FROM {data_taxonomy} dt INNER JOIN {term_geo} tg ON tg.tid = dt.tid AND dt.data_table_name = '%s' AND dt.id = %d INNER JOIN {taxonomy_term_data} td ON td.tid = tg.tid ORDER BY tg.tid ASC LIMIT 1", 'feeds_data_syndication', $values->{$this->view->base_field});
    }
    else {
      $result = db_query("SELECT tg.%s FROM {data_taxonomy} dt INNER JOIN {term_geo} tg ON tg.tid = dt.tid WHERE dt.data_table_name = :dt.data_table_name AND dt.id = :dt.id ORDER BY tg.tid ASC LIMIT 1", array(':dt.data_table_name' => $this->real_field, ':dt.id' => 'feeds_data_syndication', '' => $values->{$this->view->base_field}));
    }
    return $result->fetchField();
  }
}
