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
    while (not GameOver::End(map) or not map.IsFull())
    {
        for (auto &player : gameController.players)
        {
            ViewMap();
            player->Move(map);
            if (GameOver::End(map))
            {
                GameOver::Victory(player);
                break;
            }
            else if(map.IsFull())
                GameOver::Draw();
        }
    }
}

void TicTacToe::Start()
{
    gameController.SelectGameMode(GameMode::PvP);
    GameLoop();
}