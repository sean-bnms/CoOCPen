
#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68); // Create the object which is the Acele
int status;

void setup() {
  // serial to display data
  Serial.begin(9600);
  while(!Serial) {} // If The Serial is not there, do nothing

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
}

void loop() {
// read the sensor
  IMU.readSensor(); // Here it reads the different values of ACC and Gyro
// display the data
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("Accelerometre\n");
  Serial.print("Ax:");
  Serial.print(IMU.getAccelX_mss(),6); // ACC of X
  Serial.print("\t");
  Serial.print("Ay:");
  Serial.print(IMU.getAccelY_mss(),6); // ACC of Y
  Serial.print("\t");
  Serial.print("Az:");
  Serial.print(IMU.getAccelZ_mss(),6); // ACC of Z
  Serial.println(" \n");
  Serial.print("\t");
  Serial.print("\t");
  Serial.println("Gyroscope");
  Serial.print("Gx:");
  Serial.print(IMU.getGyroX_rads(),6); // Gyro of X
  Serial.print("\t");
  Serial.print("Gy:");
  Serial.print(IMU.getGyroY_rads(),6); // Gyro of Y
  Serial.print("\t");
  Serial.print("Gz:");
  Serial.print(IMU.getGyroZ_rads(),6); // Gyro of Z
  Serial.println("\n");
 
  delay(100);
}
