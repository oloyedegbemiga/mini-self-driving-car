#include <Arduino.h>
#include "motor_drive.h"

// define pins

#define BIN1 13
#define BIN2 12
#define AIN1 27
#define AIN2 26

#define CH_A1 0
#define CH_B1 1
#define CH_A2 2
#define CH_B2 3

// general variables
const int freq = 1000;
const int resolution = 8;

// put function declarations here:
// void leftWheelDrive(int pwm);
// void rightWheelDrive(int pwm);

void setup() {
  // put your setup code here, to run once:
  // pinMode(BIN1, OUTPUT);
  // pinMode(BIN2, OUTPUT);
  // pinMode(AIN1, OUTPUT);
  // pinMode(AIN2, OUTPUT);

  Serial.begin(115200);
  setup_motors();
  setup_encoders();

  // // PWM setup 0
  // ledcSetup(CH_A1, freq, resolution);
  // ledcAttachPin(AIN1, CH_A1);

  // // ledcAttach(LEDC_PIN, 50, LEDC_RESOLUTION);

  // // PWM setup 1
  // ledcSetup(CH_A2, freq, resolution);
  // ledcAttachPin(AIN2, CH_A2);

  // // ledcAttach(LEDC_PIN, 50, LEDC_RESOLUTION);

  // // PWM setup 2
  // ledcSetup(CH_B1, freq, resolution);
  // ledcAttachPin(BIN1, CH_B1);

  // // ledcAttach(LEDC_PIN, 50, LEDC_RESOLUTION);

  // // PWM setup 3
  // ledcSetup(CH_B2, freq, resolution);
  // ledcAttachPin(BIN2, CH_B2);

  // ledcAttach(LEDC_PIN, 50, LEDC_RESOLUTION);


}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(BIN1, HIGH);
  // digitalWrite(BIN2, LOW);
  Serial.println("Ongoing-drive");
  // delay(3000);
  // leftWheelDrive(120);
  // delay(5000);
  // rightWheelDrive(180);
  // delay(2000);
  leftWheelDrive(120);
  rightWheelDrive(120);
  delay(5000);

  // stop
  leftWheelDrive(0);
  rightWheelDrive(0);
}

// // put function definitions here:
// void leftWheelDrive(int pwm){
//   // pass
//   Serial.println("Left drive");
//   if (pwm > 0){
//     Serial.println("Left drive + ");
//     ledcWrite(CH_A1, 255);
//     ledcWrite(CH_A2, 255 - pwm);
//   }else{
//     Serial.println("Left drive - ");
//     ledcWrite(CH_A1, 255);
//     ledcWrite(CH_A2, 255 + pwm);
//   }
// }

// void rightWheelDrive(int pwm){
//   // pass
//   Serial.println("Right drive");
//   if (pwm > 0){
//     Serial.println("Right drive + ");
//     ledcWrite(CH_B1, 255);
//     ledcWrite(CH_B2, 255 - pwm);
//   }else{
//     Serial.println("Right drive - ");
//     ledcWrite(CH_B1, 255);
//     ledcWrite(CH_B2, 255 + pwm);
//   }
// }