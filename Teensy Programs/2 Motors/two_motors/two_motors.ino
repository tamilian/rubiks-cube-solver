#include <AccelStepper.h>

const int enablePin = 0;

const int stepPin1 = 1;
const int dirPin1 = 2;

const int stepPin2 = 3;
const int dirPin2 = 4;  

int speed = 7000;  // maximum speed
int acceleration = 10000;  // acceleration value
int stepsFor90Degrees = 200;  // steps for 90 degrees in quarter-step mode

// create two instances of the AccelStepper class
AccelStepper stepper1(AccelStepper::DRIVER, stepPin1, dirPin1);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin2, dirPin2);

void setup() {
  Serial.begin(115200);
  
  // set the maximum speed and acceleration for each motor
  stepper1.setMaxSpeed(speed);
  stepper1.setAcceleration(acceleration);

  stepper2.setMaxSpeed(speed);
  stepper2.setAcceleration(acceleration);

  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH); 

  Serial.println("Stepper motor test program ready.");
  Serial.println("Commands:");
  Serial.println("'A' - Rotate Motor 1 90 degrees clockwise");
  Serial.println("'B' - Rotate Motor 1 90 degrees counter-clockwise");
  Serial.println("'C' - Rotate Motor 2 90 degrees clockwise");
  Serial.println("'D' - Rotate Motor 2 90 degrees counter-clockwise");
  Serial.println("'Q' - Stop both motors");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the incoming command
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
      case 'Q':
        stepper1.stop();
        stepper2.stop();
        Serial.println("Stopped and reset motors.");
        break;
      default:
        Serial.println("Invalid command");
        break;
    }
  }

  // Run the steppers
  stepper1.run();
  stepper2.run();
}
