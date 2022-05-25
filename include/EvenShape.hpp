#ifndef __EVENSHAPE_HPP__
#define __EVENSHAPE_HPP__

#include "DSUtils.hpp"
#include "Primitive.hpp"

using namespace ds;

class EvenShape : public Primitive, public ds::evenShape2D, public sf::VertexArray
{

private:
    void updateVerticePositions()
    {
        // First vertex (Center)
        sf::Vector2f &first_pos = this->sf::VertexArray::operator[](0).position;
        first_pos.x = this->m_center.x;
        first_pos.y = this->m_center.y;

        // Middle vertices
        size_t i {1};
        for (auto vertex : this->evenShape2D::m_vertices)
        {
            sf::Vector2f &current_pos = this->sf::VertexArray::operator[](i).position;
            current_pos.x = vertex.x;
            current_pos.y = vertex.y;
            i++;
        }

        // Last vertice (Creates edge from first middle one with last)
        sf::Vector2f &last_pos = this->sf::VertexArray::operator[](i).position;
        last_pos.x = this->evenShape2D::operator[](0).x;
        last_pos.y = this->evenShape2D::operator[](0).y;
    }

    void updateVerticeColor()
    {
        for (size_t i {0}; i < this->sf::VertexArray::getVertexCount(); i++)
            this->sf::VertexArray::operator[](i).color = sf::Color::Red;
    }

public:
    EvenShape(
        sf::Vector2f center,
        float radius,
        size_t size
    ) : Primitive(),
        evenShape2D(ds::vec2f(center.x, center.y), radius, size),
        sf::VertexArray(sf::TriangleFan, (size+2))
    {
        this->updateVerticePositions();
        this->updateVerticeColor();
    }

    ~EvenShape() {}

    void render(sf::RenderTexture &target)
    {
        target.draw(*this);
    }

    void update(sf::Vector2f center)
    {
        *this = EvenShape(center, this->m_radius, this->size());
        this->updateVerticePositions();
    }

    void castShadow(sf::Vector2f &ls, sf::RenderTexture &texture)
    {
        auto shadow = sf::VertexArray(sf::TriangleStrip, 4);
        auto be = Edge(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
        try {
            be = ds::getBlockingEdge(ls, *this);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << " occured, continuing..." << std::endl;
        }

        shadow.operator[](0).position = be.m_start;
        shadow.operator[](1).position = be.m_end;
        shadow.operator[](2).position = be.m_start + ds::unit(ls, be.m_start) * 100.f;
        shadow.operator[](3).position = be.m_end + ds::unit(ls, be.m_end) * 100.f;

        for (size_t i {0}; i < shadow.getVertexCount(); i++)
            shadow.operator[](i).color = sf::Color::Black;

        texture.draw(shadow);
    }

}; // EvenShape

#endif