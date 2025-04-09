#include <Arduino.h>
#include <Servo.h>

// Variabel servo
Servo myservo;

void setup() {
  myservo.attach(D5);
}

void loop() {
  // for posisi 180 derajat sesuai spesifikasi servo
  // menggerakkan seervo dengan perulangan
  for (int position = 0; position <= 180; position++)
  {
    myservo.write(position);
    delay(10);
  }

  for (int position = 0; position >= 0; position--)
  {
    myservo.write(position);
    delay(10);
  }

  // menggerakkan servo dengan derajat 
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
}