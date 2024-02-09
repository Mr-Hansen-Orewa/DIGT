//What does this do?
#include <Servo.h>

//set up all the pins as constants
const byte LEDPIN = 12;
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;
const byte LEFTEARPIN = 9;
const byte RIGHTEARPIN = 10;

//What does this do?
Servo leftEar;
Servo rightEar;

//setup which pins are input/output
//and attach the servos to their pins
void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(PAWPIN1, INPUT);
  pinMode(PAWPIN2, INPUT);
  pinMode(PAWPIN3, INPUT);
  pinMode(PAWPIN4, INPUT);
  leftEar.attach(LEFTEARPIN);
  rightEar.attach(RIGHTEARPIN);
}

void loop() {
  // If paw 1 is pressed then turn on led
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  // If paw 2 is pressed then turn off led
  if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, LOW);
  }
  // If paw 3 is pressed then call wagEars method
  if (digitalRead(PAWPIN3) == HIGH) {
    wagEars();
  }
  // If paw 4 is pressed then call blinkingLed method
  if (digitalRead(PAWPIN4) == HIGH) {
    blinkingLed();
  }
}

//move both ears to 0, then 90, then back to 0
void wagEars() {
  leftEar.write(0);
  rightEar.write(0);
  leftEar.write(90);
  rightEar.write(90);
  leftEar.write(0);
  rightEar.write(0);
}

//blink the led between 1 and 3 times
void blinkingLed() {
  //What does this do?
  byte randNumber = random(1, 3);

  //What does this do?
  for (int i = 0; i < randNumber; i++) {
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500);
  }
}