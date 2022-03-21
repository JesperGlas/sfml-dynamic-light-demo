#ifndef __VEC2UTIL_HPP__
#define __VEC2UTIL_HPP__

#include "Vec2fUtil.hpp"

/**
 * @brief Allows for the << operator in the sf::Vector2f class.
 * 
 * @param out std::ostream
 * @param v sf::Vector2f
 * @return std::ostream& 
 */
std::ostream & operator<<(std::ostream &out, const sf::Vector2f &v)
{
    return out << "[" << v.x << ", " << v.y << "]";
}

#endif