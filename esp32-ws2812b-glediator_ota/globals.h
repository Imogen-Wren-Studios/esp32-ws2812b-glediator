



enum state {
  UDP_MODE = 0,
  PLAYBACK_MODE = 1
};

uint8_t currentMode = PLAYBACK_MODE;



//uint32_t timeout_time = 10000; //if no UDP packet for timeout_time// Demo mode starts
uint32_t timeoutTimer;
uint32_t last_packet_rx;

bool udp_packet_detected;
