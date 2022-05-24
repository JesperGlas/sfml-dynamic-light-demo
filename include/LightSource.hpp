#ifndef __LIGHTSOURCE_HPP__
#define __LIGHTSOURCE_HPP__

#include "SFML/Graphics.hpp"
#include "vec2f.hpp"

using namespace ds;

class LightSource : public vec2f
{
public:
    float m_intensity;

public:
    LightSource(float x, float y, float intensity)
    : vec2f(x, y), m_intensity(intensity) {}

    void update(float x, float y) { this->x = x; this->y = y; }
}; // LightSource

#endif