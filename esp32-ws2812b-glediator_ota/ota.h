
AsyncWebServer server(80);  // Async Webserver on port 80

void handle_client_requests() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });
}



void otaSetup(){
  handle_client_requests();  // Start Elegent OTA
  AsyncElegantOTA.begin(&server);
  //Initialise Server
  server.begin();
}
