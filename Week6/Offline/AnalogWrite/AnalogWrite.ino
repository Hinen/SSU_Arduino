enum ButtonFlag {
  NONE = 0,
  DOWN = 1,
  PRESSING = 2,
  UP = 3
};

int led = 11;
int ledBright = 0;

int btn1 = 8;
int btn1OldState = LOW;

int btn2 = 7;
int btn2OldState = LOW;

void setup() {
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {
  int btn1Flag = getButtonFlag(btn1, &btn1OldState);
  int btn2Flag = getButtonFlag(btn2, &btn2OldState);
  
  if (btn1Flag == ButtonFlag::PRESSING) {
    ledBright++;
    delay(100);

    if (ledBright > 255)
      ledBright = 0;
  }

  if (btn2Flag == ButtonFlag::PRESSING) {
    ledBright--;
    delay(100);

    if (ledBright < 0)
      ledBright = 255;
  }
  
  Serial.println(ledBright);
  analogWrite(led, ledBright);
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
