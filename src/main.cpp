#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

#include "Game.hpp"

void addLight();

int main() {
    Game game("Name of Game");
    game.run();

    return 0;
}

void addLight()
{
    std::cout << "Adding light!" << std::endl;
}