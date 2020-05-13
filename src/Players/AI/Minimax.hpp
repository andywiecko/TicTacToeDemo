#ifndef SRC_PLAYERS_AI_MINIMAX_HPP
#define SRC_PLAYERS_AI_MINIMAX_HPP

#include "../../GameMap/GameMap.hpp"
#include "../../GameController/GameOver.hpp"
 
class Minimax
{

    static double Layer(GameMap &map, int depth, bool isMaximizing)
    {
        //Console::Log(depth);
        //Console::Log('\n');
        Field winner;
        if (GameOver::CheckWin(map, winner))
        {
            if (winner == Field::X) // TODO: computer field
                return 10;
            else
                return -10;
        }
        if (map.IsFull()) // Draw
            return 0;

        if (isMaximizing)
        {
            double bestScore = -1000; // TODO: - infty
            for (auto &field : map)
            {
                if (field == Field::_)
                {
                    field = Field::X;
                    double score = Minimax::Layer(map, depth + 1, false);
                    field = Field::_;
                    bestScore = std::max(score, bestScore);
                }
            }
            return bestScore;
        }
        else
        {
            double bestScore = 1000; // TODO: + infty
            for (auto &field : map)
            {
                if (field == Field::_)
                {
                    field = Field::O; // TODO: human other humans
                    double score = Minimax::Layer(map, depth + 1, true);
                    field = Field::_;
                    bestScore = std::min(score, bestScore);
                }
            }
            return bestScore;
        }
    }

public:
    static void Move(GameMap &map)
    {

        double bestScore = -1000; // TODO: - infty
        size_t bestField{0};
        
        size_t index{0};
        for (auto &field : map)
        {
            if (field == Field::_)
            {
                field = Field::X; // TODO: computer field
                double score = Minimax::Layer(map, 0, false);
                field = Field::_;
                if (score > bestScore)
                {
                    bestScore = score;
                    bestField = index;
                }
            }
            index++;
        }

        map.SetField(Field::X, bestField);

    }
};

#endif