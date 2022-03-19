#ifndef __VEC2F_UTIL_HPP__
#define __VEC2F_UTIL_HPP__

#include <iostream>
#include "SFML/Graphics.hpp"

inline std::ostream & operator<<(std::ostream &out, const sf::Vector2f &v)
{
    return out << "[" << v.x << ", " << v.y << "]";
}

#endif