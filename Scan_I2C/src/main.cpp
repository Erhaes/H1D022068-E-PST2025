#include <Arduino.h>
#include <Wire.h>

int SDA_pin = D3;
int SCL_pin = D4;
// 3v3 disambung ke Vin supaya dayanya kuat
// gnd tetap

void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  Serial.begin(9600);
}

void loop() {
  byte error,address;
  int nDevices;
  Serial.print("scanning...");
  nDevices = 0;
  for (address = 1; address <  127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C terbaca pada alamat 0x");
      if (address < 16)
      {
        Serial.print("0"); 
      }
      Serial.println(address,HEX);
      Serial.println("!");

      nDevices++;
    }else if (error==4)
      {
        Serial.print("Ada error yang tidak diketahui pada alamat");
        if (address<16)
        {
          Serial.print("0");
        }
        Serial.print(address,HEX); 
      }
    }
  if (nDevices == 0)
  {
    Serial.print("Tidak ada satupun alamat I2C yang ditemukan\n");
  }else
  {
    Serial.print("selesai");
  }
  delay(5000);
}

