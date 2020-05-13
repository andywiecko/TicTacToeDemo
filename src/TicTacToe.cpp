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
}


void TicTacToe::Start()
{
    gameController.SelectGameMode(GameMode::PvC);
    GameLoop();
}