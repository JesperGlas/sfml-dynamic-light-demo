#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include "SFML/Graphics.hpp"
#include "LightSource.hpp"

class Primitive
{
public:
    virtual ~Primitive() {};

    virtual void render(sf::RenderTexture &target) = 0;
    virtual void update(sf::Vector2f pos) = 0;
    virtual void castShadow(LightSource &light_source, sf::RenderTexture &texture) = 0;
};

#endif