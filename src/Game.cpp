#include "Game.hpp"

/* === Private functions === */

// Init functions

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
}

/**
 * @brief Function responsible for initializing the main gui.
 * 
 */
void Game::initGui()
{
    ImGui::SFML::Init(this->m_Window);
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
    }

    // Update objects

    // Update Gui
    ImGui::SFML::Update(this->m_Window, this->m_DeltaClock.restart());
}

/**
 * @brief Function containts the applications main gui.
 * 
 */
void Game::GUI()
{
    ImGui::Text("Debug Menu");
    ImGui::Text(
        "Mouse Coords: %.2f.%.2f",
        this->getMousePositon().x,
        this->getMousePositon().y
    );

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
    this->m_Window.clear(sf::Color::Black);

    // Render objects
    test.render(this->m_Window);
    
    // Render Gui
    ImGui::SFML::Render(this->m_Window);

    // Update window
    this->m_Window.display();
}

// Run-time Setters

void Game::addObject()
{
    std::cout << "Adding object placeholder..." << std::endl;
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
}

// Constructors

/**
 * @brief Construct a new Game:: Game object
 * 
 * @param name Title of the application.
 */
Game::Game(
    std::string name
) : m_Title {name}, test(EdgeShape(Vec2f(100.f, 100.f), Vec2f(400.f, 400.f)))
{
    this->initWindow();
    this->initGui();

    // Create objects
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
        this->GUI();
        this->render();
    }

    this->shutDown();
}