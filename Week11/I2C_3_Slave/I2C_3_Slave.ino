#include <Wire.h>

enum ButtonFlag {
  NONE = 0,
  DOWN = 1,
  PRESSING = 2,
  UP = 3
};

int led = 8;

void setup() { 
  Wire.begin(8);
  Wire.onReceive(receiveEvent);

  Serial.begin(9600);

  pinMode(led, OUTPUT);
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  Serial.println("Test");
  
  int btnFlag = Wire.read();
  digitalWrite(led, btnFlag == ButtonFlag::PRESSING);

  Serial.println(btnFlag);
}
