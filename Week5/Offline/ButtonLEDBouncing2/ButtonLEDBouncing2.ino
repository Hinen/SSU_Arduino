enum ButtonFlag {
  NONE = 0,
  DOWN = 1,
  PRESSING = 2,
  UP = 3
};

//
int led1 = 13;
int led1State = LOW;

int btn1 = 8;
int btn1OldState = LOW;

//
int led2 = 12;
int led2State = LOW;

int btn2 = 7;
int btn2OldState = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {
  int btn1Action = Button1Action();
  int btn2Action = Button2Action();

  if (led1State == HIGH && led2State == HIGH) {
    if (btn1Action == ButtonFlag::PRESSING && 
        btn2Action == ButtonFlag::PRESSING) {
      led1State = LOW;
      led2State = LOW;
    }
  }
  else {
    if (btn1Action == ButtonFlag::DOWN)
      led1State = HIGH;

    if (btn2Action == ButtonFlag::DOWN)
      led2State = HIGH;
  }
  
  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
}

int Button1Action() {
  bool nowBtn1State = digitalRead(btn1);
  
  // 버튼을 입력하는 순간 해당 if문을 타게 된다.
  if (nowBtn1State == HIGH && btn1OldState == LOW) {
    btn1OldState = HIGH;
    return ButtonFlag::DOWN;
  }
  // 버튼을 계속 누르고 있을 경우
  else if (nowBtn1State == HIGH) {
    return ButtonFlag::PRESSING;
  }
  // 버튼을 손에서 떼는 순간 해당 else if를 타게 된다.
  else if (nowBtn1State == LOW && btn1OldState == HIGH) {
    // 버튼을 떼는 행동은 아무리 늦어도 0.1초안에 끝날테니 100밀리 대기
    delay(100);

    // 0.1초후 btn1OldState을 LOW로 set해주면서, 다시 버튼을 눌렀을때 동작이 입력되도록 설정
    btn1OldState = LOW;
    return ButtonFlag::UP;
  }

  return ButtonFlag::NONE;
}

int Button2Action() {
  bool nowBtn2State = digitalRead(btn2);
  
  // 버튼을 입력하는 순간 해당 if문을 타게 된다.
  if (nowBtn2State == HIGH && btn2OldState == LOW) {
    btn2OldState = HIGH;
    return ButtonFlag::DOWN;
  }
  // 버튼을 계속 누르고 있을 경우
  else if (nowBtn2State == HIGH) {
    return ButtonFlag::PRESSING;
  }
  // 버튼을 손에서 떼는 순간 해당 else if를 타게 된다.
  else if (nowBtn2State == LOW && btn2OldState == HIGH) {
    // 버튼을 떼는 행동은 아무리 늦어도 0.1초안에 끝날테니 100밀리 대기
    delay(100);

    // 0.1초후 btn2OldState을 LOW로 set해주면서, 다시 버튼을 눌렀을때 동작이 입력되도록 설정
    btn2OldState = LOW;
    return ButtonFlag::UP;
  }

  return ButtonFlag::NONE;
}
