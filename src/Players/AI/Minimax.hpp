#ifndef SRC_PLAYERS_AI_MINIMAX_HPP
#define SRC_PLAYERS_AI_MINIMAX_HPP

#include "../../GameMap/GameMap.hpp"

class Minimax
{

static double Layer(GameMap &map, int depth, bool isMaximaze)
{
    return 10;
}

public:
    static void Move(GameMap &map)
    {

        double bestScore = 1000; // + infty
        Field &bestField = map.GetFirstField();

        for (auto &field : map)
        {
            if (field == Field::_)
            {
                field = Field::X; // computer field
                double score = Minimax::Layer(map, 0, false);
                field = Field::_;
                if (score > bestScore)
                {
                    bestScore = score;
                    bestField = field;
                }
            }
        }

        bestField = Field::X; // computer move
    }
};

#endif