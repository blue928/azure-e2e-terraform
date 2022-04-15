<?php
/**
 * @file
 * vocabulary.product_category.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '2',
  'name' => 'Product Category',
  'machine_name' => 'product_category',
  'description' => '',
  'hierarchy' => '1',
  'module' => 'taxonomy',
  'weight' => '0',
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'skos:ConceptScheme',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'description' => array(
      'predicates' => array(
        0 => 'rdfs:comment',
      ),
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'taxonomy',
);
