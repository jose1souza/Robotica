#include <Wire.h>

const int sdaPin = 21;
const int sclPin = 22;

void setup() {
  Serial.begin(115200);
  Wire.begin(sdaPin, sclPin);
  Serial.println("Scanner I2C iniciado.");
}

void loop() {
  int devicesFound = 0;

  for (int address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo em 0x");
      if (address < 16) {
        Serial.print('0');
      }
      Serial.println(address, HEX);
      devicesFound++;
    }
  }

  if (devicesFound == 0) {
    Serial.println("Nenhum dispositivo I2C encontrado.");
  }

  delay(5000);
}