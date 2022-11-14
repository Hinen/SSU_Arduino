int vr = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int vrValue = analogRead(vr) / 4;
  Serial.println(vrValue);

  delay(100);
}
