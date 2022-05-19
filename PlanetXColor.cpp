#include "PlanetXColor.h"

PlanetXColor::PlanetXColor()
{
  _r = 0;
  _g = 0;
  _b = 0;
  _lastTime = 0;
  _sampleTime = MIN_SAMPLE_TIME;
}

bool PlanetXColor::begin()
{
  return APDS.begin();
}

uint8_t PlanetXColor::getR()
{
  return _r;
}

uint8_t PlanetXColor::getG()
{
  return _g;
}

uint8_t PlanetXColor::getB()
{
  return _b;
}

void PlanetXColor::update()
{
  uint32_t now = millis();
  if (APDS.colorAvailable() && (now - _lastTime > _sampleTime)) {
    int r = 0;
    int g = 0;
    int b = 0;
    APDS.readColor(r, g, b);
    _r = (uint8_t)map(r, 0, 4097, 0, 255);
    _g = (uint8_t)map(g, 0, 4097, 0, 255);
    _b = (uint8_t)map(b, 0, 4097, 0, 255);
    _lastTime = now;
  }
}

void PlanetXColor::setSampleTime(uint16_t ms)
{
  if (ms < MIN_SAMPLE_TIME) {
    ms = MIN_SAMPLE_TIME;
  }
  _sampleTime = ms;
}
