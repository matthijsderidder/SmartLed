#ifndef SMARTLED_H
#define SMARTLED_H

class SmartLed
{
  public:
    SmartLed(uint8_t rPin = 12, uint8_t gPin = 13, uint8_t bPin = 14);
    void off();
    void color(uint8_t r, uint8_t g, uint8_t b);
    void fade(uint8_t r, uint8_t g, uint8_t b, uint16_t duration = 500);
    void glow(uint8_t r, uint8_t g, uint8_t b, uint16_t duration = 500, uint16_t hold = 250);
    void rainbow(uint16_t amount = 1, uint16_t duration = 500, uint16_t hold = 250);

  private:
    uint8_t _rPin, _gPin, _bPin;
    uint8_t _rCurr, _gCurr, _bCurr;
};

#endif
