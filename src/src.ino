// #include "motor.h"
#include "controller.h"
// #include "servo.h"

void setup() {
  Serial.begin(115200);

  motorSetup();
  // servoSetup();
  controllerSetup();

  Serial.println("DONE SETUP!");
}

void loop() {
  motorLoop();
  // servoLoop();
  controllerLoop();
  // delay(50);
}
