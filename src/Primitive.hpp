#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include "Vec2f_util.hpp"

class Primitive : sf::VertexArray
{
public:
    Primitive(
        sf::Vector2f p1,
        sf::Vector2f p2
    ) : sf::VertexArray(sf::Lines, 2)
    {
        this->operator[](0).position = p1;
        this->operator[](1).position = p2;
    }

    Primitive(
        sf::Vector2f p1,
        sf::Vector2f p2,
        sf::Vector2f p3,
        sf::Vector2f p4
    ) : sf::VertexArray(sf::Quads, 4)
    {
        this->operator[](0).position = p1;
        this->operator[](1).position = p2;
        this->operator[](2).position = p3;
        this->operator[](3).position = p4;
    }

    Primitive(
        sf::Vector2f top_left,
        float width,
        float height
    ) : sf::VertexArray(sf::Quads, 4)
    {
        this->operator[](0).position = top_left;
        this->operator[](1).position = sf::Vector2f(top_left.x + width, top_left.y);
        this->operator[](2).position = sf::Vector2f(top_left.x + width, top_left.y + height);
        this->operator[](3).position = sf::Vector2f(top_left.x, top_left.y + height);
    }
};

#endif