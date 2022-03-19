#include "SFML/Graphics.hpp"

class Vec2f : public sf::Vector2f
{
public:
    Vec2f() : sf::Vector2f() {}
    Vec2f(float x, float y) : sf::Vector2f(x, y) {}

    virtual ~Vec2f() {}

private:
    friend std::ostream & operator<<(std::ostream &out, const Vec2f &v);

    // Simple math operators
    friend Vec2f operator+(const Vec2f &u, const Vec2f &v);
    friend Vec2f operator-(const Vec2f &u, const Vec2f &v);

    // Multiplier operators
    friend Vec2f operator*(const Vec2f &u, const Vec2f &v);
    friend Vec2f operator*(const float &u, const Vec2f &v);
    friend Vec2f operator*(const Vec2f &v, const float &u);

    // Division operators
    friend Vec2f operator/(const Vec2f &v, const float &u);
};