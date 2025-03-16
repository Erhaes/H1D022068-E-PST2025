#include <Arduino.h>

// put function declarations here:

int redLED = D3;
int yellowLED = D5;
int greenLED = D6;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLED, HIGH);
  delay(100);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(100);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(100);
  digitalWrite(greenLED, LOW);
}
