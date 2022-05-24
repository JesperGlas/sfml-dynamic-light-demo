#ifndef __EVENSHAPE_HPP__
#define __EVENSHAPE_HPP__

#include "Primitive.hpp"
#include "evenShape2D.hpp"

using namespace ds;

class EvenShape : public Primitive, public ds::evenShape2D
{
private:
    sf::VertexArray m_vertexArray;
public:
    EvenShape(
        ds::vec2f center,
        float radius,
        size_t size
    ) : Primitive(), evenShape2D(center, radius, size)
    {
        // Init the vertex array used to draw the shape
        this->m_vertexArray = sf::VertexArray(sf::TriangleFan, this->m_size + 2); // +2 refers to center and final connection end->start

        // Set first point which is center in a VertexArray
        this->m_vertexArray[0].position = sf::Vector2f(center.x, center.y);
        this->m_vertexArray[0].color = sf::Color::Red;

        // Set perimiter points
        size_t i {1}; // start at 1 since sf::VertexArray[0] is center
        for (auto vertex : this->m_vertices)
        {
            this->m_vertexArray[i].position = sf::Vector2f(vertex.x, vertex.y);
            this->m_vertexArray[i].color = sf::Color::Red;
            i++;
        }

        // Set last point which connects last point with the first
        this->m_vertexArray[i].position = sf::Vector2f(this->m_vertices[0].x, this->m_vertices[0].y);
        this->m_vertexArray[i].color = sf::Color::Red;
    }

    ~EvenShape() {}

    void render(sf::RenderTarget &target)
    {
        target.draw(this->m_vertexArray);
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