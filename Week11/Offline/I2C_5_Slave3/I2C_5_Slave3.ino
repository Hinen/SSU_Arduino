#include <Wire.h>

enum ButtonFlag {
  NONE = 0,
  DOWN = 1,
  PRESSING = 2,
  UP = 3
};

int led = 8;

void setup() { 
  Wire.begin(3);
  Wire.onReceive(receiveEvent);

  pinMode(led, OUTPUT);
}

void loop() {
  delay(100);
}

void receiveEvent(int value) {
  int btnFlag = Wire.read();
  digitalWrite(led, btnFlag == ButtonFlag::PRESSING);
}
