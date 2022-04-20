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

    this->m_Shadowmap.create(
        this->m_Window.getSize().x,
        this->m_Window.getSize().y
    );
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
void Game::gui()
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
    // Clear window and shadowmap
    this->m_Window.clear(sf::Color::Black);
    this->m_Shadowmap.clear(sf::Color::Black);


    // Render objects (To shadowmap for now before shading is implemented)
    for (auto object : this->m_Objects)
    {
        object->render(this->m_Shadowmap);
        object->castShadow(this->getMousePositon(), this->m_Shadowmap); // Update shadowmap
        this->m_Shadowmap.display();
        this->m_Window.draw(sf::Sprite(this->m_Shadowmap.getTexture()));
    }
    
    // Render Gui
    ImGui::SFML::Render(this->m_Window);

    // Update window
    this->m_Window.display();
}

// Run-time Setters

void Game::addObject()
{
    std::cout << "Adding object placeholder..." << std::endl;

    auto v1 = ds::vec2f(1, 1);
    std::cout << v1 << std::endl;

    this->m_Objects.push_back(
        //new Square(ds::vec2f(400, 400), 100)
        new EvenShape(ds::vec2f(400, 400), 100, 16)
    );
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

    for (size_t i {0}; i < this->m_Objects.size(); i++)
    {
        delete this->m_Objects.at(i);
    }
    this->m_Objects.clear();
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