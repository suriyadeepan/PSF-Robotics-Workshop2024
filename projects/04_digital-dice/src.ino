#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment object
long randNumber;

void setup() {
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
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
  // print a random number from 0 to 299
  randNumber = random(300);
  Serial.println(randNumber);

  sevseg.refreshDisplay(); // Must run repeatedly
  sevseg.setNumber(randNumber); // Displays '3.141'
  
  delay(1000);
}