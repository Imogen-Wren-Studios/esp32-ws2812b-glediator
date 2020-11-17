// Libraries required for UDP & Neopixel Functions
//#include <ESP8266WiFi.h>
#include <WiFi.h>

#include <WiFiUdp.h>
#include <FastLED.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define DATA_PIN      5 //Data Pin
#define NUM_LEDS      64  //Number of Pixles

// Libraries required for SD card functions
#include <SPI.h>
#include <SD.h>
#include <FS.h>


// Variables required for SD Card Functions.

#define SD_CS 22

int writeID = 0;

char writePacket[513];  // Buffer to copy and save the frame data as it is recieved.

const int PACKET_SIZE = 512;  // try bigger numbers = better?

#include "sd_functions.h"



CRGB leds[NUM_LEDS];

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


char testString[] = {"This is my Test String"};

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






void setup() {

  Serial.begin(115200);
  WiFi.disconnect(true);
  delay(1000);
  WiFi.onEvent(WiFiEvent);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("x");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  // Serial.println(udp.localPort());
  Serial.println(localPort);

  LEDS.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(255);
  sd_setup();
 // sd_write("Power On");
}






void loop() {

  LEDS.setBrightness(255);

  int cb = udp.parsePacket();
  // Serial.println(cb);
  if (!cb)  {
    Serial.setDebugOutput(true);
  }  else  {
    // We've received a packet, read the data from it
    udp.read(packetBuffer, PACKET_SIZE); // read the packet into the buffer

    // for (int i = 0; i < PACKET_SIZE; i++) {
    //   Serial.println(packetBuffer[i]);
    //  }
  //  writePacket = ((const uint8_t *) &packetBuffer);

   // sd_write(writePacket);

    if (cb >= 6 && packetBuffer[0] == 0x9C)    {
      // header identifier (packet start)
      byte blocktype = packetBuffer[1]; // block type (0xDA)
      // Serial.println(blocktype);
      unsigned int framelength = ((unsigned int)packetBuffer[2] << 8) | (unsigned int)packetBuffer[3]; // frame length (0x0069) = 105 leds
      //    Serial.print("Frame.");
      //    Serial.println(framelength); // chan/block


      byte packagenum = packetBuffer[4];   // packet number 0-255 0x00 = no frame split (0x01)
      byte numpackages = packetBuffer[5];   // total packets 1-255 (0x01)



      if (blocktype == 0xDA) {

        // data frame ...
        //   Serial.println("Data Frame");

        int packetindex;

        if (cb >= framelength + 7 && packetBuffer[6 + framelength] == 0x36) {
          // header end (packet stop)

          //    Serial.println("s:");
          int i = 0;
          packetindex = 6;
          if (packagenum == 1){
            led_index = 0;
          }
          
          while (packetindex < (framelength + 6)){
            
            led.r = ((int)packetBuffer[packetindex]);
            led.g = ((int)packetBuffer[packetindex + 1]);
            led.b = ((int)packetBuffer[packetindex + 2]);
            
            //LEDS.setBrightness(255);
            leds[led_index] = CRGB(led.r, led.g, led.b);
            led_index++;
            //    Serial.println(led_index);

            packetindex += 3;
          }
        }
        // Serial.print(packagenum);
        //  Serial.print("/");
        //  Serial.println(numpackages);

      }

      if ((packagenum == numpackages) && (led_index == NUM_LEDS))      {
        FastLED.show();
        led_index == 0;
      }

    }

  }

}
