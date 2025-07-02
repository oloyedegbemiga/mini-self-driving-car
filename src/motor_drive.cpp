#include <Arduino.h>

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
void leftWheelDrive(int pwm);
void rightWheelDrive(int pwm);
void setup_motors();
void setup_encoders();

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
}

// put function definitions here:
void leftWheelDrive(int pwm){
  // pass
  Serial.println("Left drive");
  if (pwm > 0){
    Serial.println("Left drive + ");
    ledcWrite(CH_A1, 255);
    ledcWrite(CH_A2, 255 - pwm);
  }else{
    Serial.println("Left drive - ");
    ledcWrite(CH_A1, 255);
    ledcWrite(CH_A2, 255 + pwm);
  }
}

void rightWheelDrive(int pwm){
  // pass
  Serial.println("Right drive");
  if (pwm > 0){
    Serial.println("Right drive + ");
    ledcWrite(CH_B1, 255);
    ledcWrite(CH_B2, 255 - pwm);
  }else{
    Serial.println("Right drive - ");
    ledcWrite(CH_B1, 255);
    ledcWrite(CH_B2, 255 + pwm);
  }
}