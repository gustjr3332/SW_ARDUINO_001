
/*  git command
echo "# SW_ARDUINO_001" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/gustjr3332/SW_ARDUINO_001.git
git push -u origin main

git remote add origin https://github.com/gustjr3332/SW_ARDUINO_001.git
git branch -M main
git push -u origin main
*/




//헤더파일,라이브러리 관리

#include <Arduino.h>
#include "motor.h" // motor.h 파일 포함


//전역변수 관리 

#define sensorPin A0 // 조도 센서 핀 번호
int sensorValue = 0; // 조도 센서 값 저장 변수

//setup 함수수

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
  setupMotor(); // 모터 설정 함수 호출
  Serial.println("모터 설정 완료"); // 모터 설정 완료 메시지 출력
}
  
// loop 함수

void loop() {
  
  sensorValue = analogRead(sensorPin); // 센서 값 읽기
  
  Serial.print("조도 센서 값: ");
  Serial.println(sensorValue); // 시리얼 모니터에 값 출력
  
  delay(1000); // 1초 대기
  loopMotor(); // 모터 루프 함수 호출
    
}

