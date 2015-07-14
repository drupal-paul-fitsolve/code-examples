Author: Orizu Nwokeji

RND15 Search README.txt
=======================
http://confluence.comicrelief.com/display/rnd15Documentation/Search+Implementation

The idea behind this search module for search functionality using Search API with Apache Solr as its back end.

Results are returned via a Search API view.

** Rationale **

Each campaign the content types listed by search have been re-implemented
in order to take advantage of new theming practices.

This feature configures the search feature with those content types.

** Modifications to the search feature **

Additional indexes may be added using hook_default_search_api_index_alter().
Additional views displays can be added using hook_default_views_alter().