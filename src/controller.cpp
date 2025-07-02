#include "include/controller.hpp"

#include "include/globals.hpp"

#include <Arduino.h>
#include <PS2X_lib.h>;
#include <cstdlib>

unsigned long lastRun = 0;

PS2X ps2x;

// bool slow_mode = false;

void controllerSetup() {
  int error = -1;
  while (error != 0) {
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);
  }
}

void controllerLoop() {
  if (millis() - lastRun >= CONTROLLER_INTERVAL)
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
    openingGate = false;
  }

  int left_right = X_JOY_CENTER - ps2x.Analog(PSS_LX);
  int front_back = Y_JOY_CENTER - ps2x.Analog(PSS_RY);

  moveDirection.x = 0;
  moveDirection.y = 0;

  if (std::abs(left_right) > JOY_THRESHOLD) {
    int moveSpeed = std::abs(left_right) * 100 / X_JOY_CENTER;

    if (left_right < 0) {
      // The joystick is being moved left

      moveDirection.x = -moveSpeed;
    } else {
      // The joystick is being moved right

      moveDirection.x = moveSpeed;
    }
  } else {
    if (std::abs(front_back) > JOY_THRESHOLD) {
      int moveSpeed = std::abs(front_back) * 100 / Y_JOY_CENTER;

      if (front_back < 0) {
        // The joystick is being moved up

        moveDirection.y = -moveSpeed;
      } else {
        // The joystick is being moved down

        moveDirection.y = moveSpeed;
      }
    }
  }

  // if (left_right > JOY_THRESHOLD) {
  //   if (left_right < 0) {
  //     // The joystick is being moved left
  //
  //     updateMotorSpeed(WHEEL1_PIN, 0, false);
  //     updateMotorSpeed(WHEEL2_PIN, -left_right * 100 / X_JOY_CENTER,
  //                      not WHEEL_REVERSE);
  //   } else {
  //     // The joystick is being moved right
  //
  //     updateMotorSpeed(WHEEL1_PIN, left_right * 100 / X_JOY_CENTER,
  //                      not WHEEL_REVERSE);
  //     updateMotorSpeed(WHEEL2_PIN, 0, false);
  //   }
  // } else {
  //   if (front_back > JOY_THRESHOLD) {
  //     if (front_back < 0) {
  //       // The joystick is being moved up
  //       updateMotorSpeed(WHEEL1_PIN, -front_back * 100 / Y_JOY_CENTER,
  //                        not WHEEL_REVERSE);
  //       updateMotorSpeed(WHEEL2_PIN, -front_back * 100 / Y_JOY_CENTER,
  //                        not WHEEL_REVERSE);
  //     } else {
  //       // The joystick is being moved down
  //       updateMotorSpeed(WHEEL1_PIN, front_back * 100 / Y_JOY_CENTER,
  //       WHEEL_REVERSE); updateMotorSpeed(WHEEL1_PIN, front_back * 100 /
  //       Y_JOY_CENTER, WHEEL_REVERSE);
  //     }
  //   }
  // }
}
