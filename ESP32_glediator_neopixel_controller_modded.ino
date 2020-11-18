// Libraries required for UDP & Neopixel Functions
//#include <ESP8266WiFi.h>
#include <WiFi.h>

#include <WiFiUdp.h>
#include <FastLED.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define DATA_PIN      5 //Data Pin

// LED Variables

//#define NUM_LEDS      64  //Number of Pixles

// Params for width and height
const uint8_t kMatrixWidth = 8;
const uint8_t kMatrixHeight = 8;

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
//CRGB leds_plus_safety_pixel[ NUM_LEDS + 1];
//CRGB* const leds( leds_plus_safety_pixel + 1);
CRGBArray < NUM_LEDS + 1 > leds;
//CRGB* const leds( ledArray + 1);


#define BRIGHTNESS 100    // brightness for demo fx when no UDP data is present
//CRGB leds[NUM_LEDS];


// SD Card
// Libraries required for SD card functions
#include <SPI.h>
#include <SD.h>
#include <FS.h>


// Variables required for SD Card Functions.

#define SD_CS 22

int writeID = 0;


const int PACKET_SIZE = 512;  // try bigger numbers = better?

char writePacket[PACKET_SIZE];  // Buffer to copy and save the frame data as it is recieved.

#include "sd_functions.h"


// Wifi & UDP Variables

const char* ssid     = "EE-Hub-G3ge";  //Wifi Name  - SSID
const char* password = "stock-led-HALF"; //Router Password - PASSWORD

IPAddress ip(192, 168, 1, 222);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

unsigned int localPort = 65506;      // local port to listen for UDP packets
//const int PACKET_SIZE = 512;
//const int PACKET_SIZE = 1024;


byte packetBuffer[PACKET_SIZE]; //buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;

typedef struct
{
  byte r;
  byte g;
  byte b;
} colorpin;

colorpin led;
int led_index = 0;

bool update_LEDS;



//includes for other pages

#include "globals.h"
#include "wifi_functions.h"
#include "udp_functions.h"
#include "fastLED_functions.h"
#include "animations.h"
#define COLOUR_ORDER GRB

void setup() {

  Serial.begin(115200);

  wifi_setup();





  LEDS.addLeds<WS2812, DATA_PIN, COLOUR_ORDER>(leds, NUM_LEDS);
  LEDS.setBrightness(255);



  // sd_setup();
  // sd_write("Power On");
}


#define UDP_TIMEOUT 10000


void loop() {




  if (millis() - last_packet_rx >= UDP_TIMEOUT) {
    currentMode = PLAYBACK_MODE;
  }



  int cb = detect_udp_packet();

  if (currentMode == PLAYBACK_MODE) {
    LEDS.setBrightness(BRIGHTNESS);
    //rainbow_demo();
    //  trans_flag();
    //  pride_flag();
    //agender_flag();
    // bi_flag();
   // aromantic_flag();
  // pan_flag();
  inclusive_flag();
    FastLED.show();
  } else {
    jinx_data_mode(cb);
  }

}
