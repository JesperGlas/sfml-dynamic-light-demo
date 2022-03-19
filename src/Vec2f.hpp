#include "SFML/Graphics.hpp"

class Vec2f : public sf::Vector2f
{
    public:
        Vec2f() : sf::Vector2f() {}
        Vec2f(float x, float y) : sf::Vector2f(x, y) {}

        virtual ~Vec2f() {}
};