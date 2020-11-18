

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
