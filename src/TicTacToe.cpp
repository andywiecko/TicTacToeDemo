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

#include "Players/AI/Minimax.hpp"

void TicTacToe::Start()
{
    gameController.SelectGameMode(GameMode::PvP);

    map.Print();
    Minimax::Move(map);
    map.Print();

    //GameLoop();
}