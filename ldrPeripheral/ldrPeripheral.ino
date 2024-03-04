//So we can use the Wire library
#include <Wire.h> 

//need an id to use for the peripheral/slave
const byte HELPER_ADDR = 2;
const byte LDR = A1;

int ldrVal = 0;

void setup(){
  pinMode(LDR, INPUT);
  
  //initialize Wire library with this id
  Wire.begin(HELPER_ADDR);
  //when you hear a request run this method
  Wire.onRequest(requestEvent);
  
  Serial.begin(9600);
  Serial.println("request LDR demonstration");  
}
 
void loop(){
  delay(50);
  ldrVal = map(analogRead(LDR), 0, 1023, 255, 1);
  // Serial.println(ldrVal); //could use this to tune the resistor size
}

/*
  run this method when the controller/master sends a transmission
*/
void requestEvent(){
  //reply to the transmission request with this message
  Wire.write(ldrVal);
  Serial.println(ldrVal);
}