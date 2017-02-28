#include <Arduino.h>
#include "DRV8825.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200

// All the wires needed for full functionality
#define DIR 8
#define STEP 9
#define ENBL 13

// microstep control for DRV8825
// same pinout as A4988, different pin names, supports 32 microsteps
#define MODE0 10
#define MODE1 11
#define MODE2 12
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, MODE0, MODE1, MODE2);


/*
* Microstepping mode: 1,2,4,8,16 or 32(DRV8834 only)
* Mode 1 is full speed.
* Mode 32 is 32 microsteps per step.
* The motor should rotate just as fast (set RPM),
* but movement precision is increased.
*/
//MicroStep speed devider
int msSpeed = 8;
int RPM = 3;

void setup() {
  stepper.setRPM(RPM);
}

void loop() {
  
  stepper.setMicrostep(msSpeed);
  
  stepper.move(800 * msSpeed);

}
