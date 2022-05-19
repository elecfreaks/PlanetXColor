#ifndef _PlanetXCOLOR_H_
#define _PlanetXCOLOR_H_

#include <Arduino.h>
#include <Arduino_APDS9960.h>

#define MIN_SAMPLE_TIME   50

class PlanetXColor
{
public:
  PlanetXColor();
  bool begin();
  uint8_t getR();
  uint8_t getG();
  uint8_t getB();
  void update();
  void setSampleTime(uint16_t ms);

private:
  uint8_t _r;
  uint8_t _g;
  uint8_t _b;
  uint32_t _lastTime;
  uint16_t _sampleTime;
};

#endif
