// Include the library
#include <TM1637Display.h>

// Define the connections pins
#define CLK 3
#define DIO 4

// Create a display object of type TM1637Display
TM1637Display display = TM1637Display(CLK, DIO);

// Create an array that turns all segments ON
const uint8_t allON[] = {0xff, 0xff, 0xff, 0xff};

// Create an array that turns all segments OFF
const uint8_t allOFF[] = {0x00, 0x00, 0x00, 0x00};

// Create an array that sets individual segments per digit to display the word "dOnE"
const uint8_t done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

// Create degree celsius symbol
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Degree symbol
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

int count = 1000;  // 10 seconds
const int buzzingTime = 3000; // 3 seconds


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	// Set the brightness to 5 (0=dimmest 7=brightest)
	display.setBrightness(5);
  display.showNumberDec(int(count/100), false, 4, 4);
  if (count/100 <= 0){
    count = 1000;  // reset count
    digitalWrite(LED_BUILTIN, HIGH);
    delay(buzzingTime);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  count -= 100;

  // display.showNumberDec(randNum, false, 4, 4);
	// delay(2000);
  delay(300);
	display.clear();
  
}
