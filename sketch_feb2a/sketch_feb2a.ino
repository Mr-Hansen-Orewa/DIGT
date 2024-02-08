const byte LEDPIN = 12;
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(PAWPIN1, INPUT);
  pinMode(PAWPIN2, INPUT);
  pinMode(PAWPIN3, INPUT);
  pinMode(PAWPIN4, INPUT);
}

void loop() {
  // If paw 1 is pressed then do the following
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  // If paw 2 is pressed then do the following
  if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, LOW);
  }
  // If paw 3 is pressed then do the following
  if (digitalRead(PAWPIN3) == HIGH) {
    playMusic();
  }
  // If paw 4 is pressed then do the following
  if (digitalRead(PAWPIN4) == HIGH) {
    int score = playGame();
  }
}

void playMusic(){
  //play an MP3 file here
}

int playGame(){
  byte score = 99;
  //play simon says game
  return score;
}




