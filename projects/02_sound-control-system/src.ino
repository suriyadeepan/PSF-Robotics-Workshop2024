/*
Read the analog input of a microphone
*/

int micIN= A0;
int  audioVal = 0;
int threshold = 300;
int ledPin = 12;

void setup() {
  Serial.begin(9600);

}

void  loop() {
 audioVal = analogRead(micIN);
 Serial.println(audioVal);

 if(audioVal > threshold){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
 delay(600);
}