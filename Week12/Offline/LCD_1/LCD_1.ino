#include <LiquidCrystal.h>

// rs, e, d4, d5, d6, d7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldr = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("LDR Value");
}

void loop() {
  lcd.setCursor(0, 1);

  int ldrValue = analogRead(ldr);
  ldrValue = map(ldrValue, 130, 350, 0, 255);
  ldrValue = ldrValue < 0 
              ? 0 
              : (ldrValue > 255 
                  ? 255 
                  : ldrValue);
  
  lcd.print(ldrValue);
}
