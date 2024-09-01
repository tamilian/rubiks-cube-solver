#include <AccelStepper.h>

const int stepPin = 1;  // STEP pin
const int dirPin = 2;   // DIR pin
const int microStep = 0; // ENABLE pin

// Stepper motor object
AccelStepper testStepper(AccelStepper::DRIVER, stepPin, dirPin);

int speed = 7000;  // Maximum speed
int acceleration = 10000;  // Acceleration value
int stepsFor90Degrees = 200;  // Steps for 90 degrees (adjust this value)

void setup() {
  Serial.begin(115200);
  
  testStepper.setMaxSpeed(speed);
  testStepper.setAcceleration(acceleration);
  
  pinMode(enablePin, OUTPUT);
  digitalWrite(microStep, HIGH);  
  
  Serial.println("Stepper motor test program ready.");
  Serial.println("Commands:");
  Serial.println("'R' - Rotate 90 degrees clockwise");
  Serial.println("'L' - Rotate 90 degrees counter-clockwise");
  Serial.println("'S' - Stop motor");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    switch (command) {
      case 'R':
        Serial.println("Rotating 90 degrees clockwise");
        testStepper.move(stepsFor90Degrees);
        break;
        
      case 'L':
        Serial.println("Rotating 90 degrees counter-clockwise");
        testStepper.move(-stepsFor90Degrees);
        break;
        
      case 'S':
        Serial.println("Stopping motor");
        testStepper.stop();
        testStepper.setCurrentPosition(0);  // Reset position to 0
        break;
        
      default:
        Serial.println("Invalid command");
        break;
    }
  }
  
  testStepper.run();  // Run the motor to the set position
}
