//
int led1 = 13;
int led1State = LOW;

int btn1 = 8;
int btn1OldState = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(btn1, INPUT);
}

void loop() {
  bool nowBtn1State = digitalRead(btn1);

  // 버튼을 입력하는 순간 해당 if문을 타게 된다.
  if (nowBtn1State == HIGH && btn1OldState == LOW) {
    led1State = HIGH - led1State;
    btn1OldState = HIGH;
  }
  // 버튼을 손에서 떼는 순간 해당 else if를 타게 된다.
  else if (nowBtn1State == LOW && btn1OldState == HIGH) {
    // 버튼을 떼는 그 순간은 아무리 늦어도 0.1초안에 끝날테니 100밀리 대기
    delay(100);

    // 0.1초후 btn1OldState을 LOW로 set해주면서, 다시 버튼을 눌렀을때 동작이 입력되도록 설정
    btn1OldState = LOW;
  }
  
  digitalWrite(led1, led1State);
}
