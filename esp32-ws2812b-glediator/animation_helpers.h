/*  // Maths Functions and Utility Scripts for Animations
 * 
 * 
 * 
 */






// Functions to return random numbers for cycling colours and effects
 
// returns either 1 or -1 randomly to change hueshift directions
int16_t returnRandomShift() {
  int x = random(0, 200);

  if (x >= 100) {
    return 1;
  } else {
    return -1;
  }
}


bool returnRandomTrue() {

  if (returnRandomShift() > 0) {
    return true;
  } else {
    return false;
  }

}


// checks whether a returned value + and - another value will be inside our valid range
bool checkif_added(int8_t input, int8_t addition){

  if(input + addition >= NUM_LEDS){
    return false;
  } else {
    return true;
  }  
}

bool checkif_subtracted(int8_t input, int8_t subtraction){

if (input - subtraction < 0){
    return false;
  } else {
    return true;
  }  
 
}
