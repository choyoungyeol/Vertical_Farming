#include <HCMotor.h>

#define DIR_PIN 2 //스텝모터드라이버 DIR 연결핀
#define CLK_PIN 3 //스텝모터드라이버 CLK 연결핀

HCMotor HCMotor;

int Speed = 5;

void setup()
{
  HCMotor.Init();
  HCMotor.attach(0, STEPPER, CLK_PIN, DIR_PIN);
  HCMotor.Steps(0, CONTINUOUS);
  HCMotor.DutyCycle(0, Speed);
}

void loop()
{
  HCMotor.Direction(0, FORWARD);
  HCMotor.DutyCycle(0, Speed);
  HCMotor.Direction(0, REVERSE);
  delay(6000);
  HCMotor.DutyCycle(0, 0);
  delay(3000);
  
  HCMotor.Direction(0, REVERSE);
  HCMotor.DutyCycle(0, Speed);
  HCMotor.Direction(0, FORWARD);
  delay(6000);
  HCMotor.DutyCycle(0, 0);
  delay(3000);
}
