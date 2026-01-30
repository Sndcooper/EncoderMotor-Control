
#include <Arduino.h>

#define enc 2
volatile long count = 0;

unsigned long lastPulseTime = 0;

void pulse() {
  if (millis() - lastPulseTime > 5) {
    count++;
    lastPulseTime = millis();
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(enc, INPUT_PULLUP); // Use INPUT_PULLUP. See note below.
  attachInterrupt(digitalPinToInterrupt(enc), pulse, RISING); 
}

void loop() {
//   int t1 = millis();
  Serial.print(count);
  Serial.print(" ");
//   int t2 = millis();
  Serial.println(count/20);
  delay(100); 

}