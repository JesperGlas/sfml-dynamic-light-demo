#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "Primitive.hpp"
#include "square2D.hpp"

class Square : public Primitive, public ds::square2D, public sf::VertexArray
{
public:
    Square(
        ds::vec2f center,
        float radius
    ) : Primitive(), ds::square2D(center, radius), sf::VertexArray(sf::TriangleStrip, 4)
    {
        for (size_t i {0}; i < this->getVertexCount(); i++)
        {
            ds::vec2f corner = this->corners().at(i);
            this->operator[](i).position = sf::Vector2f(corner.x, corner.y);
            this->operator[](i).color = sf::Color::Red;
        }
    }

    ~Square() {}

    void render(sf::RenderTarget &target)
    {
        target.draw(*this);
    }

    void castShadow(sf::Vector2f light_source, sf::RenderTexture &texture)
    {
        auto shadow = sf::VertexArray(sf::Lines, 2);
        ds::line2D blocking = this->getBlockingEdge(ds::point2D(light_source.x, light_source.y));
        shadow.operator[](0).position = sf::Vector2f(blocking.start.x, blocking.start.y);
        shadow.operator[](1).position = sf::Vector2f(blocking.end.x, blocking.end.y);
        shadow.operator[](0).color = sf::Color::Green;
        shadow.operator[](1).color = sf::Color::Green;

        texture.draw(shadow);
    }
};

#endif