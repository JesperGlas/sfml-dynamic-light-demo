#ifndef _CANVAS_HPP_
#define _CANVAS_HPP_

#include "RectObject.hpp"

class Canvas
{
private:
    sf::Vector2f m_Size;

    sf::RectangleShape m_Canvas;
    sf::RenderTexture m_Texture;

private:
    void initTexture();
    void initCanvas();
public:
    // Constructors
    Canvas(
        float width,
        float height
    );

    // Deconstructor
    ~Canvas();

    void draw(sf::VertexBuffer &vertex_buffer);
};

#endif