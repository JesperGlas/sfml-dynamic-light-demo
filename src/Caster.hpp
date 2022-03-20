#ifndef __CASTER_HPP__
#define __CASTER_HPP__

#include "Edge.hpp"

class Caster
{
public:
    Caster();

    virtual render(sf::RenderTarget &target) = 0;
    virtual castShadow(sf::RenderTexture &target) = 0;
};

#endif