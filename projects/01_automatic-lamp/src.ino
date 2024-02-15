int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 12;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorThreshold = 300;


void setup() {
  // init serial port: baud rate
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  if(sensorValue > sensorThreshold){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  
  Serial.println(sensorValue);
  delay(500);
}
