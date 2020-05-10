#ifndef SRC_TICTACTOE_HPP
#define SRC_TICTACTOE_HPP

#include "GameMap/GameMap.hpp"
#include "GameController/GameController.hpp"
#include "GameController/GameOver.hpp"
#include "Misc/Misc.hpp"

class TicTacToe
{
private:
    GameController gameController{};
    GameMap map{};

    void ViewMap();
    void GameLoop();

public:
    void Start();
};

#endif