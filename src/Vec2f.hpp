#include "SFML/Graphics.hpp"

class Vec2f : public sf::Vector2f
{
    public:
        Vec2f() : sf::Vector2f() {}

        virtual ~Vec2f() {}
};