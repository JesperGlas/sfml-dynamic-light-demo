#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "SFML/Graphics.hpp"
#include "imgui-SFML.h"
#include "imgui.h"

#include "Primitive.hpp"
#include "EvenShape.hpp"
#include "LightSource.hpp"

class Game
{
private:
    sf::RenderWindow m_Window;
    sf::RenderTexture m_Shadowmap;
    sf::Event m_Event;
    sf::Clock m_DeltaClock;

    std::string m_Title;

    bool m_ShowObject;
    Primitive *m_Object;

    bool m_ShowLightSource;
    LightSource *m_LightSource;

    std::vector<Primitive *> m_Objects;
    std::vector<LightSource *> m_LightSources;
private:
    // Init functions
    void initWindow();
    void initGui();
    void initLightMap();
    
    // Run-time core
    void update();
    void gui();
    void render();

    // Run-time Setters
    void addLightSource();
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