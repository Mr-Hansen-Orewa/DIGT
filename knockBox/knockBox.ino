//add the Servo library of functions
#include <Servo.h>

//set up all the pins as constants
const byte LEDPIN = 13;
const byte BTNPIN = 1;
const byte MICROPIN = 2;
const byte SERVOPIN = 3;
//set up servo positions and trigger volume
const byte LOCK = 0;
const byte UNLOCK = 90;
const byte LOUDENOUGH = 512;

//create a servo called latch
Servo latch;

//setup which pins are input/output
//and attach the latch servo to its pin
void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BTNPIN, INPUT);
  pinMode(MICROPIN, INPUT);
  latch.attach(SERVOPIN);

  Serial.begin(9600);
}

//keep checking if the two if statements are true
void loop() {
  //ACHIEVED COMMENT
  //is the microphone value bigger than the trigger volume
  if (analogRead(MICROPIN) > LOUDENOUGH) {
    Serial.print("Heard a knock, unlocking box");
    digitalWrite(LEDPIN, HIGH);
    latch.write(UNLOCK);
  }
  //MERIT COMMENT
  //has the button been pressed
  //move the servo to locked position
  if (digitalRead(BTNPIN) == HIGH) {
    Serial.print("Button pressed, locking box");
    latch.write(LOCK);
  }
}