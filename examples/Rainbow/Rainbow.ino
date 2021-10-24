/*
 This is a sample sketch to show how to use the SmartLed library
 to run a rainbow effect on a RGB LED

 Setup a test circuit:
 * Connect the LED's common cathode (-) to ground
 * Connect the LED's red anode (+) through a 221 ohm resistor to pin 12
 * Connect the LED's green anode (+) through a 221 ohm resistor to pin 13
 * Connect the LED's blue anode (+) through a 221 ohm resistor to pin 14

 The sketch shows how to setup the library and run the rainbow effect on the RGB LED
 */

#include "SmartLed.h"

#define PIN_LEDR 12
#define PIN_LEDG 13
#define PIN_LEDB 14

// Setup a new SmartLed on pins given
SmartLed led(PIN_LEDR, PIN_LEDG, PIN_LEDB);

// setup code here, to run once:
void setup()
{
  Serial.begin(115200);
  Serial.println("SmartLed Example with rainbow effect.");
  
  led.off();
} // setup

// main code here, to run repeatedly:
void loop()
{
  led.rainbow();
} // loop

// End