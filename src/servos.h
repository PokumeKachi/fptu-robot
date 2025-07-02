#include <ESP32Servo.h>

Servo servo1;
Servo servo2;

// #define SERVO1_PIN1 12
// #define SERVO1_PIN2 13
// #define SERVO2_PIN1 14
// #define SERVO2_PIN2 15

bool servoqt = false;
bool bamlt = false;

void servoSetup() {
  // Serial da duoc khoi tao o file ino chinh

  // Serial.begin(9600);
  servo1.attach(SERVO1_PIN1);
  servo2.attach(SERVO2_PIN2);
  servo1.write(0);
  servo2.write(0);

  // PS2 da duoc khoi tao o file PS2_controller.h

  // int er = ps2x.config_gamepad(5, 17, 16, 4, true, true);
  // if (er == 0) {
  //   Serial.println("OK")
  // } else {
  //   Serial.print("ERROR");
  //   Serial.println(er);
  // }
}
void servoLoop() {
  ps2x.read_gamepad();
  bool qthao = ps2x.Button(PSB_TRIANGLE);
  if (qthao && !bamlt) {
    servoqt = !servoqt;
    if (servoqt) {
      servo1.write(180);
      servo2.write(180);
    } else {
      servo1.write(0);
      servo2.write(0);
    }
    delay(1000);
  }
  bamlt = qthao;
}
