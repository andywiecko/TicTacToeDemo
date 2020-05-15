#ifndef SRC_GAMECONTROLLER_GAMEMENU_HPP
#define SRC_GAMECONTROLLER_GAMEMENU_HPP

#include "GameController.hpp"

enum class MenuEnum : size_t
{
    PVP = 1,
    PVC_EASY = 2,
    PVC_NORMAL = 3,
    CVC = 4,
    EXIT = 5
};

class GameMenu
{
private:
    bool exit = false;
    GameController &gameController;
    void MenuHeader();

public:
    GameMenu(GameController &_gameController);
    void Menu();
    bool Exit();

};

#endif