#include <Wire.h>



void setup() {
  // put your setup code here, to run once:

Wire.begin();
Serial.begin(9600);
while (!Serial); // Uno wait for serial monitor
Serial.println("\n I2C Scanner");
}

void loop() {
  // put your main code here, to run repeatedly:

byte error,adress;
int nDevices;

Serial.println("Scanning..");
nDevices=0;

for (adress=1;adress<127;adress++){

   // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.

    Wire.beginTransmission(adress);
    error= Wire.endTransmission();

    if (error==0){
      Serial.print("I2C device found at address 0x");
      if (adress<16)
        Serial.print("0");
       Serial.print(adress,HEX);
       Serial.println("  !");
       nDevices++;
      
    }

    else if (error ==4){
      Serial.print("Unknown error at address 0x");
      if (adress<16)
        Serial.print("0");
      Serial.println(adress,HEX);
      
      }   

if (nDevices==0)
  Serial.println("No i2C devices found \n");
else
  Serial.println("done \n");

}

delay(5000);
}
