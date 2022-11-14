enum ButtonFlag {
  NONE = 0,
  DOWN = 1,
  PRESSING = 2,
  UP = 3
};

int btn1 = 8;
int btn1OldState = LOW;

int vr = 5;

void setup() {
  pinMode(btn1, INPUT);
  Serial.begin(9600);
}

void loop() {
  int btn1Flag = getButtonFlag(btn1, &btn1OldState);
  if (btn1Flag == ButtonFlag::DOWN) {
    Serial.println(9999);
    delay(500);
  }
  else {
    int vrValue = map(analogRead(vr) / 4, 0, 255, 500, 0); // 게임 디스플레이 500에 맞게 mapping 
    Serial.println(vrValue);
    delay(100);
  }
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
