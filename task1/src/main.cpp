#include <Arduino.h>

const int led1 = 13;
const int led2 = 14;
const int led3 = 27;

bool led1State = false;
bool led2State = false;
bool led3State = false;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "1") {
      led1State = !led1State;
      digitalWrite(led1, led1State ? HIGH : LOW);
      Serial.println(led1State ? "LED1亮" : "LED1灭");
    }
    else if (cmd == "2") {
      led2State = !led2State;
      digitalWrite(led2, led2State ? HIGH : LOW);
      Serial.println(led2State ? "LED2亮" : "LED2灭");
    }
    else if (cmd == "3") {
      led3State = !led3State;
      digitalWrite(led3, led3State ? HIGH : LOW);
      Serial.println(led3State ? "LED3亮" : "LED3灭");
    }
    else {
      Serial.println("无效指令");
    }
  }
}