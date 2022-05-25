#include "Game.hpp"

/* === Private functions === */

// Init functions

void Game::initShaders()
{
    if (!this->m_Shader.loadFromFile(
        "shaders/shader.vert",
        "shaders/shader.frag"
    ))
    {
        std::cout << "Error loading shaders..." << std::endl;\
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Function responsible for initializing the main window.
 * 
 */
void Game::initWindow()
{
    this->m_Window.create(
        sf::VideoMode(1280, 720),
        this->m_Title
    );

    m_Window.setFramerateLimit(60);

    this->m_ViewTexture.create(
        this->m_Window.getSize().x,
        this->m_Window.getSize().y
    );

    this->m_Lightmap.create(
        this->m_Window.getSize().x,
        this->m_Window.getSize().y
    );

    this->m_View = sf::Sprite(m_ViewTexture.getTexture());
}

/**
 * @brief Function responsible for initializing the main gui.
 * 
 */
void Game::initGui()
{
    ImGui::SFML::Init(this->m_Window);
    this->m_LightSource = new LightSource(this->getMousePositon(), 100);
    this->m_Object = new EvenShape(this->getMousePositon(), 50, 6);
}

// Run-time Core functions

/**
 * @brief Function for handling update events for the window, gui and objects.
 * 
 */
void Game::update()
{
    // Handle events
    while (m_Window.pollEvent(this->m_Event))
    {
        ImGui::SFML::ProcessEvent(this->m_Event);

        if (m_Event.type == sf::Event::Closed)
            this->m_Window.close();
        if (m_Event.type == sf::Event::KeyReleased)
        {
            if (m_Event.key.code == sf::Keyboard::L)
                this->m_ShowLightSource = !this->m_ShowLightSource;
            if (m_Event.key.code == sf::Keyboard::O)
                this->m_ShowObject = !this->m_ShowObject;
            if (m_Event.key.code == sf::Keyboard::A)
            {
                if (this->m_ShowLightSource)
                    this->addLightSource();
                if (this->m_ShowObject)
                    this->addObject();
            }

            m_DeltaClock.restart();
        }
    }

    // Update objects
    sf::Vector2f mp = this->getMousePositon();
    this->m_LightSource->update(mp);
    this->m_Object->update(mp);

    // Update Gui
    ImGui::SFML::Update(this->m_Window, this->m_DeltaClock.restart());
}

/**
 * @brief Function containts the applications main gui.
 * 
 */
void Game::gui()
{
    ImGui::Text("Debug Menu");
    ImGui::Text(
        "Mouse Coords: %.2f.%.2f",
        this->getMousePositon().x,
        this->getMousePositon().y
    );

    if (ImGui::Button("Toggle Light"))
        this->m_ShowLightSource = !this->m_ShowLightSource;

    if (ImGui::Button("Toggle Object"))
        this->m_ShowObject = !this->m_ShowObject;

    if (ImGui::Button("Add Object"))
    {
        this->addObject();
    }
}

/**
 * @brief Function that handles the applications rendering.
 * 
 */
void Game::render()
{
    // Clear window
    this->m_Window.clear(sf::Color::White);

    // Render objects on object texture
    this->renderObjects();

    // Render shadows on shadowmap
    this->renderShadows();

    // Draw view on window
    this->m_Shader.setUniform("u_currentTexture", sf::Shader::CurrentTexture);
    this->m_Shader.setUniform("u_lightmap", this->m_Lightmap.getTexture());
    this->m_Window.draw(this->m_View, &this->m_Shader);

    // Render Gui
    ImGui::SFML::Render(this->m_Window);

    // Update window
    this->m_Window.display();
}

void Game::renderObjects()
{
    this->m_ViewTexture.clear(sf::Color::Green);

    for (auto obj : this->m_Objects)
    {
        obj->render(this->m_ViewTexture);
    }

    if (this->m_ShowObject)
        this->m_Object->render(this->m_ViewTexture);

    this->m_ViewTexture.display();
}

void Game::renderShadows()
{
    this->m_Lightmap.clear(sf::Color::Black);

    for (auto lightSource : this->m_LightSources)
        lightSource->render(this->m_Lightmap);
    
    for (auto obj : this->m_Objects)
        obj->castShadow(
            *this->m_LightSource,
            this->m_Lightmap
            );

    for (auto lightSource : this->m_LightSources)
    {
        for (auto obj : this->m_Objects)
            obj->castShadow(
                *lightSource,
                this->m_Lightmap
                );
    }

    if (this->m_ShowLightSource)
        this->m_LightSource->render(this->m_Lightmap);

    this->m_Lightmap.display();
}

// Run-time Setters
void Game::addLightSource()
{
    this->m_LightSources.push_back(this->m_LightSource);
    this->m_LightSource = new LightSource(this->getMousePositon(), 100);   
}

void Game::addObject()
{
    this->m_Objects.push_back(this->m_Object);
    this->m_Object = new EvenShape(this->getMousePositon(), 50, 6);
}

// Run-time Accessors

/**
 * @brief Accessor for the mouse position in the window.
 * 
 * @return const sf::Vector2f 
 */
const sf::Vector2f Game::getMousePositon()
{
    return sf::Vector2f(
        sf::Mouse::getPosition(this->m_Window)
    );
}

// Shutdown functions

/**
 * @brief Function resposible for correct shutdown of the application.
 * 
 */
void Game::shutDown()
{
    std::cout << "Shutting down.." << std::endl;
    ImGui::SFML::Shutdown();

    delete this->m_LightSource;
    delete this->m_Object;

    for (size_t i {0}; i < this->m_Objects.size(); i++)
        delete this->m_Objects.at(i);
    this->m_Objects.clear();

    for (size_t i {0}; i < this->m_LightSources.size(); i++)
        delete this->m_LightSources.at(i);
    this->m_LightSources.clear();
}

// Constructors

/**
 * @brief Construct a new Game:: Game object
 * 
 * @param name Title of the application.
 */
Game::Game(
    std::string name
) : m_Title {name}
{
    this->initShaders();
    this->initWindow();
    this->initGui();

    // Create objects
    this->m_Objects = {};
}

Game::~Game()
{

}

/**
 * @brief Function that handles the applications main loop.
 * 
 */
void Game::run()
{
    while (this->m_Window.isOpen())
    {
        this->update();
        this->gui();
        this->render();
    }

    this->shutDown();
}