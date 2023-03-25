




void WiFiEvent(WiFiEvent_t event) {
  switch (event)
  {
    //  case WIFI_EVENT_STAMODE_GOT_IP:
    case SYSTEM_EVENT_STA_CONNECTED:
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      break;
  }
}

int wifi_skip = 0;
int wifi_skip_count = 10;
bool wifi_connected = false;

void wifi_setup() {

  WiFi.disconnect(true);
  delay(1000);
  WiFi.onEvent(WiFiEvent);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)  {
    delay(500);
    Serial.print("x");
    wifi_skip++;
    if (wifi_skip >= wifi_skip_count) {
      break;
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    wifi_connected = true;
  }

  if (wifi_connected) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Starting UDP");
    udp.begin(localPort);
    Serial.print("Local port: ");
    // Serial.println(udp.localPort());
    Serial.println(localPort);
  } else {
    Serial.println("Wifi Failed. Skipping Setup");
  }

}
