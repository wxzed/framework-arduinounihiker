#include "Wire.h"

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  byte error, address;
  int nDevices = 0;

  delay(5000);

  Serial.println("Scanning for I2C devices ...");
  for(address = 0x01; address < 0x7f; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0){
      Serial.print("I2C device found at address 0x%02X");
      Serial.println(address);
      nDevices++;
    } else if(error != 2){
      Serial.print("Error %d at address 0x%02X\n");
      Serial.println(error);
      Serial.println(address);
    }
  }
  if (nDevices == 0){
    Serial.println("No I2C devices found");
  }
}
