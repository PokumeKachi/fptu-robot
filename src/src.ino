#include "motor.h"
#include "controller.h"
#include "servo.h"

void setup() {
  Serial.begin(115200);

  controllerSetup();
  motorSetup();
  servoSetup();

  Serial.println("DONE SETUP!");
}

void loop() {
  controllerLoop();
  motorLoop();
  servoLoop();
}
