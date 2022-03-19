#include "Vec2f.hpp"

std::ostream & operator<<(std::ostream &out, Vec2f &v)
{
    return out << "[" << v.x << ", " << v.y << "]";
}