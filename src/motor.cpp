#include <Arduino.h>
#include <Stepper.h>
#include "motor.h"
// motor.cpp


// 스텝 수 정의
const int stepsPerRevolution = 2048;  

// 핀 번호 정의
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// 스테퍼 모터 객체 생성
Stepper myStepper(stepsPerRevolution, IN1, IN2, IN3, IN4);

void setupMotor() {
  // 초기화
  Serial.begin(9600);
  myStepper.setSpeed(10);  // 10 RPM
}
void loopMotor() {
  Serial.println("시계 방향");
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  Serial.println("반시계 방향");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}