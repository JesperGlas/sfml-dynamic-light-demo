#ifndef __EVENSHAPE_HPP__
#define __EVENSHAPE_HPP__

#include "Primitive.hpp"
#include "evenShape2D.hpp"

using namespace ds;

class EvenShape : public Primitive, public ds::evenShape2D
{
private:
    sf::VertexArray m_vertexArray;

private:
    void updateVerticePositions()
    {
        // First vertex (Center)
        sf::Vector2f &first_pos = this->m_vertexArray[0].position;
        first_pos.x = this->m_center.x;
        first_pos.y = this->m_center.y;

        // Middle vertices
        size_t i {1};
        for (auto vertex : this->m_vertices)
        {
            sf::Vector2f &current_pos = this->m_vertexArray[i].position;
            current_pos.x = vertex.x;
            current_pos.y = vertex.y;
            i++;
        }

        // Last vertice (Creates edge from first middle one with last)
        sf::Vector2f &last_pos = this->m_vertexArray[i].position;
        last_pos.x = this->operator[](0).x;
        last_pos.y = this->operator[](0).y;
    }

    void updateVerticeColor()
    {
        for (size_t i {0}; i < this->m_vertexArray.getVertexCount(); i++)
            this->m_vertexArray[i].color = sf::Color::Red;
    }

public:
    EvenShape(
        ds::vec2f center,
        float radius,
        size_t size
    ) : Primitive(), evenShape2D(center, radius, size)
    {
        this->m_vertexArray = sf::VertexArray(sf::TriangleFan, size + 2);
        this->updateVerticePositions();
        this->updateVerticeColor();
    }

    ~EvenShape() {}

    void render(sf::RenderTarget &target)
    {
        target.draw(this->m_vertexArray);
    }

    void update(sf::Vector2f center)
    {
        *this = EvenShape(ds::vec2f(center.x, center.y), this->m_radius, this->size());
        this->updateVerticePositions();
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

}; // EvenShape

#endif