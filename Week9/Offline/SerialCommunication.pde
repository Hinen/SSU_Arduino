import processing.serial.*;

color c;
Serial port;

String buffer;
int light;
int circleSize;

void setup() {
  size(1200, 600);
  frameRate(30);
  
  PFont font = loadFont("NanumGothicBold-48.vlw");
  fill(255);
  textFont(font, 32);
  
  String arduinoPort = Serial.list()[1];
  port = new Serial(this, arduinoPort, 9600);
}

void draw() {
  background(c);
  
  int value = readBuffer();
  
  //func1(value);
  func2(value);
}

int readBuffer() {
  int value = -1;
  
  if (port.available() > 0) {
    int inByte = port.read();
    if (inByte != 10) {
      buffer += char(inByte);
    }
    else if (buffer.length() > 1) {
      buffer = buffer.substring(0, buffer.length() - 1);
      value = int(buffer);
      
      buffer = "";
      port.clear();
    }
  }
  
  return value;
}

void func1(int value) {
  if (value != -1)
    light = value;
  
  text("light level", 100, 100);
  text(light, 300, 100);
}

void func2(int value) {
  if (value != -1)
    circleSize = value;
  
  text(circleSize, 300, 100);
  circle(600, 300, circleSize);
}
