#include "RectObject.hpp"

/* === Private functions === */

/* === Constructors === */

RectObject::RectObject(
    sf::Vector2f position,
    sf::Vector2f size
)
{
    this->m_IdleColor = sf::Color::Blue;
    this->m_HoverColor = sf::Color::Red;
    this->m_ActiveColor = sf::Color::Green;

    this->m_Shape.setPosition(position);
    this->m_Shape.setSize(size);
    this->m_Shape.setFillColor(this->m_HoverColor);
}

/* === Deconstructors === */
RectObject::~RectObject()
{

}

/* === Accessors === */

const bool RectObject::mouseOver(const sf::Vector2f & mouse_position)
{
    return this->m_Shape.getGlobalBounds().contains(mouse_position);
}

/* === Setters === */

void RectObject::update(const sf::Vector2f & mouse_position)
{
    if (this->m_Shape.getGlobalBounds().contains(mouse_position))
    {
        this->m_Shape.setFillColor(this->m_HoverColor);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->m_Shape.setFillColor(this->m_ActiveColor);
            std::cout << "Selected!" << std::endl;
        }
    }
    else
    {
        std::cout << "Idle color" << std::endl;
        this->m_Shape.setFillColor(this->m_IdleColor);
    }
}

void RectObject::render(sf::RenderTarget & target)
{
    ImGui::Text("Rect");
    ImGui::Text(
        "Pos: %.1f.%.1f",
        this->m_Shape.getPosition().x,
        this->m_Shape.getPosition().y
    );
    ImGui::Text(
        "Size: %.1f.%.1f",
        this->m_Shape.getSize().x,
        this->m_Shape.getSize().y
    );

    target.draw(this->m_Shape);
}