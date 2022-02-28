/* STEPPER MOTOR DRIVER TEST
 * Common Arduino Sketch for Testing Stepper Motor Driver
 * Example Wiring images for Arduino Mega at:
 * https://github.com/Vin-X-Mod/OLED-ACE128-Encoder-Stepper-Driver
 */

#include <AccelStepper.h>

// Define a stepper and the pins it will use
// AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper stepper(1,7,6);

void setup()
{  
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(400);
  stepper.setAcceleration(20);
  stepper.moveTo(2400);
}

void loop()
{
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());

    stepper.run();
}
