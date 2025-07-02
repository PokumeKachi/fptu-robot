#pragma once

#include "def.h"

#include <ESP32Servo.h>

Servo servo;

bool servoqt = false;
bool bamlt = false;

void servoSetup() {
  servo.attach(SERVO_PIN);
  servo.write(0);
}

void servoLoop() {
  bool qthao = ps2x.Button(PSB_TRIANGLE);
  if (qthao && !bamlt) {
    servoqt = !servoqt;
    if (servoqt) {
      servo.write(180);
    } else {
      servo.write(0);
    }
    delay(1000);
  }
  bamlt = qthao;
}
