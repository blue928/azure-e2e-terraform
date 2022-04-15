<?php
/**
 * @file
 * fp_template_configs.4.inc
 */

$api = '2.0.0';

$data = entity_import('fp_template_configs', '{
    "id" : "4",
    "name" : "UPC Books",
    "status" : "1",
    "module" : null,
    "description" : "Template used for generating pricing\\/no-pricing UPC Book downloads.",
    "file_type" : "pdf",
    "data_format" : "csv",
    "template" : "upc",
    "cfg_file" : null,
    "cache" : "1",
    "created" : "1503015936",
    "changed" : "1503015936",
    "rdf_mapping" : []
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'fp_template_configs',
);
