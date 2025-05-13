#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int redPin = 9;    // 빨간색 핀
const int greenPin = 10; // 녹색 핀
const int bluePin = 11;  // 파란색 핀
const int potPin = A0;   // 가변저항 핀



LiquidCrystal_I2C lcd(0x27,20,4);
// I2C 주소는 0x27로 설정, LCD 크기는 20x4로 설정

// LED 타입 설정 (true: 공통 애노드, false: 공통 캐소드)
const bool COMMON_ANODE = false;

// RGB LED 색상 설정 함수
void setColor(int red, int green, int blue) {
    // 공통 애노드 LED인 경우 값을 반전
    if (COMMON_ANODE) {
      red = 255 - red;
      green = 255 - green;
      blue = 255 - blue;
    }
    
    // RGB LED에 색상 값 적용
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
  
}