#include <Arduino.h>
#include <Servo.h>

// kode ultrasonik
int echoPin = D2;
int trigPin = D3;

// led
int redLED = D4;
int greenLED = D5;

// jarak dan waktu ultasonik
long duration;
int distance;


// servo
Servo myservo;



void setup() {
  // kode ultrasonik
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  // led
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);

  // servo
  myservo.attach(D7);
}

void loop() {
  // loop ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Ternak terdeteksi pada jarak ");
  Serial.print(distance);
  Serial.println(" cm");

  //Jarak Ternak
  if (distance <= 150) {
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,HIGH);

    // servo
    for (int position = 0; position <= 90; position++)
    {
      myservo.write(position);
      delay(10);
    }


    Serial.println("Kandang Terbuka");
    delay(10000);

  }else{
    digitalWrite(greenLED,LOW);
    digitalWrite(redLED,HIGH);

    // servo
    for (int position = 90; position >= 0; position--)
    {
      myservo.write(position);
      delay(10);
    }
    Serial.println("Kandang Tertutup");
    delay(10000);
  }
  delay(500);
  // penutup
  
}

