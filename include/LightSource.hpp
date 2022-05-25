#ifndef __LIGHTSOURCE_HPP__
#define __LIGHTSOURCE_HPP__

#include "SFML/Graphics.hpp"
#include "evenShape2D.hpp"

using namespace ds;

class LightSource : public sf::Vector2f, public sf::VertexArray
{
public:
    LightSource(
        sf::Vector2f center,
        float intensity
    ) : sf::Vector2f(center),
        sf::VertexArray(sf::TriangleFan, 32)
    {
        this->operator[](0).position = center;
        this->operator[](0).color = sf::Color::White;

        ds::evenShape2D shape = ds::evenShape2D(
            ds::point2D(center.x, center.y),
            intensity,
            this->getVertexCount() - 2
        );

        for (size_t i {1}; i < this->getVertexCount(); i++)
        {
            sf::Vertex &vert = this->operator[](i);
            vert.position.x = shape[i].x;
            vert.position.y = shape[i].y;
            vert.color = sf::Color::Black;
        }
    }

    void update(sf::Vector2f pos)
    {
        sf::Vector2f diff = pos - *this;
        *this += diff;

        for (size_t i {0}; i < this->getVertexCount(); i++)
        {
            this->operator[](i).position += diff;
        }
    }

    void render(sf::RenderTexture &target)
    {
        target.draw(*this);
    }
}; // LightSource

#endif