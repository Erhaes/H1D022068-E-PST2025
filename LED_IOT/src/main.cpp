#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid = "i used to know you so well";
const char* password ="00000000";

ESP8266WebServer server(80);
String webpage;

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  // connect wifi
  Serial.println();
  Serial.print("Configuring access point....");

  // Mengatur wifi
  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid, password);

  // Print status connect
  Serial.println("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Isi webpage
  webpage+= "<h1>Rassya</h1>";
  webpage+= "<h1> Web Control ESP8266";
  webpage+= "<p> LED 1: ";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p> LED 2: ";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p> LED 3: ";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p><br>";

  // membuat tampilan webpage
  server.on("/", [](){
    server.send(200,"text/html", webpage);
  });

  // respon perintah yang masuk
  // ON
  server.on("/LED1ON", [](){
    server.send(200,"text/html", webpage);
    digitalWrite(D2,HIGH);
    delay(1000);
  });

  server.on("/LED2ON", [](){
    server.send(200,"text/html", webpage);
    digitalWrite(D3,HIGH);
    delay(1000);
  });

  server.on("/LED3ON", [](){
    server.send(200,"text/html", webpage);
    digitalWrite(D4,HIGH);
    delay(1000);
  });

  // OFF
  server.on("/LED1OFF", [](){
    server.send(200,"text/html", webpage);
    digitalWrite(D2,LOW);
    delay(1000);
  });

  server.on("/LED2OFF", [](){
    server.send(200,"text/html", webpage);
    digitalWrite(D3,LOW);
    delay(1000);
  });

  server.on("/LED3OFF", [](){
    server.send(200,"text/html", webpage);
    digitalWrite(D4,LOW);
    delay(1000);
  });

  server.begin();
  Serial.println("Webserver dijalankan");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}