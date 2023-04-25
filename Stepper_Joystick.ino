#include <HCMotor.h>

#define DIR_PIN 8 //스텝모터드라이버 DIR 연결핀
#define CLK_PIN 9 //스텝모터드라이버 CLK 연결핀

#define LLIMIT_PIN 24
#define RLIMIT_PIN 22

const int AXIS_X = A0;
const int AXIS_Y = A1;
const int SW_P = 5;

HCMotor HCMotor;

int Speed = 10;

void setup()
{
  HCMotor.Init();
  HCMotor.attach(0, STEPPER, CLK_PIN, DIR_PIN);
  HCMotor.Steps(0, CONTINUOUS);
  HCMotor.DutyCycle(0, Speed);
  pinMode(LLIMIT_PIN, INPUT);
  pinMode(RLIMIT_PIN, INPUT);
  pinMode(SW_P, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(LLIMIT_PIN) == LOW)
    HCMotor.Direction(0, FORWARD);
  else if (digitalRead(RLIMIT_PIN) == LOW)
    HCMotor.Direction(0, REVERSE);

  if (analogRead(AXIS_X) <= 300) {
    HCMotor.Direction(0, REVERSE);
  }

  if (analogRead(AXIS_X) >= 700) {
    HCMotor.Direction(0, FORWARD);
  }

}
