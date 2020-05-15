#include "GameMenu.hpp"

void GameMenu::MenuHeader()
{
    Console::Log("\n");
    Console::Line();
    Console::Log("1. Human vs Human\n");
    Console::Log("2. Human vs Computer (Easy)\n");
    Console::Log("3. Human vs Computer (Normal)\n");
    Console::Log("4. Computer vs Computer\n");
    Console::Log("5. Exit\n");
    Console::Line();
}

GameMenu::GameMenu(GameController &_gameController) : gameController{_gameController}
{
}

void GameMenu::Menu()
{
    MenuHeader();
    exit = false;
    size_t mode;
    Console::ReadLine("Select game mode:\n", mode);

    while (mode > 5 or mode < 1) // TODO: better checker
        Console::ReadLine("Unknown option, try again:\n", mode);

    switch (static_cast<MenuEnum>(mode))
    {
    case MenuEnum::PVP:
        gameController.SelectGameMode(GameMode::PvP);
        break;
    case MenuEnum::PVC_EASY:
        gameController.SelectGameMode(GameMode::PvC_EASY);
        break;
    case MenuEnum::PVC_NORMAL:
        gameController.SelectGameMode(GameMode::PvC_NORMAL);
        break;
    case MenuEnum::CVC:
        gameController.SelectGameMode(GameMode::CvC);
        break;
    case MenuEnum::EXIT:
        exit = true;
    default:
        break;
    }
}

bool GameMenu::Exit()
{
    return exit;
}