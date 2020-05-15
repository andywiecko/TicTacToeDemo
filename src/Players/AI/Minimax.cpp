#include "Minimax.hpp"

namespace Player
{
    double Minimax::Minimizing(int depth)
    {
        double bestScore = Constants::infty;
        Field lastPlayer = players.GetLastOther();
        // there can be more players than 2
        for (auto &player : players.GetOthers())
        {
            for (auto &field : map)
            {
                if (field == Field::_)
                {
                    field = player;
                    double score;
                    if (player == lastPlayer)
                        score = Layer(depth + 1, true);
                    else
                        score = Layer(depth + 1, false);

                    field = Field::_;
                    bestScore = std::min(score, bestScore);
                }
            }
        }
        return bestScore;
    }

    double Minimax::Maximizing(int depth)
    {
        double bestScore = Constants::m_infty;
        for (auto &field : map)
        {
            if (field == Field::_)
            {
                field = players.GetSelf();
                double score = Layer(depth + 1, false);
                field = Field::_;
                bestScore = std::max(score, bestScore);
            }
        }
        return bestScore;
    }

    double Minimax::Layer(int depth, bool isMaximizing)
    {
        Field winner;
        if (GameOver::CheckWin(map, winner))
        {
            if (winner == players.GetSelf())
                return 10;
            else
                return -10;
        }
        if (map.IsFull()) // Draw
            return 0;

        if (isMaximizing)
            // self turn
            return Maximizing(depth);
        else
            // other player
            return Minimizing(depth);
    }

    void Minimax::Move()
    {
        Field self = players.GetSelf();
        double bestScore = Constants::m_infty;
        size_t bestField{0};
        size_t index{0};
        for (auto &field : map)
        {
            if (field == Field::_)
            {
                field = self;
                double score = Layer(0, false);
                field = Field::_;
                if (score > bestScore)
                {
                    bestScore = score;
                    bestField = index;
                }
            }
            index++;
        }

        map.SetField(self, bestField);
    }

    Minimax::Minimax(GameMap &_map, PlayersInfo &_players)
        : map{_map}, players{_players}
    {
    }
} // namespace Player