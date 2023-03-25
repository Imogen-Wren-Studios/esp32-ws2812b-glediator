
uint8_t currentEffect = 0;

//rainbow_demo();
//  trans_flag();
//  pride_flag();
//agender_flag();
// bi_flag();
// aromantic_flag();
// pan_flag();
//  inclusive_flag();


uint32_t demo_delayTime = 10;

uint8_t currentHue = 0;

autoDelay hueDelay;
autoDelay animationDelay;

uint32_t hueShift_timing = 10;  // delay between steps of hue shifts
uint32_t animation_timing = 300;  // delay for steps between animations

int16_t hueShift_step = 1;     // Number of steps to take each time



// Dynamic Effects & forgrounds


void solid_colour(bool randomSpeed = false, uint32_t shiftSpeed = 100 ) {

  leds( XY(0, 0), XY(7, 7) )  = CHSV(currentHue, 255, 255);   // Blue Stripe




  if (randomSpeed) {                                      // if randomtime is true, pick a new time
    hueShift_timing = random(1, 500);
  } else {
    hueShift_timing = shiftSpeed;
  }


  if (hueDelay.millisDelay(hueShift_timing)) {       // If time is up

    currentHue = currentHue + hueShift_step;
  }
}




void solid_black() {
  leds( XY(0, 0), XY(7, 7) )  = CHSV(currentHue, 0, 0);   // Blue Stripe
}


uint8_t forground_hue = 150;

autoDelay forgroundSwitchDelay;    // used for big changes in animation speed and direction every few seconds
autoDelay forgroundHueDelay;       // used for small changes to the hue in the forground using millis timing
autoDelay forgroundAnimation;      // Used to step the animation
autoDelay additionalDelay;       //extra delay for other 

uint32_t forground_switch_timing = 10;  // in seconds
uint32_t animationSpeed = 500;

byte squareX;
byte squareY;
byte squareSequencer = 7;

#define Q squareSequencer // to make code more readable

bool use_pastels = false;
uint8_t saturation = 255;


void generate_squares(bool background = false, bool fastColour = false) {


  if (background) {
    solid_colour(false, 200);               // slow background colour shift
  } else {
    solid_black();
  }

if (additionalDelay.secondsDelay(forground_switch_timing + 3)){
   // currentHue = random(0, 255);                       // jump to a random background colour as well.
   forground_hue = random(0, 255);                  // jump to a random forground colour
}

  // if the timer has run out pick a random colour for the forground;
  if (forgroundSwitchDelay.secondsDelay(forground_switch_timing)) {
    //  animation_timing = random (300, 2000);
    forground_switch_timing = random(3, 13);
  //  forground_hue = random(0, 255);                  // jump to a random colour
    currentHue = random(0, 255);                       // jump to a random background colour as well.
    if (fastColour) {
      hueShift_timing = random(10, 300);                // Looks better with no background
    } else {
      hueShift_timing = random(100, 1000);              // make the forground hue shift on average slower than background shift.
    }
    hueShift_step =  returnRandomShift();
    use_pastels = returnRandomTrue();
    if (use_pastels) {                               // randomised using pastel shades for forground
      saturation = random(0, 255);
    } else {
      saturation = 255;
    }
  }

  if (forgroundHueDelay.millisDelay(hueShift_timing)) {       // shift forground colour around
    forground_hue = forground_hue - hueShift_step;           // used - so it travels in the opposite direction to the background
  }



  if (squareSequencer >= 4) {                                          // // this works with 4 steps but not with 5
    squareSequencer = 0;
    //if (animationDelay.millisDelay(animation_timing)) {                  /// Times the generation of a new square
    // pick a seed location for the square;
    animationSpeed = random(50, 270);
    // animationSpeed = 500;
    squareX = random(3, 5);
    squareY = random(3, 5);
    // squareX = 4;
    //squareY = 4;


  }



  // Controls the expansion animation of the current square

  if (squareSequencer == 0) {
    leds[XY(squareX, squareY)] = CHSV(forground_hue, saturation, 255);   //Lights a single LED

  }

  if (squareSequencer == 1) { // lights the 8 surrounding LEDs (requires 4 lines)

    leds(XY(squareX - 1, squareY + 1), XY(squareX + 1, squareY + 1)) = CHSV(forground_hue, saturation, 255); //
    leds[XY(squareX - 1, squareY)] = CHSV(forground_hue, saturation, 255); //
    leds[XY(squareX + 1, squareY)] = CHSV(forground_hue, saturation, 255); //
    leds(XY(squareX - 1, squareY - 1), XY(squareX + 1, squareY - 1)) = CHSV(forground_hue, saturation, 255); //

  }

  if (squareSequencer >= 2) { // lights the 8 surrounding LEDs (requires 4 lines)


    leds(XYsafe(squareX - Q, squareY + Q), XYsafe(squareX + Q, squareY + Q)) = CHSV(forground_hue, saturation, 255); //

    for (int i = 0; i < 2 * Q; i++) {
        leds[XYsafe(squareX - Q, (squareY + (i - (Q - 1))))] = CHSV(forground_hue, saturation, 255); //       
        leds[XYsafe(squareX + Q, (squareY + (i - (Q - 1))))] = CHSV(forground_hue, saturation, 255); //      
    }
      leds(XYsafe(squareX - Q, squareY - Q), XYsafe(squareX + Q, squareY - Q)) = CHSV(forground_hue, saturation, 255); //
    }


    if (forgroundAnimation.millisDelay(animationSpeed)) {
      squareSequencer++;
    }

  }





  void horizontal_lines(bool randomSpeed = true) {


    if (randomSpeed) {
      hueShift_timing = random(1, 50);         // These values seem a nice balance of random colours
      animation_timing = random(100, 400);
    }

    if (animationDelay.millisDelay(animation_timing)) {
      int currentLine = random(0, 8);
      leds( XY(0, currentLine), XY(7, currentLine) )  = CHSV(currentHue, 255, 255);   // Blue Stripe
    }


    if (hueDelay.millisDelay(hueShift_timing)) {
      currentHue = currentHue + hueShift_step;
    }

  }



  // Static Effects & Backgrounds

  void trans_flag() {
    leds( XY(0, 0), XY(7, 0) )  = CRGB(0, 0, 255);   // Blue Stripe
    leds( XY(0, 1), XY(7, 2) )  = CRGB(255, 70, 150); // Pink Stripe
    leds( XY(0, 3), XY(7, 4) )  = CRGB(255, 255, 255);     // White middle Stripe
    leds( XY(0, 5), XY(7, 6) )  = CRGB(255, 70, 150); // Pink Stripe// Pink Stripe
    leds( XY(0, 7), XY(7, 7) )  = CRGB(0, 0, 255);  // Blue Stripe
  }




  void pride_flag() {
    leds( XY(0, 0), XY(7, 0) )  = CRGB(255, 0, 0 );   // red Stripe
    leds( XY(0, 1), XY(7, 1) )  = CRGB(255, 100, 0); // Orange Stripe
    leds( XY(0, 2), XY(7, 3) )  = CRGB(255, 180, 0);     // Yellow
    leds( XY(0, 4), XY(7, 5) )  = CRGB(0, 255, 00); // Green
    leds( XY(0, 6), XY(7, 6) )  = CRGB(0, 0, 255);  // Blue Stripe
    leds( XY(0, 7), XY(7, 7) )  = CRGB(255, 0, 255);  // Purple
  }



  void agender_flag() {
    leds( XY(0, 0), XY(7, 0) )  = CRGB(0, 0, 0 );   // black
    leds( XY(0, 1), XY(7, 1) )  = CHSV(20, 0, 90); // grey
    leds( XY(0, 2), XY(7, 2) )  = CRGB(255, 255, 255);     // white
    leds( XY(0, 3), XY(7, 4) )  = CRGB(100, 255, 00); // Green
    leds( XY(0, 5), XY(7, 5) )  = CRGB(255, 255, 255);  // White
    leds( XY(0, 6), XY(7, 6) )  = CHSV(20, 0, 90); // grey
    leds( XY(0, 7), XY(7, 7) )  = CRGB(0, 0, 0);  // black
  }


  void bi_flag() {
    leds( XY(0, 0), XY(7, 2) )  = CRGB(255, 30 , 115 );   //Pink
    leds( XY(0, 3), XY(7, 5) )  = CRGB(120, 0, 255);     // Purple
    leds( XY(0, 6), XY(7, 7) )  = CRGB(0, 0, 255);  // Blue
  }

  void aromantic_flag() {
    // Background
    leds( XY(0, 0), XY(7, 1) )  = CHSV(20, 0, 0); // black
    leds( XY(0, 2), XY(7, 3) )  = CHSV(20, 0, 90); // grey
    leds( XY(0, 4), XY(7, 5) )  = CRGB(255, 255, 255);   //white
    leds( XY(0, 6), XY(7, 7) )  = CRGB(150, 0, 255);     // Purple

    // Forground
    leds[ XY(2, 1)]            = CRGB(0, 255, 0);     // green
    leds[ XY(5, 1)]            = CRGB(0, 255, 0);     // green
    leds( XY(1, 2), XY(6, 2) )  = CRGB(150, 255, 0);     //lime green
    leds( XY(2, 3), XY(5, 3) )  = CRGB(255, 255, 255);   //white
    leds( XY(3, 4), XY(4, 4) )  = CHSV(20, 0, 90); // grey
    leds( XY(3, 5), XY(4, 5) )  = CHSV(20, 0, 0); // black
    leds( XY(3, 6), XY(4, 6) )  = CHSV(20, 0, 0); // black

  }


  void pan_flag() {
    // Background
    leds( XY(0, 0), XY(7, 2) )  = CRGB(255, 20, 100); // Pink/Salmon
    leds( XY(0, 3), XY(7, 4) )  = CRGB(255, 180, 0);   //Yellow
    leds( XY(0, 5), XY(7, 7) )  = CRGB(0, 100, 255);     // Blue
  }



  void inclusive_flag() {
    // Stripes
    leds( XY(3, 0), XY(7, 0) )  = CRGB(255, 0, 0 );   // red Stripe
    leds( XY(4, 1), XY(7, 1) )  = CRGB(255, 100, 0); // Orange Stripe
    leds( XY(5, 2), XY(7, 2) )  = CRGB(255, 180, 0);     // Yellow
    leds( XY(6, 3), XY(7, 3) )  = CRGB(255, 180, 0);     // Yellow
    leds( XY(6, 4), XY(7, 4) )  = CRGB(0, 255, 00); // Green
    leds( XY(5, 5), XY(7, 5) )  = CRGB(0, 255, 00); // Green
    leds( XY(4, 6), XY(7, 6) )  = CRGB(0, 0, 255);  // Blue Stripe
    leds( XY(3, 7), XY(7, 7) )  = CRGB(130, 0, 255);  // Purple

    // Triangles
    leds[ XY(0, 0)]             = CRGB(150, 75, 0);   //Brown
    leds[ XY(1, 1)]             = CRGB(150, 75, 0);   //Brown
    leds[ XY(2, 2)]             = CRGB(150, 75, 0);   //Brown
    leds[ XY(3, 3)]             = CRGB(150, 75, 0);   //Brown


    leds[ XY(0, 1)]             = CRGB(0, 120, 255);   //Blue
    leds[ XY(1, 2)]             = CRGB(0, 120, 255);   //Blue
    leds[ XY(2, 3)]             = CRGB(0, 120, 255);   //Blue

    leds[ XY(0, 2)]             = CRGB(255, 50, 130);   //pink
    leds[ XY(1, 3)]             = CRGB(255, 50, 130);   //pink

    leds[ XY(0, 3)]             = CRGB(255, 255, 255);   //white
    leds[ XY(0, 4)]             = CRGB(255, 255, 255);   //white

    leds[ XY(1, 4)]             = CRGB(255, 50, 130);   //pink
    leds[ XY(0, 5)]             = CRGB(255, 50, 130);   //pink

    leds[ XY(2, 4)]             = CRGB(0, 120, 255);   //Blue
    leds[ XY(1, 5)]             = CRGB(0, 120, 255);   //Blue
    leds[ XY(0, 6)]             = CRGB(0, 120, 255);   //Blue


    leds[ XY(3, 4)]             = CRGB(150, 75, 0);   //Brown
    leds[ XY(2, 5)]             = CRGB(150, 75, 0);   //Brown
    leds[ XY(1, 6)]             = CRGB(150, 75, 0);   //Brown
    leds[ XY(0, 7)]             = CRGB(150, 75, 0);   //Brown

  }
