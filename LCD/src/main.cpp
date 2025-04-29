#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// (lokasii2c, 26 kolom , 2 row) tempat di lcd
LiquidCrystal_I2C lcd(0x27, 26, 2);
int SDA_pin = D3;
int SCL_pin = D4;

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("SISTEM TERTANAM DAN APAPUN ITULAH APALAGI COBA");
  lcd.setCursor(0,1);
  lcd.print("INFORMATIKA DAN APAPUN ITULAH APALAGI COBA");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.scrollDisplayLeft();
  delay(300);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}