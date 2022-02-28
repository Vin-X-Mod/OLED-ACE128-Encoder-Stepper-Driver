/* OLED_BOURNS_ACE128 Sketch for Arduino MEGA 2560
 * This Sketch Shows Bourns Encoder Value on OLED Display
 * Arduino Sketch will clear the Screen blank for 1 second
 * Then will show ACE128 Splash Screen for 3 seconds
 * Then will show Bourns Encoder Value starting at 0
 * Clockwise Positive Values
 * Counter-Cloakwise Negative Values when below 0
 * Connect Encoder to Pins 46,47,48,49,50,51,52,53 on MEGA
 * ACE128 Library at: https://github.com/arielnh56/ACE128
 */

// OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

 
// Include the Bourns EAW Encoder ACE128 library
#include <ACE128.h>  // Library info at: https://github.com/arielnh56/ACE128

// Include the Bourns EAW Encoder mapping
#include <ACE128map12345678.h> // Mapping for ACE128 Encoder pin order 12345678

// Attach to Arduino MEGA's pins 46,47,48,49,50,51,52,53 to Encoder pins 1,2,3,4,5,6,7,8
ACE128 myACE(46,47,48,49,50,51,52,53, (uint8_t*)encoderMap_12345678); // Line used or Arduino Mega2560

// Variable to hold multiturn value of encoder (-32768 to 32767)
int16_t multiturn_encoder_value;  


void setup() {
  Serial.begin(9600); // initialize the encoder library
  myACE.begin(); // initialize the encoder library

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear Display (Blank)for 1 second
  display.clearDisplay();
  display.display();
  delay(1000);  
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10, 18);

  // Display 3 second Splash Screen
  display.println("ACE128");
  display.display(); 
  delay(3000);   
}


void loop() {
  multiturn_encoder_value = myACE.mpos();  // Value from encoder

// Displays Bourns Encoder Value on Serial Monitor
  Serial.print("Encoder: ");
  Serial.print(multiturn_encoder_value);
  Serial.println("");

  delay(100);
  display.clearDisplay();
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10, 18);

  // Displays Bourns Encoder Value starting at 0
  display.println(multiturn_encoder_value);
  display.display(); 
}

// Example Sketch DONE 
