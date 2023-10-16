  // Define pins for individual segments and digit selection
//ORIGINAL PIN CONFIG
int pinA = 13;   // Segment A
int pinB = 12;   // Segment B
int pinC = 11;   // Segment C
int pinD = 10;   // Segment D
int pinE = 9;    // Segment E
int pinF = 8;    // Segment F
int pinG = 7;    // Segment G
int D1 = 6;      // Digit 1 
int D2 = 5;      // Digit 2

int btnPin = 3;
bool buttonPressed = false;
bool lastButtonState = false;

// Variables for controlling the display
int i = 0;        // Counter for the first digit
int k = 0;        // Counter for the second digit
int j = 0;        // General-purpose loop counter
int displayInterval = 1000; // Adjust this value for the display speed

// Arrays to hold the pin configurations and segment patterns
int Arduino_Pins[7] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG};
int Segment_Pins[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0 (Common Anode)
  {1, 0, 0, 1, 1, 1, 1}, // 1 (Common Anode)
  {0, 0, 1, 0, 0, 1, 0}, // 2 (Common Anode)
  {0, 0, 0, 0, 1, 1, 0}, // 3 (Common Anode)
  {1, 0, 0, 1, 1, 0, 0}, // 4 (Common Anode)
  {0, 1, 0, 0, 1, 0, 0}, // 5 (Common Anode)
  {0, 1, 0, 0, 0, 0, 0}, // 6 (Common Anode)
  {0, 0, 0, 1, 1, 1, 1}, // 7 (Common Anode)
  {0, 0, 0, 0, 0, 0, 0}, // 8 (Common Anode)
  {0, 0, 0, 0, 1, 0, 0}  // 9 (Common Anode)
};


void setup() {
  // Configure pins as outputs
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);

  pinMode(btnPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool btn = digitalRead(btnPin);

  if (btn && !lastButtonState) { // Button press detected
    buttonPressed = true;
    lastButtonState = true;
  }

  if (!btn && lastButtonState) { // Button release detected
    lastButtonState = false;
  }

  if (buttonPressed) {
    for (int n = 0; n < 500; n++) {
    
    // Display the digit i on the first digit
    for (j = 0; j < 7; j++) {
      digitalWrite(Arduino_Pins[j], Segment_Pins[i][j]);
    }
    digitalWrite(D1, LOW);  // Select the first digit (common anode: LOW to turn off)
    digitalWrite(D2, HIGH); // Deselect the second digit (common anode: HIGH to turn on)
    delay(1); // Wait for a short time

    // Display the digit k on the second digit
    for (j = 0; j < 7; j++) {
      digitalWrite(Arduino_Pins[j], Segment_Pins[k][j]);
    }
    digitalWrite(D1, HIGH); // Deselect the first digit (common anode: HIGH to turn off)
    digitalWrite(D2, LOW);  // Select the second digit (common anode: LOW to turn on)
    delay(1); // Wait for a short time


  }

   i++; // Move to the next digit for the first display
   if (i == 10) {
     i = 0; // Reset to 0 after reaching 9
     k++;  // Move to the next digit for the second display
     if (k == 10) {
       k = 0; // Reset to 0 after reaching 9
     }
   }
  
  }else {
    // If the button is not pressed, reset the counters and turn off the display
    i = 0;
    k = 0;
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
  }
}
