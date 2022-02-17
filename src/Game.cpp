#include "Game.hpp"

Game::Game(std::string name)
    : m_Title {name}
{
    
}

Game::~Game()
{

}

void Game::printName()
{
    std::cout << this->m_Title << std::endl;
}