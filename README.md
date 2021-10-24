# Arduino SmartLed Library

This Arduino library helps with RGB LED effects.

It sends values to RGB LED's.

## Getting Started

Clone this repository into `Arduino/Libraries` or use the built-in Arduino IDE Library manager to install
a copy of this library. You can find more detail about installing libraries 
[here, on Arduino's website](https://www.arduino.cc/en/guide/libraries).

```CPP
#include <Arduino.h>
#include <SmartLed.h>
```

Each RGB LED requires its own `SmartLed` instance. You can initialize them like this:


### Initialize a RGB LED

```CPP
#define PIN_LEDR 12
#define PIN_LEDG 13
#define PIN_LEDB 14

/**
 * Initialize a new SmartLed instance for a RGB LED
 * connected to digital pins 12, 13, 14 and GND.
 */

SmartLed led = SmartLed(
  PIN_LEDR,    // Output pin for the red LED
  PIN_LEDG,    // Output pin for the green LED
  PIN_LEDB     // Output pin for the blue LED
);
```


### Functions

`SmartLed` provides a couple of functions to set the LED effects:

| Function                                                | Description                                 |
| ------------------------------------------------------- | ------------------------------------------- |
| `void off()`                                            | Turns the LED off.                          |
| `void color(r, g, b)`                                   | Sets the color of the LED                   |
| `void fade(r, g, b, duration = 500)`                    | Fades the LED to the color given            |
| `void glow(r, g, b, duration = 500, hold = 250)`        | Glows the LED with the color given          |
| `void rainbow(amount = 1, duration = 500. hold = 250)`  | Runs a rainbow effect on the LED            |


## Troubleshooting

If your LED's aren't acting they way they should, check these items:

1. Check your wiring and pin numbers.
   