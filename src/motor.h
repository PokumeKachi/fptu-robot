#pragma once

#include "def.h"

// #include <Adafruit_PWMServoDriver.h>
// #include <Wire.h>
// #include <stdio.h>

// enum MotorState { MOTOR_IDLE, MOTOR_FORWARD, MOTOR_BACKWARD };

void updateMotorSpeed(int motor_pin, int speedPercent, bool reverse) {
  if (not reverse) {
    ledcWrite(motor_pin, MAX_PWM / 100 * speedPercent);
    ledcWrite(motor_pin + 1, MIN_PWM);
  } else {
    ledcWrite(motor_pin, MIN_PWM);
    ledcWrite(motor_pin + 1, MAX_PWM / 100 * speedPercent);
  }
}

// void updateMotor(int motor_pin, enum MotorState state) {
//   switch (state) {
//   case MOTOR_IDLE:
//     ledcWrite(motor_pin, MIN_PWM);
//     ledcWrite(motor_pin + 1, MIN_PWM);
//     break;
//   case MOTOR_FORWARD:
//     ledcWrite(motor_pin, MAX_PWM);
//     ledcWrite(motor_pin + 1, MIN_PWM);
//     break;
//   case MOTOR_BACKWARD:
//     ledcWrite(motor_pin, MIN_PWM);
//     ledcWrite(motor_pin + 1, MAX_PWM);
//     break;
//   default:
//     Serial.println("Edge case of motor enum state handling detected! Please "
//                    "recheck your code!");
//     break;
//   }
// }

void motorSetup() {
  ledcAttach(WHEEL1_PIN, ANALOG_FREQ, ANALOG_RESOLUTION);
  ledcAttach(WHEEL2_PIN, ANALOG_FREQ, ANALOG_RESOLUTION);
  ledcAttach(PULLEY1_PIN, ANALOG_FREQ, ANALOG_RESOLUTION);
  ledcAttach(PULLEY2_PIN, ANALOG_FREQ, ANALOG_RESOLUTION);

  updateMotorSpeed(WHEEL1_PIN, 0, 0);
  updateMotorSpeed(WHEEL2_PIN, 0, 0);
  updateMotorSpeed(PULLEY1_PIN, 0, 0);
  updateMotorSpeed(PULLEY2_PIN, 0, 0);
  // updateMotor(WHEEL1_PIN, MOTOR_IDLE);
  // updateMotor(WHEEL2_PIN, MOTOR_IDLE);
  // updateMotor(PULLEY1_PIN, MOTOR_IDLE);
  // updateMotor(PULLEY2_PIN, MOTOR_IDLE);
}

void motorLoop() {}
