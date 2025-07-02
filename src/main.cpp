#include <Arduino.h>
#include "motor_drive.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_motors();
  setup_encoders();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Ongoing-drive");
  leftWheelDrive(120);
  rightWheelDrive(120);
  delay(5000);

  // stop
  leftWheelDrive(0);
  rightWheelDrive(0);
}