#include <Servo.h>
const int trigPin = 9;  
const int echoPin = 10; 


Servo myservo;

 
float duration, distance;  

void setup() {  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600); 
  myservo.attach(6);
  myservo.write(0); 
}  

 
void loop() {  
	digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration*.0343)/2;  
  	Serial.print("Distance: ");  
	Serial.println(distance);  
	delay(100);  

  if(distance < 20){
    myservo.write(90);
  } else{
    myservo.write(0);
  }

}