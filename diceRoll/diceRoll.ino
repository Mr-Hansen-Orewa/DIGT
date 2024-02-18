//set up all the pins as constants
const byte BTNPIN = 1;
const byte POTPIN = A1;

//setup which pins are input/output
void setup() {
  pinMode(BTNPIN, INPUT);
  pinMode(POTPIN, INPUT);

  Serial.begin(9600);
}

//keep checking if the roll dice button is pressed
void loop() {
  //MERIT COMMENT
  //if the button has been pressed
  //read the potentiometer to check what dice type
  //then call the rollDice method with that sort of dice
  if (digitalRead(BTNPIN) == HIGH) {
    Serial.println("Rolling dice");
    //gives a value 0 - 1023
    int diceType = analogRead(POTPIN);
    //use map(value, fromLow, fromHigh, toLow, toHigh) to change value
    //1=4sided, 2=6sided, 3=8sided, 4=10sided, 5=12sided, 6=20sided
    diceType = map(diceType, 0, 1023, 1, 6);
    //pass the new value to rollDice method
    rollDice(diceType);
  }
}

//takes a value from 1 to 6 as the type of dice
//uses random to choose a value and prints it to screen
void rollDice(byte numSides) {
  //create a variable with default value
  byte diceRoll = 255;

  //check which sided dice is needed
  //make a random choice and then print the value
  switch (numSides) {
    case 1:
      Serial.print("A 4 sided dice rolls: ");
      diceRoll = random(1, 4);
      break;
    case 2:
      Serial.print("A 6 sided dice rolls: ");
      diceRoll = random(1, 6);
      break;
    case 3:
      Serial.print("An 8 sided dice rolls: ");
      diceRoll = random(1, 8);
      break;
    case 4:
      Serial.print("A 10 sided dice rolls: ");
      diceRoll = random(1, 10);
      break;
    case 5:
      Serial.print("A 12 sided dice rolls: ");
      diceRoll = random(1, 12);
      break;
    case 6:
      Serial.print("A 20 sided dice rolls: ");
      diceRoll = random(1, 20);
      break;
    default:
      Serial.println("Issue with mapping potentiometer values");
      break;
  }
  Serial.println(diceRoll);
}