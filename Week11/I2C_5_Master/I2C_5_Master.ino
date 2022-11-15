#include <Wire.h>

enum ButtonFlag {
  NONE = 0,
  DOWN = 1,
  PRESSING = 2,
  UP = 3
};

int btn1 = 7;
int btn1OldState = LOW;

int btn2 = 6;
int btn2OldState = LOW;

int btn3 = 5;
int btn3OldState = LOW;

void setup() {
  Wire.begin();
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
}

void loop() {
  BtnWire(1, btn1, &btn1OldState);
  BtnWire(2, btn2, &btn2OldState);
  BtnWire(3, btn3, &btn3OldState);
}

void BtnWire(int address, int btn, int* btnOldState) {
  int btnFlag = getButtonFlag(btn, btnOldState);
  
  Wire.beginTransmission(address);
  Wire.write(btnFlag);
  Wire.endTransmission();
}

int getButtonFlag(int btn, int* btnOldState) {
  int btnFlag = ButtonFlag::NONE;
  
  int btnNowState = digitalRead(btn);
  if (btnNowState == HIGH) {
    if (*btnOldState == LOW) {
      btnFlag = ButtonFlag::DOWN;
    }
    else {
      btnFlag = ButtonFlag::PRESSING;
    }
  }
  else {
    btnFlag = ButtonFlag::UP;
  }

  *btnOldState = btnNowState;
  return btnFlag;
}
