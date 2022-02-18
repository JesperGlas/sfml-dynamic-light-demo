#include "Canvas.hpp"

/* === Private functions === */

void Canvas::initTexture()
{
    this->m_Texture.create(
        this->m_Size.x,
        this->m_Size.y
    );
    this->m_Texture.setSmooth(true);
}

void Canvas::initCanvas()
{
    this->m_Canvas.setSize(this->m_Size);
    this->m_Canvas.setTexture(&this->m_Texture.getTexture());
}

/* === Constructors === */

Canvas::Canvas(
    float widht,
    float height
) : m_Size {sf::Vector2f(widht, height)}
{
    this->initCanvas();
    this->initTexture();
}

void Canvas::draw(sf::VertexBuffer &vertex_buffer)
{
    this->m_Texture.draw(vertex_buffer);
}