#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <iostream>
#include <string>

class Game
{
private:
    std::string m_Title;

public:
    Game(std::string title);

    virtual ~Game();

    void printName();
};

#endif