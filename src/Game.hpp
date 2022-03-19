#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>

#include "imgui-SFML.h"
#include "imgui.h"

#include "Canvas.hpp"
#include "EdgeShape.hpp"

class Game
{
private:
    sf::RenderWindow m_Window;
    sf::Event m_Event;
    sf::Clock m_DeltaClock;

    std::string m_Title;

    EdgeShape test;

private:
    // Init functions
    void initWindow();
    void initGui();
    void initLightMap();
    
    // Run-time core
    void update();
    void GUI();
    void render();

    // Run-time Setters
    void addObject();

    // Run-time Accessors
    const sf::Vector2f getMousePositon();

    // Shutdown functions
    void shutDown();

public:
    // Constructor
    Game(std::string title);

    // Deconstructor
    virtual ~Game();

    // Run Game
    void run();
};

#endif