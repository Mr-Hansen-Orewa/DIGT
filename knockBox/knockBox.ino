//What does this do?
#include <Servo.h>

//set up all the pins as constants
const byte LEDPIN = 13;
const byte BTNPIN = 1;
const byte MICROPIN = 2;
const byte SERVOPIN = 3;
const byte LOCK = 0;
const byte UNLOCK = 90;
const byte LOUDENOUGH = 512;

//What does this do?
Servo latch;

//setup which pins are input/output
//and attach the servos to their pins
void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BTNPIN, INPUT);
  pinMode(MICROPIN, INPUT);
  latch.attach(SERVOPIN);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BTNPIN) == HIGH) {
    Serial.print("Button pressed, locking box");
    latch.write(LOCK);
  }
  if (analogRead(MICROPIN) > LOUDENOUGH) {
    Serial.print("Heard a knock, unlocking box");
    Serial.print(analogRead(MICROPIN));
    Serial.println(" is the loudness");
    digitalWrite(LEDPIN, HIGH);
    latch.write(UNLOCK);
  }
}