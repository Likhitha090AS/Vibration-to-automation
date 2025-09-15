#include <Wire.h>
#include <Servo.h>
#include <MPU9250_asukiaaa.h>
#include <LiquidCrystal_I2C.h>

// LCD setup (address may be 0x27 or 0x3F depending on your module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

MPU9250_asukiaaa mpu;
Servo gateServo;

const int servoPin = 7;
const int buzzerPin = 9;
bool gateClosed = false;

const float motionThreshold = 1.7; // sensitive to minute vibrations

void setup() {
  Serial.begin(9600);

  // Initialize I2C
  Wire.begin();

  // MPU setup
  mpu.setWire(&Wire);
  mpu.beginAccel();

  // Servo setup
  gateServo.attach(servoPin);
  gateServo.write(0); // Start with gate open

  // Buzzer setup
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  // LCD setup
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Initializing");
  delay(2000);
  lcd.clear();
  lcd.print("Wait for Train");
}

void loop() {
  mpu.accelUpdate();

  float ax = abs(mpu.accelX());
  float ay = abs(mpu.accelY());
  float az = abs(mpu.accelZ());
  float totalMotion = ax + ay + az;

  Serial.print("Motion: ");
  Serial.println(totalMotion);

  if (totalMotion > motionThreshold) {
    if (!gateClosed) {
      // Close gate
      gateServo.write(90);
      digitalWrite(buzzerPin, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Train incoming");
      lcd.setCursor(0, 1);
      lcd.print("Gate Closing...");
      gateClosed = true;
    }
  } else {
    if (gateClosed) {
      // Open gate
      gateServo.write(0);
      digitalWrite(buzzerPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Train Passed");
      lcd.setCursor(0, 1);
      lcd.print("Gate Opening...");
      delay(2000);
      lcd.clear();
      lcd.print("Waiting for Train");
      gateClosed = false;
    }
  }

  delay(200);
}
