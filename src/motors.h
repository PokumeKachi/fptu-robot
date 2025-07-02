#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <stdio.h>

#define MIN_PWM 0
#define MAX_PWM 4095

#define WHEEL1_PIN1 8
#define WHEEL1_PIN2 9
#define WHEEL2_PIN1 10
#define WHEEL2_PIN2 11

#define PULLEY1_PIN1 12
#define PULLEY1_PIN2 13
#define PULLEY2_PIN1 14
#define PULLEY2_PIN2 15

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setWheelSpeed(int c1, int c2, int c3, int c4) {
  char dbg_str[30];
  sprintf(dbg_str, "C1: %d\tC2: %d\tC3: %d\tC4: %d", c1, c2, c3, c4);
  Serial.println(dbg_str);

  pwm.setPin(WHEEL1_PIN1, c1);
  pwm.setPin(WHEEL1_PIN2, c2);
  pwm.setPin(WHEEL2_PIN1, c3);
  pwm.setPin(WHEEL2_PIN2, c4);
}

void setPulleySpeed(int c1, int c2, int c3, int c4) {
  char dbg_str[30];
  sprintf(dbg_str, "C1: %d\tC2: %d\tC3: %d\tC4: %d", c1, c2, c3, c4);
  Serial.println(dbg_str);

  pwm.setPin(PULLEY1_PIN1, c1);
  pwm.setPin(PULLEY1_PIN2, c2);
  pwm.setPin(PULLEY2_PIN1, c3);
  pwm.setPin(PULLEY2_PIN2, c4);
}

void motorSetup() {
  Wire.begin();
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(1600);
  Wire.setClock(400000);

  setWheelSpeed(0, 0, 0, 0);
  setPulleySpeed(0, 0, 0, 0);
}

void motorLoop() {}
