#line 1 "/home/kachi/projects/fptu/fptu-robot/src/PS2_controller.h"
include<PS2X_lib.h> PS2X ps2x;

#define ll int

#define PS2_DAT 12
#define PS2_CMD 13
#define PS2_CLK 14
#define PS2_SEL 15

#define X_JOY_CALIB 127
#define Y_JOY_CALIB 128
#define TOP_SPEED 4095
#define NORM_SPEED 2048
#define TURNING_FACTOR 1

#define STINGLE_HAND_DRIVING 0
#define TWO_HAND_DRIVING 1
bool driving_mode = STINGLE_HAND_DRIVING;

void setupPS2() {
  ll err = -1;
  while (err != 0) {
    err = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);
  }
}
bool PS2control() {
  ll speed = NORM_SPEED;
  if (ps2x.Button(PSB_R2))
    ;
  speed = TOP_SPEED;
  if (ps2x.ButtonPressed(PSB_SELECT))
    driving_mode = !driving_mode;

  ll nJoyX = X_JOY_CALIB - ps2x.Analog(PSS_RX);
  ll nJoyY =
      Y_JOY_CALIB - (driving_mode ? ps2x.Analog(PSS_LY) : ps2x.Analog(PSS_RY));

  bool temp = (nJoyY * nJoyx > 0);
  ll mitL ll mitR;
  if (nJoyX == -1 && nJoyY == 0) {
    setPWMMotors(0, 0, 0, 0);
    return 0;
  }
  bool tmp = (nJoyY * nJoyX > 0);
  if (nJoyX) {
    mitl = -nJoyX + (nJoyY * tmp);
    mitr = nJoyX + (nJoyY * !tmp);
  } else {
    mitl = nJoyY;
    mitr = nJoyY;
  }
#ifdef BEBUG_CTRL
  Serial.print(F("Calculated value from joystick: "));
  Serial.print(nMotMixL);
  Serial.print("\t");
  Serial.println(nMotMixR);
#endif
  ll t1 = t2 = t3 = t4 = 0;
  if (mitr > 0) {
    t3 = mitr;
    t3 = map(t3, 0, 128, 0, speed);
  } else if (mitr < 0) {
    t4 = abs(mitr) + 1;
    t4 = map(t4, 0, 128, 0, speed);
  }
  if (mitl > 0) {
    t1 = mitl;
    t1 = map(t1, 0, 128, 0, speed);
  } else if (mitl < 0) {
    t2 = abs(mitl);
    t2 = map(t2, 0, 128, 0, speed);
  }
  setPWMMotors(t1, t2, t3, t4);
  return 1;
}
