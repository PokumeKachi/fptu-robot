#include "include/motor.hpp"
#include "include/servo.hpp"
#include "include/controller.hpp"
// #include "def.h"

void setup()
  pwm.begin();
  pwm.setPWMFreq(50);

  Serial.begin(115200);

  Serial.println("Start SETUP!");

  controllerSetup();
  motorSetup();
  servoSetup();

  Serial.println("DONE SETUP!");
}

void loop()
{
  controllerLoop();
  motorLoop();
  servoLoop();
}
