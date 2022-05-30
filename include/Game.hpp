#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "imgui-SFML.h"
#include "imgui.h"

#include "Primitive.hpp"
#include "EvenShape.hpp"
#include "LightSource.hpp"

class Game
{
private:
    sf::Shader m_Shader;
    sf::RenderWindow m_Window;
    sf::Sprite m_View;
    sf::RenderTexture m_ViewTexture;
    sf::RenderTexture m_Lightmap;
    sf::Event m_Event;
    sf::Clock m_DeltaClock;
    bool m_KeyPressed {false};

    std::string m_Title;

    float m_Ambiance {0.2f};
    float m_LightIntensity {800.f};


    bool m_ShowObject {true};
    Primitive *m_Object;
    float m_ObjectRadius {50.f};
    int m_ObjectVertices {16};

    bool m_ShowLightSource {true};
    LightSource *m_LightSource;

    std::vector<Primitive *> m_Objects;
    std::vector<LightSource *> m_LightSources;
private:
    // Init functions
    void initShaders();
    void initWindow();
    void initGui();
    
    // Run-time core
    void update();
    void gui();
    void render();
    void renderLights();
    void renderShadows();
    void renderObjects();

    // Run-time Setters
    void mouseAdd();
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