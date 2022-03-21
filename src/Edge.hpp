#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include "Vec2fUtil.hpp"

class Edge : public sf::VertexArray
{
public:
    sf::Vector2f start;
    sf::Vector2f end;
};

#endif