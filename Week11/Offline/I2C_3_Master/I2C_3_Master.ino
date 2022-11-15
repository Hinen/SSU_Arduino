#include <Wire.h>

enum ButtonFlag {
  NONE = 0,
  DOWN = 1,
  PRESSING = 2,
  UP = 3
};

int btn1 = 7;
int btn1OldState = LOW;

void setup() {
  Wire.begin();
  pinMode(btn1, INPUT);
}

void loop() {
  int btn1Flag = getButtonFlag(btn1, &btn1OldState);
  
  Wire.beginTransmission(8);
  Wire.write(btn1Flag);
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
