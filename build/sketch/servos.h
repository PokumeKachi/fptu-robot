#line 1 "/home/kachi/projects/fptu/fptu-robot/src/servos.h"
// #include <servos.h>

// Servo servo1;
// Servo servo2;

// #define servo1_pin 18
// #define servo2_pin 19

// bool servoqt = false;
// bool bamlt = false;

// void setup()
// {
//   Serial.begin(9600);
//   servo1.attach(servo1_pin);
//   servo2.attach(servo2_pi n);
//   servo1.write(0);
//   servo2.write(0);
//   int er = ps2x.config_gamepad(5,17,16,4,true,true);
//   if (er == 0) Serial.println("OK")
//   else
//   {
//     Serial.print("ERROR");
//     Serial.println(er);
//   }
// }
// void loop()
// {
//   ps2x.read_gamepad();
//   bool qthao = ps2x.Button(PSB_TRIANGLE);
//   if (qthao && !bamlt)
//   {
//     servoqt = !servoqt;
//     if (servoqt)
//     {
//       servo1.write(180);
//       servo2.write(180);
//     }
//     else
//     {
//       servo1.write(0);
//       servo2.write(0);
//     }
//     delay(1000);
//   }
//   bamlt=qthao;
// }

Servo servo1;
Servo servo2;

#define servo1_pin 18
#define servo2_pin 19

bool servoqt = false;
bool bamlt = false;

void setup()
{
  Serial.begin(9600);
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pi n);
  servo1.write(0);
  servo2.write(0);
  int er = ps2x.config_gamepad(5,17,16,4,true,true);
  if (er == 0) Serial.println("OK")
  else
  {
    Serial.print("ERROR");
    Serial.println(er);
  }
}
void loop()
{
  ps2x.read_gamepad();
  bool qthao = ps2x.Button(PSB_TRIANGLE);
  if (qthao && !bamlt)
  {
    servoqt = !servoqt;
    if (servoqt)
    {
      servo1.write(180);
      servo2.write(180);
    }
    else
    {
      servo1.write(0);
      servo2.write(0);
    }
    delay(1000);
  }
  bamlt=qthao;
}
}
// }