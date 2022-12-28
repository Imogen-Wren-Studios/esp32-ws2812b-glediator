# ESP32_glediator_neopixel_controller_modded
 jinx! and glediator stypoe matrix neopixel control software
 
 
 Program runs preset demo on 8x8 WS2812 Matrix untill receives glediator dataframe. Timeout return to demo mode if no data packet recieved in 10 seconds.


I use jinx! to send UDP packets. Basic Setup Instructions:


## Using Glediator with Jinx!

1. Download Jinx! http://www.live-leds.de/

2. Load this sketch into ESP32. (Make sure to enter correct WiFi credentials) ESP and PC running Jinx! must be on same network subnet. (currently set to 192.168.1.x but change to suit your WiFi network) 

3. Make connections between LED matrix and ESP32.
  - #define DATA_PIN      5  

## Jinx! Settings:

1. In `Setup` ensure that `Start Output` is DESELECTED.

Ensure that all sub-menues read as per screenshots

### Matrix Options

![image](https://user-images.githubusercontent.com/53580358/209884346-cc38eadb-e64d-44c4-9541-43450391305d.png)

### Output Devices

- Click Add, then ensure match to:


![image](https://user-images.githubusercontent.com/53580358/209884372-8c52d926-ad0b-456c-8950-46771d2f8bf0.png)

- Click ok to add tmp2.net device.
- Close Output Devices Window

### Output Patch
- Select tmp2.net device from `Patch Device` drop down menu
- Click `Fast Patch` then ensure menu match to:


![image](https://user-images.githubusercontent.com/53580358/209884486-469bb832-5584-499d-9a8e-f44837a09d04.png)

- NOTE: If colours are incorrect (eg green for red) redo this step but change `Pixel Order` eg from RGB to GRB but this may just need to experiment with your specific LED strip

- Click okay then close menu windows.

### Starting Show

- Select `Start Output` the LED matrix will then show the scene currently shown in the `Main Mix` window.

- Additional effects can be setup and queued. Slide the mixer to change source.

![image](https://user-images.githubusercontent.com/53580358/209884713-db4d1246-f990-4691-b45f-54304eaf9c08.png)


### Demo Mode

If no output from PC, or missed data packets, ESP will revert to demo after 10 seconds














