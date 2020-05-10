#include "TicTacToe.hpp"

void TicTacToe::ViewMap()
{
    Console::Clear();
    Console::Line();
    Console::Log("Select row/column\nenumeration: 0-2\n");
    Console::Line();
    Console::Log("\n\n");
    map.Print();
    Console::Log("\n\n");
    Console::Line();
}

void TicTacToe::GameLoop()
{
    while (not GameOver::End(map))
    {
        for (auto &player : gameController.players)
        {
            ViewMap();
            Console::Log(player->Info());
            player->Move(map);
            std::cout << std::endl;
            if (GameOver::End(map))
                break;
        }
    }

    ViewMap();
    GameOver::Victory();
}

void TicTacToe::Start()
{
    gameController.SelectGameMode(GameMode::PvP);
    GameLoop();
}