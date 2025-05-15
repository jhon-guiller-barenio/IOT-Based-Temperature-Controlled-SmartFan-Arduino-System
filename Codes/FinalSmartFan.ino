#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Pins
#define LM35_PIN A0     // LM35 sensor
#define ENABLE 10       // L293D ENA
#define DIRA 9          // L293D IN1
#define DIRB 8          // L293D IN2
#define VREF 5.0

LiquidCrystal_I2C lcd(0x27, 16, 2);

int fanSpeed = 0;
float temperature = 0;
bool autoMode = true;

String inputString = ""; // store incoming Bluetooth data
bool stringComplete = false;

float readTemperature() {
  long sum = 0;
  const int samples = 10;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(LM35_PIN);
    delay(10);
  }
  float avg = sum / (float)samples;
  return avg * (VREF / 1023.0) * 100.0;
}

void setup() {
  Serial.begin(9600); // Bluetooth module connected to Serial

  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  digitalWrite(DIRA, HIGH); // Fan direction
  digitalWrite(DIRB, LOW);
  analogWrite(ENABLE, 0);   // Start with fan off

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Group 6 Project");
  lcd.setCursor(0, 1);
  lcd.print("Temp Fan Ctrl");
  delay(2000);
  lcd.clear();
}

void loop() {
  temperature = readTemperature();

  // Handle Bluetooth command
  if (stringComplete) {
    stringComplete = false;

    inputString.trim(); // clean the input
    if (inputString == "ON") {
      autoMode = false;
      fanSpeed = 255;
    } else if (inputString == "OFF") {
      autoMode = false;
      fanSpeed = 0;
    } else if (inputString == "AUTO") {
      autoMode = true;
    }

    inputString = ""; // clear the buffer
  }

  // Auto mode logic
  if (autoMode) {
    if (temperature < 35.0) {
      fanSpeed = 0;
    } else {
      fanSpeed = map(temperature, 35, 50, 0, 255);
      fanSpeed = constrain(fanSpeed, 0, 255);
    }
  }

  analogWrite(ENABLE, fanSpeed);

  // Send data to MIT App Inventor (format: "temp|speed")
  Serial.print(temperature, 1);
  Serial.print("|");
  Serial.println(fanSpeed);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C    ");

  lcd.setCursor(0, 1);
  lcd.print("Fan PWM: ");
  lcd.print(fanSpeed);
  lcd.print("   ");

  delay(1000);
}

// Serial event: triggered when data received over Bluetooth
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}

