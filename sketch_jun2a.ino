#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define pins for HC-SR04
const int trigPin = 9;
const int echoPin = 10;
long duration, distance;
void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Set up the HC-SR04 pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Print a startup message on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance Sensor");
}

void loop() {
  // Clear the second line on the LCD
  lcd.setCursor(0, 1);
  lcd.print("                ");

  // Trigger the HC-SR04 sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration / 58.2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Display the distance on the LCD
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  // Wait for a short period before the next measurement
  delay(1000);
}
