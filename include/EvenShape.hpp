#ifndef __EVENSHAPE_HPP__
#define __EVENSHAPE_HPP__

#include "DSUtils.hpp"
#include "Primitive.hpp"

using namespace ds;

class EvenShape : public Primitive, public ds::shape2D, public sf::VertexArray
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
        for (auto vertex : this->shape2D::m_vertices)
        {
            sf::Vector2f &current_pos = this->sf::VertexArray::operator[](i).position;
            current_pos.x = vertex.x;
            current_pos.y = vertex.y;
            i++;
        }

        // Last vertice (Creates edge from first middle one with last)
        sf::Vector2f &last_pos = this->sf::VertexArray::operator[](i).position;
        last_pos.x = this->shape2D::operator[](0).x;
        last_pos.y = this->shape2D::operator[](0).y;
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
        shape2D(ds::vec2f(center.x, center.y), radius, size),
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

    void castShadow(LightSource &ls, sf::RenderTexture &texture)
    {
        if (!(abs(sfds::distance(ls, this->sf::VertexArray::operator[](0).position) < ls.m_Intensity)))
            return;

        auto shadow = sf::VertexArray(sf::TriangleStrip, 4);
        auto be = sfds::Edge(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
        try {
            be = sfds::getBlockingEdge(ls, *this);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << " occured, continuing..." << std::endl;
        }

        shadow.operator[](0).position = be.m_start;
        shadow.operator[](0).color = sf::Color::Black;
        shadow.operator[](1).position = be.m_end;
        shadow.operator[](1).color = sf::Color::Black;

        float start_dist = ls.m_Intensity - abs(sfds::distance(ls, be.m_start));
        shadow.operator[](2).position = be.m_start + sfds::unit(ls, be.m_start) * start_dist;
        shadow.operator[](2).color = sf::Color::Transparent;

        float end_dist = ls.m_Intensity - abs(sfds::distance(ls, be.m_end));
        shadow.operator[](3).position = be.m_end + sfds::unit(ls, be.m_end) * end_dist;
        shadow.operator[](3).color = sf::Color::Transparent;

        texture.draw(shadow);
    }

}; // EvenShape

#endif