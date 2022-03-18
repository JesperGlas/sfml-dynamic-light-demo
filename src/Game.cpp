#include "Game.hpp"

/* === Private functions === */

// Init functions

void Game::initWindow()
{
    this->m_Window.create(
        sf::VideoMode(1280, 720),
        this->m_Title
    );

    m_Window.setFramerateLimit(60);
}

void Game::initGui()
{
    ImGui::SFML::Init(this->m_Window);
}

// Run-time Core functions

void Game::update()
{
    while (m_Window.pollEvent(this->m_Event))
    {
        ImGui::SFML::ProcessEvent(this->m_Event);

        if (m_Event.type == sf::Event::Closed)
            this->m_Window.close();
    }

    // Update objects


    ImGui::SFML::Update(this->m_Window, this->m_DeltaClock.restart());
}

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

void Game::render()
{
    // Clear window
    this->m_Window.clear(sf::Color::Black);

    // Render objects
    
    // Render Gui
    ImGui::SFML::Render(this->m_Window);

    // Update window
    this->m_Window.display();
}

// Run-time Setters

void Game::addObject()
{
    std::cout << "Adding object placeholder..." << std::endl;
    Vec2f v = Vec2f();
    v.x = 1.f;
    v.y = 0.5f;

    std::cout << "Test v is [" << v.x << ", " << v.y << "]" << std::endl;
}

// Run-time Accessors

const sf::Vector2f Game::getMousePositon()
{
    return sf::Vector2f(
        sf::Mouse::getPosition(this->m_Window)
    );
}

// Shutdown functions
void Game::shutDown()
{
    std::cout << "Shutting down.." << std::endl;
    ImGui::SFML::Shutdown();
}

Game::Game(
    std::string name
) : m_Title {name}
{
    this->initWindow();
    this->initGui();

    // Create objects

}

Game::~Game()
{

}

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