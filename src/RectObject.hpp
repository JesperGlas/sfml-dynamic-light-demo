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
    sf::Vector2f m_Position;
    sf::Vector2f m_Size;
    
    sf::RectangleShape m_Shape;

    sf::Color m_IdleColor;
    sf::Color m_HoverColor;
    sf::Color m_ActiveColor;

    bool m_Active;
    bool m_Alive;

private:
    void updateInput(const sf::Vector2f & mouse_position);
    void updateObject();
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
    const bool & isActive() const;
    const bool & isAlive() const;
    void getObjectGUI();

    // Setters
    void setState(ObjectState state);

    void update(const sf::Vector2f & mouse_position);
    void render(sf::RenderTarget & target);
};

#endif