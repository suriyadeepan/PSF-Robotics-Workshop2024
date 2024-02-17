int RMotor_1 = 2;
int RMotor_2 = 3;
int LMotor_1 = 4;
int LMotor_2 = 5;
int REnable = 10;
int LEnable = 11;
int motor_speed = 60;
const int ldr_thresh = 500;

void setup() {

  Serial.begin(9600);
  Serial.println("GPIO test!");
  pinMode(RMotor_1, OUTPUT);
  pinMode(RMotor_2, OUTPUT);
  pinMode(LMotor_1, OUTPUT);
  pinMode(LMotor_2, OUTPUT);
  pinMode(REnable, OUTPUT);
  pinMode(LEnable, OUTPUT);
  analogWrite(10, motor_speed);
  analogWrite(11, motor_speed);

} 

void loop() {

  int ldrright = analogRead(A1);
  int ldrleft = analogRead(A0);
  Serial.print(ldrleft);
  Serial.print(" ");
  Serial.println(ldrright);
  
  if (ldrright <= ldr_thresh && ldrleft <= ldr_thresh) {
    Serial.println("F");
    move_forward();
  }

  if (ldrright > ldr_thresh && ldrleft <= ldr_thresh) {
    Serial.println("R");
    turn_right();
  }

  if (ldrright <= ldr_thresh && ldrleft > ldr_thresh) {
    Serial.println("L");
    turn_left();
  }

  if (ldrright > ldr_thresh && ldrleft > ldr_thresh) {
    Serial.println("S");
    move_stop();
  }

  delay(1000);

}

void move_forward() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}

//NOT USING BACKWARD

void move_backward() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}

void turn_right() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, HIGH);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}

void turn_left() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
}

void move_stop() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, LOW);
}
