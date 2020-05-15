#include "TicTacToe.hpp"

void TicTacToe::GameLoop()
{
    while (not GameOver::HasFinished(map))
    {
        for (auto &player : gameController.players)
        {
            MapViewer::View(map);
            player->Move(map);
            if (GameOver::HasFinished(map, player))
                break;
        }
    }
    map.Clear();
}

void TicTacToe::Start()
{
    Console::Clear();
    menu.Menu();
    while (not menu.Exit())
    {
        GameLoop();
        menu.Menu();
    }
}