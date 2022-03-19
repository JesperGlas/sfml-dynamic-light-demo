#include "EdgeShape.hpp"

EdgeShape::EdgeShape(Vec2f p1, Vec2f p2)
: sf::VertexArray(sf::TriangleStrip, 4)
{
    this->start = this->operator[](0);
    this->end = this->operator[](1);

    start.position = p1;
    start.color = sf::Color::Red;

    end.position = p2;
    end.color = sf::Color::Red;

    // Adds width to the EdgeShape to allow rendering
    this->operator[](2) = Vec2f(p1.x, p1.y + 5);
    this->operator[](2).color = sf::Color::Red;

    this->operator[](3) = Vec2f(p2.x, p2.y + 5);
    this->operator[](3).color = sf::Color::Red;
}

void EdgeShape::render(sf::RenderTarget &target)
{
    target.draw(*this);
}