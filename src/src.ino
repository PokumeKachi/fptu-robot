#include "motors.h"
#include "PS2_controller.h"
#include "servos.h"

void setup() {
  Serial.begin(115200);
  motorSetup();
  servoSetup();
  PS2Setup();
  Serial.println("DONE SETUP!");
}

void loop() {
  ps2x.read_gamepad(0, 0);
  PS2control();
  // delay(50);
}
