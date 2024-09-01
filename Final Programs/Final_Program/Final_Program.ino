#include <AccelStepper.h>

// Define stepper motor connections and motor interface type
const int enablePin = 0;

const int stepPin1 = 1;
const int dirPin1 = 2;

const int stepPin2 = 3;
const int dirPin2 = 4;  

const int stepPin3 = 5;
const int dirPin3 = 6;

const int stepPin4 = 7; 
const int dirPin4 = 8;

const int stepPin5 = 9;
const int dirPin5 = 10;

const int stepPin6 = 11;
const int dirPin6 = 12;

const int stepsFor90Degrees = 50;  // 90° ÷ 1.8° = 50 steps

AccelStepper stepper1(AccelStepper::DRIVER, stepPin1, dirPin1);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin2, dirPin2);
AccelStepper stepper3(AccelStepper::DRIVER, stepPin3, dirPin3);
AccelStepper stepper4(AccelStepper::DRIVER, stepPin4, dirPin4);
AccelStepper stepper5(AccelStepper::DRIVER, stepPin5, dirPin5);
AccelStepper stepper6(AccelStepper::DRIVER, stepPin6, dirPin6);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
