#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

#include "Game.hpp"

void addLight();

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Dynamic Shadows");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    Game game("Name of Game");

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // ImGui Window
        // ImGui::ShowDemoWindow();

        ImGui::Text("Debug Menu");
        if (ImGui::Button("Add Light"))
        {
            addLight();
            game.printName();
        }

        // ImGui Window end

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}

void addLight()
{
    std::cout << "Adding light!" << std::endl;
}