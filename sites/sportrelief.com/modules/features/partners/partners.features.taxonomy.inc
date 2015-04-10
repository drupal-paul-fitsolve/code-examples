<?php
/**
 * @file
 * partners.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function partners_taxonomy_default_vocabularies() {
  return array(
    'partner_categories' => array(
      'name' => 'Partner Categories',
      'machine_name' => 'partner_categories',
      'description' => 'The different levels of partner involvement',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
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
    ),
  );
}
