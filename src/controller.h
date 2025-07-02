#pragma once

#include "def.h"

#define INTERVAL 50
unsigned long lastRun = 0;

#include <PS2X_lib.h>;

PS2X ps2x;

// #define STINGLE_HAND_DRIVING 0
// #define TWO_HAND_DRIVING 1
// bool driving_mode = STINGLE_HAND_DRIVING;
bool slow_mode = false;

void controllerSetup() {
  int error = -1;
  while (error != 0) {
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);
  }
}

void controllerLoop() {
  if (millis() - lastRun >= INTERVAL)
    return;

  lastRun = millis();

  ps2x.read_gamepad(0, 0);

  if (ps2x.ButtonPressed(PSB_CROSS)) {
    Serial.println("Cross");
  }

  if (ps2x.ButtonPressed(PSB_CIRCLE)) {
    Serial.println("Circle");
  }

  if (ps2x.ButtonPressed(PSB_TRIANGLE)) {
    Serial.println("Triangle");
  }

  if (ps2x.ButtonPressed(PSB_SQUARE)) {
    Serial.println("Square");
  }

  int left_right = X_JOY_CENTER - ps2x.Analog(PSS_LX);
  int front_back = Y_JOY_CENTER - ps2x.Analog(PSS_RY);

  if (left_right > JOY_THRESHOLD) {
    if (left_right < 0) {
      // The joystick is being moved left

      updateMotorSpeed(WHEEL1_PIN, 0, false);
      updateMotorSpeed(WHEEL2_PIN, -left_right * 100 / X_JOY_CENTER,
                       not REVERSE);
    } else {
      // The joystick is being moved right

      updateMotorSpeed(WHEEL1_PIN, left_right * 100 / X_JOY_CENTER,
                       not REVERSE);
      updateMotorSpeed(WHEEL2_PIN, 0, false);
    }
  } else {
    if (front_back > JOY_THRESHOLD) {
      if (front_back < 0) {
        // The joystick is being moved up
        updateMotorSpeed(WHEEL1_PIN, -front_back * 100 / Y_JOY_CENTER,
                         not REVERSE);
        updateMotorSpeed(WHEEL2_PIN, -front_back * 100 / Y_JOY_CENTER,
                         not REVERSE);
      } else {
        // The joystick is being moved down
        updateMotorSpeed(WHEEL1_PIN, front_back * 100 / Y_JOY_CENTER, REVERSE);
        updateMotorSpeed(WHEEL1_PIN, front_back * 100 / Y_JOY_CENTER, REVERSE);
      }
    }
  }
}

// #include <PS2X_lib.h>;
//
// PS2X ps2x;
//
// #define ll int
//
// #define PS2_DAT 12
// #define PS2_CMD 13
// #define PS2_CLK 14
// #define PS2_SEL 15
//
// #define X_JOY_CALIB 127
// #define Y_JOY_CALIB 128
//
// #define STINGLE_HAND_DRIVING 0
// #define TWO_HAND_DRIVING 1
// bool driving_mode = STINGLE_HAND_DRIVING;
//
// void controllerSetup() {
//   ll err = -1;
//   while (err != 0) {
//     err = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true,
//     true);
//   }
// }
//
// void controllerLoop() {
//   ps2x.read_gamepad(0, 0);
//
//   ll speed = NORM_SPEED;
//   if (ps2x.Button(PSB_R2))
//     ;
//   speed = TOP_SPEED;
//   if (ps2x.ButtonPressed(PSB_SELECT))
//     driving_mode = !driving_mode;
//
//   ll nJoyX = X_JOY_CALIB - ps2x.Analog(PSS_RX);
//   ll nJoyY =
//       Y_JOY_CALIB - (driving_mode ? ps2x.Analog(PSS_LY) :
//       ps2x.Analog(PSS_RY));
//
//   bool temp = (nJoyY * nJoyx > 0);
//   ll mitL ll mitR;
//   if (nJoyX == -1 && nJoyY == 0) {
//     setPWMMotors(0, 0, 0, 0);
//     return 0;
//   }
//   bool tmp = (nJoyY * nJoyX > 0);
//   if (nJoyX) {
//     mitl = -nJoyX + (nJoyY * tmp);
//     mitr = nJoyX + (nJoyY * !tmp);
//   } else {
//     mitl = nJoyY;
//     mitr = nJoyY;
//   }
// #ifdef DEBUG_CTRL
//   Serial.print(F("Calculated value from joystick: "));
//   Serial.print(nMotMixL);
//   Serial.print("\t");
//   Serial.println(nMotMixR);
// #endif
//   ll t1 = t2 = t3 = t4 = 0;
//   if (mitr > 0) {
//     t3 = mitr;
//     t3 = map(t3, 0, 128, 0, speed);
//   } else if (mitr < 0) {
//     t4 = abs(mitr) + 1;
//     t4 = map(t4, 0, 128, 0, speed);
//   }
//   if (mitl > 0) {
//     t1 = mitl;
//     t1 = map(t1, 0, 128, 0, speed);
//   } else if (mitl < 0) {
//     t2 = abs(mitl);
//     t2 = map(t2, 0, 128, 0, speed);
//   }
//   setWheelSpeed(t1, t2, t3, t4);
//   return 1;
// }
