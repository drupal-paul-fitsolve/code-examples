
1. Setup permissions to access the event map settings & access to the Event Map Bean

2. Login to the main Google Account and setup a Fusion table with the correct columns. The current working version has the following columns: description, name, Coordinates, type, cta, status
The Coordinates column needs to be of the type "Location"

3. Make the Fusion Table publicly accessible and copy paste the fusion table doc id from the URL e.g. 
1tsedCL2KoyDuaN0m7oxrF6UBqzBv9b9s53-KEjs

4. Open a separate window and get the API OAuth settings from the API Console of the google account
For oAuth you will need: Client ID, Client Secret
You will also need the Developer Key/API Key which you can find under "Simple API Access" right beneath your oAuth information
Depending on the environment/domain your on you will need to modify the Redirect URIs to match up with the ones in the settings page.

4. Go to settings page admin/config/services/cr_event_map

5. Make sure the Redirect URIs match up with the ones in your API console and oAuth settings

6. Enter your Google oAuth details and save the page

7. Press on Login to Google. You will be redirected to Google. Login with the same Google account and allow access to fusion tables.

8. On redirect back to the site it will now say you are logged in and can logout if you want. This means the site is authenticated with Google and can upload/manage the fusion tables.

9. Create a KML Source. Enter the Fusion tables ID you have setup, select the SR14 or another parser. (See the kml_parsers.inc file in the modules folder for more info). Specify the originating URL to grab the KML file from.

10. Check the KML source yourself and matches the example source provided in the modules folder called sample_events.kml

11. Press on "Force Update All"

12. If everything is setup correctly you will receive a success message telling you how may events were successfully imported into the fusion table.

13. Check this by going to the Fusion Table itself and see if the records are all there.

14. Now you have setup a source for your Event Map Beans. Ensure you have access to the Bean type and go to /block/add/event-map

15. Enter 
the bean name to identify this bean, 
the title to appear above the map, 
select the source you just created,
update the marker source (The markers will be created using base64 and provided directly to the google maps API to decrease HTTP requests, so no CDN is required here)
Update the map settings to change the height based on breakpoints provided by the Omega theme

16. Save and assign to your panel 

# Troubleshooting and other important points

- If you are getting errors with Google connecting to the API, try logging out and back in again. Otherwise check the variable "cr_event_map_gapi_token". It contains the access token and the refresh token which is required to grab a new valid token. It also helps clearing the cache.
- The markers for SR14 are located in the themes folder and need to be referenced specifically in the bean
- When setting up the Fusion Table, ensure that you setup the table with the correct columns in the correct order. 
- If the map is not showing for anonymous users, check the view event map bean permission
- If something is up with the importing of the files, check in the sites/*/files/cr_event_maps/csv or kml folders to see if the files were downloaded and parsed correctly
- If you need to modify your own source, checkout the kml_parsers.inc. It has a default parser and sr14 parser
- If you need specific JS, I'd recommend just overriding the cr_event_map.js with your own version
- Multiple maps on one page has not been tested as it was not part of the initial requirement. However, it should work. You might just need to ensure that each map creates it's own container ID and referrs to the correct settings
