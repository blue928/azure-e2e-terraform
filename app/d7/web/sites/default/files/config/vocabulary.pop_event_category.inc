<?php
/**
 * @file
 * vocabulary.pop_event_category.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '4',
  'name' => 'POP Event Category',
  'machine_name' => 'pop_event_category',
  'description' => '',
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
