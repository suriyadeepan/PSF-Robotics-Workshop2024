#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment object

void setup() {
  byte numDigits = 3;
  byte digitPins[] = {11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]


  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, 
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(30);
  
}

void loop() {
  sevseg.refreshDisplay(); // Must run repeatedly
  sevseg.setNumber(314, 2); // Displays '3.141'
  delay(100);
}
