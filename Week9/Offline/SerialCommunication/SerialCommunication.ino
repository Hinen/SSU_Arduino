int led1 = 11;
int ldr = 0;
int vr = 5;

void setup() {
  pinMode(led1, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  func1();
  //func2();
}

void func1() {
  int ldrValue = map(analogRead(ldr), 350, 900, 0, 255);
  
  Serial.println(ldrValue);
  analogWrite(led1, ldrValue);

  delay(100);
}

void func2() {
  // 왼쪽으로 돌리면 값이 작아지도록 처리하기 위해서 255에서 뺀 값으로 설 
  int vrValue = 255 - analogRead(vr) / 4;
  Serial.println(vrValue);

  delay(100);
}
