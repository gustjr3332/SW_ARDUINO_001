// motor.h
#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <Stepper.h>

// 외부에서 접근할 변수/함수 선언
extern Stepper myStepper;
void setupMotor();
void loopMotor();

#endif