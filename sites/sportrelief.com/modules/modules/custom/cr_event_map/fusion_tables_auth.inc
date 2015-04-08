<?php

/**
 * Include the library files for the api client and AdSense service class.
 */
require_once __DIR__.'/google-api-php-client/src/Google_Client.php';
require_once __DIR__.'/google-api-php-client/src/contrib/Google_FusiontablesService.php';

/**
 * Handles authentication and OAuth token storing.
 * Assumes the presence of a sqlite database called './examples.sqlite'
 * containing a table called 'auth' composed of two VARCHAR(255) fields called
 * 'user' and 'token'.
 *
 * @author Silvano Luciani <silvano.luciani@gmail.com>
 */

class FusionTablesAuth {
  protected $apiClient;
  protected $fusionTablesUploadService;
  protected $fusionTablesService;

  /**
   * Create the dependencies.
   * (Inject them in a real world app!!)
   */
  public function __construct() {
    global $base_url;
    // Create the apiClient instances.
    $this->apiClient = new Google_Client();

    $gapi_settings = variable_get('cr_event_map_gapi_settings');

    if(empty($gapi_settings)) {
      drupal_set_message(t('Please set your Google API details.'));
    } else {
      $gapi_settings = unserialize($gapi_settings);
      $this->apiClient->setApplicationName('CR Events Map');
      $this->apiClient->setClientId($gapi_settings['clientid']);
      $this->apiClient->setClientSecret($gapi_settings['clientsecret']);
      $this->apiClient->setRedirectUri($base_url .'/admin/config/services/cr_event_map/gapi/auth');
      // Be careful setting the developer key. If set, google client will use this to authenticate meaning that authorised calls with the fusion tables service won't work anymore!
      //$this->apiClient->setDeveloperKey($gapi_settings['apikey']); 
    }
    $this->fusionTablesUploadService = new Google_FusiontablesUploadService($this->apiClient);
    $this->fusionTablesService = new Google_FusiontablesService($this->apiClient);    
  }

  /**
   * Check if a token for the user is already in the db, otherwise perform
   * authentication.
   * @param string $user The user to authenticate
   */
  public function authenticate() {
    $token = $this->getToken();
    if ($token) {
      // I already have the token.
      $this->apiClient->setAccessToken($token);
    } else {
      // Go get the token
      $this->apiClient->setAccessToken($this->apiClient->authenticate());
      $this->saveToken($this->apiClient->getAccessToken());
    }
  }

  /*
   * Checks if the user is authenticated
   */
  public function hasToken() {
    $token = $this->getToken();
    if($token) {
      return true;
    }
    return false;
  }

  /**
   * Return the fusionTablesUploadService instance (to be used to retrieve data).
   * @return fusionTablesUploadService the authenticated fusionTablesUploadService instance
   */
  public function getFusionTablesUploadService() {
    return $this->fusionTablesUploadService;
  }

  /**
   * Return the fusionTablesService instance (to be used to retrieve data).
   * @return fusionTablesService the authenticated fusionTablesService instance
   */
  public function getFusionTablesService() {
    return $this->fusionTablesService;
  }

  /**
   * During the request, the access code might have been changed for another.
   * This function updates the token in the db.
   */
  public function resaveToken() {
    if ($this->apiClient->getAccessToken() != null) {
      $this->saveToken($this->apiClient->getAccessToken());
    }
  }


  /**
   * We may wish to completely delete the old token and logout of the google api
   */
  public function logout() {
    variable_del('cr_event_map_gapi_token');
  }

  /**
   * During the request, the access code might have been changed for another.
   * This function updates the token in the db.
   */
  public function refreshToken() {
    $token = $this->getToken();
    if($token) {
      $tokenObj = json_decode($token);

      if($this->tokenExpired()) {
        $this->apiClient->refreshToken($tokenObj->refresh_token);
        $this->saveToken($this->apiClient->getAccessToken());
      }
    }
  }

  /*
   * 
   */
  public function createAuthUrl() {
    return $this->apiClient->createAuthUrl();
  }

  /*
   * Check Expiry
   */
  private function tokenExpired() {
    $token = $this->getToken();
    $tokenObj = json_decode($token);
    if( ($tokenObj->created + $tokenObj->expires_in) < time() ) {
      return true;
    } else {
      return false;
    }
  }

  /**
   * Insert/update the auth token for the user.
   * @param PDO $dbh a PDO object for the local authentication db
   * @param bool $userExists true if the user already exists in the db
   * @param string $token the auth token to be saved
   */
  private function saveToken($token) {
    return variable_set('cr_event_map_gapi_token', $token);
  }

  /**
   * Retrieves token for use.
   * @param PDO $dbh a PDO object for the local authentication db
   * @return string a JSON object representing the token
   */
  private function getToken() {
    $token = variable_get('cr_event_map_gapi_token', false);
    return $token;
  }

}