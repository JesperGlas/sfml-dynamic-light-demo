#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "Canvas.hpp"

class Game
{
private:
    sf::RenderWindow m_Window;
    sf::Event m_Event;
    sf::Clock m_DeltaClock;

    std::string m_Title;

    std::vector<RectObject> m_Objects;

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