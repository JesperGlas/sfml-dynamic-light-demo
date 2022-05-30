#ifndef __LIGHTSOURCE_HPP__
#define __LIGHTSOURCE_HPP__

#include "SFML/Graphics.hpp"
#include "DSUtils.hpp"

class LightSource : public sf::Vector2f, public sf::VertexArray
{
public:
    float m_Intensity;
public:
    LightSource(
        sf::Vector2f center,
        float intensity
    ) : sf::Vector2f(center),
        sf::VertexArray(sf::TriangleFan, 32),
        m_Intensity(intensity)
    {
        this->operator[](0).position = center;
        this->operator[](0).color = sf::Color::White;

        auto shape = ds::shape2D(
            ds::point2D(center.x, center.y),
            m_Intensity,
            this->getVertexCount() - 2
        );

        for (size_t i {1}; i < this->getVertexCount(); i++)
        {
            sf::Vertex &vert = this->operator[](i);
            vert.position.x = shape[i].x;
            vert.position.y = shape[i].y;
            vert.color = sf::Color::Transparent;
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

    void resize(const float intensity)
    {
        this->m_Intensity = intensity;
        sf::Vector2f c = this->operator[](0).position;
        auto sh = ds::shape2D(
            ds::point2D(c.x, c.y),
            m_Intensity,
            this->getVertexCount() - 2
        );

        for (size_t i {1}; i < this->getVertexCount(); i++)
        {
            sf::Vector2f &vert = this->operator[](i).position;
            vert.x = sh[i].x;
            vert.y = sh[i].y;
        }
    }

    void render(sf::RenderTexture &target)
    {
        target.draw(*this);
    }
}; // LightSource

#endif