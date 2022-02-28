/*  STEPPER MOTOR DRIVER ARDUINO MEGA
 *  This Sketch will Rotate Stepper Motor.
 *  Press the Button and Rotation will Switch Direction.
 *  Press Button again to Switch Rotation again.
 *  Turn potentiometer to change Stepper Motor speed.
 *  Wiring images for ACE-128 Encoder, OLED, and Stepper Motor Driver at: 
 *  https://github.com/Vin-X-Mod/OLED-ACE128-Encoder-Stepper-Driver
*/
 
// Arduino MEGA Pins
 
int reverseSwitch = 2;  // Push button for reverse
int driverPUL = 7;    // PUL- pin
int driverDIR = 6;    // DIR- pin
int spd = A0;     // Potentiometer
 
// Variables
 
int pd = 500;       // Pulse Delay period
boolean setdir = LOW; // Set Direction
 
// Interrupt Handler
 
void revmotor (){
 
  setdir = !setdir;
  
}
 
 
void setup() {
 
  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(reverseSwitch), revmotor, FALLING);
  
}
 
void loop() {
  
    pd = map((analogRead(spd)),0,1023,2000,50);
    digitalWrite(driverDIR,setdir);
    digitalWrite(driverPUL,HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL,LOW);
    delayMicroseconds(pd);
 
}
