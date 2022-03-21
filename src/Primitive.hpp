#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include "Vec2fUtil.hpp"

class Primitive
{
    virtual void render(sf::RenderTarget &target) = 0;
    virtual void castShadow(sf::RenderTexture &texture) = 0;
};

#endif