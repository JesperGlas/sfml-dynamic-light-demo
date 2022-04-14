#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include "vec2f.hpp"

class Primitive
{
public:
    virtual ~Primitive() {};

    virtual void render(sf::RenderTarget &target) = 0;
    virtual void castShadow(sf::Vector2f light_source, sf::RenderTexture &texture) = 0;
};

#endif