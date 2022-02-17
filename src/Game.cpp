#include "Game.hpp"

/* === Private functions === */

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

Game::Game(std::string name)
    : m_Title {name}
{
    this->initWindow();
    this->initGui();
}

Game::~Game()
{

}

void Game::printName()
{
    std::cout << this->m_Title << std::endl;
}

void Game::update()
{
    while (m_Window.pollEvent(this->m_Event))
    {
        ImGui::SFML::ProcessEvent(this->m_Event);

        if (m_Event.type == sf::Event::Closed)
            this->m_Window.close();
    }

    ImGui::SFML::Update(this->m_Window, this->m_DeltaClock.restart());
}

void Game::GUI()
{
    ImGui::Text("Debug Menu");
    if (ImGui::Button("Add Light"))
    {
        std::cout << "Pressed light btn!" << std::endl;
    }
}

void Game::render()
{
    // Clear window
    this->m_Window.clear(sf::Color::Black);

    // Render Gui
    ImGui::SFML::Render(this->m_Window);

    // Update window
    this->m_Window.display();
}

void Game::shutDown()
{
    ImGui::SFML::Shutdown();
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