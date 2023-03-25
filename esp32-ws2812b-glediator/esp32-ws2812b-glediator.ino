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

const char* ssid     = "XXXXXX";  //Wifi Name  - SSID
const char* password = "XXXXXXXX"; //Router Password - PASSWORD

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

#include <autoDelay.h>

autoDelay demoDelay;

//includes for other pages

#include "globals.h"
#include "wifi_functions.h"
#include "udp_functions.h"
#include "fastLED_functions.h"
#include "animation_helpers.h"
#include "animations.h"
#define COLOUR_ORDER GRB

void setup() {

  Serial.begin(115200);

  randomSeed(analogRead(0));   // psudo random number generator for randomness & chaos

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
  //  generate_squares(false, true);       // (background colour, fast Colour shift)
    runDemo();
    FastLED.show();
  } else {
    jinx_data_mode(cb);
  }

}




#define NUM_EFFECTS 12


void randomEffects(){
// 
// choose a random background effect


// chose a random forground effect.


  
}


void runDemo() {

  if (currentEffect == 0) {
     demo_delayTime = 60;
    rainbow_demo();
   
  } else if (currentEffect == 1) {
    demo_delayTime = 10;
    trans_flag();
    
  } else if (currentEffect == 2) {
    bi_flag();
    
  } else if (currentEffect == 3) {
    demo_delayTime = 60;
    solid_colour(true);
    
  } else if (currentEffect == 4) {
    demo_delayTime = 10;
    pride_flag();
    
  } else if (currentEffect == 5) {
    demo_delayTime = 60;
    horizontal_lines();
    
  } else if (currentEffect == 6) {
    demo_delayTime = 10;
    pan_flag();
    
  } else if (currentEffect == 7) {
    inclusive_flag();
    
  } else if (currentEffect == 8) {
    demo_delayTime = 60;
    generate_squares(false, true);       // (background colour, fast Colour shift)
    
  } else if (currentEffect == 9) {
    demo_delayTime = 10;
    agender_flag();
    
  } else if (currentEffect == 10) {
    demo_delayTime = 60;    
    generate_squares(true, false);       // (background colour, fast Colour shift)
    
  } else if (currentEffect == 11) {
    demo_delayTime = 10;
    aromantic_flag();
    
  }

  if (demoDelay.secondsDelay(demo_delayTime)) {
    currentEffect++;
  }

  if (currentEffect >= NUM_EFFECTS) {
    currentEffect = 0;
  }


}
