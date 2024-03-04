#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"

const String FILENAME = "jokeFile.txt";
OpenLog sdCard;  //Create an instance of the openlog board

void setup() {
  Wire.begin();
  sdCard.begin();
  sdCard.create(FILENAME);
  sdCard.append(FILENAME); //should mean all further sdCard print statements go to this file 
  sdCard.println("Knock knock");
  sdCard.syncFile(); //make sure anything in the buffer is synced to the sdCard before moving on
  Serial.begin(9600);
  Serial.println("sdCard should have a file containing the text, knock knock");

  //I would suggest you look at the check status example to make this 'excellent' code
}

void loop() {
  sdCard.println("Knock knock");
  Serial.println("Knock knock");

  sdCard.println("Who's there?");
  Serial.println("Who's there?");

  sdCard.println("Wooden shoe.");
  Serial.println("Wooden shoe.");

  sdCard.println("Wooden shoe who?");
  Serial.println("Wooden shoe who?");

  sdCard.println("Wooden shoe you like to hear another joke?");
  Serial.println("Wooden shoe you like to hear another joke?");
  sdCard.syncFile();
}
