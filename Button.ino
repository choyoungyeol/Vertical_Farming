#define Zero 8
#define Manual 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Zero, INPUT);
  pinMode(Manual, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int Zero_Value =  digitalRead(Zero);
  int Manual_Value =  digitalRead(Manual);

  if (Zero_Value == HIGH) {  //1
    //waterVolume = 0;
    Serial.println(Zero_Value);
  } else {                   //0
    Serial.println(Zero_Value);
  }
  delay(1000);

  if (Manual_Value == HIGH) {
    //digitalWrite(Relay, HIGH);
    Serial.println(Manual_Value);
  } else {
    Serial.println(Manual_Value);
  }
  delay(1000);
}
