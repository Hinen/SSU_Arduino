int led1 = 13;
int button1 = 8;

int led2 = 12;
int button2 = 7;

bool button1OffFlag = false;
bool button2OffFlag = false;

bool isLed1On = false;
bool isLed2On = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  int button1Pressed = digitalRead(button1);
  int button2Pressed = digitalRead(button2);

  if (isLed1On && isLed2On)
    LEDOffFunc(button1Pressed, button2Pressed);
  else
    LEDOnFunc(button1Pressed, button2Pressed);
  
  if (isLed1On)
    digitalWrite(led1, HIGH);
  else
    digitalWrite(led1, LOW);

  if (isLed2On)
    digitalWrite(led2, HIGH);
  else
    digitalWrite(led2, LOW);
}

void LEDOffFunc(int button1Pressed, int button2Pressed) {
  if (!button1OffFlag && button1Pressed == HIGH)
    button1OffFlag = true;
  else if (!button2OffFlag && button2Pressed == HIGH)
    button2OffFlag = true;
  else {
    button1OffFlag = false;
    button2OffFlag = false;
  }

  // Button Press가 동시 인식이 안되므로
  // Button Flag를 저장해두고, 이 두 값이 모두 true되면 LED를 끄도록 
  if (button1OffFlag && button2OffFlag) {
    isLed1On = false;
    isLed2On = false;
  } 
}

void LEDOnFunc(int button1Pressed, int button2Pressed) {
  if (button1OffFlag && button2OffFlag) {
    // 만약 Flag가 true인 경우라면 LED를 끄기 위한 버튼 입력인 것이므로, 
    // return 시키고 버튼 다시 재입력 하도록 함
    if (button1Pressed || button2Pressed)
      return;

    button1OffFlag = false;
    button2OffFlag = false;
  }
    
  if (button1Pressed == HIGH)
    isLed1On = true;

  if (button2Pressed == HIGH)
    isLed2On = true;
}
