// Define pin numbers for buttons and LEDs
const byte BUTTON_PIN_1 = 2;
#define BUTTON_PIN_2 3
#define BUTTON_PIN_3 4
#define LED_PIN_1 5
#define LED_PIN_2 6
#define LED_PIN_3 7

// Array to store the order of LEDs
int ledOrder[] = {LED_PIN_1, LED_PIN_2, LED_PIN_3};
int numLEDs = sizeof(ledOrder) / sizeof(ledOrder[0]);
int currentLED = 0;

// Array to store whether each LED has been lit or not
bool ledsLit[] = {false, false, false};

// Variable to store the index of the last button pressed
int lastButtonPressed = -1;


void setup() {
  // Initialize pins
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
 
  // Seed random number generator
  randomSeed(analogRead(0));
 
  // Start the game by lighting a random LED
  lightRandomLED();
}

void loop() {
  // Check for button presses
  if (digitalRead(BUTTON_PIN_1) == LOW && lastButtonPressed != BUTTON_PIN_1) {
    lastButtonPressed = BUTTON_PIN_1;
    if (lastButtonPressed == ledOrder[currentLED]) {
      currentLED++;
      if (currentLED < numLEDs) {
        lightRandomLED();
      } else {
        // Player wins if all LEDs are lit in the correct order
        // You can add your win condition code here
      }
    } else {
      // Player loses if wrong button is pressed
      
    }
  } else if (digitalRead(BUTTON_PIN_2) == LOW && lastButtonPressed != BUTTON_PIN_2) {
    lastButtonPressed = BUTTON_PIN_2;
    if (lastButtonPressed == ledOrder[currentLED]) {
      currentLED++;
      if (currentLED < numLEDs) {
        lightRandomLED();
      } else {
        // Player wins if all LEDs are lit in the correct order
        
      }
    } else {
      // Player loses if wrong button is pressed
      // You can add your lose condition code here
    }
  } else if (digitalRead(BUTTON_PIN_3) == LOW && lastButtonPressed != BUTTON_PIN_3) {
    lastButtonPressed = BUTTON_PIN_3;
    if (lastButtonPressed == ledOrder[currentLED]) {
      currentLED++;
      if (currentLED < numLEDs) {
        lightRandomLED();
      } else {
        // Player wins if all LEDs are lit in the correct order
        // You can add your win condition code here
      }
    } else {
      // Player loses if wrong button is pressed
      // You can add your lose condition code here
    }
  }
}
  // Function to light up a random LED
void lightRandomLED() {
  int randomIndex;
  do {
    randomIndex = random(numLEDs);
  } while (ledsLit[randomIndex]);
 
  digitalWrite(ledOrder[randomIndex], HIGH);
  ledsLit[randomIndex] = true;
}

// Function to check if all LEDs have been lit
bool allLEDsLit() {
  for (int i = 0; i < numLEDs; i++) {
    if (!ledsLit[i]) {
      return false;
    }
  }
  return true;
}