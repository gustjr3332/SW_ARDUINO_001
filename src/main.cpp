
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
#include <Servo.h>
#include <DHT.h>
#include <SoftwareSerial.h>


//전역변수 관리 

#define RED_PIN    9
#define GREEN_PIN 10
#define BLUE_PIN  11

#define DHTPIN     5
#define DHTTYPE    DHT11
DHT dht(DHTPIN, DHTTYPE);

#define PM_RX 6
#define PM_TX 7
SoftwareSerial pmSerial(PM_RX, PM_TX);

#define MQ135_PIN A1
#define FLAME_PIN A0
#define WATER_PIN A2

#define SERVO_PIN 3
Servo myServo;

#define BUZZER_PIN 4
#define FLAME_THRESHOLD 100  // 불꽃 감지 임계값
#define WATER_THRESHOLD 300 // 수위 임계값
//setup 함수

void setup() {
  Serial.begin(9600);
  dht.begin();
  pmSerial.begin(9600);
  myServo.attach(SERVO_PIN);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("시스템 초기화 완료");
}
  

// 부저 울리기
void buzz(int frequency, int duration) {
  tone(BUZZER_PIN, frequency);
  delay(duration);
  noTone(BUZZER_PIN);
}

// 불꽃 사이렌 재생
void playFireSiren(int cycles = 5) {
  int highFreq = 880; // 높은 음 (A5)
  int lowFreq  = 440; // 낮은 음 (A4)
  int duration = 300; // 각 음 지속 시간 (ms)

  for (int i = 0; i < cycles; i++) {
    buzz(highFreq, duration);
    delay(50);
    buzz(lowFreq, duration);
    delay(50);
  }
}

// RGB 제어
void setRGBColor(int r, int g, int b) {
  analogWrite(RED_PIN, 255 - r);
  analogWrite(GREEN_PIN, 255 - g);
  analogWrite(BLUE_PIN, 255 - b);
}

// DHT11 읽기
void readDHT11() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("온도: "); Serial.print(t);
  Serial.print(" °C, 습도: "); Serial.print(h); Serial.println(" %");
}

// PM2008M 읽기
int pm2_5 = 0;
int pm10 = 0;

void readPM2008M() {
  if (pmSerial.available() >= 32) {
    byte data[32];
    pmSerial.readBytes(data, 32);
    pm2_5 = (data[13] << 8) | data[14];
    pm10 = (data[19] << 8) | data[20];
    Serial.print("PM2.5: "); Serial.print(pm2_5);
    Serial.print(" μg/m³, PM10: "); Serial.println(pm10);
  }
}

// MQ135 공기질 읽기
int readMQ135() {
  int value = analogRead(MQ135_PIN);
  Serial.print("MQ135 값: "); Serial.println(value);
  return value;
}

// 불꽃 감지
void readFlameSensor() {
  int value = analogRead(FLAME_PIN);
  Serial.print("불꽃 감지 값: "); Serial.println(value);
}

// 수위 센서
int readWaterLevel() {
  int value = analogRead(WATER_PIN);
  Serial.print("수위 센서 값: "); Serial.println(value);
  return value;
}

// 서보 제어
void moveServo(int angle) {
  myServo.write(angle);
  Serial.print("서보 모터 이동: "); Serial.print(angle); Serial.println("도");
}

// 불꽃 감지 + 경고
void checkFlameAndAlert() {
  int value = analogRead(FLAME_PIN);
  Serial.print("불꽃 감지 값: "); Serial.println(value);

  if (value < FLAME_THRESHOLD) {
    Serial.println("🔥 불꽃 감지됨! 경고음 발생");
    setRGBColor(255, 0, 0);  // 빨간색 점등
    playFireSiren(5);         // 사이렌 반복 5회
  }
}
//공기질 판단,창문 제어
void checkAirQualityAndVentilate() {
  int mq135 = readMQ135();
  int waterLevel = readWaterLevel();

  // 수위가 높으면 → 무조건 닫기
  if (waterLevel > WATER_THRESHOLD) {
    Serial.println("💧 수위 높음 → 창문 닫음");
    moveServo(90);           // 닫기
    return; // 조건 우선순위 높으므로 여기서 종료
  }

  // 조건 만족 시 서보 작동
  if (mq135 > 400 || pm2_5 > 75 || pm10 > 150) {
    Serial.println("🌫️ 공기 오염 감지 → 환기 필요! 창문을 열겠습니다!");
    setRGBColor(0, 255, 255);  // 청록색 (환기 알림용)
    moveServo(0);              // 서보 0도 → 창문 열기 등
  } else {
    Serial.println("🌤️ 공기 깨끗함 → 창문 닫기");
    moveServo(90);             // 서보 닫힘 위치 유지
  }
}

// loop 함수
void loop() {
  readDHT11();
 

  setRGBColor(0, 0, 255);   // 기본 파란색
  moveServo(90);

  checkFlameAndAlert();     // 불꽃 감지 및 경보
  checkAirQualityAndVentilate(); // 공기질 나쁨 → 서보 작동
  
  delay(3000);
}

