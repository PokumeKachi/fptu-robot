#include "include/globals.hpp"

bool openingGate = false;
bool elevating = false;
bool lowering = false;
struct Vec2 moveDirection = {0, 0};
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
