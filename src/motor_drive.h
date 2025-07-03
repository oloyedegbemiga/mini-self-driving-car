#include <Arduino.h>
#ifndef MY_MOTOR_DRIVE_H
#define MY_MOTOR_DRIVE_H

// encoder reading values
extern volatile long encoderData_L, encoderData_R;


void leftWheelDrive(int pwm);
void rightWheelDrive(int pwm);
void setup_motors();
void setup_encoders();

#endif