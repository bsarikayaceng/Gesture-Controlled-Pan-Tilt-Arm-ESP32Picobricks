#include <Wire.h>
#include <picobricks.h>

// === Object Declarations ===
motorDriver motor;
APDS9960 gestureSensor;

// === Pin Definitions ===
#define BUTTON_PIN 2

// === Servo Angle Constants ===
const int servoStartAngle = 90;
const int servoLeft = 60;
const int servoRight = 120;
const int servoUp = 60;
const int servoDown = 120;

void setup() {
  Wire.begin();                   // Start I2C
  Serial.begin(115200);          // Start serial communication

  pinMode(BUTTON_PIN, INPUT);    // Set button pin as input

  gestureSensor.init(GESTURE);   // Initialize gesture sensor
  Serial.println("Gesture sensor initialized.");

  // Move both servos to center position at startup
  motor.servo(1, servoStartAngle);
  motor.servo(2, servoStartAngle);
}

void loop() {
  // Reset servos if button is pressed
  if (digitalRead(BUTTON_PIN) == HIGH) {
    Serial.println("Button pressed → Resetting both servos to center.");
    motor.servo(1, servoStartAngle);
    motor.servo(2, servoStartAngle);
    delay(500);  // Debounce delay
  }

  // Read gesture
  int gesture = gestureSensor.readGesture();

  if (gesture != 0) {
    switch (gesture) {
      case UP:
        Serial.println("Gesture detected: UP");
        motor.servo(2, servoUp);
        break;
      case DOWN:
        Serial.println("Gesture detected: DOWN");
        motor.servo(2, servoDown);
        break;
      case LEFT:
        Serial.println("Gesture detected: LEFT");
        motor.servo(1, servoLeft);
        break;
      case RIGHT:
        Serial.println("Gesture detected: RIGHT");
        motor.servo(1, servoRight);
        break;
      default:
        Serial.print("Unknown gesture code: ");
        Serial.println(gesture);
        break;
    }
  }

  delay(200);  // Polling delay
}