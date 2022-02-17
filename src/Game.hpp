#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

#include <iostream>
#include <string>

class Game
{
private:
    sf::RenderWindow m_Window;
    sf::Event m_Event;
    sf::Clock m_DeltaClock;

    std::string m_Title;

private:
    void initWindow();
    void initGui();
    void initClock();
public:
    Game(std::string title);

    virtual ~Game();

    void printName();

    void update();
    void GUI();
    void render();
    void shutDown();
    void run();
};

#endif