#include <Servo.h>

enum ButtonFlag {
  NONE = 0,
  DOWN = 1,
  PRESSING = 2,
  UP = 3
};

Servo servo;
int degree = 0;

int btn1 = 8;
int btn2 = 7;
int btn1OldState = LOW;
int btn2OldState = LOW;

int led1 = 11;
int led2 = 10;
int vr = 5;

void setup() {
  servo.attach(5);
  servo.write(0);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  //func1(); // 서보 모터 단순 실행동
  //func2(); // 서보 모터와 버튼, LED 연동
  func3(); // 가변 저항과 서보 모터 연
}

void func1() {
  for (degree = 0; degree < 180; degree++) {
    servo.write(degree);
    delay(15);
  }
  delay(1000);

  for (degree = 180; degree > 0; degree--) {
    servo.write(degree);
    delay(15);
  }
  delay(1000);
}

void func2() {
  int btn1Flag = getButtonFlag(btn1, &btn1OldState);
  int btn2Flag = getButtonFlag(btn2, &btn2OldState);
  int oldDegree = degree;

  if (btn1Flag == ButtonFlag::DOWN && degree < 180)
    degree += 10;
  else if (btn2Flag == ButtonFlag::DOWN && degree > 0)
    degree -= 10;

  if (oldDegree != degree) {
    servo.write(degree);
    delay(150);
  }
  
  digitalWrite(led1, degree == 180 ? HIGH : LOW);
  digitalWrite(led2, degree == 0 ? HIGH : LOW);
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

void func3() {
  int vrValue = analogRead(vr) / 4;
  
  // vrValue는 0 ~ 255까지, 서보모터는 0 ~ 180까지 이므로 그에 맞도록 map처리
  degree = map(vrValue, 0, 255, 0, 180);
  servo.write(degree);
  
  delay(15);
}
