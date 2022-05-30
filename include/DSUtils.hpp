#ifndef __DSUTILS_HPP__
#define __DSUTILS_HPP__

#include "SFML/Graphics.hpp"
#include "shape2D.hpp"

namespace sfds
{

class Edge {
public:
    sf::Vector2f m_start;
    sf::Vector2f m_end;

    Edge(sf::Vector2f start, sf::Vector2f end) : m_start(start), m_end(end) {}
};

inline const sf::Vector2f unit(const sf::Vector2f &start, const sf::Vector2f &end)
{
    sf::Vector2f norm = end - start;
    auto uv = ds::vec2f(norm.x, norm.y).unit();
    return sf::Vector2f(uv.x, uv.y);
}

inline float distance(const sf::Vector2f &start, const sf::Vector2f &end)
{
    sf::Vector2f norm = end - start;
    return ds::vec2f(norm.x, norm.y).magnitude();
}

inline Edge getBlockingEdge(const sf::Vector2f &ls, const ds::shape2D &shape)
{
    ds::line2D be = shape.getBlockingEdge(ds::point2D(ls.x, ls.y));
    return Edge(
        sf::Vector2f(be.start.x, be.start.y),
        sf::Vector2f(be.end.x, be.end.y)
    );
}

}; // namespace ds

#endif