#ifndef _RECTOBJECT_HPP_
#define _RECTOBJECT_HPP_

#include <SFML/Graphics.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

#include <iostream>
#include <string>
#include <vector>

enum ObjectState
{
    IDLE = 0,
    HOVER = 1,
    ACTIVE = 2
};

class RectObject
{
private:
    sf::RectangleShape m_Shape;

    sf::Color m_IdleColor;
    sf::Color m_HoverColor;
    sf::Color m_ActiveColor;

public:
    // Constructors
    RectObject(
        sf::Vector2f position,
        sf::Vector2f size
    );

    // Deconstructor
    ~RectObject();

    // Accessors
    const bool mouseOver(const sf::Vector2f & mouse_position);

    // Setters
    void setState(ObjectState state);

    void update(const sf::Vector2f & mouse_position);
    void render(sf::RenderTarget & target);
};

#endif