//So we can use the Wire library
#include <Wire.h> 

//need an id to use for the peripheral/slave
const byte POT_ADDR = 1;
const byte LDR_ADDR = 2;
//need an id to use for the peripheral/slave
const byte MESSAGE_SIZE = 1;
const byte YELLOWLED = 10;
const byte REDLED = 13;

/*
  this variable is where we will save the 
  message/reply from the peripheral/slave
  its only an int because we know that is the
  datatype that will be passed
*/
int yellowBlinkSpeed = 0;
int redBlinkSpeed = 0;

void setup(){
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  //initialize Wire library 
  Wire.begin();
  
  Serial.begin(9600);
  Serial.println("request demonstration");
}

void loop(){
  delay(50);
  //-------------- POT peripheral -------------------
  //request a transmission with this id and message size
  Wire.requestFrom(POT_ADDR, MESSAGE_SIZE); 

  /*
    while more bytes of the message are available to
    do the following. This is needed as the
    peripheral/slave may send less than requested
  */
  while (Wire.available()) { 
    //read the transmission and save it to the blinkSpeed variable
    redBlinkSpeed = Wire.read();
    Serial.println(redBlinkSpeed); 
  }
  
  //-------------- LDR peripheral -------------------
  //request a transmission with this id and message size
  Wire.requestFrom(LDR_ADDR, MESSAGE_SIZE); 

  /*
    while more bytes of the message are available to
    do the following. This is needed as the
    peripheral/slave may send less than requested
  */
  while (Wire.available()) { 
    //read the transmission and save it to the blinkSpeed variable
    yellowBlinkSpeed = Wire.read();
    Serial.println(yellowBlinkSpeed); 
  }
  
  //--------------LED blinking -----------------------
  digitalWrite(REDLED, HIGH);
  delay(redBlinkSpeed);
  digitalWrite(REDLED, LOW);
  delay(redBlinkSpeed);
  
  digitalWrite(YELLOWLED, HIGH);
  delay(yellowBlinkSpeed);
  digitalWrite(YELLOWLED, LOW);
  delay(yellowBlinkSpeed);
}