int led1 = 11;

int ldr = 0;
int ldrValue = 0;

int vr = 5;
int vrValue = 0;

void setup() {
  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  //Assignment1(); // 1 조도 센서 
  //Assignment2(); // 2 조도 센서 map
  //Assignment3(); // 3 가변 저항
  Assignment4(); // 4 조도 센서 저항 순서 변경 
}

void Assignment1() {
  ldrValue = analogRead(ldr);
  ldrValue /= 4;
  
  Serial.println(ldrValue);
  analogWrite(led1, ldrValue);
  
  delay(10);
}

void Assignment2() {
  ldrValue = map(analogRead(ldr), 400, 650, 0, 255);
  ldrValue = ldrValue > 255 ? 255 
              : ldrValue < 0 ? 0
              : ldrValue;
  
  Serial.println(ldrValue);
  analogWrite(led1, ldrValue);
  
  delay(10);
}

void Assignment3() {
  vrValue = analogRead(vr);
  vrValue /= 4;

  Serial.println(vrValue);
  analogWrite(led1, vrValue);
  
  delay(10);
}

void Assignment4() {
  ldrValue = map(analogRead(ldr), 250, 700, 0, 255);
  ldrValue = ldrValue > 255 ? 255 
              : ldrValue < 0 ? 0
              : ldrValue;
  
  Serial.println(ldrValue);
  analogWrite(led1, ldrValue);
  
  delay(10);
}
