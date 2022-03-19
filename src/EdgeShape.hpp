#ifndef __EDGESHAPE_HPP__
#define __EDGESHAPE_HPP__

#include "SFML/Graphics.hpp"

class EdgeShape : public sf::VertexArray
{
    public:
        sf::Vertex start;
        sf::Vertex end;
    public:
        EdgeShape(sf::Vector2f p1, sf::Vector2f p2);

        void render(sf::RenderTarget &target);
};

#endif