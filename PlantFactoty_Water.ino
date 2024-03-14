#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define WaterPin A0
#define Relay 7
#define Zero 8
#define Manual 9

volatile double waterVolume;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int n = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);
  pinMode(Zero, INPUT);
  pinMode(Manual, INPUT);
  waterVolume = 0;
  attachInterrupt(0, pulseHigh, RISING);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
  lcd.setCursor(0, 1);
  lcd.print("Vege. Info. Lab");
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Water_Value = analogRead(A0);
  int Water_Content = map(Water_Value, 96, 256, 0, 100);
  Water_Content = constrain(Water_Content, 0, 100);
  int Zero_Value =  digitalRead(Zero);
  int Manual_Value =  digitalRead(Manual);
  Serial.print(Water_Value);
  Serial.print(", ");
  Serial.println(Water_Content);
  Serial.print("Total Water Volume:");
  Serial.print(waterVolume);
  Serial.println(" L");
  delay(500);

  if (n < 20) {
    if (Water_Content <= 30) {
      digitalWrite(Relay, HIGH);
      n = n + 1;
    }
    if (Water_Content >= 35) {
      digitalWrite(Relay, LOW);
      n = 0;
    }
  } else {
    digitalWrite(Relay, LOW);
    n = 0;
  }

  if (Zero_Value == LOW) {
    waterVolume = 0;
  }
  delay(10);

  if (Manual_Value == LOW) {
    digitalWrite(Relay, HIGH);
    delay(60000);
  }
  delay(10);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water = ");
  lcd.print(Water_Content);
  lcd.print(" %, ");
  lcd.print(n);
  lcd.setCursor(0, 1);
  lcd.print("Total = ");
  lcd.print(waterVolume);
  lcd.print(" L");
  delay(500);
}

void pulseHigh()   //measure the quantity of square wave
{
  waterVolume += 1.0 / 5880.0;
}
