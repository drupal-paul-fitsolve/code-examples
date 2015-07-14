api = 2
core = 7.x

projects[drupal] = 7.34
projects[drupal][type] = core

defaults[projects][subdir] = "contrib"

projects[admin_menu] = "3.0-rc4"
projects[adminrole] = "1.0"
projects[backup_migrate] = "2.7"
projects[bean] = "1.1"
projects[block_class][version] = "2.x-dev"
projects[block_class][download][type] = "git"
projects[block_class][download][url] = "http://git.drupal.org/project/block_class.git"
projects[block_class][download][revision] = "c2bb84ac5baea1506338a532889da17ab5b5f5ec"
projects[boxes] = "1.1"
projects[cdn] = "2.6"
projects[clientside_validation] = "1.38"
projects[node_clone] = "1.0-rc1"

;Ported from RND15
projects[ckeditor] = "1.16"
projects[colorbox] = "2.4"
projects[colorbox_node] = "3.0"
projects[context] = "3.2"
projects[cors] = "1.1"
projects[css_custom_aggregate] = "1.0-alpha1"
projects[date] = "2.6"
projects[delta] = "3.0-beta11"
projects[diff] = "3.2"
projects[draggableviews] = "2.0"
projects[ds] = "2.2"
projects[elements] = "1.3"
projects[email] = "1.2"
projects[entity] = "1.5"
projects[entityreference] = "1.1"
projects[features_extra] = "1.0-beta1"
projects[features] = "2.0-beta2"
projects[feeds] = "2.0-alpha8"
projects[feeds_oauth] = "1.0-beta2"
projects[feeds_xpathparser] = "1.0-beta4"
projects[field_group] = "1.1"
projects[fieldable_panels_panes] = "1.4"

;Ported from RND15
projects[filefield_paths] = "1.0-beta4"
projects[google_analytics] = "1.3"

;Ported from RND15
projects[google_tag] = "1.0"
projects[http_client] = "2.4"
projects[imagecache_actions] = "1.4"
projects[image_style_quality] = "1.3"
projects[image_url_formatter] = "1.4"
projects[imageapi_optimize] = "1.2"
projects[imagemagick] = "1.0"
projects[imce] = "1.7"
projects[imce_wysiwyg] = "1.0"
projects[job_scheduler] = "2.0-alpha3"
projects[less] = "3.x-dev"
projects[less][download][url] = "http://git.drupal.org/project/less.git"
projects[less][download][revision] = "9138617aba71b42ed522fc5f248c3bbb0981e621"
projects[libraries] = "2.1"
projects[link] = "1.1"
projects[logo_block] = "1.6"
projects[magic] = "1.5"
projects[memcache] = "1.3"
projects[menu_block] = "2.3"
projects[message_broker] = "1.0"
projects[modernizr] = "3.1"
projects[module_filter] = "1.7"
projects[multiupload_filefield_widget] = "1.13"
projects[multiupload_imagefield_widget] = "1.3"
projects[node_save_redirect] = "1.0"
projects[nodequeue] = "2.0-beta1"
projects[oauth] = "3.1"
projects[omega_tools] = "3.0-rc4"
projects[override_node_options] = "1.12"
projects[pathauto] = "1.2"

;Only 1 packaged version
projects[prev_next] = "1.x-dev"
projects[rules] = "2.6"
projects[search_api] = "1.7"
projects[search_api_page] = "1.0-rc1"
projects[search_api_solr_overrides] = "1.0-rc1"
projects[semantic_panels] = "1.2"
projects[serial] = "1.2"
projects[site_map] = "1.0"
projects[site_verify] = "1.0"
projects[strongarm] = "2.0"
projects[styleguide] = "1.1"
projects[timeago] = "2.2"
projects[title] = "1.0-alpha7"
projects[token] = "1.5"
projects[token_filter] = "1.1"
projects[transliteration] = "3.1"
projects[trimmed_plaintext] = "1.0-beta4"
projects[uuid] = "1.0-alpha4"
projects[uuid_features] = "1.0-alpha3"
projects[varnish] = "1.0-beta2"
projects[view_unpublished] = "1.1"
projects[views] = "3.7"

;Ported from RND15
projects[views_data_export] = "3.0-beta8"

;Only 1 packaged version
projects[views_datasource][version] = "1.x-dev"
projects[views_datasource][download][revision] = "6e9b6b980fc2826b09391ae1c2ec0c5a85c6c24a"

projects[views_limit_grouping] = "1.x-dev"
projects[views_load_more] = "1.2"
projects[views_responsive_grid] = "1.3"
projects[views_slideshow] = "3.0"
projects[webform] = "3.18"
projects[webform_validation] = "1.2"
projects[wsclient] = "1.0"
projects[wysiwyg][version] = "2.x-dev"
projects[wysiwyg][download][url] = "http://git.drupal.org/project/wysiwyg.git"
projects[wysiwyg][download][revision] = "d9c3f6559046ff9790d8ba8589653d0646e2baae"
projects[xautoload] = "3.1"
projects[xmlsitemap] = "2.0-rc2"


; Patcheds
projects[better_exposed_filters][subdir] = "patched"
projects[better_exposed_filters][version] = "3.0-beta3"
projects[better_exposed_filters][patch][] = "https://www.drupal.org/files/better_exposed_filters-1268150-59-ajax-select-as-links.patch"
projects[better_exposed_filters][patch][] = "patches/better_exposed_filters_patch.patch"
projects[breakpoints][subdir] = "patched"
projects[breakpoints][version] = "1.3"
projects[breakpoints][patch][] = "https://www.drupal.org/files/issues/performance_issue_with-2378449-1.patch"
projects[ctools][subdir] = "patched"
projects[ctools][version] = "1.4"
projects[ctools][patch][] = "patches/ctools_local_1.patch"
projects[context_addassets][subdir] = "patched"
projects[context_addassets][patch][] = "https://www.drupal.org/files/issues/context_addassets-features-filter_0.patch"
projects[context_addassets][version] = "1.x-dev"
projects[context_addassets][download][type] = "git"
projects[context_addassets][download][url] = "http://git.drupal.org/project/context_addassets.git"
projects[context_addassets][download][revision] = "c07555a0f93ae850381c8a7513badeb1bea5318e"
projects[context_block_disable][subdir] = "patched"
projects[context_block_disable][version] = "1.0"
projects[context_block_disable][patch][] = "patches/context_block_disable_local_1.patch"
projects[drupagram][subdir] = "patched"
projects[drupagram][version] = "1.2"
projects[drupagram][patch][] = "https://www.drupal.org/files/issues/drupagram-show-url-1864664.patch"
projects[epsacrop][subdir] = "patched"
projects[epsacrop][version] = "2.2"
projects[epsacrop][patch][] = "https://www.drupal.org/files/epsacrop-add-dimensions-callback-1473140-1.patch"
projects[eu-cookie-compliance][subdir] = "patched"
projects[eu-cookie-compliance][version] = "1.11"
projects[eu-cookie-compliance][patch][] = "patches/eu_cookie_compliance_local_1.patch"
projects[fast_404][subdir] = "patched"
projects[fast_404][patch][] = "https://www.drupal.org/files/fast_404-with-pdo.patch"
projects[fast_404][version] = "1.x-dev"
projects[fast_404][download][type] = "git"
projects[fast_404][download][url] = "http://git.drupal.org/project/fast_404.git"
projects[fast_404][download][revision] = "e5cb9fd09c874305cc4fc3a0b6b5b3c912440c96"
projects[feeds_jsonpath_parser][subdir] = "patched"
projects[feeds_jsonpath_parser][version] = "1.0-beta2"
projects[feeds_jsonpath_parser][patch][] = "https://www.drupal.org/files/FeedsJSONPathParser-invalidcharacter-1824506-5.patch"
projects[feeds_tamper][subdir] = "patched"
projects[feeds_tamper][patch][] = "patches/feeds_tamper_local_1.patch"
projects[feeds_tamper][version] = "1.x-dev"
projects[feeds_tamper][download][type] = "git"
projects[feeds_tamper][download][url] = "http://git.drupal.org/project/feeds_tamper.git"
projects[feeds_tamper][download][revision] = "747d779a97ca9b4a7878afae00f32f84a322b5ff"
projects[flexslider][subdir] = "patched"
projects[flexslider][version] = "2.0-alpha1"
projects[flexslider][patch][] = "patches/flexslider_local_1.patch"
projects[flexslider_views_slideshow][subdir] = "patched"
projects[flexslider_views_slideshow][patch][] = "patches/flexslider_views_slideshow_local_1.patch"
projects[flexslider_views_slideshow][version] = "2.x-dev"
projects[flexslider_views_slideshow][download][type] = "git"
projects[flexslider_views_slideshow][download][url] = "http://git.drupal.org/project/flexslider_views_slideshow.git"
projects[flexslider_views_slideshow][download][revision] = "0b1f8e7e24c168d1820ccded63c319327d57a97e"
projects[ife][subdir] = "patched"
projects[ife][version] = "2.0-alpha2"
projects[ife][patch][] = "patches/ife_local_1.patch"
projects[insert][subdir] = "patched"
projects[insert][patch][] = "https://www.drupal.org/files/picture-picture--insert-1954546-9.patch"
projects[insert][version] = "1.x-dev"
projects[insert][download][type] = "git"
projects[insert][download][url] = "http://git.drupal.org/project/insert.git"
projects[insert][download][revision] = "0bd93014c157756248537effbf8e3130dddcee2c"
projects[jquery_update][subdir] = "patched"
projects[jquery_update][version] = "2.3"
projects[jquery_update][patch][] = "https://www.drupal.org/files/jquery_update-fix-states-1448490-21.patch"
projects[jquery_update][patch][] = "patches/jquery_update_local_1.patch"
projects[maxlength][subdir] = "patched"
projects[maxlength][version] = "3.0"
projects[maxlength][patch][] = "https://www.drupal.org/files/issues/maxlength-limit_per_field_instance-1341970-20.patch"
projects[mediaelement][subdir] = "patched"
projects[mediaelement][version] = "1.2"
projects[mediaelement][patch][] = "https://www.drupal.org/files/responsive_width-1348816-7.patch"
projects[metatag][subdir] = "patched"
projects[metatag][version] = "1.0-beta7"
projects[metatag][patch][] = "https://www.drupal.org/files/metatag-notice-1970064-13.patch"
projects[minify][subdir] = "patched"
projects[minify][version] = "1.3"
projects[minify][patch][] = "https://www.drupal.org/files/issues/minify-2410871-config-directory.patch"
projects[node_embed][subdir] = "patched"
projects[node_embed][version] = "1.1"
projects[node_embed][patch][] = "patches/node_embed_local_1.patch"
projects[placeholder][subdir] = "patched"
projects[placeholder][version] = "1.0"
projects[placeholder][patch][] = "patches/placeholder_local_1.patch"
projects[redirect][subdir] = "patched"
projects[redirect][version] = "1.0-rc1"
projects[redirect][patch][] = "https://www.drupal.org/files/redirect-fix_for_admin_setting-1904332.patch"
projects[search_api_multi][subdir] = "patched"
projects[search_api_multi][version] = "1.0"
projects[search_api_multi][patch][] = "https://www.drupal.org/files/issues/search_api_multi-undefined-index-relevance-2138225-1.patch"
projects[search_api_solr][subdir] = "patched"
projects[search_api_solr][version] = "1.5"
projects[search_api_solr][patch][] = "patches/search_api_solr_local_1.patch"
projects[views_dependent_filters][subdir] = "patched"
projects[views_dependent_filters][version] = "1.1"
projects[views_dependent_filters][patch][] = "https://www.drupal.org/files/1441352.views_dependent_filters.exposed-filters-block.patch"
projects[views_fluidgrid][subdir] = "patched"
projects[views_fluidgrid][version] = "1.x-dev"
projects[views_fluidgrid][patch][] = "patches/views_fluid_grid_local_1.patch"

; Themes

; Libraries
; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[SportRelief2014_AvM_HTML5_SR][download][type] = ""
libraries[SportRelief2014_AvM_HTML5_SR][download][url] = ""
libraries[SportRelief2014_AvM_HTML5_SR][directory_name] = "SportRelief2014_AvM_HTML5_SR"

libraries[timeago][download][type] = "file"
libraries[timeago][download][url] = "https://raw.githubusercontent.com/rmm5t/jquery-timeago/v1.3.1/jquery.timeago.js"
libraries[timeago][directory_name] = "timeago"

libraries[colorbox][download][type] = "file"
libraries[colorbox][download][url] = "https://github.com/jackmoore/colorbox/archive/1.4.27.zip"
libraries[colorbox][directory_name] = "colorbox"

libraries[mediaelement][download][type] = "file"
libraries[mediaelement][download][url] = "https://github.com/johndyer/mediaelement/archive/2.12.0.zip"
libraries[mediaelement][directory_name] = "mediaelement"

; The following library in our code has been stripped down to just the 2 jquery files
; (main and minified) and the stylesheets folder in /demo has been moved into
; the root.  We will need to determine the best way to deal with this when we test
libraries[tabslet][download][type] = "file"
libraries[tabslet][download][url] = "https://github.com/vdw/Tabslet/archive/v1.4.2.zip"
libraries[tabslet][directory_name] = "tabslet"

libraries[history][download][type] = "file"
libraries[history][download][url] = "https://github.com/balupton/jquery-history/archive/v1.5.0-final.zip"
libraries[history][directory_name] = "history"

libraries[php-proauth][download][type] = "git"
libraries[php-proauth][download][url] = "https://github.com/RobLoach/php-proauth.git"
; There are no tags, only a master branch with 2 commits, following commit is latest on master
libraries[php-proauth][download][revision] = "9880ba6db124d0d786181aff30262816637c7633"
libraries[php-proauth][directory_name] = "php-proauth"

; There is no version number referenced in the code we have, but v1.5.8 seems to match
; what we have in as this was the last version that supported gears and browserplus
; which I can see support for in our version.  However there are mismatches in which
; folders and files are present, the main js files however match up.
libraries[plupload][download][type] = "file"
libraries[plupload][download][url] = "https://github.com/moxiecode/plupload/archive/v1.5.8.zip"
libraries[plupload][directory_name] = "plupload"

; Specified the v2 tag as our version referenced v2 in various files.  However there are
; a few diffs in socialite.js file and README file.
libraries[socialitejs][download][type] = "file"
libraries[socialitejs][download][url] = "https://github.com/tmort/Socialite/archive/v2.0.zip"
libraries[socialitejs][directory_name] = "socialitejs"

libraries[lessphp][download][type] = "file"
libraries[lessphp][download][url] = "https://github.com/leafo/lessphp/archive/v0.3.9.zip"
libraries[lessphp][directory_name] = "lessphp"

; Matching version is not tagged so pinned to latest commit on master branch
libraries[posterfill][download][type] = "git"
libraries[posterfill][download][url] = "https://github.com/lewisnyman/posterfill.git"
libraries[posterfill][download][revision] = "8324159451972e704ea289ca258d4ac20998f554"
libraries[posterfill][directory_name] = "posterfill"

; Matching version not tagged, pinned to a the appropriate commit on master branch
libraries[json2][download][type] = "git"
libraries[json2][download][url] = "https://github.com/douglascrockford/JSON-js.git"
libraries[json2][download][revision] = "ff55d8d4513b149e2511aee01c3a61d372837d1f"
libraries[json2][directory_name] = "json2"

libraries[phpamqp][download][type] = "file"
libraries[phpamqp][download][url] = "https://github.com/videlalvaro/php-amqplib/archive/v2.1.0.zip"
libraries[phpamqp][directory_name] = "phpamqp"

libraries[flexslider][download][type] = "file"
libraries[flexslider][download][url] = "https://github.com/woothemes/FlexSlider/archive/version/2.1.zip"
libraries[flexslider][directory_name] = "flexslider"

; zipped library from github omitted the build folder so git cloning instead
; to get that folder
libraries[Jcrop][download][type] = "git"
libraries[Jcrop][download][url] = "https://github.com/tapmodo/Jcrop.git"
libraries[Jcrop][download][revision] = "v0.9.12"
libraries[Jcrop][directory_name] = "Jcrop"

; version 2.0.7 + a couple of bug fix commits
libraries[placeholder][download][type] = "git"
libraries[placeholder][download][url] = "https://github.com/mathiasbynens/jquery-placeholder.git"
libraries[placeholder][download][revision] = "40c2091e649426dfad6d120b0b7b301c4bbe7f2e"
libraries[placeholder][directory_name] = "placeholder"

; @todo Our existing version of this library consists of a single file
; jquery.cycle.all.min.js (which in fact is not minified)
; whereas the version of the library on github has jquery.cycle.all.js
; Therefore we will need to update calling code for this library to be used
libraries[jquery.cycle][download][type] = "file"
libraries[jquery.cycle][download][url] = "https://github.com/malsup/cycle/archive/3.0.3.zip"
libraries[jquery.cycle][directory_name] = "jquery.cycle"

; Our existing code indicated version 4.0, current version is 4.4.7. After discussion with Girish
; we are going to bring down the 4.4.7 version as the builder page at http://ckeditor.com/builder
; only creates builds from the latest version, and we ought to be upgrading anyway.
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://ckeditor.com/online-builder/releases/minified/4.4.7/moono/4.4.7/ckeditor_4.4.7_9e2f4050d27c.zip"
libraries[ckeditor][directory_name] = "ckeditor"
