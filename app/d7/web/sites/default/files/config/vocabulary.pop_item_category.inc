<?php
/**
 * @file
 * vocabulary.pop_item_category.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '3',
  'name' => 'POP Item Category',
  'machine_name' => 'pop_item_category',
  'description' => 'Terms for the POP item product type',
  'hierarchy' => '0',
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
