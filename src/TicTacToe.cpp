#include "TicTacToe.hpp"

void TicTacToe::GameLoop()
{
    while (not GameOver::End(map))
    {
        for (auto &player : gameController.players)
        {
            Console::Clear();
            map.Print();
            player->Move(map);
            std::cout << std::endl;
            if (GameOver::End(map))
                break;
        }
    }
    GameOver::Victory();
}

void TicTacToe::Start()
{
    map.Print();

    std::cout << std::endl;

    gameController.SelectGameMode(GameMode::PvP);

    GameLoop();
}