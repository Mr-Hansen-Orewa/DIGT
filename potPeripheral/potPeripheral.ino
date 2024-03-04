//So we can use the Wire library
#include <Wire.h> 

//need an id to use for the peripheral/slave
const byte HELPER_ADDR = 1;
const byte POT = A0;

int potVal = 0;

void setup(){
  pinMode(POT, INPUT);
  
  //initialize Wire library with this id
  Wire.begin(HELPER_ADDR);
  //when you hear a request run this method
  Wire.onRequest(requestEvent);
  
  Serial.begin(9600);
  Serial.println("request POT demonstration");  
}
 
void loop(){
  delay(50);
  potVal = map(analogRead(POT), 0, 1023, 255, 1);
  // Serial.println(potVal);
}

/*
  run this method when the controller/master sends a transmission
*/
void requestEvent(){
  //reply to the transmission request with this message
  Wire.write(potVal);
  Serial.println(potVal);
}