<?php
/**
 * @file
 * rnd15_site_vocabularies.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function rnd15_site_vocabularies_taxonomy_default_vocabularies() {
  return array(
    'media_category' => array(
      'name' => 'Media category',
      'machine_name' => 'media_category',
      'description' => 'Media categories.',
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
