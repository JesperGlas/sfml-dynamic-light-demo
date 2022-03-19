#include "SFML/Graphics.hpp"
#include "Vec2f.hpp"

class EdgeShape : public sf::VertexArray
{
    public:
        sf::Vertex start;
        sf::Vertex end;
    public:
        EdgeShape(Vec2f p1, Vec2f p2);

        void render(sf::RenderTarget &target);
};