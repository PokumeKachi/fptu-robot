#include "include/servo.hpp"

#include "include/globals.hpp"

#include <Arduino.h>
#include <ESP32Servo.h>

static unsigned long lastRun = 0;

static Servo servo;

// bool servoqt = false;
// bool bamlt = false;

void servoSetup() {
  servo.attach(SERVO_PIN);
  servo.write(0);
}

void servoLoop() {
  if (millis() - lastRun >= SERVO_INTERVAL)
    return;

  lastRun = millis();

  if (openingGate) {
    // We are letting the balls fall out
    if (servo.read() < 180) {
      // The servo hasn't reached 180 degrees

      servo.write(servo.read() + 1);
    }
  } else {
    if (servo.read() > 0) {
      servo.write(servo.read() - 1);
    }
  }

  // bool qthao = ps2x.Button(PSB_TRIANGLE);
  // if (qthao && !bamlt) {
  //   servoqt = !servoqt;
  //   if (servoqt) {
  //     servo.write(180);
  //   } else {
  //     servo.write(0);
  //   }
  //   delay(1000);
  // }
  // bamlt = qthao;
}
