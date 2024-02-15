#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object


int sensorValue = 0;  
int sensorPin = A0; 
int count = 0;

void setup() {
  byte numDigits = 3;
  byte digitPins[] = {11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  // sevseg.begin(1,10,11,12,13,2,3,4,5,6,7,8,9);
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, 
  updateWithDelays, leadingZeros, disableDecPoint);
  // sevseg.blank();
  sevseg.setBrightness(30);
  Serial.begin(9600);
  
}

void loop() {
  
  // put your main code here, to run repeatedly:
  if (count % 40000 == 0){
    Serial.println(sensorValue);
  }

  if (count % 5000 == 0){
    sensorValue = int(0.5 * analogRead(sensorPin));
  }
  
  // delay(300);
  sevseg.refreshDisplay(); // Must run repeatedly
  sevseg.setNumber(sensorValue); // Displays '3.141'
  count += 1;

  if (count > 10000000){
    count = 0;
  }
  // sevseg.setChars("abc");
  // sevseg.blank();
  // delay(500);
  
}
