#include <AccelStepper.h>

// define stepper motor connections and motor interface type
const int enablePin = 0;

const int stepPin1 = 1;
const int dirPin1 = 2;

const int stepPin2 = 3;
const int dirPin2 = 4;  

const int stepPin3 = 5;
const int dirPin3 = 6;

const int stepsFor90Degrees = 50;  // 90° ÷ 1.8° = 50 steps

// Create three instances of the AccelStepper class
AccelStepper stepper1(AccelStepper::DRIVER, stepPin1, dirPin1);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin2, dirPin2);
AccelStepper stepper3(AccelStepper::DRIVER, stepPin3, dirPin3);

void setup() {
  Serial.begin(115200);
  
  // set the maximum speed and acceleration for each motor
  stepper1.setMaxSpeed(1000);
  stepper1.setAcceleration(500);

  stepper2.setMaxSpeed(1000);
  stepper2.setAcceleration(500);

  stepper3.setMaxSpeed(1000);
  stepper3.setAcceleration(500);

  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);  
} 

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // read the incoming command
    switch (command) {
      case 'A':
        stepper1.move(stepsFor90Degrees);
        Serial.println("Moving Motor 1 90 Degrees clockwise");
        break;
      case 'B':
        stepper1.move(-stepsFor90Degrees);
        Serial.println("Moving Motor 1 90 Degrees counter-clockwise");
        break;
      case 'C':
        stepper2.move(stepsFor90Degrees);
        Serial.println("Moving Motor 2 90 Degrees clockwise");
        break;
      case 'D':
        stepper2.move(-stepsFor90Degrees);
        Serial.println("Moving Motor 2 90 Degrees counter-clockwise");
        break;
      case 'E':
        stepper3.move(stepsFor90Degrees);
        Serial.println("Moving Motor 3 90 Degrees clockwise.");
        break;
      case 'F':
        stepper3.move(-stepsFor90Degrees);
        Serial.println("Moving Motor 3 90 Degrees counter-clockwise");
        break;
      case 'Q':
        stepper1.stop();
        stepper2.stop();
        stepper3.stop();
        Serial.println("Stopped and reset motors.");
        break;
      default:
        Serial.println("Invalid command.");
        break;
    }
  }

  // run the steppers
  stepper1.run();
  stepper2.run();
  stepper3.run();
}
