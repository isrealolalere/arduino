int myArray[2][2] = {
  {1, 2}, 
  {3, 4}
};

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Accessing and printing elements
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            Serial.print(myArray[i][j]);
            Serial.print("\t"); // tab for formatting
        }
        Serial.println(); // new line for each row
    }

    delay(1000); // Delay for 1 second
}
