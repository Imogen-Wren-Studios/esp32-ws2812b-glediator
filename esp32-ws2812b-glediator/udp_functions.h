
// Always runs through loop to detect any incoming UDP packetsa


int detect_udp_packet() {
  int cb = udp.parsePacket();
  // Serial.println(cb);
  if (!cb)  {
    Serial.setDebugOutput(true);
   
  }  else  {
    // We've received a packet, read the data from it
    udp.read(packetBuffer, PACKET_SIZE); // read the packet into the buffer

    last_packet_rx = millis();
    udp_packet_detected = true;
    currentMode = UDP_MODE;
    return cb;
  }
   return 0;
}



void jinx_data_mode(int cb) {

  if (udp_packet_detected) {

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
          if (packagenum == 1) {
            led_index = 0;
          }

          while (packetindex < (framelength + 6)) {

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
    udp_packet_detected = false;
  }

}
