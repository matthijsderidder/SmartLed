#include "Arduino.h"
#include "SmartLed.h"

/**
    Initializes a new instance of the Config class.

    @param rPin     The pin number for the red led.
    @param gPin     The pin number for the green led.
    @param bPin     The pin number for the blue led.
    
    @return         A new instance of the SmartLed class.
*/
SmartLed::SmartLed(uint8_t rPin, uint8_t gPin, uint8_t bPin) {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  
  _rPin = rPin;
  _gPin = gPin;
  _bPin = bPin;

  color(0, 0, 0);
}

/**
    Turns the LED's off.
*/
void SmartLed::off() {
  fade(0, 0, 0);
}

/**
    Sets the LED's color.

    @param r        The amount of red.
    @param g        The amount of green.
    @param b        The amount of blue.
*/
void SmartLed::color(uint8_t r, uint8_t g, uint8_t b) {
  _rCurr = r;
  _gCurr = g;
  _bCurr = b;
  
  analogWrite(_rPin, 255 - r);
  analogWrite(_gPin, 255 - g);
  analogWrite(_bPin, 255 - b);
}

/**
    Fades the LED's color.

    @param r        The amount of red.
    @param g        The amount of green.
    @param b        The amount of blue.
    @param duration The duration of the fade effect
*/
void SmartLed::fade(uint8_t r, uint8_t g, uint8_t b, uint16_t duration) { 
  int dly = 20;
  int steps = duration / dly;

  uint8_t rStart = _rCurr;
  uint8_t gStart = _gCurr;
  uint8_t bStart = _bCurr;

  int rDiff = r - rStart;
  int gDiff = g - gStart;
  int bDiff = b - bStart;

  uint8_t rVal, bVal, gVal;

  for(int i = 0; i < steps - 1; i++) {
    rVal = rStart + (rDiff * i / steps);
    gVal = gStart + (gDiff * i / steps);
    bVal = bStart + (bDiff * i / steps);

    color(rVal, gVal, bVal);
    delay(dly);
  }

  color(r, g, b);
}

/**
    Glows the LED's color.

    @param r        The amount of red.
    @param g        The amount of green.
    @param b        The amount of blue.
    @param duration The duration of the glow effect
    @param hold     The amount of time to wait between the fade-in and fade-out
*/
void SmartLed::glow(uint8_t r, uint8_t g, uint8_t b, uint16_t duration, uint16_t hold) {
  fade(r, g, b, duration);
  delay(hold);
  fade(0, 0, 0, duration);
  delay(50);
}

/**
    Runs a rainbow effect

    @param amount   The amount of cycles.
    @param duration The duration of the glow effect
    @param hold     The amount of time to wait between the fades
*/
void SmartLed::rainbow(uint16_t amount, uint16_t duration, uint16_t hold) {  
  for (int i = 0; i < amount; i++) {
    // Yellow
    fade(255, 255, 0, duration);
    delay(hold);
    
    // Red
    fade(255, 0, 0, duration);
    delay(hold);

    // Magenta
    fade(255, 0, 255, duration);
    delay(hold);

    // Blue
    fade(0, 0, 255, duration);
    delay(hold);

    // Cyan
    fade(0, 255, 255, duration);
    delay(hold);

    // Green
    fade(0, 255, 0, duration);
    delay(hold);
  }
}
