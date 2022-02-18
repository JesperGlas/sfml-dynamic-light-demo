#include "RectObject.hpp"

/* === Private functions === */

void RectObject::objectGui()
{
    ImGui::Text("Rect");

    ImGui::Text(
        "Pos: %.1f.%.1f",
        this->m_Shape.getPosition().x,
        this->m_Shape.getPosition().y
    );
    if (ImGui::InputFloat("x: ", &this->m_Position.x))
        this->m_Shape.setPosition(this->m_Position);
    if (ImGui::InputFloat("y: ", &this->m_Position.y))
        this->m_Shape.setPosition(this->m_Position);

    ImGui::Text(
        "Size: %.1f.%.1f",
        this->m_Shape.getSize().x,
        this->m_Shape.getSize().y
    );
    if (ImGui::InputFloat("Width: ", &this->m_Size.x))
        this->m_Shape.setSize(this->m_Size);
    if (ImGui::InputFloat("Height: ", &this->m_Size.y))
        this->m_Shape.setSize(this->m_Size);
}

/* === Constructors === */

RectObject::RectObject(
    sf::Vector2f position,
    sf::Vector2f size
) : m_Position {position},
    m_Size {size}
{
    this->m_IdleColor = sf::Color::Blue;
    this->m_HoverColor = sf::Color::Red;
    this->m_ActiveColor = sf::Color::Green;

    this->m_Shape.setPosition(this->m_Position);
    this->m_Shape.setSize(this->m_Size);
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
    this->objectGui();
    target.draw(this->m_Shape);
}