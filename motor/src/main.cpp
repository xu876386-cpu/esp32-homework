#include <Arduino.h>

const int IN1 = 26;
const int IN2 = 27;
const int IN3 = 14;
const int IN4 = 13;

const int stepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

const int stepsPerRev = 2048;

void stepMotor(int step) {
  digitalWrite(IN1, stepSequence[step][0]);
  digitalWrite(IN2, stepSequence[step][1]);
  digitalWrite(IN3, stepSequence[step][2]);
  digitalWrite(IN4, stepSequence[step][3]);
}

void rotate(int steps, bool clockwise) {
  for (int i = 0; i < steps; i++) {
    int step = clockwise ? (i % 8) : (7 - (i % 8));
    stepMotor(step);
    delay(2);
  }
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stopMotor();
}

void loop() {
  rotate(stepsPerRev, true);   
  stopMotor();
  delay(1000);                 
  rotate(stepsPerRev, false);  
  stopMotor();
  delay(1000);                 
}