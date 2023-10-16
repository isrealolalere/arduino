/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;
int myLed = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  pinMode(myLed, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned long receivedCode = results.value;
    
    Serial.println(results.value, HEX);
    //perform some actions based on remote ke pressed
    if (receivedCode == 0x11BF50AF) {
      // Execute code for this specific IR code
      Serial.println("IR code 0x11BF50AF received");
      // Add your code here
      digitalWrite(myLed, HIGH);
    } else {
      // Handle unrecognized IR codes, if needed
      Serial.println("Unrecognized IR code received");
      digitalWrite(myLed, LOW);
    }
    
    irrecv.resume(); // Receive the next value
  }
  delay(500);
}
