
struct udp_structure{
  byte udpPacket[PACKET_SIZE]; //buffer to hold incoming and outgoing packets
};
//

struct savedData;  // variable to store the data to save
// Can be accessed as saveData.updPacket[y];

//sizeof(var)
/*
void sd_write_data(udp_structure inputStruct){

   configFile = SD.open("/data.txt", FILE_WRITE);                     // open the file. note that only one file can be open at a tim
//fs.open(path, FILE_APPEND);


  if (configFile) {                                        // if configFile is avaliable
    /*
      All the magic happens when you tell it to just write a bunch of bytes instead of text:
  

    
    int sizeofStruct = sizeof(inputStruct);

    

}

*/





void writeFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();
}


void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if (file.print(message)) {
    Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();
}



void sd_setup() {


  SD.begin(SD_CS);

  if (!SD.begin(SD_CS)) {
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if (cardType == CARD_MMC) {
    Serial.println("MMC");
  } else if (cardType == CARD_SD) {
    Serial.println("SDSC");
  } else if (cardType == CARD_SDHC) {
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }


  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);

  if (SD.exists("config.txt")) {

    File file = SD.open("/data.txt");
    Serial.println("File already exists");
  } else {
    writeFile(SD, "/data.txt", "Jinx! Data\r\n");
  }
 // file.close();
}


//void sd_write_byteArray(byte input[512];

void sd_write(char writeData[513]) {
  char id[8];
  sprintf(id, "%i: \r\n", writeID);
  appendFile(SD, "/data.txt", id);
  appendFile(SD, "/data.txt", writeData);
  writeID++;
}


void listFree_space() {

  Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
  Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));

}
