#include <Arduino.h>

const int ledPins[] = {26, 13, 14, 27};
const int ledCount = 4;

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(300);
    digitalWrite(ledPins[i], LOW);
  }
}