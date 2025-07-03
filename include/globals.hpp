#pragma once

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

struct Vec2 {
  int x;
  int y;
};

// Cac bien toan cuc

extern bool openingGate;
extern bool elevating;
extern bool lowering;
extern struct Vec2 moveDirection;
extern Adafruit_PWMServoDriver pwm;

// Cac hang so co the chinh sua:

// Motor

#define ANALOG_FREQ 5000
#define ANALOG_RESOLUTION 8

#define WHEEL1_PIN 8
#define WHEEL2_PIN 10
#define PULLEY1_PIN 12
#define PULLEY2_PIN 14

#define MIN_PWM 0
#define MAX_PWM 255

#define WHEEL_REVERSE true
#define PULLEY_REVERSE true

// Servo

#define SERVO_PIN 2

// Controller

#define JOY_THRESHOLD 10

#define PS2_DAT 12
#define PS2_CMD 13
#define PS2_CLK 14
#define PS2_SEL 15

#define X_JOY_CENTER 127
#define Y_JOY_CENTER 128

// Loop intervals

#define SERVO_INTERVAL 2
#define CONTROLLER_INTERVAL 2
