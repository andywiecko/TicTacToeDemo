#ifndef SRC_TICTACTOE_HPP
#define SRC_TICTACTOE_HPP

#include "GameMap/GameMap.hpp"
#include "GameController/GameController.hpp"
#include "GameController/GameOver.hpp"
#include "GameMap/MapViewer.hpp"

class TicTacToe
{
private:
    GameController gameController{};
    GameMap map{};
    void GameLoop();

public:
    void Start();
};

#endif