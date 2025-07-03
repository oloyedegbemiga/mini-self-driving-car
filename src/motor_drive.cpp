#include <Arduino.h>
#include "motor_drive.h"

// define pins for driving motors
#define BIN1 13
#define BIN2 12
#define AIN1 27
#define AIN2 26

// define pwm channels
#define CH_A1 0
#define CH_B1 1
#define CH_A2 2
#define CH_B2 3

// define encoder pins

#define ENCODER_L 17
#define DIRECTION_L 16
#define ENCODER_R 19
#define DIRECTION_R 18

// general variables
const int freq = 1000;
const int resolution = 8;

volatile long encoderData_L, encoderData_R;


// put function declarations here:
void leftWheelDrive(int pwm);
void rightWheelDrive(int pwm);
void setup_motors();
void setup_encoders();

void READ_R_ENCODER();
void READ_L_ENCODER();

void setup_motors(){
  // PWM setup 0
  ledcSetup(CH_A1, freq, resolution);
  ledcAttachPin(AIN1, CH_A1);

  // ledcAttach(LEDC_PIN, 50, LEDC_RESOLUTION);

  // PWM setup 1
  ledcSetup(CH_A2, freq, resolution);
  ledcAttachPin(AIN2, CH_A2);

  // ledcAttach(LEDC_PIN, 50, LEDC_RESOLUTION);

  // PWM setup 2
  ledcSetup(CH_B1, freq, resolution);
  ledcAttachPin(BIN1, CH_B1);

  // ledcAttach(LEDC_PIN, 50, LEDC_RESOLUTION);

  // PWM setup 3
  ledcSetup(CH_B2, freq, resolution);
  ledcAttachPin(BIN2, CH_B2);

}

void setup_encoders(){
    // pass
    pinMode(ENCODER_R, INPUT);
    pinMode(DIRECTION_R, INPUT);
    pinMode(ENCODER_L, INPUT);
    pinMode(DIRECTION_L, INPUT);

    // setup interrupts for encoders
    attachInterrupt(digitalPinToInterrupt(ENCODER_R), READ_R_ENCODER, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_L), READ_L_ENCODER, CHANGE);
}

// put function definitions here:
void leftWheelDrive(int pwm){
  // pass
//   Serial.println("Left drive");
  if (pwm > 0){
    // Serial.println("Left drive + ");
    ledcWrite(CH_A1, 255);
    ledcWrite(CH_A2, 255 - pwm);
  }else{
    // Serial.println("Left drive - ");
    ledcWrite(CH_A1, 255);
    ledcWrite(CH_A2, 255 + pwm);
  }
}

void rightWheelDrive(int pwm){
  // pass
//   Serial.println("Right drive");
  if (pwm > 0){
    // Serial.println("Right drive + ");
    ledcWrite(CH_B1, 255);
    ledcWrite(CH_B2, 255 - pwm);
  }else{
    // Serial.println("Right drive - ");
    ledcWrite(CH_B1, 255);
    ledcWrite(CH_B2, 255 + pwm);
  }
}

void READ_R_ENCODER(){
    // TODO
    if (digitalRead(ENCODER_R) == LOW){
        if (digitalRead(DIRECTION_R) == LOW){
            encoderData_R++;
        } else{
            encoderData_R--;
        }
    }else{
        if (digitalRead(DIRECTION_R) == LOW){
            encoderData_R--;
        } else {
            encoderData_R++;
        }
    }
}

void READ_L_ENCODER(){
    // TODO
    if (digitalRead(ENCODER_L) == LOW){
        if (digitalRead(DIRECTION_L) == LOW){
            encoderData_L++;
        } else{
            encoderData_L--;
        }
    }else{
        if (digitalRead(DIRECTION_L) == LOW){
            encoderData_L--;
        } else {
            encoderData_L++;
        }
    }
}