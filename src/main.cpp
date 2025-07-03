#include <Arduino.h>
#include "motor_drive.h"

// timer

unsigned long timeA=0;
unsigned long timeB=0;
unsigned long encoderTime=0;

// encoder
bool encoderFlag = 1;


int delayShow = 0;
float velocityLeft, velocityRight;

// use this function to test velocity

int getSerialValue(){
  if (Serial.available()){
    int getInt = Serial.parseInt();

    if (getInt > 255) getInt=255;
    if (getInt < -255) getInt=-255;
    return getInt;
  } else{
    return 120;
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setup_motors();
  setup_encoders();

}

void loop() {
  // put your main code here, to run repeatedly:

  int pwm = getSerialValue();
  // Serial.println("Ongoing-drive");
  leftWheelDrive(pwm);
  rightWheelDrive(pwm);
  // delay(5000);

  timeA = millis();

  if(encoderFlag) encoderFlag = 0, encoderTime = timeA;

  if (timeA - encoderTime > 9){
    encoderFlag = 1;
    velocityLeft = encoderData_L; encoderData_L = 0; // get speed using number of pulses per unit time
    velocityRight = encoderData_R; encoderData_R = 0; // same with here

    velocityLeft = (velocityLeft/780.0f) * 100 * 60;
    velocityRight = (velocityRight/780.0f) * 100 * 60;

    delayShow++;
  }

  if (delayShow==50){
    Serial.print("Velocity: ");
    Serial.println(velocityLeft);
  }







  // stop
  leftWheelDrive(0);
  rightWheelDrive(0);
}