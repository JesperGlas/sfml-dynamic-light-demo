#ifndef __VEC2F_UTIL_HPP__
#define __VEC2F_UTIL_HPP__

#include <iostream>
#include <math.h>
#include "SFML/Graphics.hpp"

/**
 * @brief Allows for the << operator in the sf::Vector2f class.
 * 
 * @param out std::ostream
 * @param v sf::Vector2f
 * @return std::ostream& 
 */
inline std::ostream & operator<<(std::ostream &out, const sf::Vector2f &v)
{
    return out << "[" << v.x << ", " << v.y << "]";
}

#endif