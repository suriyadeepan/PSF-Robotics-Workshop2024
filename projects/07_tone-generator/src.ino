int potPin = A5;
int SPEAKER = 10;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int potReading = analogRead (potPin);

  // if the reading is zero, turn it off
  if (potReading == 0) {
    noTone (SPEAKER);
  } else {
    // This is a special function that will take one range of values,
    // in this case the analogue input reading between 0 and 1023, and
    // produce an equivalent point in another range of numbers, in this
    // case a range of frequencies to use for the pitch (120 to 1500 Hz).
    int pitch = map(potReading, 0, 1023, 120, 1500);
  
    tone (SPEAKER, pitch);
  }
}